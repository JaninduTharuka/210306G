#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> Graph = {
    {0,3,0,0,0,1},
    {3,0,2,1,10,0},
    {0,2,0,3,0,5},
    {0,1,3,0,5,0},
    {0,10,0,5,0,4},
    {1,0,5,0,4,0}
};

vector<pair<int,int>> Prim(vector<vector<int>> G,int s) {
    vector<int> V;
    V.push_back(s);
    vector<pair<int,int>> MST;
    vector<bool> Visited;
    Visited.resize(G.size(),false);
    Visited[s] = true;
    while (V.size()<G.size()) {
        int minweight = INT_MAX;
        int u=-1;
        int v=-1;
        for (int x=0;x<V.size();x++) {
            int u_dash = V[x];
            for (int y=0;y<G[u_dash].size();y++) {
                if ((G[u_dash][y] != 0 && G[u_dash][y] < minweight) && !Visited[y]) {
                    minweight = G[u_dash][y];
                    u = u_dash;
                    v = y;
                }
            }
        }
        MST.push_back(make_pair(u,v));
        V.push_back(v);
        Visited[v] = true;
    }
    return MST;
}

int main() {
    cout << endl;
    vector<pair<int,int>> MST = Prim(Graph,0);
    for (int i=0;i<MST.size();i++) {
        cout << " ( " << MST[i].first << " , " << MST[i].second << " )  : " << Graph[MST[i].first][MST[i].second] << "\n";
    }
    cout << endl;
    return 0;
}