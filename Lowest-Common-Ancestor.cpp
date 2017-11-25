#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <iomanip>
#include <string.h>
#include <map>

#define INF 0x3f3f3f3f
#define MAX 100001

typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<vector<pair<int, int> > > vvpii;

using namespace std;

int parent[MAX], nivel[MAX], superParent[MAX], tam = -1;

void montaParent(vvi &adj, int daVez, int ant, int level){
	parent[daVez] = ant;
	nivel[daVez] = level;
	if(level > tam){
		tam = level;
	}
	for(size_t i = 0; i < adj[daVez].size(); i++){
		int u = adj[daVez][i];
		if(parent[u] == -1){
			montaParent(adj, u, daVez, level + 1);
		}
	}
}

void montaSuperParent(vvi &adj, int daVez, int pai){
	superParent[daVez] = pai;
	if(nivel[daVez]%tam == 0){
		pai = daVez;
	}
	for(size_t i = 0; i < adj[daVez].size(); i++){
		int u = adj[daVez][i];
		if(superParent[u] == -1){
			montaSuperParent(adj, u, pai);
		}
	}
}

int LCA(int a, int b){
	while(superParent[a] != superParent[b]){
		if(nivel[a] > nivel[b]){
			a = superParent[a];
		} else {
			b = superParent[b];
		}
	}

	while(a != b){
		if(nivel[a] > nivel[b]){
			a = parent[a];
		} else {
			b= parent[b];
		}
	}

	return a;
}

int main(){

	vvi adj(MAX);

	adj[1].push_back(0);
	adj[0].push_back(1);
	adj[2].push_back(1);
	adj[1].push_back(2);
	adj[3].push_back(1);
	adj[1].push_back(3);
	adj[4].push_back(0);
	adj[0].push_back(4);
	adj[5].push_back(4);
	adj[4].push_back(5);
	memset(parent, -1, sizeof(parent));
	memset(superParent, -1, sizeof(superParent));
	montaParent(adj, 0, 0, 0);
	tam = (int)sqrt(tam);
	montaSuperParent(adj, 0, 0);
	cout << LCA(2, 3) << endl;
	cout << LCA(0, 4) << endl;
	cout << LCA(1, 4) << endl;

    return 0;
}
