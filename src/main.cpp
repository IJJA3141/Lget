#include "json/json.h"
#include <iostream>
#include <fstream>

#include "./save/save.hpp"

int main() {
  Json::Value data = Load("./test.json"); 
  std::cout << data << std::endl;

  return 0;
}
