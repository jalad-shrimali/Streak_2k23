class Solution
{
public:
    long long ans = 0;
    vector<vector<int>> graph;
    vector<bool> visited;
    long long dfs(int node, int seats, long long count)
    {
        visited[node] = true;
        long long temp = 1;
        for (auto x : graph[node])
        {
            if (!visited[x])
            {
                temp += dfs(x, seats, 0);
            }
        }
        // cout<<"node is "<<node<<" count is "<<temp<<endl;
        ans += (temp + seats - 1) / seats;
        return temp;
    }

    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        graph.resize(roads.size() + 1);
        visited.resize(roads.size() + 1, false);
        for (auto x : roads)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        visited[0] = true;
        for (auto x : graph[0])
        {
            long long count = 0;
            dfs(x, seats, count);
        }
        return ans;
    }
};
