// File: A2_S14_20221103_11.cpp
// Author: Abdelrahman Abdelhamid Mostafa
// Section: S14
// ID: 20221103
// TA: Belal



#include <bits/stdc++.h>

using namespace std;


bool compareCharacterByCharacter(string file1, string file2)
{
    ifstream inFile1(file1);
    ifstream inFile2(file2);

    if (!inFile1 || !inFile2) {
        std::cout << "Error opening files." << std::endl;
        return false;
    }

    string line1, line2;
    int lineNum = 1;

    while (getline(inFile1, line1) && getline(inFile2, line2))
    {
        if (line1 != line2)
        {
            cout << "File are different at line: " << lineNum << endl;
            cout << "File 1: " << line1 << endl;
            cout << "File 2: " << line2 << endl;
            return false;
        }
        lineNum++;
    }

    if (!inFile1.eof() || !inFile2.eof()) {
        cout << "Files have different number of lines." << endl;
        return false;
    }

    cout << "Files are identical." << endl;
}


bool compareWordByWord(string file1, string file2)
{
    std::ifstream inFile1(file1);
    std::ifstream inFile2(file2);

    if (!inFile1 || !inFile2) {
        std::cout << "Error opening files." << std::endl;
        return false;
    }

    string word1, word2;
    int lineNum = 1;

    while (inFile1 >> word1 && inFile2 >> word2) {
        if (word1 != word2) {
            cout << "First different line is: " << lineNum << endl;
            cout << "File 1: " << word1 << endl;
            cout << "File 2: " << word2 << endl;
            return false;
        }
        if (inFile1.peek() == '\n' || inFile2.peek() == '\n') {
            lineNum++;
        }   
    }

    if (inFile1.eof() && inFile2.eof()) {
        cout << "Files are identical." << endl;
    } else {
        cout << "Files have different number of words." << endl;
    }

}
int main()
{
    string file1, file2;
    char comparisonType;

    cout << "Enter the name of the first file: ";
    getline(cin, file1);

    cout << "Enter the name of the second file: ";
    getline(cin, file2);

    cout << "Enter 'c' for character by character comparison or 'w' for word by word comparison: ";
    cin >> comparisonType;

    if (comparisonType == 'c') {
        compareCharacterByCharacter(file1, file2);
     } 
    else if (comparisonType == 'w') {
        compareWordByWord(file1, file2);
    }
    
}