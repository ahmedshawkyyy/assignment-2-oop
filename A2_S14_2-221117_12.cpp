/*
File : question12.cpp

Purpose :

A struct named `Keyword` is created with two members: `text` (a string representing a keyword or phrase)
and `points` (an integer representing the point value associated with that keyword or phrase).

phishingKeywords array is defined, it contains predefined phishing-related keywords and their associated point values.
Each keyword is associated with a point value, indicating how suspicious the presence of that keyword is in an input text.

In the `main` function:
- A string variable inputText is declared to store the text input from the user.
- A temporary file named `tempfile.txt` is created. This file will be used to store the user's input for further processing.

The program checks if the file was successfully opened. If it's open, it prompts the user to enter text
and stores it in the `tempfile.txt` file. If there is an issue with file creation or writing, an error message is printed.

The code then attempts to read from the `tempfile.txt` file, which was just created, to perform keyword scanning.

Inside a loop, it reads the file line by line and checks for the presence of phishing-related keywords in each line.
For each line, it iterates through the list of `phishingKeywords`, and for each keyword,
it uses the `find` function to search for occurrences of the keyword in the line. If found, it adds the associated points to the `totalPoints` variable.

After processing all lines, the input file is closed.

The code then enters another loop to output the results.
It goes through the `phishingKeywords` list again and counts the occurrences of each keyword in the entire text.
If any occurrences are found, it prints the keyword, the number of occurrences, and the total points accumulated for that keyword.

Finally, the program prints the total points accumulated from all keywords in the text.

The temporary file `tempfile.txt` is removed, as it's no longer needed.

Author : mohamed eprahim mohamed

Section : 14

ID : 20221117

TA : Belal

Date : 28 Oct 2023

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Keyword {
    string text;
    int points;
};

const int NUM_KEYWORDS = 30;
Keyword phishingKeywords[NUM_KEYWORDS] = {
    {"bank", 1},
    {"password", 1},
    {"login", 1},
    {"account", 1},
    {"verify", 1},
    {"urgent", 2},
    {"suspicious", 2},
    {"verify your account", 3},
    {"security alert", 3},
    {"update your information", 3},
    {"your account has been compromised", 3},
    {"unauthorized access", 3},
    {"click the link below", 2},
    {"congratulations, you've won", 3},
    {"lottery winner", 3},
    {"your password is about to expire", 3},
    {"claim your prize", 3},
    {"exclusive deal", 3},
    {"free trial", 1},
    {"order now", 1},
    {"limited time offer", 2},
    {"cash prize", 3},
    {"invoice", 3},
    {"important message", 2},
    {"IRS", 3},
    {"PayPal", 3},
    {"Amazon", 3},
    {"Apple", 3},
    {"Microsoft", 3},
    {"Google", 3}
};


int main() {
    string inputText;
    ofstream file_("tempfile.txt");

    if (file_.is_open()) {
        cout << "Enter text to be scanned: ";
        getline(cin, inputText);
        file_ << inputText;
        file_.close();
    }
    else {
        cerr << "Error creating or writing to the file." << std::endl;
        return 1;
    }

    ifstream inputFile("tempfile.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    int totalPoints = 0;

    while (getline(inputFile, line)) {
        for (int i = 0; i < NUM_KEYWORDS; ++i) {
            size_t pos = 0;
            while ((pos = line.find(phishingKeywords[i].text, pos)) != string::npos) {
                totalPoints += phishingKeywords[i].points;
                pos += phishingKeywords[i].text.length();
            }
        }
    }

    inputFile.close();

    for (int i = 0; i < NUM_KEYWORDS; ++i) {
        size_t occurrences = 0;
        size_t pos = 0;
        while ((pos = line.find(phishingKeywords[i].text, pos)) != string::npos) {
            ++occurrences;
            pos += phishingKeywords[i].text.length();
        }
        if (occurrences > 0) {
            cout << "Keyword/Phrase: " << phishingKeywords[i].text << " | Occurrences: " << occurrences << " | Points: " << occurrences * phishingKeywords[i].points << endl;
        }
    }

    cout << "Total Points: " << totalPoints << endl;

    remove("tempfile.txt");

    return 0;
}

