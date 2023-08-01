#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> e(n + 1);
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
  }
  vector<int> vis(n + 1);
  function<void(int)> f = [&](int x) {
    vis[x] = 1;
    for(int i : e[x]) if(!vis[i]) f(i);
  };
  for(int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    fill(vis.begin(), vis.end(), 0);
    f(y);
    if(vis[x]) { cout << '1'; e[y].push_back(x); }
    else { cout << '0'; e[x].push_back(y); }
  }
  cout << '\n';
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