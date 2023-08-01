#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  
  vector<int> p(n + 1), ofs(n + 1), cf(n + 1);
  for(int i = 1; i <= n; i++) p[i] = i;
  const function<int(int)> f = [&](int x) {
    if(x == p[x]) return x;
    int r = f(p[x]);
    ofs[x] += ofs[p[x]];
    return p[x] = r;
  };
  while(q--) {
    int t, i, j;
    cin >> t >> i >> j;
    if(t == 1) {
      int d;
      cin >> d;
      int ri = f(i), rj = f(j);
      if(ri == rj) {
        if(ofs[i] - ofs[j] != d) cf[ri] = 1;
      }
      else {
        p[rj] = ri;
        if(cf[rj]) cf[ri] = 1;
        else ofs[rj] = -d + ofs[i] - ofs[j];
      }
    }
    else {
      int ri = f(i), rj = f(j);
      if(ri == rj) {
        if(cf[ri]) cout << "CF\n";
        else cout << (ofs[i] - ofs[j]) << '\n'; 
      }
      else cout << "NC\n";
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  for(int ctc = 1; ctc <= tc; ctc++) {
    cout << "Case #" << ctc << "\n";
    solve();
  }
  
  return 0;
}