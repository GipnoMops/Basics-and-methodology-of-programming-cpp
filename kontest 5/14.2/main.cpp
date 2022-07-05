#include <iostream>
#include <vector>
#include <string>

std::vector<int> DAY_IN_MONTH = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

class Date {
    friend Date DaysToDate(int days);
    friend int DateToDays(const Date& date);
private:
    int day_;
    int month_;
    int year_;

public:
    Date(int day, int month, int year): day_(day), month_(month), year_(year) {}

    int GetDay() const {
        return day_;
    }

    int GetMonth() const {
        return month_;
    }

    int GetYear() const {
        return year_;
    }

    Date operator+ (int n) {
        return DaysToDate(DateToDays(*this) + n);
    }

    Date operator- (int n) {
        n = DateToDays(*this) - n;
        return DaysToDate(n);
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

    if ((leaps_years + 1970) % 4 == 0) {
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

int operator- (const Date& date1, const Date& date2) {
    return DateToDays(date1) - DateToDays(date2);
}

void print(const Date& date) {
    std::cout << date.GetDay() << " " << date.GetMonth()  << " " << date.GetYear() << "\n";
}


int main() {
    Date d(1, 1, 2000);
    std::cout << DateToDays(d) << "\n";
    print(d);
    --d;
    std::cout << DateToDays(d) << "\n";
    print(d);
    std::cout << DaysToDate(1000).GetDay() << "\n";
    return 0;
}
