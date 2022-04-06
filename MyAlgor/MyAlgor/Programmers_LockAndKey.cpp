#include <string>
#include <vector>

using namespace std;
// 홈을 1, 돌기를 2로!
int matrix[100][100];
int keyMatrix[21][21][4];

void makeRotationKey(vector<vector<int>> &key) {
  // 원본
  for(int i = 0; i < key.size(); i++) {
    for(int j = 0; j < key.size(); j++) {
      keyMatrix[i][j][0] = key[i][j];
    }
  }

  // 90도
  for(int i = 0; i < key.size(); i++) {
    for(int j = 0; j < key.size(); j++) {
      keyMatrix[i][j][1] = keyMatrix[key.size() - j - 1][i][0];
    }
  }

  // 180도
  for(int i = 0; i < key.size(); i++) {
    for(int j = 0; j < key.size(); j++) {
      keyMatrix[i][j][2] = keyMatrix[key.size() - j - 1][i][1];
    }
  }

  // 270도
  for(int i = 0; i < key.size(); i++) {
    for(int j = 0; j < key.size(); j++) {
      keyMatrix[i][j][3] = keyMatrix[key.size() - j - 1][i][2];
    }
  }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
  int keySize = key.size();
  int lockSize = lock.size();
  int totalFitCount = 0;

  for(int i = 0; i < lock.size(); i++) {
    for(int j = 0; j < lock[0].size(); j++) {
      if(!lock[i][j]) {
        totalFitCount++;
      }

      matrix[i + lockSize][j + lockSize] = lock[i][j] + 1;
    }
  }

  makeRotationKey(key);

  int start = lockSize - keySize + 1;

  for(int i = start; i < 2 * lockSize; i++) {
    for(int j = start; j < 2 * lockSize; j++) {

      // 4방향으로!
      for(int x = 0; x < 4; x++) {
        bool flag = false;
        int fitCount = 0;

        // Key 끼워보기
        for(int k = i; k < i + keySize; k++) {
          for(int z = j; z < j + keySize; z++) {
            // 돌기끼리 만난다면!
            if(matrix[k][z] == 2 && keyMatrix[k - i][z - j][x] == 1) {
              flag = true;
              break;
            }

            // 홈에 돌기가 맞았다면!
            if(matrix[k][z] == 1 && keyMatrix[k - i][z - j][x] == 1) {
              fitCount++;
            }
          }

          // 조건에 부합하지 않는다면!
          if(flag) {
            break;
          }
        }

        if(totalFitCount == fitCount) {
          return true;
        }
      }
    }
  }

  return false;
}