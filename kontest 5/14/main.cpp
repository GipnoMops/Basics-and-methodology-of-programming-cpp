#include <iostream>
#include <vector>
#include <string>

class Date {
    inline static std::vector<int> MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
private:
    int day_;
    int month_;
    int year_;
    bool leap_;

public:
    Date(int day, int month, int year): day_(day), month_(month), year_(year) {
        if (year_ % 4 == 0) {
            ++MONTH[1];
        }
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

    Date operator+ (int n) {
        DaysToDate((*this).DateToDays() + n);
        return *this;
    }

    Date operator- (int n) {
        DaysToDate((*this).DateToDays() - n);
        return *this;
    }

    Date& operator++ () {
        *this = *this + 1;
        return *this;
    }

    Date& operator- () {
        *this = *this - 1;
        return *this;
    }

    int DateToDays() const {
        int num_of_days = 0;

        int leaps_years = ((year_ - 1969) / 4);
        num_of_days += 366 * leaps_years + 365 * (year_ - 1970 - leaps_years);

        for (size_t i = 0; i < month_ - 1; ++i) {
            num_of_days += MONTH[i];
        }

        num_of_days += day_;
        return num_of_days;
    }

    Date DaysToDate(int days) const {
        int suppose_years = days / 365;
        int leaps_years = ((suppose_years + 1) / 4);
        int days_in_years = 366 * leaps_years + 365 * (suppose_years - leaps_years);
        if (days < days_in_years && days >= 365) {
            --suppose_years;
            days_in_years = 366 * leaps_years + 365 * (suppose_years - leaps_years);
        }

        days -= days_in_years;

        int num_of_month = 1;
        for (int i = 0; days > MONTH[i]; ++i) {
            days -= MONTH[i];
            ++num_of_month;
        }

        int num_of_days = days;
        return Date(num_of_days, num_of_month, 1970 + suppose_years);
    }
};

int operator- (const Date& date1, const Date& date2) {
    return date1.DateToDays() - date2.DateToDays();
}

std::string print(const Date& date) {
    std::cout << date.GetDay() << " " << date.GetMonth()  << " " << date.GetYear();
}


int main() {
    Date d(30, 3, 1970);
    std::cout << d.DateToDays() << "\n" << print(d) << "\n";
    d = d - 1;
    std::cout << d.DateToDays() << "\n" << print(d) << "\n";
    return 0;
}
