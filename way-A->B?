#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

//Function to remove a node of the white place
void removeWhite(int daVez, set<int> &white){
    white.erase(daVez);
}

//Function to return if have a way from A to B
bool DFS(map<int, vector<int> > mapa, int from, int destiny, set<int> &white){
    
    removeWhite(from, white);                         //Calling the function to remove a node (line 15)
    for(int i = 0; i < mapa[from].size(); i++){       //Passing by all neighbors to verify if one of them is the destiny

        if(mapa[from][i] == destiny){                 //If the neighbor of the actual node is the destiny, return True
            return true;
        }

        set<int>::iterator it = white.find(mapa[from][i]); //Searching for the neighbor in the white place

        if(it != white.end()){                             //If the neightbor is in the white place, call the DFS function
            if(DFS(mapa, mapa[from][i], destiny, white)){  //in recursion
                return true;
            }
        }                                                  //Else, just jump to another neighbor
    }

    return false;                                          //If the actual node haven't another neighbors, just return false
                                                           //which means that, reaching here, don't exist a way to reach the destiny from this node
}

int main(){

    int quantVert, quantEd;

    cin >> quantVert >> quantEd;

    map<int, vector<int> > mapa;
    set<int> white;

    int x, y;

    for(int i = 0; i < quantEd; i++){
        cin >> x >> y;
        mapa[x].push_back(y);                         //Creating the adjacency list for a undirected graph
        mapa[y].push_back(x);
        white.insert(x);                              //Creating the white place, where stay the nodes that have a neighbor
        white.insert(y);
    }

    int from, destiny;
    cin >> from >> destiny;                           //Defining the start and the destiny

    if(DFS(mapa, from, destiny, white)){              //If have a way from A to B, write "1"
        cout << "1";
    } else {                                          //Else write "0"
        cout << "0";
    }

    return 0;
}
