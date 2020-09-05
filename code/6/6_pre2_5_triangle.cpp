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

const int N = 605;
pll a[N];
int n, can[N][N], d[N][N];

int ccw(const pll &a, const pll &b, const pll &c) {
  ll t = (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
  return (t > 0) - (t < 0);
};

bool f(int x) {
  for(int i = 0; i < 2 * n; i++) fill(d[i], d[i] + 2 * n, 0);

  for(int t = 2; t < n; t++) {
    for(int i = 0, j = t; j < 2 * n; i++, j++) {
      d[i][j] = x + 1;
      for(int k = i + 1; k < j; k++) {
        if(!can[i][k] || !can[k][j]) continue;
        if(d[i][k] + d[k][j] > x) continue;
        d[i][j] = min(d[i][j], max(d[i][k], d[k][j]) + 1);
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = i + 2; j < n + i; j++) {
      if(!can[i + 1][j] || !can[j][n + i]) continue;
      if(d[i + 1][j] + d[j][n + i] <= x) return true;
    }
  }
  return false;
}

void solve() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    a[n + i] = a[i];
  }

  for(int i = 0; i < 2 * n; i++) for(int j = i + 1; j < n + i && j < 2 * n; j++) {
    int val = 1;
    for(int k = 0; k < n; k++) {
      if(ccw(a[i], a[j], a[k]) * ccw(a[i], a[j], a[k + 1]) < 0
      && ccw(a[k], a[k + 1], a[i]) * ccw(a[k], a[k + 1], a[j]) < 0) {
        val = 0;
        break;
      }
    }
    if(val) {
      ll area = a[i].x * a[j].y - a[j].x * a[i].y;
      for(int k = i; k < j; k++) {
        area += a[k + 1].x * a[k].y - a[k].x * a[k + 1].y;
      }
      val &= (area <= 0);
      
      int ni = j, nj = i + n;
      if(nj >= 2 * n) { ni -= n; nj -= n; }
      area = a[ni].x * a[nj].y - a[nj].x * a[ni].y;
      for(int k = ni; k < nj; k++) {
        area += a[k + 1].x * a[k].y - a[k].x * a[k + 1].y;  
      }
      val &= (area <= 0);
    }
    can[i][j] = val;
  }

  int l = 0, r = n - 1;
  while(l < r) {
    int m = (l + r) / 2;
    if(f(m)) r = m;
    else l = m + 1;
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