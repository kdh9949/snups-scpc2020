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
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

const int N = 2005;
int b[N][N];
ll s[N][N], d[N][N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  auto solve = [&]() {
    ints(n);
    for(int i = 1; i <= n; i++) {
      strs(t);
      for(int j = 1; j <= n; j++) {
        b[i][j] = (t[j - 1] == '#' ? 0 : 1);
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + b[i][j];
      }
    }

    auto sum = [&](int a, int b, int c, int d) {
      return s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1];
    };

    ll ans = s[n][n] * (s[n][n] - 1) / 2;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(!b[i][j]) continue;
        ans -= sum(i, j, n, n) - 1;
      }
    }
    auto f = [&]() {
      for(int i = 1; i <= n; i++) d[n][i] = d[i][n] = 0;
      for(int i = n - 1; i >= 1; i--) {
        for(int j = n - 1; j >= 1; j--) {
          if(!b[i][j]) continue;
          if(!b[i][j + 1]) d[i][j] = sum(i, j + 1, i, n) + d[i + 1][j];
          else d[i][j] = d[i][j + 1];
          ans += d[i][j];
        }
      }
    };
    f();
    for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++)
      { swap(b[i][j], b[j][i]); swap(s[i][j], s[j][i]); }
    f();
    cout << ans << '\n';
  };

  ints(tc);
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}