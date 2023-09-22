#include "./fn.hpp"
#include "./list.hpp"

#include "json/value.h"
#include <corecrt_wstdio.h>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
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

  std::vector<List> vList;

  std::cout << "1" << std::endl;

  for (Json::ValueConstIterator i = _data.begin(); i != _data.end(); i++) {
    List list;

    list.name = i.key().asString();
    list.path = _data[list.name]["path"].asString();

    for (Json::ValueIterator j = _data[i.key().asString()]["arr"].begin();
         j != _data[i.key().asString()]["arr"].end(); j++) {
      list.vpNQ.push_back(
          {j.key().asString(),
           _data[i.key().asString()]["arr"][j.key().asString()].asString()});
    }

    vList.push_back(list);
  }

  std::cout << "2" << std::endl;

  for (List _list : vList) {
    std::cout << _list << "\n\n";
  }

  std::cout << std::endl;

  return;
}

void install(Json::Value &_data, std::string _list, bool _help) {
  if (_help) {
    std::cout << "help message" << std::endl;
    exit(-1);
  }

  char buffer[256];
  std::string str;

  FILE *pipe;
  for (Json::ValueConstIterator i = _data[_list]["arr"].begin();
       i != _data[_list]["arr"].end(); i++) {
    std::string cmd = "winget install -s winget -q ";
    cmd += _data[_list]["arr"][i.key().asString()].asString();
    cmd += " -l ";
    cmd += _data[_list]["path"].asString();

    pipe = _popen(cmd.c_str(), "r");

    if (!pipe)
      throw std::runtime_error("cmd failed");
    try {
      str = "";

      while (fgets(buffer, sizeof(buffer), pipe) != NULL)
        str += buffer;
    } catch (...) {
      _pclose(pipe);
      throw;
    }

    std::cout << str << std::endl;
  }

  return;
}

void uninstall(Json::Value &_data, std::string _list, bool _help) {
  if (_help) {
    std::cout << "help message" << std::endl;
    exit(-1);
  }

  char buffer[256];
  std::string str;

  FILE *pipe;
  for (Json::ValueConstIterator i = _data[_list]["arr"].begin();
       i != _data[_list]["arr"].end(); i++) {
    std::string cmd = "winget uninstall -q ";
    cmd += _data[_list]["arr"][i.key().asString()].asString();

    pipe = _popen(cmd.c_str(), "r");

    if (!pipe)
      throw std::runtime_error("cmd failed");
    try {
      str = "";

      while (fgets(buffer, sizeof(buffer), pipe) != NULL)
        str += buffer;
    } catch (...) {
      _pclose(pipe);
      throw;
    }

    std::cout << str << std::endl;
  }

  return;
}
