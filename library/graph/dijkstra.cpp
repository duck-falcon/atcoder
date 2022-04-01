// dijkstra

struct weight {
  int to,cost;
};

vector<vector<weight>> g;
vi d;

void dijkstra(int s) {
  d.at(s) = 0;
  priority_queue<P,vector<P>,greater<P>> que;
  que.push(P(0,s));
  while(que.size()) {
    P p = que.top();que.pop();
    int nowd = p.fi;
    int edgeNum = p.se;
    if(d.at(edgeNum) < nowd) continue;
    rep(i,g.at(edgeNum).size()) {
      weight w = g.at(edgeNum).at(i);
      if(d.at(w.to) > nowd + w.cost) {
        d.at(w.to) = nowd + w.cost;
        que.push(P(d.at(w.to),w.to));
      }
    }
  }
}

const int INF = 1001001001;
int main() {
  int n,m;cin >> n >> m;

  g = vector<vector<weight>>(n,vector<weight>());
  rep(i,m) {
    int a,b,t;
    cin >> a >> b >> t;
    a--;b--;
    g.at(a).eb(weight{b,t});
    g.at(b).eb(weight{a,t});
  }
  int ans = 0;
  rep(i,n) {
    d = vi(n,INF);
    dijkstra(i);
    rep(j,d.size()) if(d.at(j) != INF) ans = max(ans,d.at(j));
  }
  cout << ans << endl;

  return 0;
}
