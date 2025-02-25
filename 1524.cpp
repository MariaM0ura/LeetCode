#include <vector>

class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd = 0, even = 1; // even = 1 para contar a soma vazia
        int prefix_sum = 0, result = 0;

        for (int num : arr) {
            prefix_sum += num;

            if (prefix_sum % 2 == 0) {
                result = (result + odd) % MOD;
                even++;
            } else {
                result = (result + even) % MOD;
                odd++;
            }
        }

        return result;
    }
};
