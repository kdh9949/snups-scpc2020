#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vint> e(n);
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }

  vint q(n);
  auto eval = [&](vint &p) {
    for(int i = 0; i < n; i++) q[p[i]] = i;
    int ret = 0;
    for(int i = 0; i < n; i++) {
      for(int j : e[i]) {
        if(i < j) ret += abs(q[i] - q[j]);
      }
    }
    return ret;
  };

  int ans = int(1e9);
  vint av, p, chk(n), cur;
  mt19937 mt(9949 * n + m);
  uniform_int_distribution<int> rnd(0, n - 1);

  for(int st = 0; st < n * 20; st++) {
    p.clear();
    fill(all(chk), 0);  
    p.push_back(st % n);
    chk[st % n] = 1;

    for(int t = n - 1; t--; ) {
      int mx = -n;
      vint cur;
      for(int i = 0; i < n; i++) {
        if(chk[i]) continue;
        int cnt = 0;
        for(int j : e[i]) cnt += (2 * chk[j] - 1);
        if(mx <= cnt) {
          if(mx < cnt) cur.clear();
          mx = cnt;
          cur.push_back(i);
        }
      }
      shuffle(all(cur), mt);
      p.push_back(cur[0]);
      chk[cur[0]] = 1;
    }

    int t = eval(p);
    if(ans > t) {
      ans = t;
      av = p;
    }
  }
    
  int tt = 2000;
  while(tt--) {
    int x, y;
    do {
      x = rnd(mt);
      y = rnd(mt);
    } while(x == y);

    swap(av[x], av[y]);
    int t = eval(av);
    if(ans > t) ans = t;
    else swap(av[x], av[y]);
  }

  cout << ans << '\n';
  for(int i = 0; i < n; i++) cout << av[i] << " \n"[i == n - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}