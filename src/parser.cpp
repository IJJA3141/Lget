#include "./parser.hpp"
#include <string.h>

Parser::Parser(int _argc, char *_argv[]) {
  if (_argc < 2) {
    this->command = Parser::cmd::NONE;
    this->help = true;
    return;
  }

  if (0 == strcmp(_argv[2], "add")) {
    this->command = Parser::cmd::ADD;
  } else if (0 == strcmp(_argv[2], "remove")) {
    this->command = Parser::cmd::REMOVE;
  } else {
  }
}
