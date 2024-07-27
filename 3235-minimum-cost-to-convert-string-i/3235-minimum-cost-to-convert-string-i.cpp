class Solution {
public:
    void find(int node, vector<vector<int>>& graph, map<pair<int, int>, long long>& cost, vector<vector<long long>>& mat) {
        queue<pair<int, long long>> bfs;
        bfs.push({node, 0});

        long long lim = 1e18;
        vector<long long> dis(26, lim);
        dis[node] = 0;

        while (!bfs.empty()) {
            pair<int, long long> temp = bfs.front();
            bfs.pop();
            int cnode = temp.first;
            long long c = temp.second;

            for (auto& x : graph[cnode]) {
                long long cc = c + cost[{cnode, x}];
                if (cc < dis[x]) {
                    dis[x] = cc;
                    bfs.push({x, cc});
                }
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (dis[i] == lim) mat[node][i] = -1;
            else mat[node][i] = dis[i];
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans = 0;
        int m = changed.size();
        map<pair<int, int>, long long> cCost;
        vector<vector<int>> graph(26);

        for (int i = 0; i < m; i++) {
            long long val = cost[i];
            pair<int, int> cur = {original[i] - 'a', changed[i] - 'a'};

            if (cCost.find(cur) != cCost.end()) {
                cCost[cur] = min(cCost[cur], val);
            } else {
                cCost[cur] = val;
            }

            graph[original[i] - 'a'].push_back(changed[i] - 'a');
        }

        int n = source.size();
        vector<vector<long long>> mat(26, vector<long long>(26, 1e18));

        for (int i = 0; i < 26; ++i) {
            find(i, graph, cCost, mat);
        }

        for (int i = 0; i < n; ++i) {
            int c = source[i] - 'a';
            int d = target[i] - 'a';

            if (mat[c][d] == -1) return -1;
            ans += mat[c][d];
        }

        return ans;
        
    }
};