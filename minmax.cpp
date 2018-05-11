#include <bits/stdc++.h>

using namespace std;

#define VAZIO 0
#define P1 1
#define P2 2
#define INF 0x3f3f3f3f

int fimJogo(vector<vector<int> > &vet){
    for(int i = 0; i < 3; i++){
        if(vet[i][0] == vet[i][1] and vet[i][1] == vet[i][2] and vet[i][0] != VAZIO){
            return 1;
        }
        if(vet[0][i] == vet[1][i] and vet[1][i] == vet[2][i] and vet[0][i] != VAZIO){
            return 1;
        }
    }
    if(vet[0][0] == vet[1][1] and vet[1][1] == vet[2][2] and vet[0][0] != VAZIO){
        return 1;
    }
    if(vet[0][2] == vet[1][1] and vet[1][1] == vet[2][0] and vet[0][2] != VAZIO){
        return 1;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(vet[i][j] == VAZIO){
                return -1;
            }
        }
    }
    return 0;
}

int minMax(vector<vector<int> > &vet, int daVez, int p){
    int r = fimJogo(vet);
    if(r >= 0){
        return (r == 0 ? 0 : (daVez == P1 ? p : -p));
    }
    int b;
    if(daVez == P2){
        b = -INF;
    } else {
        b = INF;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(vet[i][j] == VAZIO){
                vet[i][j] = daVez;
                int tmp = minMax(vet, (daVez == P1 ? P2 : P1), p - 1);
                if(daVez == P2){
                    b = max(b, tmp);
                } else {
                    b = min(b, tmp);
                }
                vet[i][j] = VAZIO;
            }
        }
    }
    return b;
}

int main(){

    vector<vector<int> > jogo(3, vector<int>(3, VAZIO));

    int fim = 0;
    int daVez = 0;

    while(!fim){
        if(daVez == 0){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(j) cout << " | ";
                    cout << (jogo[i][j] == VAZIO ? " " : (jogo[i][j] == P1 ? "O" : "X"));
                } cout << endl;
                for(int j = 0; j < 9; j++){
                    cout << "-";
                } cout << endl;
            }
            int imbecil;
            int x, y;
            do {
                imbecil = 0;
                cout << "Faca sua escolha: > ";
                cin >> x >> y;
                x--; y--;
                if(jogo[x][y] != VAZIO){
                    cout << "Celula ja ocupada!" << endl;
                    imbecil = 1;
                }
            } while(imbecil);
            jogo[x][y] = P1;
            daVez = 1;
        } else {
            int b = -INF;
            int p = 0;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(jogo[i][j] == VAZIO){
                        jogo[i][j] = P2;
                        int tmp = minMax(jogo, P1, 10);
                        if(tmp > b){
                            b = tmp;
                            p = 3 * i + j;
                        }
                        jogo[i][j] = VAZIO;
                    }
                }
            }
            int x = p / 3;
            int y = p % 3;

            jogo[x][y] = P2;
            daVez = 0;
        }

        fim = fimJogo(jogo);
        fim = (fim >= 0);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j) cout << " | ";
            cout << (jogo[i][j] == VAZIO ? " " : (jogo[i][j] == P1 ? "O" : "X"));
        } cout << endl;
        for(int j = 0; j < 9; j++){
            cout << "-";
        } cout << endl;
    }

}
