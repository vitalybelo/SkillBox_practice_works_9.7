#include <iostream>
using namespace std;

bool digitsInStringOnly (string inString);

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    string number1, number2;

    do {
        cout << "Введите первое число (из 4х чисел) = ";
        cin >> number1;
    } while (!digitsInStringOnly(number1) || number1.size() != 4);
    do {
        cout << "Введите второе число (из 4х чисел) = ";
        cin >> number2;
    } while (!digitsInStringOnly(number2) || number2.size() != 4);

    char c = 'A';
    int cows = 0;
    int bulls = 0;
    int cowsOptions = 0;
    string subString1;
    string subString2;

    // Ищем быков и нарезаем строки для коров
    for (int i = 0; i < 4; i++) {
        if (number1[i] == number2[i]) {
            bulls++;
        } else {
            subString1 += number1[i];
            subString2 += number2[i];
            cowsOptions++;
        }
    }
    // Ищем коров там где уже нет быков
    for (int i = 0; i < cowsOptions; i++) {
        for (int n = 0; n < cowsOptions; n++) {
            if (subString1[i] == subString2[n]) {
                subString1[i] = c++;
                subString2[n] = c++;
                cows++;
                break;
            }
        }
    }

    cout << "\nБыков = " << bulls << " :: Коров = " << cows << endl;
    return 0;
}
/*
 * возвращает истину если строка параметр состоит только из цифр
 */
bool digitsInStringOnly(string inString) {
    if (inString.empty()) return false;
    for (int i = 0; i < inString.size(); i++) {
        if (inString[i] < '0' || inString[i] > '9') return false;
    }
    return true;
}
