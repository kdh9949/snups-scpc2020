#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define x first
#define y second

void solve() {
  ll k;
  cin >> k;
  vector<pair<ll, ll>> ofs = {
    {k, 0}, {2 * k, 0}, {0, k}, {0, 2 * k},
    {k, 3 * k}, {2 * k, 3 * k}, {3 * k, k}, {3 * k, 2 * k}};
  sort(ofs.begin(), ofs.end());
  vector<pair<ll, ll>> p(8);
  for(int i = 0; i < 8; i++) {
    ll x, y;
    cin >> x >> y;
    p[i] = {x, y};
  }
  
  ll ans = ll(1e18);
  ll xs[8], ys[8];
  do {
    auto a = p;
    for(int i = 0; i < 8; i++) { a[i].x -= ofs[i].x; a[i].y -= ofs[i].y; }
    for(int i = 0; i < 8; i++) { xs[i] = a[i].x; ys[i] = a[i].y; }
    sort(xs, xs + 8);
    sort(ys, ys + 8);
    ll cur = 0;
    for(int i = 0; i < 8; i++) { cur += abs(a[i].x - xs[3]) + abs(a[i].y - ys[3]); }
    ans = min(ans, cur);
  } while(next_permutation(ofs.begin(), ofs.end()));
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }
    
  return 0;
}