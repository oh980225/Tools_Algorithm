#include <bits/stdc++.h>

using namespace std;

map<string, pair<int, int>> handsMap;

int distanceToLeftHand(int y, int x) {
  return abs(handsMap["left"].first - y) + abs(handsMap["left"].second - x);
}

int distanceToRightHand(int y, int x) {
  return abs(handsMap["right"].first - y) + abs(handsMap["right"].second - x);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    handsMap["left"] = {3, 0};
    handsMap["right"] = {3, 2};
    int leftDist = 0;
    int rightDist = 0;
    for(int number : numbers) {
      switch (number)
      {
      case 1:
        handsMap["left"] = {0, 0};
        answer += "L";
        break;

      case 2:
        leftDist = distanceToLeftHand(0, 1);
        rightDist = distanceToRightHand(0, 1);
        if(leftDist == rightDist) {
          handsMap[hand] = {0, 1};
          if(hand == "right") {
            answer += "R";
          }
          else {
            answer += "L";
          }
        }
        else if(leftDist > rightDist) {
          handsMap["right"] = {0, 1};
          answer += "R";
        }
        else {
          handsMap["left"] = {0, 1};
          answer += "L";
        }
        break;
      
      case 3:
        handsMap["right"] = {0, 2};
        answer += "R";
        break;
      
      case 4:
        handsMap["left"] = {1, 0};
        answer += "L";
        break;

      case 5:
        leftDist = distanceToLeftHand(1, 1);
        rightDist = distanceToRightHand(1, 1);
        if(leftDist == rightDist) {
          handsMap[hand] = {1, 1};
          if(hand == "right") {
            answer += "R";
          }
          else {
            answer += "L";
          }
        }
        else if(leftDist > rightDist) {
          handsMap["right"] = {1, 1};
          answer += "R";
        }
        else {
          handsMap["left"] = {1, 1};
          answer += "L";
        }
        break;

      case 6:
        handsMap["right"] = {1, 2};
        answer += "R";
        break;

      case 7:
        handsMap["left"] = {2, 0};
        answer += "L";
        break;

      case 8:
        leftDist = distanceToLeftHand(2, 1);
        rightDist = distanceToRightHand(2, 1);
        if(leftDist == rightDist) {
          handsMap[hand] = {2, 1};
          if(hand == "right") {
            answer += "R";
          }
          else {
            answer += "L";
          }
        }
        else if(leftDist > rightDist) {
          handsMap["right"] = {2, 1};
          answer += "R";
        }
        else {
          handsMap["left"] = {2, 1};
          answer += "L";
        }
        break;

      case 9:
        handsMap["right"] = {2, 2};
        answer += "R";
        break;

      case 0:
        leftDist = distanceToLeftHand(3, 1);
        rightDist = distanceToRightHand(3, 1);
        if(leftDist == rightDist) {
          handsMap[hand] = {3, 1};
          if(hand == "right") {
            answer += "R";
          }
          else {
            answer += "L";
          }
        }
        else if(leftDist > rightDist) {
          handsMap["right"] = {3, 1};
          answer += "R";
        }
        else {
          handsMap["left"] = {3, 1};
          answer += "L";
        }
        break;
      
      default:
        break;
      }
    }

    return answer;
}