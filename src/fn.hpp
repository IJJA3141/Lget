#ifndef FN
#define FN

#include "./json/json.h"

#include <string>
#include <vector>

void add(Json::Value &_data, std::string _query, std::string _name,
         std::string _list, std::vector<std::string> &_vArgs, bool _help);
void rm(Json::Value &_data, std::string _name, std::string _list,
        std::vector<std::string> &_vArgs, bool _help);

void make(Json::Value &_data, std::string _list, std::string _path,
          std::vector<std::string> &_vArgs, bool _help);
void del(Json::Value &_data, std::string _list,
         std::vector<std::string> &_vArgs, bool _help);

void list(Json::Value &_data, std::string _list,
          std::vector<std::string> &_vArgs, bool _help);

#endif // !FN
