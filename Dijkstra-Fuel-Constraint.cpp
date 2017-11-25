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

using namespace std;

#define INF 0x3f3f3f3f
#define MAX 15
#define mk make_pair

typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<vector<pair<int, int> > > vvpii;

int gasolina[MAX];
int dist[MAX][MAX];
int n, m, maxFuel;

void anotherDijkstra(vvi &adj, int nodo){
	priority_queue<pii, vector<pii>, greater<pii> > fila;
	int totalDist[MAX];
	memset(totalDist, INF, sizeof(totalDist));
	fila.push(mk(0, nodo));
	dist[nodo][nodo] = 0;                                                 //Dijkstra para arrumar o grafo
	totalDist[nodo] = 0;                                                  //Ele simplesmente passa por todos os nós em busca de
	while(!fila.empty()){                                                 //novas possíveis ligações entre o nó em questão e os demais
		int daVez = fila.top().second;                                      //Isto é importante pois ele poderia escolher abastecer
		int aux = fila.top().first;                                         //mais do que o necessário para a proxima viagem para poder
		fila.pop();                                                         //passar direto pela próxima cidade sem precisar abastecer
		for(size_t i = 0; i < adj[daVez].size(); i++){                      //novamente
			int u = adj[daVez][i];
			int custo = dist[daVez][u];                           //v----- Verifica se a distancia do nodo (nó fixo trabalhado) até o nó da vez
			if(dist[nodo][u] > aux + custo && aux + custo <= maxFuel){     é maior e se o custo disso é menor do que o tanque suporta
      
				if(dist[nodo][u] == INF){ // <--- Verifica se existe ligação do nodo fixo até o nó da vez, se nao tiver, ele adiciona a lista
					adj[nodo].push_back(u);        //lista de adjacência
					adj[u].push_back(nodo);
				}
				dist[nodo][u] = aux + custo;    //Atualiza a distancia do nodo fixo ate o no em questão
				dist[u][nodo] = aux + custo;
			}
			if(totalDist[u] > aux + custo){   //Verifica se deve por o nó em questão na fila
				totalDist[u] = aux + custo;
				fila.push(mk(aux + custo, u));
			}
		}
	}
}

int Dijkstra(vvi &adj){
	int totalGasto[MAX];
	memset(totalGasto, INF, sizeof(totalGasto));
	priority_queue<pair<pii, int>, vector<pair<pii, int> >, greater<pair<pii, int> > > fila;
	totalGasto[1] = 0;
	fila.push(mk(mk(0, maxFuel), 1));
	while(!fila.empty()){
		int daVez = fila.top().second;
		int gastoAte = fila.top().first.first;                                //Dijkstra normal
		if(daVez == n){
			return gastoAte;
		}
		int restaGaso = fila.top().first.second;
		fila.pop();
		for(size_t i = 0; i < adj[daVez].size(); i++){
			int u = adj[daVez][i];
			int custo = dist[daVez][u];
			int diff = (restaGaso >= custo) ? 0 : custo - restaGaso; //<--- Pega a diferença da gasolina, para verificar se deve abastecer ou nao
			if(totalGasto[u] > gastoAte + diff*gasolina[daVez] && custo <= maxFuel){
				totalGasto[u] = gastoAte + diff*gasolina[daVez];
				fila.push(mk(mk(totalGasto[u], (restaGaso >= custo) ? (restaGaso - custo) : 0), u));
			}
		}
	}
	return totalGasto[n];
}

int main(){
	while(scanf("%d %d %d", &n, &m, &maxFuel) && (n || m || maxFuel)){
		vvi adj(n + 1);
		int x, y, z;
		memset(dist, INF, sizeof(dist));
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			adj[x].push_back(y);
			adj[y].push_back(x); //<---- Construindo a lista de adjacência e a matriz de distancias
			dist[x][y] = z;
			dist[y][x] = z;
		}

		for(int i = 1; i <= n - 1; i++){
			anotherDijkstra(adj, i); //<----- Arrumando o grafo para adapta-lo corretamente para o calculo do caminho menos custoso
		}

		for(int i = 1; i <= n; i++){
			scanf("%d", &gasolina[i]); //<---- Lendo o valor da gasolina em cada cidade
		}

		int kk = Dijkstra(adj);

		printf("%d\n", (kk < INF) ? kk : -1); //<---- Se nao houver como ir de A -> B é retornado INF e é mostrado -1 caso contrário
	}                                             //é mostrado o menor custo para ir de A ->B

    return 0;
}
