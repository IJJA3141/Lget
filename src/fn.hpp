#ifndef FN
#define FN

#include "./json/json.h"

#include <string>
#include <vector>

void add(Json::Value &_data, std::string _list, std::string _query,
         std::vector<std::string> &_vArgs, bool _help);

#endif // !FN
