#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;  // Mapeia valores para seus índices
        unordered_map<int, int> dp;     // Armazena os comprimentos das sequências

        int max_length = 0;

        // Preenchendo o mapa de índices
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        // Percorre pares de números para construir sequências
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i], b = arr[j];
                int length = 2;

                while (index.find(a + b) != index.end()) {
                    int c = a + b;
                    a = b;
                    b = c;
                    length++;
                }

                max_length = max(max_length, length);
            }
        }

        return max_length >= 3 ? max_length : 0;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << solution.lenLongestFibSubseq(arr) << endl;  // Saída: 5

    return 0;
}
