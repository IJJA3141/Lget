#include "./fn.hpp"
#include <iostream>
#include <string>
#include <vector>

void add(Json::Value &_data, std::string _query, std::string _name,
         std::string _list, std::vector<std::string> &_vArgs, bool _help) {
  if (_help) {
    std::cout << "help message" << std::endl;
    exit(-1);
  }

  int i = 0;

  if (_query == "") {
    if (_vArgs.size() != 0) {
      _query = _vArgs[i++];
    } else {
      std::cout << "query: " << std::endl;
      std::cin >> _query;
    }
  }

  if (_name == "") {
    if (_vArgs.size() > i) {
      _name = _vArgs[i++];
    } else {
      std::cout << "name: " << std::endl;
      std::cin >> _name;
    }
  }

  if (_list == "default")
    if (_vArgs.size() > i)
      _list = _vArgs[i++];

  if (_vArgs.size() > i) {
    std::cout << "too mutch" << std::endl;
    std::cout << _vArgs.size() << "\n" << i << std::endl;
    exit(-1);
  }

  if (_data[_list].isObject()) {
    if (_data[_list][_name].isObject()) {
      std::cout << _name << " is already used" << std::endl;
      exit(-1);
    }
  } else {
    std::cout << _list << " deosn't exit" << std::endl;
    exit(-1);
  }

  _data[_list][_name]["query"] = _query;

  return;
}
