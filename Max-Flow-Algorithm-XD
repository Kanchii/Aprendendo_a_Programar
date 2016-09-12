#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'

using namespace std;

int quantV, quantA;

int BFS(vector<vector<int> > &adj, map<pair<int, int>, int> &custo, int origem, int destino){
    queue<int> fila;
    vector<bool> visited(quantV + 1, false);
    fila.push(origem);
    visited[origem] = true;
    vector<int> parent(quantV + 1, -1);
    while(!fila.empty()){
        int daVez = fila.front();
        fila.pop();
        for(int i = 0; i < adj[daVez].size(); i++){
            if(!visited[adj[daVez][i]] && custo[make_pair(daVez, adj[daVez][i])] > 0){
                visited[adj[daVez][i]] = true;
                parent[adj[daVez][i]] = daVez;
                fila.push(adj[daVez][i]);
            }
        }
    }

    int minimo = INF;
    if(parent[destino] != -1){
        int O = origem, D = destino;
        while(D != O){
            minimo = min(minimo, custo[make_pair(parent[D], D)]);
            D = parent[D];
        }
        O = origem, D = destino;
        while(D != O){
            custo[make_pair(parent[D], D)] -= minimo;
            D = parent[D];
        }
        return minimo;
    }

    return -1;

}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> quantV >> quantA;

    map<pair<int, int>, int> custo;
    vector<vector<int> > adj(quantV + 1);

    int x, y, z;
    for(int i = 0; i < quantA; i++){
        cin >> x >> y >> z;
        adj[x].push_back(y);
        custo[make_pair(x, y)] = z;
    }

    int origem, destino;
    cin >> origem >> destino;

    int totalFlow = 0;

    while(true){
        int fluxo = BFS(adj, custo, origem, destino);
        if(fluxo == -1){
            break;
        }
    }

    cout << "Fluxo Maximo Possivel Nesse Grafo: " << totalFlow << endl;

    return 0;
}
