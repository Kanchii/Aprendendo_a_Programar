#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

const int maxn = 1e5+5;
const int k = log2(maxn) + 1;
vvii adj;
ll table[maxn][k+5], max_dep, lca[maxn][k+5], nivel[maxn];

ll bit(ll p){return (1 << p);}

void dfs(ll u, ll p, ll w, ll d){ //Função que calcula o LCA junto com a soma das distancias
    
    table[u][0] = w;
    lca[u][0] = p;
    nivel[u] = d;
    for(int i = 1; i <= k; i++){ //Calcula o LCA de `u` para todos alcançaveis em até 2^i passos
      lca[u][i] = lca[ lca[u][i-1] ][i-1];
      table[u][i] = table[u][i-1] + table[ lca[u][i-1] ][i-1];
    }
  
    for(int i = 0; i < (int)adj[u].size(); i++){
        int v = adj[u][i].first, ww = adj[u][i].second;
        if(v != p){
            dfs(v, u, ww, d+1);
        }
    }
}

ll query(ll l, ll r){ //Faz a pesquisa
    if(nivel[l] < nivel[r]){
        swap(l, r);
    }
    
    ll diff = nivel[l] - nivel[r];
    ll res = 0;
    for(ll i = k; i >= 0; i--){ //Se houver diferença de nivel entre os caras, procura nos bits da diferença
                                //quais os saltos necessários para para chegar no mesmo nivel do outro
        if(diff & bit(i)){
            //printf("subindo %d por %d\n", l, i);
            res += table[l][i];
            l = lca[l][i];
        }
    }
    
    if(l == r){ //Se são o mesmo cara, então retorne a soma acumulada até o momento
        return res;
    }
    for(ll i = k; i >= 0; i--){ //Caso contrario vai subindo na arvore em 2^i passos e verificando quando os LCA
                                //de `l` e `r` serão o mesmo
        if(lca[l][i] != lca[r][i]){
            res += table[l][i] + table[r][i];
            l = lca[l][i];
            r = lca[r][i];
        }
    }
    return res + table[l][0] + table[r][0]; //Retorna a soma para ir para o pai de `l` e `r`
    
}

int main() {
    ll n;
    while(cin >> n, n != 0){
        adj.assign(n+5, vii());
        for(int i = 1; i <= n-1; i++){
            ll v,w; scanf("%lld %lld", &v, &w);
            adj[i].push_back(ii(v,w));
            adj[v].push_back(ii(i,w));
        }

        int q; cin >> q;
        vector<ll> res;

        dfs(0,0,0,0);
      
        for(int i = 0; i < q; i++){
            ll u,v; scanf("%lld %lld", &u, &v);
            res.push_back(query(u,v));
        }
        for(int i = 0; i < (int)res.size(); i++){
            if(i == res.size()-1) printf("%lld\n", res[i]);
            else printf("%lld ", res[i]);
        }
    }
    return 0;
}
