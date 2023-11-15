// File: A2_S14_20221103_8.cpp
// Author: Abdelrahman Abdelhamid Mostafa
// Section: S14
// ID: 20221103
// TA: Belal



#include <bits/stdc++.h>

using namespace std;

void fractalPattern(int n, int i)
{
    if (n == 1)
    {
        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j < n; j++)
        {
            cout << '*' << endl;
        }
    }
    else
    {
        fractalPattern(n / 2, i);

        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j < n; j++)
        {
            cout << '*';
        }
        cout << endl;

        fractalPattern(n / 2, i + (n / 2));
    }
}


int main()
{

    int n, i; cin >> n >> i;

    fractalPattern(n, i);

    return 0;
}