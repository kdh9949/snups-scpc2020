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
    ints(n, m, k);
    vector<vpii> e(9 * n);
    const auto node = [&](int x, int c, int v) { return 9 * (x - 1) + 3 * c + v; };
    while(m--) {
      ints(x, y);
      char c; cin >> c; c -= 'A';
      for(int i = 0; i < 3; i++) {
        for(int j = 0; j <= max(0, k); j++) {
          if(c == (i + 1) % 3) e[node(x, i, j)].emplace_back(node(y, c, j), 1);
          if(k < 0) e[node(x, i, j)].emplace_back(node(y, i, j), 0);
          if(k >= 0 && j < k) e[node(x, i, j)].emplace_back(node(y, i, j + 1), 0);
        }
      }
    }
    vector<vint> re(9 * n);
    for(int i = 0; i < 9 * n; i++) for(pii j : e[i]) re[j.x].push_back(i);
    vint v(9 * n), post;
    const function<void(int)> f = [&](int x) {
      v[x] = 1;
      for(pii i : e[x]) if(!v[i.x]) f(i.x);
      post.push_back(x);
    };
    for(int i = 0; i < 9 * n; i++) if(!v[i]) f(i);
    fill(all(v), 0);
    int cnt = 0;
    vector<vint> lst(1);
    reverse(all(post));
    const function<void(int)> rf = [&](int x) {
      v[x] = cnt;
      lst[cnt].push_back(x);
      for(int i : re[x]) if(!v[i]) rf(i);
    };
    for(int x : post) if(!v[x]) { cnt++; lst.emplace_back(); rf(x); }

    vint d(cnt + 1);
    for(int i = cnt; i >= 1; i--) {
      for(int x : lst[i]) {
        for(pii j : e[x]) {
          if(v[j.x] == v[x]) {
            if(j.y) { d[i] = -1; break; }
          }
          else {
            d[i] = (d[v[j.x]] < 0 ? -1 : max(d[i], d[v[j.x]] + j.y));
            if(d[i] < 0) break;
          }
        }
        if(d[i] < 0) break;
      }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < 3; j++) {
        ans = (d[v[node(i, j, 0)]] < 0 ? -1 : max(d[v[node(i, j, 0)]], ans));
        if(ans < 0) break;
      }
      if(ans < 0) break;
    }
    cout << ans << '\n';
  };

  ints(tc);
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}