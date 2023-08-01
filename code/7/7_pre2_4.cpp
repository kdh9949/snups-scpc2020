#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2000005, M = 505, K = 26, T = 30005;

string s, p;
int pos[K], a[N], b[M];

struct Node {
  Node *nx[M], *f;
  int dep, w;
} na[T];
int ncnt;
Node* newnode(int d) {
  memset(na[ncnt].nx, 0, sizeof na[ncnt].nx);
  na[ncnt].f = 0;
  na[ncnt].w = 0;
  na[ncnt].dep = d;
  return (na + ncnt++);
}

void calc(string &s, int a[]) {
  int n = s.length();
  for(int i = 0; i < K; i++) pos[i] = n;
  for(int i = n - 1; i >= 0; i--) {
    int c = s[i] - 'a';
    a[i] = pos[c] - i;
    pos[c] = i;
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  cin >> s;
  calc(s, a);
  reverse(a, a + n);
  
  ncnt = 0;
  newnode(1);
  for(int ord = 1; ord <= k; ord++) {
    cin >> p;
    int m = p.length();
    calc(p, b);
    reverse(b, b + m);
    Node* cur = na;
    for(int i = 0; i < m; i++) {
      if(!cur->nx[b[i]]) cur->nx[b[i]] = newnode(i + 2);
      cur = cur->nx[b[i]];
    }
    cur->w += ord;
  }
  
  queue<Node*> q;
  na->nx[1]->f = na;
  q.push(na->nx[1]);
  while(!q.empty()) {
    Node* cur = q.front();
    q.pop();
    cur->w += cur->f->w;
    for(int i = 1; i <= cur->dep; i++) if(cur->nx[i]) {
      Node* t = cur->nx[i];
      t->f = cur->f;
      while(t->f != na && !t->f->nx[min(t->f->dep, i)]) t->f = t->f->f;
      if(t->f->nx[min(t->f->dep, i)]) t->f = t->f->nx[min(t->f->dep, i)];
      q.push(t);
    }
  }
  
  ll ans = 0;
  Node *cur = na;
  for(int i = 0; i < n; i++) {
    while(cur != na && !cur->nx[min(cur->dep, a[i])]) cur = cur->f;
    if(cur->nx[min(cur->dep, a[i])]) cur = cur->nx[min(cur->dep, a[i])];
    ans += cur->w;
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