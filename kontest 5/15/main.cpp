#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <map>

std::vector<int> DAY_IN_MONTH = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int DateToDays(int day, int month, int year) {
    if (year % 4 == 0) {
        DAY_IN_MONTH[1] = 29;
    } else {
        DAY_IN_MONTH[1] = 28;
    }

    int num_of_days = 0;

    int leaps_years = ((year - 1969) / 4);
    num_of_days += 366 * leaps_years + 365 * (year - 1970 - leaps_years);

    for (int i = 0; i < month - 1; ++i) {
        num_of_days += DAY_IN_MONTH[i];
    }

    num_of_days += day;
    return num_of_days;
}

std::map<std::string, int> DaysToDate(int days) {
    std::map<std::string, int> date;
    int suppose_years = days / 365;
    int leaps_years = ((suppose_years + 1) / 4);
    int days_in_years = 366 * leaps_years + 365 * (suppose_years - leaps_years);
    if (days <= days_in_years && days >= 365) {
        --suppose_years;
        leaps_years = ((suppose_years + 1) / 4);
        days_in_years = 366 * leaps_years + 365 * (suppose_years - leaps_years);
    }
    days -= days_in_years;

    if ((suppose_years + 1970) % 4 == 0) {
        DAY_IN_MONTH[1] = 29;
    } else {
        DAY_IN_MONTH[1] = 28;
    }

    int num_of_month = 1;
    for (int i = 0; days > DAY_IN_MONTH[i]; ++i) {
        days -= DAY_IN_MONTH[i];
        ++num_of_month;
    }

    int num_of_days = days;

    date["day"] = num_of_days;
    date["month"] = num_of_month;
    date["year"] = 1970 + suppose_years;
    return date;
}

class Date {
    friend std::map<std::string, int> DaysToDate(int days);
    friend int DateToDays(int day, int month, int year);

private:
    int days_;

public:
    Date(int day, int month, int year) {
        if (year % 4 == 0) {
            DAY_IN_MONTH[1] = 29;
        } else {
            DAY_IN_MONTH[1] = 28;
        }

        if (month > 12 || month < 1 || day < 1 || day > DAY_IN_MONTH[month - 1]) {
            throw  std::invalid_argument("invalid argument");
        }

        days_ = DateToDays(day, month, year);
    }

    Date(int days) {
        days_ = days;
    }

    int GetDay() const {
        return DaysToDate(days_)["day"];
    }

    int GetMonth() const {
        return DaysToDate(days_)["month"];
    }

    int GetYear() const {
        return DaysToDate(days_)["year"];
    }

    Date& operator++ () {
        *this = *this + 1;
        return *this;
    }

    Date& operator-- () {
        *this = *this - 1;
        return *this;
    }

    Date operator+ (int n) {
        return Date(days_ + n);
    }

    Date operator- (int n) {
        return Date(days_ - n);
    }

    int operator- (const Date& other) {
        return days_ - other.days_;
    }
};

void print(const Date& date) {
    std::cout << date.GetDay() << " " << date.GetMonth()  << " " << date.GetYear() << "\n";
}


int main() {
    Date d(31, 12, 1971);
    Date d1(1, 12, 1971);
    print(d);
    //++d;
    print(d);
    std::cout << d - d1;
    return 0;
}
