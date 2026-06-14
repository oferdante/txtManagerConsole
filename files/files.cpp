#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void params() {
    cout << "Выбери вариант:\n";
    cout << "1. Добавить запись в файл.\n";
    cout << "2. Прочитать файл.\n";
    cout << "3. Редактировать файл.\n";
    cout << "4. Выход.\n\n";
    cout << "Выбор: ";
}

int main()
{
    setlocale(LC_ALL, "ru");
    unsigned short a;

    while (true) {
        params();
        cin >> a;
        cin.ignore();

        switch (a) {
        case 1: {
            ifstream inf("text.txt");
            bool haveData = false;
            if (inf.is_open()) {
                string line;
                getline(inf, line);
                inf.close();
            }

            ofstream outf("text.txt", ios::app);
            if (!outf.is_open()) {
                cout << "Ошибка открытия файла!" << endl;
            }
            else {
                cout << "\nНапиши что-то:\n";
                string str;
                getline(cin, str);
                outf << str << endl;
                outf.close();
            }
            break;
        }
        case 2: {
            ifstream inf("text.txt");
            if (!inf.is_open()) {
                cout << "Ошибка открытия файла!" << endl;
            }
            else {
                vector<string> lines;
                string str;
                while (getline(inf, str)) {
                    lines.push_back(str);
                }
                inf.close();

                if (lines.empty()) {
                    cout << "Файл пустой." << endl;
                }
                else {
                    cout << "\nСодержимое файла:\n";
                    for (size_t i = 0; i < lines.size(); ++i) {
                        cout << i + 1 << ": " << lines[i] << endl;
                    }
                }
            }
            break;
        }
        case 3: {
            ifstream inf("text.txt");
            if (!inf.is_open()) {
                cout << "Ошибка открытия файла!" << endl;
                break;
            }

            vector<string> lines;
            string str;
            while (getline(inf, str)) {
                lines.push_back(str);
            }
            inf.close();

            if (lines.empty()) {
                cout << "Пустой файл!" << endl;
                break;
            }

            cout << "\nСодержимое файла:\n";
            for (size_t i = 0; i < lines.size(); ++i) {
                cout << i + 1 << ": " << lines[i] << endl;
            }

            size_t lineNumber;
            cout << "\nВведите номер строки для редактирования (0 - выход): ";
            cin >> lineNumber;
            cin.ignore();

            if (lineNumber == 0 || lineNumber > lines.size()) {
                cout << "Выход из редактирования или некорректный номер строки" << endl;
                break;
            }

            while (true) {
                cout << "\nТекущая строка: " << lines[lineNumber - 1] << endl;
                cout << "Введите новую строку (enter - выход):\n";

                string newLine;
                getline(cin, newLine);

                if (newLine.empty()) {
                    break;
                }

                lines[lineNumber - 1] = newLine;
            }

            ofstream outf("text.txt");
            if (!outf.is_open()) {
                cout << "Ошибка открытия файла для записи!" << endl;
                break;
            }

            for (const auto& s : lines) {
                outf << s << endl;
            }
            outf.close();

            cout << "Редактирование завершено.\n";
            break;
        }

        case 4:
            exit(0);
            break;

        default:
            cout << "\nВыберите (1-4)!" << endl;
        }
        cout << endl;
    }
    return 0;
}