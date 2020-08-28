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
  int n;
  cin >> n; cin >> n; cin >> n;
  vector<pair<pii, pii>> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i].x.x >> a[i].x.y >> a[i].y.x >> a[i].y.y;
    a[i].y.x *= -1;
    a[i].y.y *= -1;
  }
  sort(all(a));
  for(int i = 0; i < n; i++) {
    a[i].y.x *= -1;
    a[i].y.y *= -1;
  }

  vint d(n);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    d[i] = 1;
    for(int j = 0; j < i; j++) {
      if(
        a[j].x.x <= a[i].x.x
        && a[j].x.y <= a[i].x.y
        && a[i].y.x <= a[j].y.x
        && a[i].y.y <= a[j].y.y
      ) {
        d[i] = max(d[i], d[j] + 1);
      }
    }
    ans = max(ans, d[i]);
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