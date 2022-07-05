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

bool operator < (const Time& time1, const Time& time2) {
    return tie(time1.day, time1.hours, time1.minutes) <
           tie(time2.day, time2.hours, time2.minutes);
}

int main() {
    Time now{};
    cin >> now.day >> now.hours >> now.minutes;

    size_t n;
    cin >> n;

    Time next_alarm{20, 20, 20};

    Time alarm{};
    for (size_t i = 0; i < n; ++i) {
        cin >> alarm.day >> alarm.hours >> alarm.minutes;

        if (tie(now.day, now.hours, now.minutes) ==
            tie(alarm.day, alarm.hours, alarm.minutes)) {
            next_alarm = alarm;
            break;
        }

        if (alarm.day == 0 &&
        tie(now.hours, now.minutes) ==
        tie( alarm.hours, alarm.minutes)) {
            next_alarm = now;
            break;
        }

        if (alarm.day == 0 &&
            tie(now.hours, now.minutes) >
            tie( alarm.hours, alarm.minutes)) {
            alarm.day = now.day + 1;

            if (alarm < next_alarm) {
                next_alarm = alarm;
            }
            continue;
        }

        if (alarm.day == 0 &&
            tie(now.hours, now.minutes) <
            tie( alarm.hours, alarm.minutes)) {
            alarm.day = now.day;

            if (alarm < next_alarm) {
                next_alarm = alarm;
            }
            continue;
        }

        if (alarm < now) {
            alarm.day += 7;

            if (alarm < next_alarm) {
                next_alarm = alarm;
            }
            continue;
        }
    }

    if (next_alarm.day > 7) {
        next_alarm.day -= 7;
    }

    cout << next_alarm.day << " " << next_alarm.hours << " " << next_alarm.minutes << "\n";

    return 0;
}