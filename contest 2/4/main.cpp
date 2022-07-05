#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct Time {
    int day;
    int hours;
    int minutes;
};

int main() {
    Time now{};
    cin >> now.day >> now.hours >> now.minutes;

    size_t n;
    cin >> n;

    Time next_alarm{};
    next_alarm.day = 20;
    next_alarm.hours = 20;
    next_alarm.minutes = 20;

    vector<Time> alarms(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> alarms[i].day >> alarms[i].hours >> alarms[i].minutes;

        if (tie(now.day, now.hours, now.minutes) ==
            tie(alarms[i].day, alarms[i].hours, alarms[i].minutes)) {
            next_alarm.day = alarms[i].day;
            next_alarm.hours = alarms[i].hours;
            next_alarm.minutes = alarms[i].minutes;
            break;
        }

        if (alarms[i].day == 0 &&
            tie(now.hours, now.minutes) >
            tie(alarms[i].hours, alarms[i].minutes)) {
            alarms[i].day = now.day + 1;

            if (tie(next_alarm.day, next_alarm.hours, next_alarm.minutes) >
                tie(alarms[i].day, alarms[i].hours, alarms[i].minutes)) {
                next_alarm.day = alarms[i].day;
                next_alarm.hours = alarms[i].hours;
                next_alarm.minutes = alarms[i].minutes;
            }

        } else if (alarms[i].day == 0) {
            alarms[i].day = now.day;

            if (tie(next_alarm.day, next_alarm.hours, next_alarm.minutes) >
                tie(alarms[i].day, alarms[i].hours, alarms[i].minutes)) {
                next_alarm.day = alarms[i].day;
                next_alarm.hours = alarms[i].hours;
                next_alarm.minutes = alarms[i].minutes;
            }

        } else if (tie(now.day, now.hours, now.minutes) >
                   tie(alarms[i].day, alarms[i].hours, alarms[i].minutes)) {
            alarms[i].day += 7;

            if (tie(next_alarm.day, next_alarm.hours, next_alarm.minutes) >
                tie(alarms[i].day, alarms[i].hours, alarms[i].minutes)) {
                next_alarm.day = alarms[i].day;
                next_alarm.hours = alarms[i].hours;
                next_alarm.minutes = alarms[i].minutes;
            }
        }
    }

    if (next_alarm.day > 7) {
        next_alarm.day -= 7;
    }

    cout << next_alarm.day << " " << next_alarm.hours << " " << next_alarm.minutes << "\n";

    return 0;
}
