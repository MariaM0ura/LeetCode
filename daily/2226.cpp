class Solution {
    public:
        // Helper function to check if we can allocate `candies_per_child` candies to at least `k` children
        bool canAllocate(const vector<int>& candies, long long candies_per_child, long long k) {
            long long count = 0;
            for (int candy : candies) {
                count += candy / candies_per_child;  // Number of children that can get `candies_per_child` from this pile
            }
            return count >= k;  // If we can allocate candies to at least `k` children, return true
        }
    
        int maximumCandies(vector<int>& candies, long long k) {
            // Binary search initialization
            long long low = 0, high = *max_element(candies.begin(), candies.end());
            int result = 0;
            
            // Perform binary search
            while (low <= high) {
                long long mid = (low + high) / 2;
                
                // Avoid division by zero
                if (mid == 0) break;
                
                if (canAllocate(candies, mid, k)) {
                    result = mid;  // `mid` is a valid solution, try for a higher value
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
    
            return result;
        }
    };
    