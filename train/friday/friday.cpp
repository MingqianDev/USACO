/*
ID: 1caokyl1
LANG: C++
TASK: friday
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Date
{
private:
    int year, month, day;
    int K, J;

public:
    Date(int _year, int _month, int _day);
    int getDay();
};

Date::Date(int _year, int _month, int _day)
{
    year = _year;
    month = _month;
    day = _day;

    if (month == 1)
    {
        month = 13;
        year--;
    }
    if (month == 2)
    {
        month = 14;
        year--;
    };
    K = year % 100;
    J = floor(year / 100);
}

int Date::getDay()
{
    int result = (day + (int)floor(13 * (month + 1) / 5) + K + (int)floor(K / 4) + (int)floor(J / 4) - 2 * J) % 7;
    return (result % 7 + 7) % 7;
}

int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int N;
    fin >> N;

    int output[7] = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 1900; i <= 1900 + N - 1; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            Date date = Date(i, j, 13);
            output[date.getDay()]++;
        }
    }

    for (int i = 0; i < 6; ++i)
    {
        fout << output[i] << " ";
    }
    fout << output[6] << endl;

    return 0;
}