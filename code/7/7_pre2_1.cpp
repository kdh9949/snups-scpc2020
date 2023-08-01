#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  for(ll i = -n + 1, j = 0; i < n; i++) {
    while(i * i + j * j < n * n) j++;
    while(i * i + j * j >= n * n) j--;
    ans += 2 * j + 1;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }
    
  return 0;
}