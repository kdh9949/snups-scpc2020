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

  vector<vpii> e(n + 1);
  for(int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    e[x].emplace_back(y, z);
    e[y].emplace_back(x, z);
  }

  vector<int> d(n + 1), ind(n + 1), chk(n + 1, 0);
  for(int st = 1; st <= n; st++) {
    fill(all(d), int(1e9));
    d[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, st);
    
    while(!pq.empty()) {
      pii c = pq.top();
      pq.pop();
      if(c.x != d[c.y]) continue;

      for(pii i : e[c.y]) {
        if(d[i.x] > c.x + i.y) {
          d[i.x] = c.x + i.y;
          pq.emplace(d[i.x], i.x);
        }
      }
    }
    
    fill(all(ind), 0);
    for(int i = 1; i <= n; i++) {
      for(pii j : e[i]) if(d[j.x] == d[i] + j.y) ind[j.x]++;
    }
    for(int i = 1; i <= n; i++) {
      if(i == st) continue;
      for(pii j : e[i]) {
        if(d[j.x] == d[i] + j.y && ind[j.x] == 1) {
          chk[i] = 1;
          break;
        }
      }
    }
  }

  cout << count(all(chk), 1);
  for(int i = 1; i <= n; i++) if(chk[i]) cout << ' ' << i;
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << "\n";
    solve();
  }

  return 0;
}
