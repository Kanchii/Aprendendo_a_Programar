#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define endl '\n'

using namespace std;

int n;
double dist[17][17], memo[17][1 << 17];

double d(int x, int y, int x1, int y1){
    return hypot(x - x1, y - y1);
}

double solve(int id, int bitmask){

    if(bitmask == (1 << n) - 1){
        return dist[id][0];
    }
    if(memo[id][bitmask] != -1){
        return memo[id][bitmask];
    }

    double ans = INF;

    for(int i = 0; i < n; i++){
        if(!(bitmask & (1 << i))){
            ans = min(ans, dist[id][i] + solve(i, bitmask | (1 << i)));
        }
    }

    return memo[id][bitmask] = ans;

}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    while(cin >> n, n){
        n++;

        int x[n], y[n];

        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                dist[i][j] = dist[j][i] = d(x[i], y[i], x[j], y[j]);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < (1 << n); j++){
                memo[i][j] = -1;
            }
        }

        cout << fixed << setprecision(2) << solve(0, 1) << endl;

    }



	return 0;
}
