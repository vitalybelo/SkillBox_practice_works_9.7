#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    int counter;
    int numArab;
    string numRoman;

    do {
        cout << "¬ведите число (от 0 до 3999) = ";
        cin >> numArab;
    } while (numArab < 0 || numArab > 3999);

    int signInt[]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string signStr[]{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i <= 12; i++) {
        if ((counter = numArab / signInt[i]) > 0) {
            for (int n = 0; n < counter; n++) {
                numRoman += signStr[i];
            }
            numArab %= signInt[i];
        }
    }

    cout << numRoman << endl;
    return 0;
}
