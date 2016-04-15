#include <iostream>
#include <string>
#include "list.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  list li;

  int n;
  cin >> n;

  for (int i = 0, data, pos; i < n; i++) {
    cin >> pos >> data;
    li.insert(pos, data);
  }

  cout << li.toString() << " size: " << li.size() << endl;

  list li2(li);
  list li3;

  li = li3 = li2 = li;

  cout << li.toString() << " size: " << li.size() << endl;
  cout << li2.toString() << " size: " << li2.size() << endl;
  cout << li3.toString() << " size: " << li3.size() << endl;

  int m;
  cin >> m;

  for (int i = 0, pos; i < m; i++) {
    cin >> pos;
    li.erase(pos);
  }

  cout << li.toString() << endl;

  cout << li.sort().toString() << endl;
  cout << li2.sort().toString() << endl;
  cout << li3.sort().toString() << endl;

  return 0;
}
