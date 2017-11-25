#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

//Function to remove a node from white set
void removeWhite(int daVez, set<int> &white){
    white.erase(daVez);
}

void DFS(map<int, vector<int> > mapa, int from, set<int> &white){ //Function to search for all nodes that are connected
    removeWhite(from, white);                                     //Removing a node
    for(int i = 0; i < mapa[from].size(); i++){                   //Looking all the node's connections

        set<int>::iterator it = white.find(mapa[from][i]);        //Verifying if the node's neighbor (that is connected with
                                                                  //the node) is in the white set

        if(it != white.end()){                                    //If the node's neighbor is in the white set
            DFS(mapa, mapa[from][i], white);                      //Call DFS function to look all the node's neighbor connection
        }
    }
}

int main(){

    int quantVert, quantEd;

    cin >> quantVert >> quantEd;

    map<int, vector<int> > mapa;
    set<int> white;

    int x, y;

    for(int i = 0; i < quantEd; i++){
        cin >> x >> y;
        mapa[x].push_back(y);                           //Creating the adjacency list
        mapa[y].push_back(x);
    }

    for(int i = 0; i < quantVert; i++){
        white.insert(i+1);                              //Creating the white set with all nodes
    }

    int quant = 0;
    while(!white.empty()){                             //While the white set isn't empty, seach for more connections
        set<int>::iterator it = white.begin();
        quant++;
        DFS(mapa, *it, white);                        //Calling the DFS function to look for all nodes connected to it
    }

    cout << quant;                                    //Print how many blocks of connected components exist in this graph

    return 0;
}
