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
  ll L, R;
  int n;
  cin >> L >> R >> n;
  L *= 2;
  R *= 2;

  vpll a(n);
  for(pll &p : a) {
    cin >> p.x >> p.y;
    p.x *= 2;
    p.y *= 2;
  }
  sort(all(a));

  auto f = [&](ll x) {
    vll v;
    v.push_back(L - x);
    for(pll &p : a) {
      if(abs(p.y) >= x || p.x < L - x || p.x > R + x) continue;
      v.push_back(p.x);
    }
    v.push_back(R + x);

    for(int i = 0; i + 1 < v.size(); i++) {
      if(v[i + 1] - v[i] >= 2 * x) return true;
    }
    return false;
  };

  ll l = 0, r = ll(1e13);
  while(l < r) {
    ll m = (l + r + 1) / 2;
    if(f(m)) l = m;
    else r = m - 1;
  }
  cout << l << '\n';
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