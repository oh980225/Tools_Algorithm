#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string input, string separator)
{
  vector<string> result;

  int start = 0;
  int end = input.find(separator);
  while (end != string::npos)
  {
    result.push_back(input.substr(start, end - start));
    start = end + separator.length();
    end = input.find(separator, start);
  }
  result.push_back(input.substr(start, end));

  return result;
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string input;
  getline(cin, input);

  vector<string> result = split(input, ", ");
  for (string element : result)
  {
    cout << element << endl;
  }

  return 0;
}