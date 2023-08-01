#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> eb, ob, b;
  ll ans = 0, wtf = 0;
  for(int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<ll> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ans += a[0] + a[1] + a[2] + a[3];
    wtf += a[0] + a[1] + a[2] + a[3];
    if(k & 1) { ans += a[0]; wtf += a[0]; ob.push_back(a[2] + a[3]); }
    else { wtf += a[0] + a[1]; eb.push_back(a[2] + a[3]); }
    b.push_back(a[2] + a[3]);
  }
  sort(b.begin(), b.end(), greater<ll>());
  sort(ob.begin(), ob.end(), greater<ll>());
  sort(eb.begin(), eb.end(), greater<ll>());
  if(ob.size() == 2 && eb.size() >= 1 && ob[1] > eb[0]) {
    ans -= ob[0] + eb[0];
    wtf -= ob[0] + ob[1];
  }
  else { ans -= b[0] + b[1]; }
  cout << min(ans, wtf) << '\n';
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