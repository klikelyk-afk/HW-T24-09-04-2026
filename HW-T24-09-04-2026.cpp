#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void task1() {

    char C = '.';
    string S = "hello world. hello step. hello it.";
    string S0 = "good";

    size_t pos = S.find(C);

    while (pos != string::npos) {

        S.insert(pos, S0);


        pos = S.find(C, pos + S0.length() + 1);
    }


    cout <<  S << endl;
}

void task2() {

    char C = '.';
    string S = "hello world. hello step. hello it.";
    string S0 = "good ";

    size_t pos = S.find(C);

    while (pos != string::npos) {

        S.insert(pos + 1, S0);

        pos = S.find(C, pos + 1 + S0.length());
    }

    cout << S << endl;
}


void task3() {

    string S = "hello world. hello step. hello it.";
    string S0 = "hello";

    int count = 0;

    size_t pos = S.find(S0, 0);

    while (pos != string::npos) {

        count++;


        pos = S.find(S0, pos + S0.length());
    }

    cout << count << endl;
}

void task4() {

    string S = "hello world. hello step. hello it.";
    string S0 = "hello";


    size_t pos = S.find(S0);


    if (pos != string::npos) {

        S.erase(pos, S0.length());
    }


    cout << S << "\"" << endl;
}

void task5() {

    string S = "hello world. hello step. hello it.";
    string S0 = "hello";

    size_t pos = S.find(S0);


    while (pos != string::npos) {

        S.erase(pos, S0.length());

        pos = S.find(S0, pos);
    }


    cout << S << "\"" << endl;
}

void task6() {

    string S = "hello world. hello step. hello it.";
    string S1 = "hello";
    string S2 = "hi";


    size_t pos = S.find(S1);

    while (pos != string::npos) {

        S.replace(pos, S1.length(), S2);


        pos = S.find(S1, pos + S2.length());
    }

    cout << S << endl;
}

void task7() {
    string S = "Программа";
    string result = "";


    for (int i = 0; i < S.length(); i++) {
        if (i % 2 == 0) {
            result += S[i];
        }
    }


    for (int i = S.length() - 1; i >= 0; i--) {
        if (i % 2 != 0) {
            result += S[i];
        }
    }

    cout << "Task 7 Result: " << result << endl;
}


void task8() {

    string S = "Пормамага";
    string result = "";

    int n = S.length();
    int evenCount = (n + 1) / 2;

    string evenPart = S.substr(0, evenCount);
    string oddPartReversed = S.substr(evenCount);


    string oddPart = "";
    for (int i = oddPartReversed.length() - 1; i >= 0; i--) {
        oddPart += oddPartReversed[i];
    }


    for (int i = 0; i < evenCount; i++) {
        result += evenPart[i];
        if (i < oddPart.length()) {
            result += oddPart[i];
        }
    }

    cout << result << endl;
}

void task9() {

    string fileA = "SA.txt";
    string fileB = "SB.txt";
    string fileC = "SC.txt";
    string fileDest = "SD.txt";


    ifstream sa(fileA);
    ifstream sb(fileB);
    ifstream sc(fileC);
    ofstream sd(fileDest);


    if (!sa.is_open() || !sb.is_open() || !sc.is_open() || !sd.is_open()) {
        cout << "Помилка при відкритті файлів!" << endl;
        return;
    }

    int a, b, c;


    while (sa >> a) {
        sb >> b;
        sc >> c;


        sd << a << " " << b << " " << c << " ";
    }


    sa.close();
    sb.close();
    sc.close();
    sd.close();

    cout << "Файл SD успiшно створено!" << endl;
}

//task10 (17) робив на парах
void task10() {
    ifstream inputFile("date.txt");
    ofstream daysFile("days.txt");
    ofstream monthsFile("months.txt");

    if (!inputFile.is_open()) {
        cout << "Помилка: не вдалося вiдкрити date.txt" << endl;
        return;
    }

    int d, m, y;
    char s1, s2;

    while (inputFile >> d >> s1 >> m >> s2 >> y) {
        daysFile << d << " ";
        monthsFile << m << " ";
    }


    daysFile.close();
    monthsFile.close();
    inputFile.close();

    cout << "Файли створено успiшно!" << endl;

    //ВИВОД ДНІВ
    ifstream readDays("days.txt");
    if (readDays.is_open()) {
        cout << "Днi: ";
        int day;
        while (readDays >> day) {
            cout << day << " ";
        }
        cout << endl;
        readDays.close();
    }
    else {
        cout << "Помилка: не вдалося вiдкрити days.txt!" << endl;
    }

    //ВИВОД МІСЯЦІВ
    ifstream readMonths("months.txt");
    if (readMonths.is_open()) {
        cout << "Мiсяцi: ";
        int month;
        while (readMonths >> month) {
            if (month < 10) cout << "0";
            cout << month << " ";
        }
        cout << endl;
        readMonths.close();
    }
    else {
        cout << "Помилка: не вдалося вiдкрити months.txt!" << endl;
    }
}

void task11() {
    ifstream inputFile("date.txt");
    ofstream summerFile("summer_dates.txt");

    if (!inputFile.is_open()) {
        cout << "Помилка: не вдалося вiдкрити date.txt" << endl;
        return;
    }

    string dateLine;
    int summerCount = 0;


    while (getline(inputFile, dateLine)) {
        if (dateLine.empty()) continue;


        int month = stoi(dateLine.substr(3, 2));


        if (month >= 6 && month <= 8) {
            summerFile << dateLine << endl;
            summerCount++;
        }
    }

    inputFile.close();
    summerFile.close();

    if (summerCount > 0) {
        cout << "Знайдено лiтнiх дат: " << summerCount << ". Файл summer_dates.txt створено." << endl;
    }
    else {
        cout << "Лiтнiх дат не знайдено. Файл порожнiй." << endl;
    }
}

void task12() {
    ifstream file1("f1.txt");
    ifstream file2("f2.txt");
    ofstream fileG("g.txt");

    if (!file1.is_open() || !file2.is_open()) {
        cout << "Помилка: не вдалося відкрити вхідні файли!" << endl;
        return;
    }


    string target, replacement;
    file2 >> target >> replacement;
    file2.close();


    string line;
    while (getline(file1, line)) {
        size_t pos = line.find(target);

        while (pos != string::npos) {

            line.replace(pos, target.length(), replacement);


            pos = line.find(target, pos + replacement.length());
        }


        fileG << line << endl;
    }

    file1.close();
    fileG.close();

    cout << "Замiна завершена! бєгом перевiряти файл g.txt :)" << endl;
}


void task13() {
    ifstream fileF("f.txt");
    ofstream fileG("g.txt");

    if (!fileF.is_open()) {
        cout << "Помилка: не вдалося відкрити файл f.txt!" << endl;
        return;
    }

    int choice;
    cout << "Виберiть варiант перетворення (1 або 2):" << endl;
    cout << "1) iм'я По батьковi Прiзвище" << endl;
    cout << "2) Прiзвище i.П.Б." << endl;
    cin >> choice;

    string lastName, firstName, patronymic;


    while (fileF >> lastName >> firstName >> patronymic) {
        if (choice == 1) {

            fileG << firstName << " " << patronymic << " " << lastName << endl;
        }
        else if (choice == 2) {

            fileG << lastName << " " << firstName[0] << "." << patronymic[0] << "." << endl;
        }
    }

    fileF.close();
    fileG.close();

    cout << "Готово! Результат записано у файл g.txt" << endl;
}


int main() {
    
    setlocale(LC_ALL, "ukr");

    task13();
    return 0;
}
