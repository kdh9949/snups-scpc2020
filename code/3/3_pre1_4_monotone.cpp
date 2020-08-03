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

using event = pair<pll, int>;
pll operator-(const pll &a, const pll &b){ return pll(a.x - b.x, a.y - b.y); }
const pll O = pll(0, 0);
const pll S = pll(1, -ll(1e9));

void solve() {
  int n;
  cin >> n;

  vpll v(n + 2);
  for(int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
  v[n] = v[0];
  v[n + 1] = v[1];

  auto ccw = [](pll a, pll b) {
    ll t = a.x * b.y - b.x * a.y;
    return (t > 0) - (t < 0);
  };

  vector<event> ev;
  for(int i = 1; i <= n; i++) {
    pll s = v[i + 1] - v[i];
    pll e = v[i] - v[i - 1];
    if(ccw(s, e) <= 0) continue;
    
    if(s < O) s = O - s;
    if(e < O) e = O - e;
    
    if(ccw(s, e) > 0) {
      ev.emplace_back(s, 1);
      if(e.x > 0) ev.emplace_back(e, -1);
    } else {
      ev.emplace_back(S, 1);
      ev.emplace_back(e, -1);
      ev.emplace_back(s, 1);
    }
  }

  sort(all(ev), [&](event a, event b){
    int t = ccw(a.x, b.x);
    if(t != 0) return t > 0;
    return a.y > b.y;
  });
  if(ev.empty() || ev[0].x != S) { cout << "YES\n"; return; }

  int c = 0;
  for(auto &x : ev) {
    c += x.y;
    if(!c){ cout << "YES\n"; return; }
  }
  cout << "NO\n";
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