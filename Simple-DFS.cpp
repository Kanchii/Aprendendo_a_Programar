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
#include <queue>
#include <utility>
#include <string>

using namespace std;

map<int, bool> visited;

void DFS(map<int, vector<int> > mapa, int origem){
    stack<int> p;
    p.push(origem);
    
    while(!p.empty()){
        int daVez = p.top();
        visited[daVez] = true;
        p.pop();
        for(int i = 0; i < mapa[daVez].size(); i++){
            if(!visited[mapa[daVez][i]]){
                p.push(mapa[daVez][i]);
            }
        }
    }
    
}

int main(){
    
    int quantLiga;
    
    cin >> quantLiga;
    
    map<int, vector<int> > mapa;
    
    int x, y;
    
    for(int i = 0; i < quantLiga; i++){
        cin >> x >> y;
        mapa[x].push_back(y);        
    }
    
    int origem;
    cin >> origem;
    
    DFS(mapa, origem);

    return 0;
}