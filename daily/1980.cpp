#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size(); 
            string result = "";
    
            for (int i = 0; i < n; i++) {
                result += (nums[i][i] == '0') ? '1' : '0';
            }
    
            return result;
    }
};

int main() {
    Solution solution;
    vector<string> nums = {"00", "01"};
    string result = solution.findDifferentBinaryString(nums);
    return 0;
}
    