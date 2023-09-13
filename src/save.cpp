#include "./save.hpp"

Json::Value Load(const char *_path) {
  std::cout << "Loading..." << std::endl;
  std::fstream stream;
  stream.open(_path, std::ios::in);
  Json::Value data;
  if (stream.is_open()) {
    stream >> data;
    stream.close();
  } else
    data = Json::Value(Json::arrayValue);
  return data;
};

void Save(Json::Value &_data, const char *_path) {
  std::cout << "Saving..." << std::endl;
  std::fstream stream;
  stream.open(_path, std::ios::out);
  if (stream.is_open()) {
    stream.clear();
    stream << _data;
    stream.close();
  } else
    std::cout << "???" << std::endl;

  return;
};
