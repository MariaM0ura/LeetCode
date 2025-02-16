#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, bool> memo;

    bool canPartition(string s, int target, int index, int currentSum) {
        if (index == s.length()) return currentSum == target;

        string key = to_string(index) + "_" + to_string(currentSum);
        if (memo.find(key) != memo.end()) return memo[key];

        int num = 0;
        for (int i = index; i < s.length(); i++) {
            num = num * 10 + (s[i] - '0');
            if (num + currentSum > target) break;
            if (canPartition(s, target, i + 1, currentSum + num)) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isPunishment(int num) {
        string squared = to_string(num * num);
        memo.clear();
        return canPartition(squared, num, 0, 0);
    }

    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (isPunishment(i)) {
                result += i * i;
            }
        }
        return result;
    }
};
