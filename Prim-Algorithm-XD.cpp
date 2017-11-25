#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <queue>
#include <list>
#include <utility>

#define INF 100000000

using namespace std;

map<int, int> dist, parent;

void init(int quantE){
    for(int i = 0; i <= quantE; i++){
        dist[i] = INF;
    }
}

map<int, bool> visited;

void Prim(vector<vector<int> > adj, map<pair<int, int>, int> custo, int O){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > fila;
    fila.push(make_pair(0, O));

    dist[O] = 0;
    parent[O] = O;

    while(!fila.empty()){
        int daVez = fila.top().second;
        fila.pop();
        visited[daVez] = true;
        for(int i = 0; i < adj[daVez].size(); i++){
            if(dist[adj[daVez][i]] == INF){
                dist[adj[daVez][i]] = custo[make_pair(daVez, adj[daVez][i])];
                parent[adj[daVez][i]] = daVez;
                fila.push(make_pair(dist[adj[daVez][i]], adj[daVez][i]));
            } else {
                if(!visited[adj[daVez][i]]){
                    if(dist[adj[daVez][i]] > custo[make_pair(daVez, adj[daVez][i])]){
                        dist[adj[daVez][i]] = custo[make_pair(daVez, adj[daVez][i])];
                        parent[adj[daVez][i]] = daVez;
                        fila.push(make_pair(dist[adj[daVez][i]], adj[daVez][i]));
                    }
                }
            }
        }
    }
}

int main(){

    int quantE, quantV;

    scanf("%d %d", &quantE, &quantV);

    map<pair<int, int>, int> custo;
    vector<vector<int> > adj(quantE + 1);

    int x, y, z;

    for(int i = 0; i < quantV; i++){
        scanf("%d %d %d", &x, &y, &z);
        adj[x].push_back(y);
        adj[y].push_back(x);
        custo[make_pair(x, y)] = z;
        custo[make_pair(y, x)] = z;
    }

    init(quantE);

    int origem;
    scanf("%d", &origem);

    Prim(adj, custo, origem);

    printf("\n");

    map<int, int>::iterator it = parent.begin();
    for(it; it != parent.end(); it++){
        cout << it -> first << " | " << it -> second << endl;
    }

    return 0;
}