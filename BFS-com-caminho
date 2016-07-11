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
#include <utility>

#define INF 100000000

using namespace std;

map<int, int> level;
map<int, int> seq;

void inicializar(int n){
    for(int i = 0; i <= n; i++){
        level[i] = INF;
    }
}

void BFS(map<int, vector<int> > mapa, int O){
    queue<int> fila;
    fila.push(O);

    level[O] = 0;

    int nivel;

    while(!fila.empty()){
        nivel = level[fila.front()];
        int daVez = fila.front();
        fila.pop();
        for(int i = 0; i < mapa[daVez].size(); i++){
            if(level[mapa[daVez][i]] == INF){
                fila.push(mapa[daVez][i]);
                level[mapa[daVez][i]] = nivel + 1;
                seq[mapa[daVez][i]] = daVez;
            }
        }
    }

}

int main(){

    int quantLiga, quantElementos;

    cin >> quantLiga >> quantElementos;

    map<int, vector<int> > mapa;
    int x, y;

    for(int i = 0; i < quantLiga; i++){
        cin >> x >> y;
        mapa[x].push_back(y);
    }

    inicializar(quantElementos);

    int origem;

    cout << "Digite a origem: " << endl;

    cin >> origem;

    BFS(mapa, origem);

    int p = -1;

    int fim;

    cout << "Digite o ultimo numero da sequencia: " << endl;

    cin >> fim;

    cout << "A sequencia, a partir da origem ate o ultimo ponto eh..." << endl;

    vector<int> vet;

    vet.push_back(fim);

    do {
        vet.push_back(seq[fim]);
        fim = seq[fim];
    } while(fim != origem);

    for(int i = vet.size() - 1; i >= 0; i--){
        cout << vet[i] << " ";
    } cout << endl;

    return 0;
}
