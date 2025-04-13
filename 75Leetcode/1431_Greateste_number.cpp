#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
            // Step 1: Find the maximum number of candies any kid has
            int maxCandies = *max_element(candies.begin(), candies.end());
            
            // Step 2: Initialize the result vector to store the boolean values
            vector<bool> result;
            
            // Step 3: Iterate over each kid and check if they can have the greatest number of candies
            for (int candy : candies) {
                // Check if the current kid's candies + extraCandies >= maxCandies
                // If so, they can have the greatest number of candies
                // Otherwise, they cannot
                // Push the result into the result vector   
                result.push_back(candy + extraCandies >= maxCandies);
            }
            
            // Return the result
            return result;

        }
    };

int main() {
Solution solution;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    
    vector<bool> result = solution.kidsWithCandies(candies, extraCandies);
    
    // Print the result
    for (bool canHaveGreatest : result) {
        cout << (canHaveGreatest ? "true" : "false") << " ";
    }
    
    return 0;
}
    