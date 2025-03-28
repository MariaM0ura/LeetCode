#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        // Passo 1: Encontrar o elemento dominante
        for (int num : nums) {
            freq[num]++;
        }
        
        int dominant = -1;
        int total_count = 0;
        for (auto& [num, count] : freq) {
            if (count * 2 > n) {
                dominant = num;
                total_count = count;
                break;
            }
        }

        if (dominant == -1) return -1; // Nenhum dominante encontrado (não deveria acontecer pelo enunciado)

        // Passo 2: Percorrer e verificar splits válidos
        int left_count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) {
                left_count++;
            }
            int right_count = total_count - left_count;
            
            // Condição para um split válido
            if (left_count * 2 > (i + 1) && right_count * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1;
    }
};
