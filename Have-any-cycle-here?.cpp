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

using namespace std;
map<int, bool> visited;
set<int> black;

void removeWhite(int daVez, set<int> &white){
    white.erase(daVez);
}

bool DFS(int daVez, map<int, vector<int> > mapa, set<int> &white){
    removeWhite(daVez, white);
    visited[daVez] = true;
    for(int i = 0; i < mapa[daVez].size(); i++){
        set<int>::iterator it = black.find(mapa[daVez][i]);
        if(it == black.end()){
            if(visited[mapa[daVez][i]]){
                return true;
            } else {
                if(DFS(mapa[daVez][i], mapa, white)){
                    return true;
                }
            }
        }
    }
    black.insert(daVez);
    return false;
}


int main(){
    
    int quantNo, quantV;

    cin >> quantNo >> quantV;

    set<int> white;
    for(int i = 1; i <= quantNo; i++){
        white.insert(i);
    }

    map<int, vector<int> > mapa;

    int x, y;

    for(int i = 0; i < quantV; i++){
        cin >> x >> y;
        mapa[x].push_back(y);
    }

    bool loop = false;

    while(!white.empty()){
        set<int>::iterator it = white.begin();
        if(DFS(*it, mapa, white)){
            loop = true;
            break;
        } else {
            visited.clear();
        }
    }

    if(loop){
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
