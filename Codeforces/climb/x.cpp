vector<bool> for_root(n, 1);
for (int i = 0; i < q; i++)
{
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    for_root[y] = 0;
    if (v[x] && v[y] && v[x] != v[y])
    {
        if (v[x] > v[y])
        {
            sane = false;
        }
    }
    dag[x].push_back(y);
    cout << x << "->" << y << "\n";
}
cout << "sane " << sane << " loc1 " << loc1 << " loc2 " << loc2 << "\n";
if (!sane || (loc1 == -1 && loc2 != -1))
{
    cout << "-1\n";
    return;
}
int root;
bool need = 1;
if (loc1 != -1 && for_root[loc1])
{
    root = loc1;
    need = 0;
}
for (int i = 0; i < n; i++)
{
    if (loc1 != -1)
    {
        if (v[i] == 2)
        {
            dag[loc1].push_back(i);
            for_root[i] = 0;
            cout << loc1 << "->" << i << "\n";
            if (loc2 != -1)
            {
                dag[i].push_back(loc2);
                for_root[loc2] = 0;
                cout << i << "->" << loc2 << "\n";
            }
        }
    }
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to perform DFS and detect cycles
bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &inRecStack, stack<int> &topoStack)
{
    visited[node] = true;
    inRecStack[node] = true;

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, graph, visited, inRecStack, topoStack))
            {
                return true; // Cycle detected
            }
        }
        else if (inRecStack[neighbor])
        {
            return true; // Back edge detected, cycle exists
        }
    }

    inRecStack[node] = false;
    topoStack.push(node); // Push the node onto the stack after visiting all neighbors
    return false;
}

// Function to check if the graph is a DAG and print topological order if it is
void checkIfDAG(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n); // Adjacency list representation
    for (const auto &edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
    }

    vector<bool> visited(n, false);
    vector<bool> inRecStack(n, false);
    stack<int> topoStack;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            if (dfs(i, graph, visited, inRecStack, topoStack))
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
}

int main()
{
    int n = 6; // Number of nodes
    vector<vector<int>> edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    checkIfDAG(n, edges);
    return 0;
}
