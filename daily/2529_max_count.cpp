class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            // Conta os negativos usando lower_bound (primeiro índice >= 0)
            int neg_count = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
            
            // Conta os positivos usando upper_bound (primeiro índice > 0)
            int pos_count = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
            
            return max(neg_count, pos_count);
        }
    };