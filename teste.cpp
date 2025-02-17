#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int testSort(string tiles) {
        sort(tiles.begin(), tiles.end());
        cout << tiles << endl;  // Imprime a string ordenada
        return 0;
    }
};

int main() {
    Solution solution;
    cout << solution.testSort("ACB") << endl;  // Chamada correta dentro do main()
    return 0;
}
