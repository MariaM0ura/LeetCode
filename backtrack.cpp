
// Para cada escolha possivel {
//     Faça a escolha
//     chamar recursivamente o backtrack(novo estado)
//     Desfaça a escolha(backtrack) }

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(string &s, int start, vector<string> &result) {
        if (start == s.size()) {  // Base: Se todas as letras foram usadas
            result.push_back(s);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            swap(s[start], s[i]);   // Escolhe uma letra para começar
            backtrack(s, start + 1, result);  // Chama recursivamente
            swap(s[start], s[i]);   // Desfaz a troca (backtrack)
        }
    }

    vector<string> permuteString(string s) {
        vector<string> result;
        backtrack(s, 0, result);
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> perms = solution.permuteString("ABC");

    for (string perm : perms) {
        cout << perm << endl;
    }

    return 0;
}
