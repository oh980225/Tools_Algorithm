//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//struct EDGE {
//    ll from, to, w;
//};
//vector<EDGE> edges;
//const ll inf = 1e9;
//vector<ll> BellmanFord(int v, int st) {
//    vector<ll> res(v + 1);
//    fill(res.begin(), res.end(), inf);
//    res[st] = 0;
//    for (int i = 1; i <= v; ++i) {
//        for (int j = 0; j < edges.size(); ++j) {
//            ll s = edges[j].from, t = edges[j].to, w = edges[j].w;
//            if (res[s] != inf && res[t] > res[s] + w) {
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
//    edges.push_back({ 1, 2, -2 });
//    edges.push_back({ 1, 3, 3 });
//    edges.push_back({ 1, 4, -6 });
//    edges.push_back({ 2, 4, 3 });
//    edges.push_back({ 2, 6, 7 });
//    edges.push_back({ 3, 4, 1 });
//    edges.push_back({ 3, 5, 2 });
//    edges.push_back({ 4, 5, -3 });
//    edges.push_back({ 4, 6, -1 });
//    edges.push_back({ 5, 7, 5 });
//    edges.push_back({ 6, 7, 1 });
//
//	vector<ll> answer = BellmanFord(7, 1);
//
//	int i = 0;
//	for (auto element : answer) {
//        if (i == 0) {
//            i++;
//            continue;
//        }
//		cout << i++ << ": ";
//		cout << element << endl;
//	}
//
//	return 0;
//}