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
  int m, k;
  ll n;
  cin >> n >> m >> k;
  n *= 2;
  m++;

  vpll v(m);
  for(pll &p : v) {
    cin >> p.x >> p.y;
    p.x *= 2;
    p.y *= 2;
  }

  auto f = [&](ll x) {
    vpll w;
    for(int i = 0; i + 1 < m; i++) {
      pll lo = (v[i].y < v[i + 1].y ? v[i] : v[i + 1]);
      pll hi = (v[i].y < v[i + 1].y ? v[i + 1] : v[i]);
      if(lo.y > x) continue;
      
      pll cur;
      if(hi.y > x) cur = pll(v[i].x + abs(x - v[i].y), x);
      else cur = hi;
      w.emplace_back(cur.x - cur.y, cur.x + cur.y);
    }
    sort(all(w));

    ll lst = 0;
    int cnt = 0;
    for(int i = 0; i < w.size() && cnt < k; ) {
      ll mx = lst;
      while(i < w.size() && w[i].x <= lst) {
        mx = max(mx, w[i].y);
        i++;
      }
      if(mx == lst) return false;
      cnt++;
      lst = mx;
      if(lst >= n) return true;
    }
    return false;
  };

  ll l = 0, r = ll(3e12);
  while(l < r) {
    ll x = (l + r) / 2;
    if(f(x)) r = x;
    else l = x + 1;
  }

  if(l > ll(2e12)) { cout << "-1\n"; }
  else {
    int odd = l % 2;
    cout << (l / (2 - odd)) << ' ' << (1 + odd) << '\n';
  }
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