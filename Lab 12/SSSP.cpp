#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> Graph = {
    {0,10,-1,-1,15,5},
    {10,0,10,30,-1,-1},
    {-1,10,0,12,5,-1},
    {-1,30,12,0,-1,20},
    {15,-1,5,-1,0,-1},
    {5,-1,-1,20,-1,0}
};

vector<int> digkstra(vector<vector<int>> G,int s) {
    vector<int> dist;
    dist.resize(G.size(),INT_MAX);
    dist[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        pair<int,int> p = pq.top();
        pq.pop();
        int u = p.second;
        for (int i=0;i<G[u].size();i++) {
            if (G[u][i] != -1) {
                int v = i;
                int w = G[u][i];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
    }
    return dist;
}
vector<int> Find_Best(vector<float> D) {
    float B = INT_MAX;
    vector<int> best;
    for (int i=0;i<D.size();i++) {
        if (D[i] < B) {
            B = D[i];
            best.clear();
            best.push_back(i);
        }
        else if (D[i] == B) {
            best.push_back(i);
        }
    }
    return best;
}

int main() {
    cout << endl;
    vector<float> D;
    for (int i=0;i<Graph.size();i++) {
        int cost = 0;
        cout << "distances from city " << i << endl;
        vector<int> dist = digkstra(Graph,i);
        for (int j=0;j<dist.size();j++) {
            cout << "  to city " << j << " : " << dist[j] << endl;
            cost += dist[j];
        }
        D.push_back(float(cost)/(Graph.size()-1));
        cout << endl;
    }
    for (int i=0;i<D.size();i++) {
        cout << "Average cost from city " << i << " : " << D[i] << endl;
    }
    cout << endl;

    // choose best cities to build Hospital.
    vector<int> best_cities = Find_Best(D);
    cout << "Best cities to build Hospital : ";
    for (int i=0;i<best_cities.size();i++) {
        cout << best_cities[i] << " ";
    }
    cout << "\n\n";
    return 0;
}