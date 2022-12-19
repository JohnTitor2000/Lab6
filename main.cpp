#include <iostream>
#include <Windows.h>
using namespace std;

enum Errors {
    VERYEARLY,
    VERYLATE,
    NEGATIVE
};

class YearException : public exception {
    Errors code;
public:
    YearException(Errors code): code(code){}
    const char* what() const throw() override {
        if (code == Errors::VERYEARLY) return "Что-то не верится...";
        else if (code == Errors::VERYLATE) return "Вы ещё не роидилсь";
        else if (code == Errors::NEGATIVE) return "Вы ввели отрицательное число";
    }
};

class Year
{
    int year;
public:
    Year(int y) : year(y)
    {
        if (y < 1850) throw YearException(Errors::VERYEARLY);
        else if (y > 2022) throw YearException(Errors::VERYLATE);
        else if (y < 0) throw YearException(Errors::NEGATIVE);
    }
    int getY()
    {
        return this->year;
    }
    void setY(int y)
    {
        if (y < 1850) throw YearException(Errors::VERYEARLY);
        else if (y > 2022) throw YearException(Errors::VERYLATE);
        else if (y < 0) throw YearException(Errors::NEGATIVE);
        this->year = y;
    }
};

int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите число от 1 до 3: ";
    int number;
    cin >> number;
    try {
        if (number == 1) {
            cout << "Один" << "\n";
        } else if (number == 2) {
            cout << "Два" << "\n";
        } else if (number == 3) {
            cout << "Три" << "\n";
        } else {
            throw "Некорректное значение";
        }

    } catch (const char* msg) {
        cout << msg << "\n";
    }
    cout << "Введите год рождения: ";
    int year;
    cin >> year;
    try {
        Year value(year);
        cout << "Спасибо" << "\n";
    } catch (YearException err) {
        cout << err.what();
    }
}