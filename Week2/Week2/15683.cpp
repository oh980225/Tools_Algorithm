//#include <iostream>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//int board[10][10];
//int tmp[10][10];
//int N, M;
//int ans = 1e9;
//int dx[] = { 0, -1, 0, 1 };
//int dy[] = { -1, 0, 1, 0 };
//vector<vector<int>> dr = { {}, {0}, {0, 2}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3} };
//vector<int> pick;
//
//struct CAMERA {
//    int x, y, p;
//};
//
//vector<CAMERA> seq;
//
//void check() {
//    for (int i = 0; i < pick.size(); i++) {
//        int sx = seq[i].x;
//        int sy = seq[i].y;
//        int p = seq[i].p;
//
//        for (int j = 0; j < dr[p].size(); j++) {
//            int r = (dr[p][j] + pick[i]) % 4;
//            int nx = sx + dx[r];
//            int ny = sy + dy[r];
//            while (0 <= nx && nx < N && 0 <= ny && ny < M) {
//                if (tmp[nx][ny] == 6) break;
//                else if (tmp[nx][ny] == 0) tmp[nx][ny] = '#';
//                nx += dx[r];
//                ny += dy[r];
//            }
//        }
//    }
//    int cnt = 0;
//    for (int i = 0; i < N; ++i)
//        for (int j = 0; j < M; ++j)
//            if (tmp[i][j] == 0) ++cnt;
//    ans = min(ans, cnt);
//}
//
//void go(int toPick) {
//    if (toPick == 0) {
//        memcpy(tmp, board, sizeof(tmp));
//        check();
//        return;
//    }
//    for (int i = 0; i < 4; ++i) {
//        pick.push_back(i);
//        go(toPick - 1);
//        pick.pop_back();
//    }
//}
//
//int main() {
//    cin >> N >> M;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cin >> board[i][j];
//            if (board[i][j] && board[i][j] != 6) {
//                seq.push_back({ i, j, board[i][j] });
//            }
//        }
//    }
//    go(seq.size());
//
//    cout << ans;
//    return 0;
//}