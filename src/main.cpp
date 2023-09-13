#include "./save.hpp"

#include "json/json.h"
#include <iostream>

int main(int _argc, char *_argv[]) {


  Json::Value data = Load("./test.json");
  std::cout << data << std::endl;

  Save(data, "./test.json");

  return 0;
}
