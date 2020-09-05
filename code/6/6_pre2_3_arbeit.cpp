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
  int n, k, q;
  cin >> n >> k >> q;

  vint a(n + 1), s(n + 2);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    s[max(k, i)] += a[i];
    s[min(n + 1, i + k)] -= a[i];
  }
  for(int i = k; i <= n; i++) s[i] += s[i - 1];

  struct Myset {
    int t;
    priority_queue<int> pq, epq;

    Myset(int t_) { t = t_; }

    void insert(int x) {
      pq.push(t * x);
    }

    void erase(int x) {
      epq.push(t * x);
    }

    int top() {
      while(!epq.empty() && pq.top() == epq.top()) {
        pq.pop();
        epq.pop();
      }
      return t * pq.top();
    }

    int size() {
      return int(pq.size()) - int(epq.size());
    }
  } l(1), r(-1);

  auto upd = [&](int x, int t) {
    if(!r.size() || x < r.top()) {
      if(t) l.insert(x);
      else l.erase(x);
    }
    else {
      if(t) r.insert(x);
      else r.erase(x);
    }
    while(r.size() > l.size() + 1) {
      l.insert(r.top());
      r.erase(r.top());
    }
    while(l.size() > r.size()) {
      r.insert(l.top());
      l.erase(l.top());
    }
  };

  for(int i = k; i <= n; i++) upd(s[i], 1);
  cout << r.top() << ' ';

  for(int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    for(int j = max(k, x); j <= min(n, x + k - 1); j++) {
      upd(s[j], 0);
      s[j] += (y - a[x]);
      upd(s[j], 1);
    }
    a[x] = y;
    cout << r.top() << " \n"[i == q - 1];
  }
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