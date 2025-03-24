#include <iostream>
#include <vector>
using namespace std;

bool canDecomposeIntoNPathsOfLengthK(int N, int K, vector<vector<int>>& tree) {
    int NK = N * K;
    vector<int> degree(NK + 1, 0);
    
    // Calculate the degree of each vertex
    for (int i = 1; i <= NK - 1; i++) {
        int u = tree[i][0];
        int v = tree[i][1];
        degree[u]++;
        degree[v]++;
    }
    
    // Count vertices with odd degree
    int oddCount = 0;
    for (int i = 1; i <= NK; i++) {
        if (degree[i] % 2 == 1) {
            oddCount++;
        }
    }
    
    // Check if decomposition is possible
    if (K % 2 == 0) {
        // For even K, we need exactly 2N odd-degree vertices
        return oddCount == 2 * N;
    } else {
        // For odd K, we need at most 2N odd-degree vertices
        return oddCount <= 2 * N;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    
    int NK = N * K;
    vector<vector<int>> tree(NK, vector<int>(2));
    
    // Read the edges
    for (int i = 1; i <= NK - 1; i++) {
        cin >> tree[i][0] >> tree[i][1];
    }
    
    if (canDecomposeIntoNPathsOfLengthK(N, K, tree)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
