#include <string>
#include <vector>

using namespace std;

int ansDis = 1e9;

void dfs(vector<int> result, vector<int> pos, int chk[21], int num, int cur, int size) {
    if (result.size() == pos.size()) {
        ansDis = min(ansDis, num);
        return;
    }
    for (int i = 0; i < pos.size(); i++) {
        if (!chk[i]) {
            chk[i]++;
            result.push_back(pos[i]);
            dfs(result, pos, chk, num + min(abs(cur - pos[i]), cur + size - pos[i] + 1), pos[i], size);
            result.pop_back();
            chk[i]--;
        }
    }
}

int solution(string name) {
    int answer = 0;
    int midIdx = (int)(name.size() / 2) - 1;
    int midAlph = 77;
    int chk[21] = { 0 };
    vector<int> pos;
    vector<int> result;
    for (int i = 0; i < name.size(); i++) {
        if (name[i] != 'A') {
            pos.push_back(i);
        }
    }
    dfs(result, pos, chk, 0, 0, name.size() - 1);
    for (int i = 0; i < name.size(); i++) {
        if (name[i] != 'A') {
            if ((int)name[i] > midAlph) {
                int gap = (int)name[i] - 65 + 1;
                answer += 26 - gap + 1;
            }
            else {
                int gap = (int)name[i] - 65;
                answer += gap;
            }
        }
    }

    answer += ansDis;
    return answer;
}

int main() {
    int ans = solution("JAZ");
    printf("%d", ans);
    return 0;
}