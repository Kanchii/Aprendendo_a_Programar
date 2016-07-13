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

void init(int quantE){
    for(int i = 0; i <= quantE; i++){
        dist[i] = INF;
    }
}

void BellmanFord(vector<vector<int> > adj, map<pair<int, int>, int> custo, int origem){
    bool sair = false;

    dist[origem] = 0;

    while(!sair){
        sair = true;
        map<pair<int, int>, int>::iterator it = custo.begin();
        for(it; it != custo.end(); it++){
            if(it -> first.first != INF){
                if(dist[it -> first.second] > dist[it -> first.first] + it -> second){
                    dist[it -> first.second] = dist[it -> first.first] + it -> second;
                    seq[it -> first.second] = it -> first.first;
                    sair = false;
                }
            }
        }
    }
}

int main(int argc, char *argv[]){

    int quantE, quantV;

    scanf("%d %d", &quantE, &quantV);

    vector<vector<int > > adj(quantE + 1);
    map<pair<int, int>, int> custo;

    int x, y, z;

    for(int i = 0; i < quantV; i++){
        scanf("%d %d %d", &x, &y, &z);
        adj[x].push_back(y);
        custo[make_pair(x, y)] = z;
    }

    int origem, destino;
    cout << "Digite a origem e o destino desejado: " << endl;
    scanf("%d %d", &origem, &destino);

    init(quantE);

    BellmanFord(adj, custo, origem);

    cout << "O custo minimo para ir do ponto " << origem << " ateh o ponto " << destino << " eh: " << endl;
    cout << dist[destino] << endl;

    cout << "A sequencia para chegar da origem ate o ponto destino eh: " << endl;

    int fim = destino;
    vector<int> vet;
    vet.push_back(destino);

    while(fim != origem){
        fim = seq[fim];
        vet.push_back(fim);
    }

    for(int i = vet.size() - 1; i >= 0; i--){
        cout << vet[i] << " ";
    } cout << endl;

    return 0;
}
