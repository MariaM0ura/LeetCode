#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int numTilePossibilities(string tiles) {
        // Ordenar 
        sort(tiles.begin(), tiles.end()); 

        vector<bool> used(tiles.size(), false);
        unordered_set<string> sequences;
        string current = "";
        backtrack(tiles, used, current, sequences);
        return sequences.size();
    }

private:
    // backtracking para gerar todas as sequências possíveis, evitando repetições
    void backtrack(string &tiles, vector<bool> &used, string &current, unordered_set<string> &sequences) {
        if (!current.empty()) {
            sequences.insert(current);
        }

        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]) continue; // Evita repetições

            used[i] = true;
            current.push_back(tiles[i]);
            backtrack(tiles, used, current, sequences);
            current.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution solution;
    // cout << solution.numTilePossibilities("AAB") << endl; // Output: 8
    // cout << solution.numTilePossibilities("AAABBC") << endl; // Output: 188
    // cout << solution.numTilePossibilities("V") << endl; // Output: 1

    cout << solution.testSort("AAB") << endl;
    return 0;
}
