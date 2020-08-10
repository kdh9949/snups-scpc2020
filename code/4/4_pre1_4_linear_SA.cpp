#include <bits/stdc++.h>
using namespace std;

const int N = 100, T = 1500000;
const double TMP = 10000, DEC = 0.999988;
vector<int> e[N];
int n, m, a[N], p[N], v[N], cp[N], r, c;

void f(int x){
    cp[x] = c++;
    v[x] = 1;
    for(int i : e[x]) if(!v[i]) f(i);
}

int main(){ srand(9949); int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++){
    scanf("%d%d", &n, &m);
    r = n * m;
    for(int i = 0; i < n; i++) e[i].clear();
    for(int x, y; m--; ){
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i = 0; i < n; i++){
        fill(v, v + n, 0);
        c = 0;
        f(i);
        int cr = 0;
        for(int j = 0; j < n; j++){
            for(int k : e[j]){
                if(k > j){
                    cr += abs(cp[k] - cp[j]);
                }
            }
        }
        if(cr < r){
            r = cr;
            for(int j = 0; j < n; j++) p[j] = cp[j];
        }
    }
    double tmp = TMP * (n - 1);
    for(int i = 0; i < T; i++){
        int x, y;
        do{
            x = rand() % n;
            y = rand() % n;
        } while(x == y);
        int cr = r;
        for(int j : e[x]) if(j != y) cr += abs(p[j] - p[y]) - abs(p[j] - p[x]);
        for(int j : e[y]) if(j != x) cr += abs(p[j] - p[x]) - abs(p[j] - p[y]);
        if(1.0 * rand() / RAND_MAX < exp((r - cr) / tmp)){
            r = cr;
            swap(p[x], p[y]);
        }
        tmp *= DEC;
    }
    printf("Case #%d\n%d\n", tt, r);
    for(int i = 0; i < n; i++) a[p[i]] = i;
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
}}