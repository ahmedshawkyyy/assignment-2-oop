// File: A2_S14_20221103_2.cpp
// Author: Abdelrahman Abdelhamid Mostafa
// Section: S14
// ID: 20221103
// TA: Belal



#include <bits/stdc++.h>

using namespace std;


int main()
{
    string s;
    cout << "Enter a speech: " ;
    getline(cin, s);

    vector<string>convertedSpeech;
    string word = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (word == "he" || word == "him" || word == "his" || word == "He" || word == "Him" || word == "His")
                word += ' ';
            if (word == "he " || word == "he?" || word == "he." || word == "he," || word == "he's" ||
                word == "He " || word == "He?" || word == "He." || word == "He," || word == "He'")
            {
                char punc = word.back();
                word.pop_back();
                word += " or she";
                word += punc;
                if (punc != ' ')
                    word += ' ';
            }
            else if (word == "him " || word == "him?" || word == "him." || word == "him," || word == "him'" ||
                     word == "Him " || word == "Him?" || word == "Him." || word == "Him," || word == "Him'")
                    {
                        char punc = word.back();
                        word.pop_back();
                        word += " or her";
                        word += punc;
                        if (punc != ' ')
                            word += ' ';
                    }
            else if (word == "his " || word == "his?" || word == "his." || word == "his," || word == "his'" ||
                     word == "His " || word == "His?" || word == "His." || word == "His," || word == "His'")
                     {
                        char punc = word.back();
                        word.pop_back();
                        word += " or her";
                        word += punc;
                        if (punc != ' ')
                            word += ' ';
                     }
            else{
                word += ' ';
            }
            convertedSpeech.push_back(word);
            word.clear();
        }
        else
        {
            word += s[i];
        }
    }

    convertedSpeech.push_back(word);

    for (int i = 0; i < convertedSpeech.size(); i++)
    {
        cout << convertedSpeech[i];
    }

}