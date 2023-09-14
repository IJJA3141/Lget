#include "./fn.hpp"
#include <iostream>
#include <string>
#include <vector>

void add(Json::Value &_data, std::string _query, std::string _name,
         std::string _list, std::vector<std::string> &_vArgs) {
  if (_vArgs.size() == 0 && _query == "" && _name == "") {
    std::cout << "err" << std::endl;
    exit(-1);
  }

  if(_vArgs.size() > 3) {
    std::cout << "err" << std::endl;
  }

  for (int i = 0; i < _vArgs.size(); i++) {
    if (_query == "") {
      _query = _vArgs[i];
    } else if (_name == "") {
      _name = _vArgs[i];
    } else if (_list == "default") {
      _list = _vArgs[i];
    } else {
      std::cout << "err" << std::endl;
      exit(-1);
    }
  }
  
  _data[_list][_name]["query"] = _query;
  return;
}
