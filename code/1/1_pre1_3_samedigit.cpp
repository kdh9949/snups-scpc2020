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
  cin >> n;

  int ans = n + 1;

  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      if(i <= n / i - 2) ans = min(ans, n / i - 1);
    }
  }

  for(int b = 2; b * b + b + 1 <= n; b++) {
    int valid = 1;
    int digit = n % b;
    int m = n;
    while(m) {
      if(m % b != digit){ valid = 0; break; }
      m /= b;
    }
    if(valid) ans = min(ans, b);
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << "\n";
    solve();
  }

  return 0;
}
