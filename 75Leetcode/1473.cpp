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
                result.push_back(candy + extraCandies >= maxCandies);
            }
            
            // Return the result
            return result;
        }
    };
    