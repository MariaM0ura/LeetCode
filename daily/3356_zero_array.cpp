#include <vector>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);  // Vetor de diferenças
        
        for (int k = 0; k < queries.size(); ++k) {
            int l = queries[k][0], r = queries[k][1], val = queries[k][2];
            diff[l] -= val;
            if (r + 1 < n) diff[r + 1] += val;

            // Aplicamos as diferenças em `nums` e verificamos se zerou
            vector<int> temp = nums;  // Criamos uma cópia para simular mudanças
            int curr = 0;
            for (int i = 0; i < n; ++i) {
                curr += diff[i];   // Aplicamos o efeito do diff
                temp[i] += curr;   // Atualizamos o valor de temp[i]
                if (temp[i] < 0) temp[i] = 0; // Evitamos valores negativos
            }

            // Verificamos se o array `temp` virou um Zero Array
            bool isZeroArray = true;
            for (int num : temp) {
                if (num != 0) {
                    isZeroArray = false;
                    break;
                }
            }

            if (isZeroArray) return k + 1;  // Achamos o menor k
        }

        return -1;  // Se não zerou após todas as queries
    }
};
