#include <string>
#include <vector>

using namespace std;
vector<int> ans;
int rightY;
int rightX;
int N;

void dfs(int y, int x) {
    if(y == rightY && x == rightX) {
        ans.push_back(max(y, x));
        return;
    }
    
    if(x > N) {
        dfs(y + 1, 1);
        return;
    }
    
    ans.push_back(max(y, x));
    dfs(y, x + 1);
    
    return;
}

vector<int> solution(int n, long long left, long long right) {
    N = n;
    rightY = right / n + 1;
    rightX = right % n + 1;
    
    int leftY = left / n + 1;
    int leftX = left % n + 1;
    
    dfs(leftY, leftX);
    
    return ans;
}