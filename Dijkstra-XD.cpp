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

map<int, int> dist;
map<int, int> seq;

void inicializar(int quantE){
    for(int i = 0; i <= quantE; i++){
        dist[i] = INF;
    }
}

void Dijkstra(map<int, vector<int> > adj, int O, map<pair<int, int>, int> custo){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > fila;
    fila.push(make_pair(0, O));
    dist[O] = 0;

    while(!fila.empty()){
        pair<int, int> t = fila.top();
        fila.pop();
        int daVez = t.second;
        for(int i = 0; i < adj[daVez].size(); i++){
            if(dist[daVez] + custo[make_pair(daVez, adj[daVez][i])] < dist[adj[daVez][i]]){
                dist[adj[daVez][i]] = dist[daVez] + custo[make_pair(daVez, adj[daVez][i])];
                seq[adj[daVez][i]] = daVez;
                fila.push(make_pair(dist[adj[daVez][i]], adj[daVez][i]));
            }
        }
    }
}

int main(){

    int quantE, quantV;

    cin >> quantE >> quantV;

    map<int, vector<int> > adj;
    map<pair<int, int>, int> custo;
    int x, y, z;

    inicializar(quantE);

    for(int i = 0; i < quantV; i++){
        cin >> x >> y >> z;
        adj[x].push_back(y);
        adj[y].push_back(x);
        custo[make_pair(x, y)] = z;
        custo[make_pair(y, x)] = z;
    }

    int O;
    cout << "Digite a origem: " << endl;
    cin >> O;

    Dijkstra(adj, O, custo);

    cout << "Digite um destino: " << endl;
    int D;
    cin >> D;

    cout << "A distancia minima da origem " << O << " ate o nodo " << D << " eh: ";
    cout << dist[D] << endl;

    cout << "Sua sequencia eh: " << endl;

    vector<int> vet;
    vet.push_back(D);
    int fim = D;
    while (fim != O){
        fim = seq[fim];
        vet.push_back(fim);
    }

    for(int i = vet.size() - 1; i >= 0; i--){
        cout << vet[i] << " ";
    } cout << endl;

    return 0;
}