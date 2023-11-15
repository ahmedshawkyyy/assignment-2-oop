#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<int> nums;

    // Initialize the vector with numbers from 2 to 'size'
    for (int i = 2; i <= size; i++) {
        nums.push_back(i);
    }

    // Sieve of Eratosthenes algorithm
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            for (int j = i + nums[i]; j < nums.size(); j += nums[i]) {
                nums[j] = 0;
            }
        }
    }

    // Print the prime numbers
    for (int val : nums) {
        if (val != 0) {
            cout << val << " ";
        }
    }

    return 0;
}
