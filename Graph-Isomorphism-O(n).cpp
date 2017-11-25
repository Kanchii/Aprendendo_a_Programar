#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define PI 3.14159265
#define EPS 0.0000001
#define MOD 1000000007
#define MAX 1000100
#define MAXN 1000

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

typedef unsigned long long int ull;
typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef struct{
  int n; list<int> adj[MAXN];
} Tree;

//Se duas arvores são isomorficas, então elas tem o mesmo ID
//Este algoritmo opera com tempo aproximado de O(n) (pode levar um pouco mais as vezes)
string getTreeID(Tree t){
 	multiset<string> s[MAXN]; multiset<string>::iterator it;
 	set<int> leaf; set<int>::iterator j;
 	char parent[MAXN]; string id[MAXN], res[2];
 	int left = t.n, i, k, x;
 
 	for(i = 0; i < t.n; i++) id[i] = "01";
 
 	while(left > 2){
    	memset(parent, 0, sizeof(parent));
    	for(i = 0; i < t.n; i++) s[i].clear();
    	leaf.clear();
   
    	for(i = 0; i < t.n; i++){
      		if(t.adj[i].size() == 1){
    			leaf.insert(i);
    			x = *t.adj[i].begin();
    			s[x].insert(id[i]);
    			parent[x] = 1;
    			left--;
      		}
      	}
   
    	for(i = 0; i < t.n; i++){
      		if(parent[i]){
			    x = id[i].size();
			    if(x > 2) s[i].insert(id[i].substr(1,x-2));
			    for(id[i] = "0", it = s[i].begin(); it != s[i].end(); ++it){
   			    	id[i] += *it;
			    }
			    id[i] += '1';
      		}
      	}

    	for(i = 0; i < t.n; i++){
      		if(leaf.count(i) == 1) t.adj[i].clear();
      		else {
    			for(j = leaf.begin(); j != leaf.end(); ++j){
      				for(k = 0; k < t.n; k++){
        				t.adj[k].remove(*j);
        			}
        		}
        	}
        }
	}
 
 	for(i = x = 0; i < t.n; i++){
    	if(parent[i]) res[x++] = id[i];
 	}
 
	if(left == 1) return res[0];
	return (res[0] < res[1]) ? res[0]+res[1] : res[1]+res[0];
}


int main() {
	int n;
	cin >> n; //Number of graphs
	for(int i = 0; i < n; i++){
		Tree t;
		string id;
		int k;
		cin >> k; //Number os nodes
		t.n = k;
		int daVez = 1;
		for(int j = 0; j < k - 1; j++){
			int a, b;
			cin >> a >> b;
			t.adj[a].push_back(b);
			t.adj[b].push_back(a);
		}
		id = getTreeID(t);
		ids.push_back(id);
	}
  
  //Dentro do array esta todos os ids das arvores. Para saber quantas são isomorficas, basta verificar quais ids são iguais

  return 0;
}
