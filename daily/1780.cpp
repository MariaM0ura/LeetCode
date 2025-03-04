#include <iostream>

using namespace std;

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while (n > 0) {
                if (n % 3 == 2) return false;
                n /= 3;
            }
            return true;
        }
    };

int main() {
    Solution solution;
    cout << solution.checkPowersOfThree(12) << endl;  // Saída: true
    cout << solution.checkPowersOfThree(91) << endl;  // Saída: true
    cout << solution.checkPowersOfThree(21) << endl;  // Saída: false

    return 0;
}

