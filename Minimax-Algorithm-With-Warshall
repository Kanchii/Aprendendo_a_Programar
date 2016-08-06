#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>

#define INF 100000000

using namespace std;

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m)){
        if(n== 0 & m == 0){
            break;
        }

        int matriz[n+1][n+1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == j){
                    matriz[i][j] = 0;
                } else {
                    matriz[i][j] = INF;
                }
            }
        }

        int x, y, z;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            matriz[x][y] = z;
            matriz[y][x] = z;
        }  
        
        /*MINIMAX*/
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    matriz[i][j] = min(matriz[i][j], max(matriz[i][k], matriz[k][j]));
                }
            }
        }
        /*------*/
    }

    return 0;
}
