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

int main(){

    int quantLiga;

    cin >> quantLiga;

    set<int> white;
    map<int, vector<int> > mapa;

    int x, y;

    for(int i = 0; i < quantLiga; i++){
        cin >> x >> y;
        mapa[x].push_back(y);
        //white.insert(x); |If all nodes have connections, use white set just inserting x and y;
        //white.insert(y); |
    }

    //int maxNum;                         |
    //cin >> maxNum;                      |
                                          |if some nodes haven't connections, insert all nodes from the minimal to largest node
    //for(int i = 0; i <= maxNum; i++){   |
    //    white.insert(i);                |
    //}

    stack<int> p;

    while(!white.empty()){
        set<int>::iterator it = white.begin();
        DFS(mapa, white, *it, p);
    }

    while(!p.empty()){
        cout << p.top() << " ";           //Just print the top of the stack, and pop it
        p.pop();
    }                                     //Now the topological sort was completed
    cout << endl;

    return 0;
}
