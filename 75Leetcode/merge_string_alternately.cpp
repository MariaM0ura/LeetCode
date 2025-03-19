#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
// 1768. Merge Strings Alternately
// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
// Return the merged string.


class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            int n1 = word1.length(), n2 = word2.length();
            int i = 0, j = 0;
            string merge;
    
            while (i < n1 || j < n2) { // Continua enquanto houver caracteres em pelo menos uma das palavras
                if (i < n1) merge += word1[i++]; // adiciona e incrementa i
                if (j < n2) merge += word2[j++];
            }
    
            return merge;
        }
    };
    
int main() {
    Solution s;
    string word1 = "abc";
    string word2 = "pqr";
    cout << s.mergeAlternately(word1, word2) << endl;
    return 0;
}