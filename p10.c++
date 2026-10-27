//NAME - MEET KUMAR
//ROLL NO- 25/DA/042
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int u, v, weight;
};

int main()
{
    int V = 5;
    int E = 8;
    vector<Edge> edges =
    {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0;
    vector<int> dist(V, 1000000);
    dist[source] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        for (auto edge : edges)
        {
            if (dist[edge.u] != 1000000 &&
                dist[edge.u] + edge.weight < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    bool negativeCycle = false;
    for (auto edge : edges)
    {
        if (dist[edge.u] != 1000000 &&
            dist[edge.u] + edge.weight < dist[edge.v])
        {
            negativeCycle = true;
            break;
        }
    }
    if (negativeCycle)
    {
        cout << "Negative-weight cycle detected!" << endl;
    }
    else
    {
        cout << "Vertex\tShortest Distance from Source\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << "\t" << dist[i] << endl;
        }
    }
    return 0;
}