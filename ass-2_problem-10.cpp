//problem 10
//Name : qahmed shawky 20210023
//Section: 13, 14

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

// Function to load the lookup table from a file
map<string, string> LoadLookupTable(const string& lookupTableFileName) {
    map<string, string> lookupTable;
    ifstream file(lookupTableFileName);
    if (!file.is_open()) {
        cerr << "Error opening lookup table file." << endl;
        return lookupTable;
    }

    string line;
    while (getline(file, line)) {
        size_t pos = line.find(",");
        if (pos != string::npos) {
            string originalWord = line.substr(0, pos);
            string alternative = line.substr(pos + 1);
            lookupTable[originalWord] = alternative;
        }
    }

    file.close();
    return lookupTable;
}

// Function to replace words in the text using the lookup table
string ReplaceWords(const string& inputText, const map<string, string>& lookupTable) {
    string modifiedText = inputText;
    for (const auto& entry : lookupTable) {
        string originalWord = entry.first;
        string alternative = entry.second;
        size_t pos = modifiedText.find(originalWord);
        while (pos != string::npos) {
            modifiedText.replace(pos, originalWord.length(), alternative);
            pos = modifiedText.find(originalWord, pos + alternative.length());
        }
    }
    return modifiedText;
}

int main() {
    string lookupTableFileName = "lookup_table.txt"; // Change to the actual filename
    string inputFileName = "input_arabic.txt"; // Change to the actual input file
    string outputFileName = "output_arabic.txt"; // Change to the desired output file

    map<string, string> lookupTable = LoadLookupTable(lookupTableFileName);

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    string inputText;
    getline(inputFile, inputText);

    string modifiedText = ReplaceWords(inputText, lookupTable);

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    outputFile << modifiedText;

    inputFile.close();
    outputFile.close();

    cout << "Text processing complete. Modified text saved to " << outputFileName << endl;

    return 0;
}
