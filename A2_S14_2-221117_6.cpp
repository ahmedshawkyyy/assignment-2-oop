/*
Author : mohamed eprahim mohamed

Section : 14

ID : 20221117

TA : Belal

Date : 28 Oct 2023

*/
/////// 6 .a
#include <iostream>

void binaryPrint(int n) {
    if (n == 0) {
        std::cout << 0;
        return;
    }

    int bits[32]; // Assuming a 32-bit binary representation, you can change this value if needed
    int index = 0;

    while (n > 0) {
        bits[index] = n % 2;
        n /= 2;
        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        std::cout << bits[i];
    }
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> n;

    binaryPrint(n);

    return 0;
}

///////  6.b


#include <iostream>
#include <string>

void numbers(const std::string& prefix, int k) {
    if (k == 0) {
        std::cout << prefix << std::endl;
    }
    else {
        numbers(prefix + "0", k - 1);
        numbers(prefix + "1", k - 1);
    }
}

int main() {
    std::string prefix;
    int k;

    // Prompt the user to enter the prefix and k.
    std::cout << "Enter the prefix (0's and 1's): ";
    std::cin >> prefix;
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    numbers(prefix, k);

    return 0;
}

