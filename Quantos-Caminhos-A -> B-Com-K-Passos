#include <iostream>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <string.h>
#include <stack>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

#define INF 0x3f3f3f3f
#define MAX 110
#define MOD 10000
#define ALPHABETIC_SIZE 30
#define endl '\n'
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
#define mp(a,b) make_pair(a,b)

typedef unsigned long long int ull;
typedef unsigned int ui;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int matriz[MAX][MAX];
int res[MAX][MAX];
int n, k, m;
int origem, destino;

void multiplica(){
	ll kk[MAX][MAX];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			kk[i][j] = 0;
			for(int k = 0; k < n; k++){
				kk[i][j] += (res[i][k] * matriz[k][j]);         //Nesta parte é feita a multiplicação da matriz resposta pela matriz
			}                                                 //de adjacência
			kk[i][j] = kk[i][j]%MOD;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			res[i][j] = kk[i][j];
		}
	}
}

void eleva(){
	ll kk[MAX][MAX];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			kk[i][j] = 0;
			for(int k = 0; k < n; k++){
				kk[i][j] += matriz[i][k] * matriz[k][j];      //Nesta parte a matriz de adjacência é elevada ao quadrado
			}
			kk[i][j] = kk[i][j]%MOD;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			matriz[i][j] = kk[i][j];
		}
	}
}

int solve(){	
	memset(res, 0, sizeof(res));
	for(int i = 0; i < n; i++){
		res[i][i] = 1;        //Inicializando a matriz resposta como uma matriz identidade
	}

	while(k > 0){
		if(k % 2 != 0){
			multiplica();       //Aplicando o "Exponentiation by squaring", algoritmo para resolver a exponenciação em O(logN)
		}                     //onde N é a pontencia
		eleva();
		k /= 2;
	}

	return res[origem - 1][destino - 1];
}

int main(int argc, char const *argv[]){
	//ios_base::sync_with_stdio(false);
	while(scanf("%d %d %d %d %d", &n, &m, &k, &origem, &destino) != EOF){
		memset(matriz, 0, sizeof(matriz));
		int x, y;
		for(int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);                 //Lendo e montando a matriz de adjacência, contando o numero de caminhos que existem
			matriz[x - 1][y - 1]++;                 //para ir de X -> Y
		}

		int kk = solve();
		printf("%d\n", kk);

	}

	return 0;
}
