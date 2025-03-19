#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            vector<int> freq(501, 0); // Vetor de frequência para contar ocorrências
    
            for (int num : nums) {
                freq[num]++;
            }
    
            // Verificar se todas as frequências são pares
            for (int count : freq) {
                if (count % 2 != 0) {
                    return false;
                }
            }
    
            return true;
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << sol.divideArray(nums) << endl;  // Output: 1
    
    nums = {1, 2, 3, 3, 2, 1};
    cout << sol.divideArray(nums) << endl;  // Output: 1
    
    nums = {1, 2, 3, 4, 5};
    cout << sol.divideArray(nums) << endl;  // Output: 0
    
    return 0;
}