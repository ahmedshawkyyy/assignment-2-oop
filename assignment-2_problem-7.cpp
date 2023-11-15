//ahmed shawky abelhalim
//20210023
//porblem 7
//s13



#include <iostream>
#include <vector>

using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

void declarationSet(vector<dominoT>& dominoSet) {
    dominoSet = { {1,3} , {3,4} , {2,6} , {6,1} , {4,3} };
}

void displayDomino(vector<dominoT>& dominoSet) {
    for (int i = 0; i < 4; i++) {
        cout << dominoSet[i].leftDots << "|" << dominoSet[i].rightDots << " - ";
    }
    cout << dominoSet[4].leftDots << "|" << dominoSet[4].rightDots << endl;
}

bool FormsDominoChain(vector<dominoT>& dominoSet) {
    int status = 0;
    for (int i = 0; i < 4; i++) {
        if (dominoSet[i].rightDots == dominoSet[i + 1].leftDots) {
            status == 1;
        }
        else
            return false;
    }
    if (status == 1)
        return true;
}

void dominoChanger(vector<dominoT>& dominoSet, int x, int y) {
    int tempX, tempY;
    tempX = dominoSet[x].leftDots;
    tempY = dominoSet[x].rightDots;

    dominoSet[x].leftDots = dominoSet[y].leftDots;
    dominoSet[x].rightDots = dominoSet[y].rightDots;

    dominoSet[y].leftDots = tempX;
    dominoSet[y].rightDots = tempY;
}

int main() {
    vector<dominoT> dominoSet;

    declarationSet(dominoSet);

    cout << "Welcome to dominoes games" << endl;
    while (true) {
        int x, y;
        displayDomino(dominoSet);
        cout << "Change position of domino pieces to solve this game" << endl;
        cout << "Piece Number:";
        cin >> x;
        cout << "Piece Number:";
        cin >> y;
        dominoChanger(dominoSet, x - 1, y - 1);

        if (FormsDominoChain(dominoSet) == true) {
            cout << "gamed";
            break;
        }
    }
}