#include "./save.hpp"

Json::Value Load(const char *_path) {
  std::fstream stream;
  stream.open(_path, std::ios::in);
  Json::Value data;
  if (stream.is_open()) {
    stream >> data;
  } else {
    std::cout << "failed to open json file" << std::endl;
    exit(-1);
  }
  return data;
};

void Save(Json::Value &_data, const char *_path) {
  std::ofstream stream(_path);
  stream << _data;
  return;
};
