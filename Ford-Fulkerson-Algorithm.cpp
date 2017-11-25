#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long int lld;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define INF 0x3f3f3f3f
#define MAX 1050
#define MOD 1300031
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b)) 
#define mp(a,b) (make_pair(a,b))
#define fr(a,b) for(int i = a; i < (int)tb; i++)
#define frj(a,b) for(int j = a; j < (int)b; j++)
#define fri(a,b) for(int i = a; i > (int)b; i--)

int n, m;
int t = 1002, s = 1001;
int dist[MAX][MAX];
int parent[MAX];

bool DFS(vvi &adj, int daVez, bool *visited){
	visited[daVez] = true;
	if(daVez == t){
		return true;
	}
	for(int i = 0; i < (int)adj[daVez].size(); i++){
		int u = adj[daVez][i];
		if(!visited[u] && dist[daVez][u] > 0){
			parent[u] = daVez;
			if(DFS(adj, u, visited)){
				return true;
			}
		}
	}
	return false;
}

int FordFulkerson(vvi &adj){
	int maxFlow = 0;
	bool visited[MAX];
	memset(visited, false, sizeof(visited));
	while(DFS(adj, s, visited)){
		int aux = t;
		lld minimo = INF;

		while(aux != s){
			int u = parent[aux];
			if(dist[u][aux] < minimo){
				minimo = dist[u][aux];
			}
			aux = u;
		}
		aux = t;
		while(aux != s){
			int u = parent[aux];
			dist[u][aux] -= minimo;
			dist[aux][u] += minimo;
			aux = u;
		}		
		maxFlow += minimo;
		memset(visited, false, sizeof(visited));
	}
	return maxFlow;
}

int main(int argc, char const *argv[]){
	//ios_base::sync_with_stdio(false);	
	

	return 0;
}
