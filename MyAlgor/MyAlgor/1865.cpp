//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//struct EDGE {
//	int from, to, w;
//};
//
//vector<EDGE> edges;
//
//vector<int> BellmanFord(int v) {
//    vector<int> res(v + 1);
//    for (int i = 1; i <= v; ++i) {
//        for (int j = 0; j < edges.size(); ++j) {
//            int s = edges[j].from, t = edges[j].to, w = edges[j].w;
//            if (res[t] > res[s] + w) {
//                if (i == v) {
//                    res[0] = -1;
//                    return res;
//                }
//                res[t] = res[s] + w;
//            }
//        }
//    }
//    return res;
//}
//
//int main() {
//	int tc;
//	scanf_s("%d", &tc);
//
//    for (int i = 0; i < tc; i++) {
//        int n, m, w;
//        bool flag = false;
//        scanf_s("%d %d %d", &n, &m, &w);
//
//        int s, e, t;
//        for (int j = 0; j < m; j++) {
//            scanf_s("%d %d %d", &s, &e, &t);
//            edges.push_back({ s, e, t });
//            edges.push_back({ e, s, t });
//        }
//        for (int j = 0; j < w; j++) {
//            scanf_s("%d %d %d", &s, &e, &t);
//            edges.push_back({ s, e, -t });
//        }
//        vector<int> result = BellmanFord(n);
//        if (result[0] == -1) {
//            printf("YES\n");
//        }
//        else {
//            printf("NO\n");
//        }
//
//        edges.clear();
//    }
//	return 0;
//}