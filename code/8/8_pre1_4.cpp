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

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  auto solve = [&]() {
    ints(n, m);
    strs(s, t);
    if(t[0] == 'b') {
      for(char &c : s) c = 'a' + 'b' - c;
      for(char &c : t) c = 'a' + 'b' - c;
    }
    vint p[2];
    for(int i = 0; i < n; i++) p[s[i] - 'a'].push_back(i);
    
    int ac = p[0].size(), bc = p[1].size();
    int A = count(all(t), 'a'), B = count(all(t), 'b');
    if(A > ac || B > bc) {
      cout << "NO\n";
      return;
    }
    if(B == 0) {
      cout << (m <= ac ? "YES\n" : "NO\n");
      return;
    }

    int X = 0;
    while(t[X] == 'a') X++;
    int Y = 0;
    while(X + Y < m && t[X + Y] == 'b') Y++;
    if(X + Y == m) {
      cout << (p[0][X - 1] < p[1][bc - Y] ? "YES\n" : "NO\n");
      return;
    }

    vector<vint> sum(2, vint(n));
    for(int i = 0; i < n; i++) sum[s[i] - 'a'][i]++;
    for(int i = 0; i < 2; i++) for(int j = 1; j < n; j++) sum[i][j] += sum[i][j - 1];
    auto cnt = [&](int i, int s, int e) {
      return (e >= 0 ? sum[i][e] : 0) - (s ? sum[i][s - 1] : 0);
    };

    auto cmp = [&](int ss, int se, int ts, int te) {
      int len = se - ss + 1;
      for(int i = 0; i < len; i++) if(s[ss + i] != t[ts + i]) return 0;
      return 1;
    };

    int lA = X, rA = 0, rB = 0;
    while(rA < m && t[m - 1 - rA] == 'a') rA++;
    while(rB < m && t[m - 1 - rB] == 'b') rB++;
    auto chk = [&](int as, int ae, int bs, int be) {
      int cs = max(as, bs), ce = min(ae, be);
      int lc = cnt(0, as, cs - 1);
      if(lA < lc) return 0;
      if(ce < ae) { if(cnt(0, ce + 1, ae) > rA) return 0; }
      if(ce < be) { if(cnt(1, ce + 1, be) > rB) return 0; }
      if(cs <= ce && !cmp(cs, ce, lc, lc + ce - cs)) return 0;
      return 1;
    };

    for(int i = 0, bi = 0; i + A - 1 < ac; i++) {
      int as = p[0][i], ae = p[0][i + A - 1];
      int U = p[0][i + X - 1], V = p[0][i + X];
      if(Y > V - U - 1) continue;
      while(bi < bc && p[1][bi] < V - Y) bi++;
      if(bi + B - 1 >= bc) break;
      int bs = p[1][bi], be = p[1][bi + B - 1];
      if(chk(as, ae, bs, be)) { cout << "YES\n"; return; }
    }
    cout << "NO\n";
  };

  ints(tc);
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}