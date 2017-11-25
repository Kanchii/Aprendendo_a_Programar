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
#include <queue>
#include <utility>


using namespace std;

priority_queue<pair<int, int> > pq;
map<int, bool> visited;

int relogio = 0;

void marcaPre(){                //Atualiza o relogio quando passa pelo numero pela primeira vez
    relogio++;
}

void marcaPos(int daVez){       //Atualiza o relogio e adiciona o no e o valor do relogio a uma fila de prioridade
    relogio++;
    pq.push(make_pair(relogio, daVez));
}

void DFS(map<int, vector<int> > mapaR, int daVez, set<int> &white){   //Primeira DFS, que passa pelo grafo reverso marcando os no com o relogio
    visited[daVez] = true;                                            //Marca o no como visitado para evitar ciclos infinitos
    marcaPre();                                                       //Atualiza o relogio (primeira vez que passa pelo no
    white.erase(daVez);                                               //Retira o no do white set, para que nao voltemos a usar esse no de novo
    for(int i = 0; i < mapaR[daVez].size(); i++){                     //Comeca a visitar todos os outros nos ligados ao no em questao
        if(!visited[mapaR[daVez][i]]){                                //Se o no vizinho do no em questao ainda nao foi visitado
            DFS(mapaR, mapaR[daVez][i], white);                       //Passamos a DFS por ele, em recursao
        }
    }
    marcaPos(daVez);                                                  //Quando todos os vizinhos deste no foi visitado, marcamos ele com o relogio e adicionamos a fila
}

void DFS2(map<int, vector<int> > mapa, int daVez, set<int> &ssc){       //Segunda DFS que faz a leitura no grafo original
	visited[daVez] = true;                                              //Marca o no como visitado
	for(int i = 0; i < mapa[daVez].size(); i++){                        //Comeca a visitar todos os nos conectados ao no em questao
        if(!visited[mapa[daVez][i]]){                                   //Se o no sendo tratado agora ainda nao foi visitado
            DFS2(mapa, mapa[daVez][i], ssc);                            //Chamamos a DFS2 para explorar agora o no ligado ao no principal
        }
	}

    ssc.insert(daVez);                                                  //Caso o no nao apresente nenhum vizinho, entao colocamos no ssc set
}

int main(){

    int quantLigacoes;

    cin >> quantLigacoes;                                             //Le o numero de vertices (ligacoes) do grafo

    map<int, vector<int> > mapa, mapaR;

    int x, y;
    set<int> white;

    for(int i = 0; i < quantLigacoes; i++){                           //Inicializando o grafo, o grafo reverso e o white set
        cin >> x >> y;
        mapa[x].push_back(y);
        white.insert(x);
        white.insert(y);
        mapaR[y].push_back(x);
    }

    while(!white.empty()){                                            //Enquanto o white set nao estiver vazio
        set<int>::iterator it = white.begin();
        DFS(mapaR, *it, white);                                       //Chame a funcao DFS para marcar os no
    }

    visited.clear();                                                  //Limpa o mapa de visitados

    /*priority_queue<pair<int, int> > teste = pq;

    while(!teste.empty()){                                              //Apenas mostra quais elementos serao visitados primeiro
        cout << teste.top().first << " " << teste.top().second << endl; //seguindo a ordem do post-order dos nos
        teste.pop();
    } */
    

    while(!pq.empty()){                                               //Enquanto estiver nos na fila
    	if(!visited[pq.top().second]){                                 //Se ainda nao foram visitados
    		int daVez = pq.top().second;
    		set<int> ssc;
    		DFS2(mapa, daVez, ssc);                                    //Chamamos a funcao DFS2 para procurar os SSC
    		set<int>::iterator it = ssc.begin();
            for(it; it != ssc.end(); it++){
                cout << *it << " ";                                    //Depois de passar o DFS2, e printado os SSC daquele grupo
            } cout << endl;
            ssc.clear();
    	}
    	pq.pop();                                                     //Caso nao, apenas tiramos o no da fila e continuamos no laco
    }

    return 0;
}
