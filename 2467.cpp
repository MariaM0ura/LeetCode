#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> bob_path = getBobPath(bob, n, adj);
        unordered_map<int, int> bob_time;
        for (int i = 0; i < bob_path.size(); ++i) {
            bob_time[bob_path[i]] = i;
        }
        
        vector<int> parent_ali(n, -1);
        vector<vector<int>> children(n);
        queue<int> q_ali;
        q_ali.push(0);
        parent_ali[0] = -1;
        while (!q_ali.empty()) {
            int u = q_ali.front();
            q_ali.pop();
            for (int v : adj[u]) {
                if (v != parent_ali[u] && parent_ali[v] == -1) {
                    parent_ali[v] = u;
                    children[u].push_back(v);
                    q_ali.push(v);
                }
            }
        }
        
        vector<int> leaves;
        for (int i = 1; i < n; ++i) {
            if (children[i].empty()) {
                leaves.push_back(i);
            }
        }
        
        int max_sum = INT_MIN;
        for (int leaf : leaves) {
            vector<int> path;
            int current = leaf;
            while (current != -1) {
                path.push_back(current);
                current = parent_ali[current];
            }
            reverse(path.begin(), path.end());
            int sum = 0;
            for (int i = 0; i < path.size(); ++i) {
                int node = path[i];
                if (bob_time.count(node)) {
                    int alice_time = i;
                    int bob_t = bob_time[node];
                    if (alice_time < bob_t) {
                        sum += amount[node];
                    } else if (alice_time == bob_t) {
                        sum += amount[node] / 2;
                    }
                } else {
                    sum += amount[node];
                }
            }
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        
        return max_sum;
    }

private:
    vector<int> getBobPath(int bob, int n, const vector<vector<int>>& adj) {
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(bob);
        parent[bob] = -1;
        bool found = false;
        while (!q.empty() && !found) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (parent[v] == -1) {
                    parent[v] = u;
                    if (v == 0) {
                        found = true;
                        break;
                    }
                    q.push(v);
                }
            }
        }
        vector<int> path;
        int current = 0;
        while (current != bob) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(bob);
        reverse(path.begin(), path.end());
        return path;
    }
};