#include <bits/stdc++.h>
using namespace std;
#define INF 99999
class Graph {
    vector<vector<int>> dist;
public:
    Graph(int vertices) {
        dist.resize(vertices, vector<int>(vertices, INF));
        for (int i = 0; i < vertices; i++) {
            dist[i][i] = 0;
        }
    }
    void addEdge(int u, int v, int weight) {
        dist[u][v] = weight;
    }
    void floydWarshall() {
        int V = dist.size();

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        // Print the shortest distance matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (format: u v weight):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    cout << "The shortest path matrix is:" << endl;
    graph.floydWarshall();

    return 0;
}

/* OUTPUT
Enter the number of vertices: 4
Enter the number of edges: 4
Enter the edges (format: u v weight):
0 1 5
0 3 10
1 2 3
2 3 1

The shortest path matrix is:
0 5 8 9 
INF 0 3 4 
INF INF 0 1 
INF INF INF 0 
*/


