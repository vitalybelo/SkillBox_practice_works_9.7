#include <iostream>
using namespace std;

bool timeFormatCorrect(string time, int &totalMinutes);

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    string startTime;
    string finalTime;
    int startMinutes, finalMinutes;
    do {
        cout << "Введите время отправления (HH:MM): ";
        cin >> startTime;
    } while (!timeFormatCorrect(startTime, startMinutes));

    do {
        cout << "Введите время прибытия (HH:MM): ";
        cin >> finalTime;
    } while (!timeFormatCorrect(finalTime, finalMinutes));
    if (finalMinutes < startMinutes) finalMinutes += 24 * 60;

    cout << "\nПоездка составила: ";
    cout << ((finalMinutes - startMinutes) / 60) << " часов ";
    cout << ((finalMinutes - startMinutes) % 60) << " минут\n";

    return 0;
}

bool timeFormatCorrect(string time, int &totalMinutes) {
    if (time.length() != 5 || time[2] != ':') return false;
    time[2] = '0';

    for (int i = 0; i < 5; i++) {
        if (time[i] < '0' || time[i] > '9') return false;
    }

    int hours = 10 * (time[0] - '0') + (time[1] - '0');
    int minutes = 10 * (time[3] - '0') + (time[4] - '0');
    if (hours > 24 || hours < 0 || minutes > 60 || minutes < 0) return false;

    totalMinutes = hours * 60 + minutes;
    return true;
}
