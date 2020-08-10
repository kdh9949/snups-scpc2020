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

  vector<set<int>> e(n + 1);
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    e[x].insert(y);
    e[y].insert(x);
  }

  queue<int> q;
  for(int i = 1; i <= n; i++) if(e[i].size() == 2) q.push(i);

  int ans = n;
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    
    if(e[x].size() < 2) continue;
    int y = *e[x].begin();
    int z = *e[x].rbegin();
    if(!e[y].count(z)) continue;

    ans--;
    e[y].erase(x);
    e[z].erase(x);
    if(e[y].size() == 2) q.push(y);
    if(e[z].size() == 2) q.push(z);
    e[x].clear();
  }
  cout << ans << '\n';
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