//#include <bits/stdc++.h>
//
//using namespace std;
//
//set<int> s;
//
//
//int main() {
//
//    s.insert(1);
//    s.insert(2);
//    s.insert(3);
//    s.insert(4);
//    s.insert(5);
//    s.insert(6);
//    s.insert(7);
//    s.insert(8);
//    s.insert(9);
//    s.insert(10);
//
//    auto itr = s.lower_bound(3);
//
//    while (itr != s.begin()) {
//        cout << *itr << endl;
//        itr--;
//    }
//    if (itr == s.begin()) {
//        cout << *itr << endl;
//    }
//
//    itr = s.lower_bound(3);
//
//    while (itr != s.end()) {
//        cout << *itr << endl;
//        itr++;
//    }
//
//	return 0;
//}