#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ArcP;//first = final, second = pes
typedef vector< vector<ArcP> > GrafP; // graf amb pesos

#define INF 999999

void dijkstra(const GrafP& G, int s, vector<int>& d, vector<int>& p) {
	int n = G.size();
	d = vector<int>(n, INF);
	d[s] = 0;
	p = vector<int>(n, -1);
	vector<bool> S(n, false);
	priority_queue<ArcP, vector<ArcP>, greater<ArcP> > Q;
	Q.push(ArcP(0, s));
	while (not Q.empty()) {
		int u = Q.top().second; Q.pop();
		if (not S[u]) {
			S[u] = true;
			for (int i = 0; i < G[u].size(); ++i) {
				int v = G[u][i].second;
				int c = G[u][i].first; 
				if (d[v] > d[u] + c) {
					d[v] = d[u] + c;
					p[v] = u;
					Q.push(ArcP(d[v], v));
				}
			}
		}
	}
}

int main() {
	int n,m; //n = number of vertices, m = number of arcs
	while(cin >> n >> m) {
		vector<int> d; //distance
		vector<int> p; //predecesor
		GrafP G(n);
		ArcP arc;
		int origen;
		for(int i = 0; i < m; ++i) {
			cin >> origen >> arc.second >> arc.first;
			G[origen].push_back(arc);
		}
		int inici, fi;
		cin >> inici >> fi;
		dijkstra(G,inici,d,p);
		if(p[fi] != -1) cout << d[fi] << endl;
		else if(inici == fi) cout << 0 << endl;
		else cout << "no path from " << inici << " to " << fi << endl;
	}
}
