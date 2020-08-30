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
  int n, k;
  cin >> n >> k;

  vpii a(n);
  for(pii &p : a) {
    cin >> p.x >> p.y;
    p.x *= 2;
    p.y *= 2;
  }
  vint b(k);
  for(int &x : b) {
    cin >> x;
    x *= 2;
  }
  sort(all(b), greater<int>());

  auto f = [&](int x) {
    vint xs, ys;
    for(pii &p : a) {
      xs.push_back(p.x + p.y);
      ys.push_back(p.x - p.y);
      for(int &u : b) {
        xs.push_back(p.x + p.y + u);
        xs.push_back(p.x + p.y - u);
        ys.push_back(p.x - p.y + u);
        ys.push_back(p.x - p.y - u);
      }
    }
    sort(all(xs));
    sort(all(ys));
    xs.erase(unique(all(xs)), xs.end());
    ys.erase(unique(all(ys)), ys.end());

    vint v(n);
    for(int A : xs) {
      for(int B : ys) {
        int X = (A + B) / 2, Y = (A - B) / 2 - x;
        int valid = 1;
        for(int i = 0; i < n; i++) {
          v[i] = abs(a[i].x - X) + abs(a[i].y - Y);
          if(v[i] > x) { valid = 0; break; }
        }
        if(!valid) continue;
        sort(all(v));
        for(int i = 0; i < n; i++) {
          if(v[i] + (i < k ? b[i] : 0) > x) { valid = 0; break; }
        }
        if(valid) return 1;
      }
    }

    return 0;
  };

  int l = 0, r = int(1e9);
  while(l < r) {
    int m = (l + r) / 2;
    if(f(m)) r = m;
    else l = m + 1;
  }

  cout << (l / 2) << '.' << (l % 2 * 5) << '\n';
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