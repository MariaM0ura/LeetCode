#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string gcdOfStrings(string str1, string str2) {
            // Se str1 + str2 for diferente de str2 + str1, não há divisor comum
            if (str1 + str2 != str2 + str1) return "";
    
            // Calcula o MDC dos tamanhos das strings
            int n1 = str1.size();
            int n2 = str2.size();
            int gcdLength = gcd(n1,n2);
    
            // Retorna o prefixo comum com tamanho gcdLength
            return str1.substr(0, gcdLength);
        }
    
    private:
        int gcd(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    };

int main() {
    Solution s;
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << s.gcdOfStrings(str1, str2) << endl;
    return 0;
}
// Output: ABC