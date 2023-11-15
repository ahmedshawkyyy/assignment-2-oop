// File: A2_S14_20221103_5.cpp
// Author: Abdelrahman Abdelhamid Mostafa
// Section: S14
// ID: 20221103
// TA: Belal



#include <bits/stdc++.h>

using namespace std;

struct Players
{
    string name;
    int score;
};

Players pList[10];

bool sortingPlayers (Players p1, Players p2)
{
    return p1.score > p2.score;
}

void addNewPlayer ()
{  
    cout << "Enter the player name : " ;
    string name; cin >> name;

    cout << "Enter the player score : ";
    int score; cin >> score;
    cout << endl;

    sort (pList, pList + 10, sortingPlayers);
    if (score > pList[9].score)
    {
        pList[9].name = name;
        pList[9].score = score;
    }
}

void printTopTen ()
{
    sort (pList, pList + 10, sortingPlayers);
    for (int i = 0; i < 10; i++)
    {
        cout << pList[i].name << ' ' << pList[i].score << endl;
    }
    cout << endl;
}

void enterPlayerName ()
{
    cout << "Enter the player name : " ;
    string name; cin >> name;

    bool found = false;
    
    sort (pList, pList + 10, sortingPlayers);

    for (int i = 0; i < 10; i++)
    {
        if (name == pList[i].name)
        {
            cout << pList[i].score << endl;
            found = true; 
            break;
        }
    }

    if (!found)
        cout << "The player's name is not in the top 10." << endl;
}

int main()
{

    char option;
    bool exit = false;
    while (!exit)
    {
        cout << "which option to invoke? " << endl;
        cout << "1- Add a new player and score  " << endl;
        cout << "2- Print top 10 names and score  " << endl;
        cout << "3- Enter a player name  " << endl;
        cout << "0- To exit " << endl;

        cin >> option;

        switch (option)
        {
        case ('0'):
            exit = true;
            break;
        case ('1'):
            addNewPlayer();
            break;
        case ('2'):
            printTopTen();
            break;
        case ('3'):
            enterPlayerName();
            break;
        }
    }
    
}