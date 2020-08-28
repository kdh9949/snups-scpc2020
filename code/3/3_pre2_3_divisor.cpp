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

const int N = 1000005;
vector<vint> dv(N);

void solve() {
  int n, q;
  cin >> n >> q;

  vint a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  vector<vpii> qv(n + 1);
  for(int i = 0; i < q; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    qv[z].emplace_back(y, x);
  }

  vint lst(N);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int d : dv[a[i]]) lst[d] = i;
    for(pii &p : qv[i]) {
      for(int d : dv[p.y]) if(lst[d] < p.x) ans++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 1; i < N; i++) {
    for(int j = i; j < N; j += i) dv[j].push_back(i);
  }

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}