#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
// 345. Reverse Vowels of a String

class Solution {
    public:
        string reverseVowels(string s) {
            unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                          'A', 'E', 'I', 'O', 'U'};
            int left = 0, right = s.length() - 1;
    
            while (left < right) {
                while (left < right && vowels.find(s[left]) == vowels.end()) {
                    left++;
                }
                while (left < right && vowels.find(s[right]) == vowels.end()) {
                    right--;
                }
    
                // Swap as vogais
                swap(s[left], s[right]);
                left++;
                right--;
            }
    
            return s;
        }
    };

    int main() {
        Solution sol;
        string s = "hello";
        cout << sol.reverseVowels(s) << endl; // Output: "holle"
        return 0;
    }
// Output: "holle"
    }   
