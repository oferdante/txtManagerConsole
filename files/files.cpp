#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void params() {
    cout << "?????? ???????:\n";
    cout << "1. ???????? ?????? ? ????.\n";
    cout << "2. ????????? ????.\n";
    cout << "3. ????????????? ????.\n";
    cout << "4. ?????.\n\n";
    cout << "?????: ";
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
                cout << "?????? ???????? ?????!" << endl;
            }
            else {
                cout << "\n?????? ???-??:\n";
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
                cout << "?????? ???????? ?????!" << endl;
            }
            else {
                vector<string> lines;
                string str;
                while (getline(inf, str)) {
                    lines.push_back(str);
                }
                inf.close();

                if (lines.empty()) {
                    cout << "???? ??????." << endl;
                }
                else {
                    cout << "\n?????????? ?????:\n";
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
                cout << "?????? ???????? ?????!" << endl;
                break;
            }

            vector<string> lines;
            string str;
            while (getline(inf, str)) {
                lines.push_back(str);
            }
            inf.close();

            if (lines.empty()) {
                cout << "?????? ????!" << endl;
                break;
            }

            cout << "\n?????????? ?????:\n";
            for (size_t i = 0; i < lines.size(); ++i) {
                cout << i + 1 << ": " << lines[i] << endl;
            }

            size_t lineNumber;
            cout << "\n??????? ????? ?????? ??? ?????????????? (0 - ?????): ";
            cin >> lineNumber;
            cin.ignore();

            if (lineNumber == 0 || lineNumber > lines.size()) {
                cout << "????? ?? ?????????????? ??? ???????????? ????? ??????" << endl;
                break;
            }

            while (true) {
                cout << "\n??????? ??????: " << lines[lineNumber - 1] << endl;
                cout << "??????? ????? ?????? (enter - ?????):\n";

                string newLine;
                getline(cin, newLine);

                if (newLine.empty()) {
                    break;
                }

                lines[lineNumber - 1] = newLine;
            }

            ofstream outf("text.txt");
            if (!outf.is_open()) {
                cout << "?????? ???????? ????? ??? ??????!" << endl;
                break;
            }

            for (const auto& s : lines) {
                outf << s << endl;
            }
            outf.close();

            cout << "?????????????? ?????????.\n";
            break;
        }

        case 4:
            exit(0);
            break;

        default:
            cout << "\n???????? (1-4)!" << endl;
        }
        cout << endl;
    }
	return 0;
}