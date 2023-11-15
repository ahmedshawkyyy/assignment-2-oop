/*
Author : mohamed eprahim mohamed

Section : 14

ID : 20221117

TA : Belal

Date : 28 Oct 2023

*/
#include <iostream>
using namespace std;

bool BearShare(int x)
{
    if (x == 42)
        return true;

    else if (x % 5 == 0)
    {
        BearShare(42 - x);

    }
    else if (x % 4 == 0 || x % 3 == 0)
    {
        int one;
        int two;
        one = x % 10;
        two = (x % 100) / 10;
        BearShare(one * two);
    }

    else if (x % 2 == 0)
    {
        BearShare(x / 2);
    }
    else
        return false;
}

int main()
{
    int x;
    cin >> x;
    BearShare(x);
    if (BearShare(x) == true)
        cout << "true" << endl;
    else
        cout << "false" << BearShare(x) << endl;
    system("pause");
    return 0;
}