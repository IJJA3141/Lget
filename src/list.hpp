#ifndef LIST
#define LIST

#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct List {
  std::string name;
  std::string path;
  std::vector<std::pair<std::string, std::string>> vpNQ;

  friend std::ostream& operator<<(std::ostream&, const List& _list);
};

#endif // !LIST
