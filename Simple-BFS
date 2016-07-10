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

    cin >> origem;

    BFS(mapa, origem);
    
    return 0;
}
