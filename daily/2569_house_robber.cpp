#include <bits/stdc++.h>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
    public:
        bool canRob(vector<int>& nums, int k, int cap) {
            int count = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                if (nums[i] <= cap) {
                    count++;
                    i++; // Pular a próxima casa, pois não podemos roubar adjacente
                }
                if (count >= k) return true;
            }
            return false;
        }
        
        int minCapability(vector<int>& nums, int k) {
            int left = *min_element(nums.begin(), nums.end());
            int right = *max_element(nums.begin(), nums.end());
            
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (canRob(nums, k, mid)) {
                    right = mid; // Tentar minimizar a capacidade
                } else {
                    left = mid + 1; // Aumentar capacidade mínima necessária
                }
            }
            
            return left;
        }
    };
    
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int k = 2;
    cout << sol.minCapability(nums, k) << endl;  // Output: 1
    
    nums = {2, 2, 3, 3, 3, 4};
    k = 3;
    cout << sol.minCapability(nums, k) << endl;  // Output: 3
    
    return 0;
}