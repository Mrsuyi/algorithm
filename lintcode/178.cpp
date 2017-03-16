class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if (edges.size() != n - 1) return false;
        
        vector<vector<int>> neibs(n);
        for (auto& edge : edges)
        {
            if (edge[0] == edge[1]) return false;
            neibs[edge[0]].push_back(edge[1]);
            neibs[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(edges.size(), false);
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            if (visited[v]) return false;

            visited[v] = true;
            for (int i = 0, cnt = 0; i < neibs[v].size(); ++i)
            {
                if (visited[neibs[v][i]])
                {
                    if (++cnt > 1)
                        return false;
                }
                else
                    q.push(neibs[v][i]);
            }
        }
        for (int i = 0; i < n; ++i)
            if (!visited[i])
                return false;
        return true;
    }
};