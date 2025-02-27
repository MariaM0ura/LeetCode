#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int max_sum = 0, min_sum = 0, current_max = 0, current_min = 0;
            
            for (int num : nums) {
                current_max = max(num, current_max + num);
                max_sum = max(max_sum, current_max);
                
                current_min = min(num, current_min + num);
                min_sum = min(min_sum, current_min);
            }
            
            return max(abs(max_sum), abs(min_sum));
        }
    };


int main() {
    Solution solution;
    vector<int> nums = {1, -3, 2, 3, -4};
    cout << solution.maxAbsoluteSum(nums) << endl;  // Saída: 5

    return 0;
}