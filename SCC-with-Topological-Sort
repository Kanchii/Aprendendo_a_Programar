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

using namespace std;

map<int, bool> visited;

void removeWhite(set<int> &white, int daVez){             //Function to remove a node from the white set
    white.erase(daVez);
}

void DFS(map<int, vector<int> > mapa, set<int> &white, int daVez, stack<int> &p){   //Simple DFS function to visit all node
    removeWhite(white, daVez);                                                      //connections
    for(int i = 0; i < mapa[daVez].size(); i++){
        set<int>::iterator it = white.find(mapa[daVez][i]);
        if(it != white.end()){
            DFS(mapa, white, mapa[daVez][i], p);
        }
    }

    p.push(daVez);                                                                  //If the node has all your connections
                                                                                    //visited, so just put the node in the
}                                                                                   //stack;

void SSC(map<int, vector<int> > mapaR, set<int> &ssc, int daVez){
    visited[daVez] = true;
    for(int i = 0; i < mapaR[daVez].size(); i++){
        if(!visited[mapaR[daVez][i]]){
            SSC(mapaR, ssc, mapaR[daVez][i]);
        }
    }
    ssc.insert(daVez);
}

int main(){

    int quantLiga;

    cin >> quantLiga;

    set<int> white;
    map<int, vector<int> > mapa, mapaR;

    int x, y;

    for(int i = 0; i < quantLiga; i++){
        cin >> x >> y;
        mapa[x].push_back(y);
        mapaR[y].push_back(x);
        white.insert(x);
        white.insert(y);
    }

    stack<int> p;

    while(!white.empty()){
        set<int>::iterator it = white.begin();
        DFS(mapa, white, *it, p);
    }

    stack<int> aux = p;
    /*while(!aux.empty()){
        cout << aux.top() << " ";
        aux.pop();
    } cout << endl;
    system("pause");*/

    while(!p.empty()){
        set<int> ssc;
        if(!visited[p.top()]){
            int daVez = p.top();
            p.pop();
            SSC(mapaR, ssc, daVez);
            set<int>::iterator it = ssc.begin();
            for(it; it != ssc.end(); it++){
                cout << *it << " ";
            } cout << endl;
            ssc.clear();
        } else {
            p.pop();
        }
    }

    return 0;
}
