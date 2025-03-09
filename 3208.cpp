#include <vector>
#include <iostream>

// O Problema:
// Dado um array de cores e um inteiro k, queremos contar quantos grupos de k cores alternam
// Exemplo:
// colors = [1, 2, 1, 2, 1], k = 2
// 1 2 1 2 1
// 2 1 2 1 2
// 1 2 1 2 1
// 2 1 2 1 2


using namespace std;

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            int count = 0;
            int alternating = 1; // Conta as transições alternantes
    
            // Checamos as transições no primeiro grupo (janela inicial)
            for (int i = 1; i < k; i++) {
                if (colors[i] != colors[i - 1]) {
                    alternating++;
                }
            }
    
            // Se a primeira janela for alternante, conta
            if (alternating == k) count++;
    
            // Movemos a janela pelo array
            for (int i = 1; i < n; i++) {
                // Removemos o efeito do elemento que sai da janela
                if (colors[(i + k - 1) % n] != colors[(i + k - 2) % n]) {
                    alternating++;
                }
                if (colors[i] != colors[(i - 1) % n]) {
                    alternating--;
                }
    
                // Se for alternante, incrementamos o contador
                if (alternating == k) count++;
            }
    
            return count;
        }
    };
    

int main() {
        Solution s;
        vector<int> colors = {1, 2, 1, 2, 1};
        int k = 2;
        cout << s.numberOfAlternatingGroups(colors, k) << endl;
        return 0;
}