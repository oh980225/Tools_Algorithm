#include <string>
#include <vector>

using namespace std;

void convertToLower(string& str) {
  for(int i = 0; i < str.size(); i++) {
    str[i] = tolower(str[i]);
  }
}

void removeInvalidElement(string& str) {
  for(int i = 0; i < str.size(); i++) {
    if(('a' <= str[i] && str[i] <= 'z') || ('0' <= str[i] && str[i] <= '9') || str[i] == '-' || str[i] == '_' || str[i] == '.') {
      continue;
    }

    str.erase(str.begin() + i);
    i--;
  }
}

void removeContinuousDot(string& str) {
  char pre = str[0];
  for(int i = 1; i < str.size(); i++) {
    if(str[i] == '.' && pre == str[i]) {
      str.erase(str.begin() + i);
      i--;
      continue;
    }

    pre = str[i];
  }
}

void removeFrontEndDot(string& str) {
  if(str[0] == '.') {
    str.erase(str.begin());
  }

  if(str[str.size() - 1] == '.') {
    str.erase(str.begin() + str.size() - 1);
  }
}

void checkEmpty(string& str) {
  if(!str.size()) {
    str.push_back('a');
  }
}

void checkTooLong(string& str) {
  while(str.size() > 15) {
    str.erase(str.begin() + str.size() - 1);
  }

  removeFrontEndDot(str);
}

void checkTooShort(string& str) {
  while(str.size() < 3) {
    str.push_back(str[str.size() - 1]);
  }
}

string recommandId(string id) {
  convertToLower(id);

  removeInvalidElement(id);

  removeContinuousDot(id);

  removeFrontEndDot(id);

  checkEmpty(id);

  checkTooLong(id);

  checkTooShort(id);

  return id;
}

string solution(string new_id) {
  return recommandId(new_id);
}