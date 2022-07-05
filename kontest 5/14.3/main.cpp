#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::vector<int> DAY_IN_MONTH = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

class Date {
    friend Date DaysToDate(int days);
    friend int DateToDays(const Date& date);
    friend Date operator+ (const Date& date, int n);
    friend Date operator- (const Date& date, int n);
private:
    int day_;
    int month_;
    int year_;

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

        day_ = day;
        month_ = month;
        year_ = year;
    }

    int GetDay() const {
        return day_;
    }

    int GetMonth() const {
        return month_;
    }

    int GetYear() const {
        return year_;
    }



    Date& operator++ () {
        *this = *this + 1;
        return *this;
    }

    Date& operator-- () {
        *this = *this - 1;
        return *this;
    }
};

int DateToDays(const Date& date) {
    if (date.GetYear() % 4 == 0) {
        DAY_IN_MONTH[1] = 29;
    } else {
        DAY_IN_MONTH[1] = 28;
    }

    int num_of_days = 0;

    int leaps_years = ((date.GetYear() - 1969) / 4);
    num_of_days += 366 * leaps_years + 365 * (date.GetYear() - 1970 - leaps_years);

    for (size_t i = 0; i < date.GetMonth() - 1; ++i) {
        num_of_days += DAY_IN_MONTH[i];
    }

    num_of_days += date.GetDay();
    return num_of_days;
}

Date DaysToDate(int days) {
    int suppose_years = days / 365;
    int leaps_years = ((suppose_years + 1) / 4);
    int days_in_years = 366 * leaps_years + 365 * (suppose_years - leaps_years);
    if (days <= days_in_years && days >= 365) {
        --suppose_years;
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
    return Date(num_of_days, num_of_month, 1970 + suppose_years);
}

Date operator+ (const Date& date, int n) {
    return DaysToDate(DateToDays(date) + n);
}

Date operator- (const Date& date, int n) {
    n = DateToDays(date) - n;
    return DaysToDate(n);
}

int operator- (const Date& date1, const Date& date2) {
    return DateToDays(date1) - DateToDays(date2);
}

void print(const Date& date) {
    std::cout << date.GetDay() << " " << date.GetMonth()  << " " << date.GetYear() << "\n";
}


int main() {
    Date d(29, 2, 1971);
    std::cout << DateToDays(d) << "\n";
    print(d);
    d = d + 1000;
    print(d);
    std::cout << DateToDays(d) << "\n";
    std::cout << DateToDays(Date(20, 3, 2060)) << "\n";
    //std::cout << (Date(29, 2, 2096) - Date(30, 3, 2096)) << "\n";
    return 0;
}
