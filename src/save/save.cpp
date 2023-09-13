#include "./save.hpp"

Json::Value Load(const char *_path) {
  std::ifstream stream("./test.json");
  Json::Value data;
  stream >> data;
  return data;
};

void Save(Json::Value &_data, const char *_path) {
  std::ofstream stream(_path);
  stream << _data;
  return;
};
