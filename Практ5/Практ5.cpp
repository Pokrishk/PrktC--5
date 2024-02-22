#include <iostream>
#include <string>
#include <random>
using namespace std;

string reverseString(string str) {
    return string(str.rbegin(), str.rend());
}

string removeglas(string str) {
    str.erase(remove_if(str.begin(), str.end(), [](char c) { return string("aeiouAEIOU").find(c) != string::npos; }), str.end());
    return str;
}

string removesoglas(string str) {
    str.erase(remove_if(str.begin(), str.end(), [](char c) { return string("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ").find(c) != string::npos; }), str.end());
    return str;
}

string shuffleString(string str) {
    random_device rd;
    mt19937 g(rd());
    shuffle(str.begin(), str.end(), g);
    return str;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    string word;
    cout << "Введите слово (на латинице): ";
    cin >> word;
    int choice;
    cout << "Выберите действие:\n1. Слово задом наперед \n2. Вывести слово без гласных \n3. Вывести слово без согласных \n4. Рандомно раскидать буквы слова\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << reverseString(word) << endl;
        break;
    case 2:
        cout << removeglas(word) << endl;
        break;
    case 3:
        cout << removesoglas(word) << endl;
        break;
    case 4:
        cout << shuffleString(word) << endl;
        break;
    default:
        cout << "Попробуйте заново, но в следующий раз введите число от 1 до 4.";
    }
}

