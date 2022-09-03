#include <iostream>
#include <string>
using namespace std;

bool checkFloatString (string inString, double &number);

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    double floatNumber;
    string floatString, answer;

    do {
        cout << "Введите число = ";
        cin >> floatString;
    } while (floatString.length() == 0);

    answer = checkFloatString(floatString, floatNumber) ? "YES" : "NO";
    cout.precision(7);
    cout << "Результат проверки: " << answer << endl;
    cout << "Полученное число с плавающей точкой = ";
    cout << fixed << floatNumber << endl << endl;

    return 0;
}

// Запилил:
// Возвращает истину если строка в численном формате
// и значение преобразованного из нее числа в случае true.
// Если результат false - значение number не меняется;
bool checkFloatString (string inString, double &number)
{
//    locale loc("");
//    const numpunct <char> &npunct = use_facet <numpunct <char> >(loc);
//    cout    <<  npunct.decimal_point() << endl;

    if (inString.empty()) return false;
    bool digitsFound = false;
    bool dotFound = false;
    bool pestNotFound = true;
    string cleanString = "";

    int i = 0;
    if (inString[i] == '-') {
        cleanString.push_back(inString[i++]);
        //cleanString += inString[i++];
    }
    for (; i < inString.length(); ++i) {
        switch (inString[i]) {
            case '+':
            case '-':
                return false;
            case '.':
                if (dotFound) return false;
                inString[i] = ',';
                dotFound = true;
                break;
            case '>': // понять зачем ?
                pestNotFound = false;
                break;
            default:
                if (inString[i] < '0' || inString[i] > '9') {
                    return false;
                } else {
                    digitsFound = true;
                }
        }
        if (pestNotFound) {
            cleanString.push_back(inString[i]);
            //cleanString += inString[i];
        }   else pestNotFound = true;
    }
    if (digitsFound) {
        //cout << " :::::: " << cleanString << endl;
        number = stod (cleanString);
        return true;
    }
    return false;
}

