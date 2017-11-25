#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>

#define INF 10000000
#define MAX 505

using namespace std;



void init(int dist[][MAX], int quantE){
    for(int i = 0; i <= quantE; i++){
        for(int j = 0; j <= quantE; j++){
            dist[i][j] = INF;
        }
    }
}

void FloydWarshall(int dist[][MAX], int quantE){
    for(int k = 0; k <= quantE; k++){
        for(int i = 0; i <= quantE; i++){
            for(int j = 0; j <= quantE; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {

    int quantE, quantV;

    cin >> quantE >> quantV;

    int dist[MAX][MAX];

    int x, y, z;

    init(dist, quantE);

    for(int i = 0; i < quantV; i++){
        cin >> x >> y >> z;
        dist[x][y] = z;
    }

    FloydWarshall(dist, quantE);

    while(true){
        cout << "Digite a origem e o destino: (Digite -1 -1 para sair)" << endl;
        if(x == -1 && y == -1){
            break;
        }
        cout << "A distancia minima entre " << x << " e " << y << " eh: " << dist[x][y] << endl;
    }

    return 0;
}
