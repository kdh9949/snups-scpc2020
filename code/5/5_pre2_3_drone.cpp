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
  int l, s, e;
  cin >> l >> s >> e;

  int a;
  cin >> a;
  vint ax(a + 1), ah(a), tx(1);
  for(int i = 0; i < a; i++) {
    cin >> ax[i + 1] >> ah[i];
    ax[i + 1] += ax[i];  
    tx.push_back(ax[i + 1]);
  }
  int b;
  cin >> b;
  vint bx(b + 1), bh(b);
  for(int i = 0; i < b; i++) {
    cin >> bx[i + 1] >> bh[i];
    bx[i + 1] += bx[i];
    tx.push_back(bx[i + 1]);
  }
  sort(all(tx));
  tx.erase(unique(all(tx)), tx.end());

  int n = int(tx.size()) - 1;
  vint lh(n), uh(n);
  for(int i = 0, ap = 0, bp = 0; i < n; i++) {
    if(ap < a - 1 && ax[ap + 1] <= tx[i]) ap++;
    if(bp < b - 1 && bx[bp + 1] <= tx[i]) bp++;
    uh[i] = ah[ap];
    lh[i] = bh[bp];
  }

  vint lpath(n), rpath(n);
  for(int i = 0, h = s; i < n; i++) {
    h = max(lh[i], min(uh[i], h));
    lpath[i] = h;
  }
  for(int i = n - 1, h = e; i >= 0; i--) {
    h = max(lh[i], min(uh[i], h));
    rpath[i] = h;
  }
  
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans += ll(tx[i + 1] - tx[i]) * abs(rpath[i] - lpath[i]);
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