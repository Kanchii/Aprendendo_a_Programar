#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <ctype.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>

#define INF 1000000

using namespace std;

map<int, int> dist;
map<int, int> seq;

set<int> negCycle;

void init(int quantE){
    for(int i = 0; i <= quantE; i++){
        dist[i] = INF;
    }
}

void BellmanFord(vector<vector<int> > adj, map<pair<int, int>, int> custo, int quantE, int origem){
    bool sair = false;
    dist[origem] = 0;

    int cont = 0;

    while(!sair){
        sair = true;
        cont++;
        map<pair<int, int>, int>::iterator it = custo.begin();
        for(it; it != custo.end(); it++){
            if(it -> first.first != INF){
                if(dist[it -> first.second] > dist[it -> first.first] + it -> second){

                    if(cont < quantE - 1){
                        dist[it -> first.second] = dist[it -> first.first] + it -> second;
                        seq[it -> first.second] = it -> first.first;
                        sair = false;
                    } else {
                        dist[it -> first.second] = dist[it -> first.first] + it -> second;
                        negCycle.insert(it -> first.second);
                    }
                }
            }
        }

        if(cont == quantE){
            sair = true;
        }
    }
}

int main(int argc, char *argv[]){

    int quantE, quantV;

    scanf("%d %d", &quantE, &quantV);

    vector<vector<int > > adj(quantE + 1);
    map<pair<int, int>, int> custo;

    int x, y, z;

    int origem;

    for(int i = 0; i < quantV; i++){
        scanf("%d %d %d", &x, &y, &z);
        adj[x].push_back(y);
        custo[make_pair(x, y)] = z;
    }

    cout << "Digite a origem: " << endl;
    scanf("%d", &origem);

    BellmanFord(adj, custo, quantE, origem);

    if(negCycle.size() > 0){
        cout << "Temos um ciclo negativo neste grafo!" << endl;
        cout << "Todos os nos seguintes tem valor infinito negativo, devido ao ciclo negativo: " << endl;
        set<int>::iterator it = negCycle.begin();
        for(it; it != negCycle.end(); it++){
            cout << *it << " ";
        } cout << endl;
    } else {
        cout << "Nao tem nenhum ciclo negativo nesse grafo" << endl;
    }

    return 0;
}
