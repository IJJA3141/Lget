#include "./fn.hpp"
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

  std::vector<std::string> list;
  std::vector<std::string> path;
  std::vector<std::string> name;
  std::vector<std::string> query;

  for (Json::ValueConstIterator i = _data.begin(); i != _data.end(); i++) {
    list.push_back(i.key().asString());
    path.push_back(_data[list[list.size() - 1]]["path"].asString());

    for (Json::ValueIterator j = _data[i.key().asString()]["arr"].begin();
         j != _data[i.key().asString()]["arr"].end(); j++) {
      name.push_back(j.key().asString());
      query.push_back(
          _data[name[name.size() - 1]]["arr"][j.key().asString()].asString());
    }
  }

  int listSize = 11 + 4; // List | Path
  int nameSize = 8 + 4;  // Nickname
  int querySize = 5 + 4; // Query

  for (std::string _str : list)
    if (_str.size() > listSize)
      listSize = _str.size();
  for (std::string _str : name)
    if (_str.size() > nameSize)
      nameSize = _str.size();
  for (std::string _str : path)
    if (_str.size() > listSize)
      listSize = _str.size();

  for (std::string _str : query)
    if (_str.size() > querySize)
      querySize = _str.size();

  /*
   *
    std::string str = "List";
    str += std::string(listSize - 4, ' ');

    std::cout << str << std::endl;


      */

  int size = listSize + nameSize + querySize;

  std::string str(size, ' ');
  std::string space = str;

  str.replace(0, 11, "List | Path");
  str.replace(listSize, 8, "Nickname");
  str.replace(listSize + nameSize, 5, "Query");

  std::cout << str << "\n" + std::string(size, '-') << "\n";

  for (std::string _str : list) {
    str = space + "\n" + space;
    str.replace(0, _str.size(), _str);
    str.replace(size + 1, path[0].size(), path[0]);
    if (name.size() > 0) {
      str.replace(listSize, name[0].size(), name[0]);
      str.replace(listSize + nameSize, query[0].size(), query[0]);
      if (name.size() > 1) {
        str.replace(listSize, name[1].size(), name[1]);
        str.replace(listSize + nameSize, query[1].size(), query[1]);
      }
    }

    std::cout << str << "\n";
    for (int i = 2; i < name.size(); i++) {
      str = space;
      str.replace(listSize, name[i].size(), name[i]);
      str.replace(listSize + nameSize, query[i].size(), query[i]);
      std::cout << str << "\n";
    }

    std::cout << "\n";
  }

  std::cout << std::endl;

  return;
}
