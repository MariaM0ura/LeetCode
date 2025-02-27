#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> sequence(size, 0); // Inicializa a sequência com zeros
        vector<bool> used(n + 1, false); // Marca quais números já foram usados
        
        // Inicia a busca a partir do índice 0
        backtrack(sequence, used, n, 0);
        
        return sequence;
    }

private:
    bool backtrack(vector<int>& sequence, vector<bool>& used, int n, int index) {
        int size = sequence.size();
        
        // Se chegamos ao final da sequência, encontramos uma solução válida
        if (index == size) return true;
        
        // Se a posição já está preenchida, avançamos para a próxima posição
        if (sequence[index] != 0) return backtrack(sequence, used, n, index + 1);
        
        // Tentamos inserir os números de n para 1 (para priorizar a maior sequência lexicograficamente)
        for (int num = n; num >= 1; --num) {
            if (used[num]) continue; // Se o número já foi usado, ignoramos
            
            if (num == 1) {
                // O número 1 aparece apenas uma vez
                sequence[index] = 1;
                used[num] = true;
                
                if (backtrack(sequence, used, n, index + 1)) return true;
                
                // Backtrack
                sequence[index] = 0;
                used[num] = false;
            } else {
                // Para números maiores que 1, verificamos se podemos colocá-los nas duas posições corretas
                int secondIndex = index + num;
                if (secondIndex < size && sequence[secondIndex] == 0) {
                    sequence[index] = sequence[secondIndex] = num;
                    used[num] = true;

                    if (backtrack(sequence, used, n, index + 1)) return true;

                    // Backtrack
                    sequence[index] = sequence[secondIndex] = 0;
                    used[num] = false;
                }
            }
        }

        return false;
    }
};
