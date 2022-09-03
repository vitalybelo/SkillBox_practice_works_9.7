#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    string inString;
    cout << "Введите строку:\n";
    getline(cin, inString);

    int i = 0;
    int countWords = 0;
    int inStringSize = inString.size();

    while (i < inStringSize) {
        if (inString[i] != ' ') {
            for (countWords++, i++ ; i < inStringSize && inString[i] != ' '; i++);
        }
        i++;
    }
    cout << "Ответ: " << countWords << endl << endl;
    return 0;
}
