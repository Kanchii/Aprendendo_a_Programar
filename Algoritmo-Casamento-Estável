#include <bits/stdc++.h>

using namespace std;

#define MAX 10100
#define SOLTEIRO -1

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int> > adj(2*n + 1);									//Algoritmo para fazer o casamento de pares de maneira estável
	map<string, int> mapa;												//onde todos acabam "felizes" com seus pares.
	map<int, string> nomes;
	int countPessoa = 0;
	int countLobo = n;

	for(int i = 0; i < n; i++){
		string pessoa;
		cin >> pessoa;													//Setando a preferencia das pessoas com seus lobos
		nomes[countPessoa] = pessoa;									//Quanto mais na frente do vector, maior a preferencia
		mapa[pessoa] = countPessoa++;									//O uso do map é para transformar as strings em números, 
		for(int j = 0; j < n; j++){										//Assim o uso de map para trabalhar com as strings não se faz necessário
			string lobo;
			cin >> lobo;
			if(i == 0){
				nomes[countLobo] = lobo;
				mapa[lobo] = countLobo++;
			}
			adj[countPessoa - 1].push_back(mapa[lobo]);
		}
	}

	for(int i = 0; i < n; i++){
		string lobo;
		cin >> lobo;													//Setando a preferencia dos lobos para com as pessoas
		for(int j = 0; j < n; j++){
			string pessoa;
			cin >> pessoa;
			adj[mapa[lobo]].push_back(mapa[pessoa]);
		}
	}

	int relacionamento[2*n + 1];
	memset(relacionamento, SOLTEIRO, sizeof(relacionamento));

	bool temNegoSolteiro = true;

	bool visited[2*n + 1][2*n + 1];

	memset(visited, false, sizeof(visited));

	while(temNegoSolteiro){
		temNegoSolteiro = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(relacionamento[i] == SOLTEIRO and !visited[i][j]){
					visited[i][j] = true;
					int u = adj[i][j];
					if(relacionamento[u] == SOLTEIRO){
						relacionamento[u] = i;												//Enquanto houver alguem solteiro
						relacionamento[i] = u;													//Dois for's para circular pelos vectors
						break;																		//Se a pessoa i for solteira e se já não tiver
					} else {																		//proposto para o lobo na posição j
						int v = relacionamento[u];														//Se o lobo na posição j for solteiro
						bool flag = 0;																		//match entre i e j
						for(int k = 0; k < n; k++){														//Caso contrario j namora com i'
							if(adj[u][k] == i){																//Verifica a preferencia de j em relação
								flag = 1;																	//ao i e o i'
								break;																		//Se j prefere i, então i' passa a ser solteiro
							} else if(adj[u][k] == v){														//e match entre i e j, caso contrário
								break;																		//i vai propor para o próximo lobo
							}
						}
						if(flag == 1){
							relacionamento[v] = SOLTEIRO;
							relacionamento[i] = u;
							relacionamento[u] = i;
						}
					}
				}
			}
		}
		for(int i = 0; i < n; i++){						//Verificando se ainda tem alguém solteiro
			if(relacionamento[i] == SOLTEIRO){
				temNegoSolteiro = true;
			}
		}
	}

	for(int i = 0; i < n; i++){
		cout << nomes[i] << " " << nomes[relacionamento[i]] << endl;
	}

	return 0;
}
