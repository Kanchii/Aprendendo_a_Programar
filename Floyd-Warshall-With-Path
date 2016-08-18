#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

int n;

void init(int matriz[][10000], int next[][10000]){
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      matriz[i][j] = (i == j) ? 0 : INF;
      next[i][j] = j;
    }
  }
}

void FloydWarshall(int matriz[][10000], int next[][10000]){
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(matriz[i][j] > matriz[i][k] + matriz[k][j]){
            matriz[i][j] = matriz[i][k] + matriz[k][j]
            next[i][j] = next[i][k];
        }
      }
    }
  }
}

void reconstruct(int next[][10000], int O, int D){
  cout << O << " ";
  while(O != D){
    O = next[O][D];
    cout << O " ";
  }
   cout << endl;
}

using namespace std;

int main(){
  
  /*Algoritmo de Floyd-Warshall com a reconstrução do caminho percorrido de A até B*/
  
  return 0;
}
