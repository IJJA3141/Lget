#include "./save.hpp"

#include "json/json.h"
#include <iostream>

int main() {
  std::cout << "?" << std::endl;
  Json::Value data = Load("./test.json");
  std::cout << "Data:\n" << data << std::endl; // data << std::endl;

  return 0;
}
