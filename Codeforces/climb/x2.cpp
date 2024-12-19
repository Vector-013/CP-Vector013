#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n = 6; // Number of nodes
    vector<vector<int>> edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    auto checkIfDAG = [&](int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> dag(n); // Adjacency list representation
        for (const auto &edge : edges)
        {
            dag[edge[0]].push_back(edge[1]);
        }

        vector<bool> vis(n, false);
        vector<bool> recStack(n, false);
        stack<int> topoStack;

        auto dfs = [&](auto &self, int node) -> bool
        {
            vis[node] = true;
            recStack[node] = true;

            for (int neighbor : dag[node])
            {
                if (!vis[neighbor])
                {
                    if (self(self, neighbor))
                    {
                        return true; // Cycle detected
                    }
                }
                else if (recStack[neighbor])
                {
                    return true; // Back edge detected, cycle exists
                }
            }

            recStack[node] = false;
            topoStack.push(node); // Push the node onto the stack after visiting all neighbors
            return false;
        };

        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                if (dfs(dfs, i))
                {
                    cout << "The graph is not a DAG." << endl;
                    return;
                }
            }
        }

        // If no cycle is detected, print the topological order
        cout << "The graph is a DAG. Topological Order: ";
        while (!topoStack.empty())
        {
            cout << topoStack.top() << " ";
            topoStack.pop();
        }
        cout << endl;
    };

    checkIfDAG(n, edges);
    return 0;
}
