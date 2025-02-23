class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            // Juntar os dois arrays
            vector<int> merged = nums1;
            merged.insert(merged.end(), nums2.begin(), nums2.end());
            
            // Ordenar o array combinado
            sort(merged.begin(), merged.end());
    
            int n = merged.size();
            
            // Se o tamanho for ímpar, retorna o elemento central
            if (n % 2 != 0) {
                return merged[n / 2];
            }
            
            // Se o tamanho for par, retorna a média dos dois elementos centrais
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
    };
    