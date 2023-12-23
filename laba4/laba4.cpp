#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readF(string* ps)
{
    ifstream File("1.txt");
    if (!File.is_open())
    {
        cout << "Ошибка!\n";
    }
    while (!File.eof())
        getline(File, *ps);
    File.close();
}

void genStr(string* ps)
{
    setlocale(0, "");
    int x;
    cout << "Введите номер оперцаии\n"
        << "1 - Ввести строку с консоли\n"
        << "2 - Ввести строку с файла\n";
    cin >> x;
    switch (x)
    {
    case 1:
        cin.ignore();
        getline(cin, *ps);
        break;
    case 2:
        readF(ps);
        cout << *ps << endl;
        break;
    default:
        cout << "Ошибка!\n\n";
        system("Pause");
        genStr(ps);
        break;
    }
}

void delSpaces(string* ps)
{
    int count = 0;
    for (int i = 0; (*ps)[i] == ' '; i++)
        count++;
    (*ps).erase(0, count);
    int lenps = (*ps).length();
    for (int i = 0; i < lenps; i++)
    {
        if ((*ps)[i] == ' ')
        {
            if ((*ps)[i + 1] == ' ')
            {
                count = 0;
                while ((*ps)[i + count + 1] == ' ')
                    count++;
                (*ps).erase(i + 1, count);
                lenps = (*ps).length();
            }
            if (((*ps)[i + 1] == '.') || ((*ps)[i + 1] == ',') || ((*ps)[i + 1] == ';') || ((*ps)[i + 1] == ':') || ((*ps)[i + 1] == '!') || ((*ps)[i + 1] == '?'))
            {
                (*ps).erase(i, 1);
                lenps = (*ps).length();
            }
        }
    }
}

void sizeLetters(string* ps)
{
    int lenps = (*ps).length();
    if ((*ps)[0] <= 'z' && (*ps)[0] >= 'a')
        (*ps)[0] -= 32;
    for (int i = 1; i < lenps; i++)
    {
        if (((*ps)[i] <= 'Z' && (*ps)[i] >= 'A') && ((*ps)[i - 1] != ' '))
            (*ps)[i] += 32;
        else if ((i >= 2) && ((*ps)[i] <= 'z' && (*ps)[i] >= 'a') && (((*ps)[i - 2] == '.') || ((*ps)[i - 2] == '!') || ((*ps)[i - 2] == '?')))
            (*ps)[i] -= 32;
        else if ((i >= 2) && ((*ps)[i] <= 'Z' && (*ps)[i] >= 'A') && (((*ps)[i - 2] != '.') || ((*ps)[i - 2] != '!') || ((*ps)[i - 2] != '?')))
            (*ps)[i] += 32;
    }
}

void punktMarks(string* ps)
{
    int countMarks = 0, countPunktMarks = 0;
    for (int i = 0; ((*ps)[i] == '.') || ((*ps)[i] == '-') || ((*ps)[i] == ',') || ((*ps)[i] == ';') || ((*ps)[i] == ':') || ((*ps)[i] == '!') || ((*ps)[i] == '?'); i++)
        countPunktMarks++;
    (*ps).erase(0, countPunktMarks);
    int lenps = (*ps).length();
    for (int i = 0; i < lenps; i++)
    {
        if (((*ps)[i] == '.') || ((*ps)[i] == '-') || ((*ps)[i] == ',') || ((*ps)[i] == ';') || ((*ps)[i] == ':') || ((*ps)[i] == '!') || ((*ps)[i] == '?'))
        {
            char mark = (*ps)[i];
            countMarks = 0;
            while (((*ps)[i + countMarks + 1] == '.') || ((*ps)[i + countMarks + 1] == '-') || ((*ps)[i + countMarks + 1] == ',') || ((*ps)[i + countMarks + 1] == ':') || ((*ps)[i + countMarks + 1] == '?') || ((*ps)[i + countMarks + 1] == '!') || ((*ps)[i + countMarks + 1] == ';'))
                countMarks++;
            countPunktMarks = 0;
            while ((*ps)[i + countPunktMarks + 1] == mark)
                countPunktMarks++;
            if ((*ps)[i] == '.' && countPunktMarks + 1 >= 3)
            {
                (*ps).erase(i + 3, countMarks - 2);
                lenps = (*ps).length();
                i += 2;
                continue;
            }
            (*ps).erase(i + 1, countMarks);
            lenps = (*ps).length();
        }
    }
}

void doubleLetter(string s) {
    int startWord = 0, endWord = 0, lens = s.length();
    char fletter;
    string s1;
    for (int i = 0; i < lens - 1; i++)
    {
        startWord = i;
        while ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
            i++;
        endWord = i - 1;
        fletter = s[startWord];
       // fletter = s[startWord];
        for (int j = startWord; j <= endWord; j++)
        {
            s1 = s1 + s[j];
        }
        if (count(begin(s1), end(s1), fletter) > 1) {
            cout << s1 << " ";
        }
        s1 = "";
        while ((i < lens - 1) && (s[i] != ' '))
            i++;
    }


}

void countSymb(string s) {
    int startWord = 0, endWord = 0, lens = s.length();
    char fletter;
    string s1;
    for (int i = 0; i < lens - 1; i++)
    {
        startWord = i;
        while ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
            i++;
        endWord = i - 1;
        for (int j = startWord; j <= endWord; j++)
        {
            s1 = s1 + s[j];
        }
        if ((endWord - startWord + 1) > 0) {
            cout << s1 << " " << endWord - startWord + 1 << endl;
        }
        s1 = "";
    }
}

void line_search(string s)
{
    string sString;
    cout << "Введите строку\n";
    cin.ignore();
    getline(cin, sString);
    int endString = sString.length();
    int ends = s.length();
    if (endString == 0 || ends < endString)
    {
        cout << "Ошибка!";
        system("Pause");
        sString.erase(0, endString);
        line_search(s);
        return;
    }
    int j, flag_str = 0;
    for (int i = 0; i < ends - endString + 1; i++)
    {
        for (j = 0; j < endString; j++)
        {
            if (s[i + j] != sString[j])
                break;
            if ((s[i + j] == sString[j]) && (j == endString - 1))
            {
                cout << "Строка найдена, ее позиция с " << i + 1 << " по " << i + endString << '\n';
                flag_str++;
                break;
            }
        }
    }
    if (!flag_str)
        cout << "Строка не найдена.\n";
}

void search_Moor(string s)
{
    int lastLetter = 0, i = 0, tabl[100], flag_str = 0;
    string sString;
    cout << "Введите строку\n";
    cin.ignore();
    getline(cin, sString);
    int endString = sString.length();
    int ends = s.length();
    if (endString == 0 || ends < endString)
    {
        cout << "Ошибка!";
        system("Pause");
        sString.erase(0, endString);
        search_Moor(s);
        return;
    }
    if (endString == 1)
        tabl[0] = 1;
    else
        tabl[endString - 2] = 1;
    for (i = endString - 3; i >= 0; i--)
    {
        int j = i;
        while (sString[i] != sString[j + 1] && j < endString - 2)
            j++;
        if (sString[i] == sString[j + 1])
            tabl[i] = tabl[j + 1];
        else
            tabl[i] = endString - 2 - i + 1;
    }
    for (i = 0; i < endString - 1; i++)
    {
        if (sString[i] == sString[endString - 1])
        {
            tabl[endString - 1] = tabl[i];
            break;
        }
    }
    if (i == endString - 1)
        tabl[i] = endString;
    i = endString - 1;
    while (i < ends)
    {
        int j = endString - 1;
        lastLetter = i;
        for (j; j >= 0; j--)
        {
            if (sString[j] != s[i])
            {
                break;
            }
            i--;
        }
        i = lastLetter;
        if (j >= 0)
        {
            i = lastLetter;
            j = endString - 1;
            for (j; j >= 0; j--)
            {
                if (sString[j] == s[i])
                {
                    i += tabl[j];
                    break;
                }
            }
            if (j < 0)
            {
                i += endString;
            }
        }
        else
        {
            cout << "Строка найдена, ее позиция с  " << lastLetter - endString + 2 << " по " << lastLetter + 1 << '\n';
            i++;
            flag_str++;
        }
    }
    if (!flag_str)
        cout << "Строка не найдена";
}

void search(string s)
{
    int x;
    cout << "\nВыберите способ поиска подстроки в последовательности:\n"
        << "1 - Линейный поиск\n"
        << "2 - Поиск с помощью алгоритма Бойера-Мура\n"
        << "0 - Выход\n" << endl;
    cin >> x;
    switch (x)
    {
    case 1:
        line_search(s);
        cout << '\n';
        search(s);
        break;
    case 2:
        search_Moor(s);
        cout << '\n';
        search(s);
        break;
    case 0:
        break;
    default:
        cout << "Ошибка!\n\n";
        system("Pause");
        search(s);
        break;
    }
}

void menu() {
    string s;
    genStr(&s);
    delSpaces(&s);
    sizeLetters(&s);
    punktMarks(&s);
    cout << "\nОтредактированная строка:\n" << s;
    cout << "\n\nСлова последовательности, в которых первая буква слова встречается в этом слове еще раз: \n";
    doubleLetter(s);
    cout << "\n\nKоличество символов в каждом слове исходной последовательности: \n";
    countSymb(s);
    search(s);
}

int main()
{ 
    menu();   
}

