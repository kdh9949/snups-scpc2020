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

const int N = 10005;
vint pal, pchk(N);

void solve() {
  int n;
  cin >> n;

  if(pchk[n]) {
    cout << "1 " << n << '\n';
    return;
  }

  for(int x : pal) {
    if(x < n && pchk[n - x]) {
      cout << "2 " << max(x, n - x) << ' ' << min(x, n - x) << '\n';
      return;
    }
  }

  for(int x : pal) {
    for(int y : pal) {
      if(x + y < n && pchk[n - x - y]) {
        vint v = {x, y, n - x - y};
        sort(all(v));
        cout << "3 " << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
        return;
      }
    }
  }

  cout << "0\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 1; i < N; i++) {
    string s = to_string(i);
    string t = s;
    reverse(all(t));
    if(s == t) {
      pal.push_back(i);
      pchk[i] = 1;
    }
  }

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}