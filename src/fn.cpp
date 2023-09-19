#include "./fn.hpp"
#include "json/value.h"
#include <iostream>
#include <stdio.h>
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
    if (_data[_list]["arr"][_name].isObject()) {
      std::cout << _name << " is already used" << std::endl;
      exit(-1);
    }
  } else {
    std::cout << _list << " deosn't exit" << std::endl;
    exit(-1);
  }

  _data[_list]["arr"][_name] = _query;

  return;
}

void rm(Json::Value &_data, std::string _name, std::string _list,
        std::vector<std::string> &_vArgs, bool _help) {
  if (_help) {
    std::cout << "help message" << std::endl;
    exit(-1);
  }

  int i = 0;

  if (_name == "") {
    if (_vArgs.size() != 0) {
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

  if (_data[_list].isObject())
    if (_data[_list]["arr"][_name].isObject()) {
      _data[_list]["arr"].removeMember(_name);
      std::cout << _name << " has been removed" << std::endl;
      return;
    }

  std::cout << _list << " doesn't exit" << std::endl;
  exit(-1);
}

void make(Json::Value &_data, std::string _list, std::string _path,
          std::vector<std::string> &_vArgs, bool _help) {
  if (_help) {
    std::cout << "help message" << std::endl;
    exit(-1);
  }

  int i = 0;

  if (_list == "default") {
    if (_vArgs.size() != 0) {
      _list = _vArgs[i++];
    } else {
      std::cout << "list: " << std::endl;
      std::cin >> _list;
    }
  }

  if (_path == "") {
    if (_vArgs.size() > i) {
      _path = _vArgs[i++];
    } else {
      std::cout << "path: " << std::endl;
      std::cin >> _path;
    }
  }

  if (_vArgs.size() > i) {
    std::cout << "too mutch" << std::endl;
    std::cout << _vArgs.size() << "\n" << i << std::endl;
    exit(-1);
  }

  if (_data[_list].isObject()) {
    std::cout << "already exist" << std::endl;
    exit(-1);
  }

  _data[_list]["path"] = _path;
  return;
}

void del(Json::Value &_data, std::string _list,
         std::vector<std::string> &_vArgs, bool _help) {
  if (_help) {
    std::cout << "help message" << std::endl;
    exit(-1);
  }

  int i = 0;

  if (_list == "default") {
    if (_vArgs.size() != 0) {
      _list = _vArgs[i++];
    } else {
      std::cout << "list: " << std::endl;
      std::cin >> _list;
    }
  }

  if (_vArgs.size() > i) {
    std::cout << "too mutch" << std::endl;
    exit(-1);
  }

  bool yes = false;
  bool no = false;
  std::string str;

  if (_data[_list].isObject()) {
    while (!yes && !no) {
      std::cout << "Are you shure you want to delete " << _list << std::endl;
      std::cin >> str;
      if (str == "yes" || str == "Yes")
        yes = true;
      if (str == "no" || str == "No")
        no = true;
    }
    if (yes)
      _data.removeMember(_list);
    return;
  } else {
    std::cout << _list << "does't exist" << std::endl;
    exit(-1);
  }
}

void list(Json::Value &_data, std::string _list,
          std::vector<std::string> &_vArgs, bool _help) {
  if (_help) {
    std::cout << "help message" << std::endl;
    exit(-1);
  }

  for (Json::ValueConstIterator i = _data.begin(); i != _data.end(); i++) {
    std::cout << i.key().asString()
              << " path:" << _data[i.key().asString()]["path"].asString() << std::endl;

    for (Json::ValueIterator j = _data[i.key().asString()]["arr"].begin();
         j != _data[i.key().asString()]["arr"].end(); j++) {
      std::cout
          << j.key().asString() << " | "
          << _data[i.key().asString()]["arr"][j.key().asString()].asString()
          << std::endl;
    }
  }

  return;
}
