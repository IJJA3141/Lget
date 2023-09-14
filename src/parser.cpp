#include "./parser.hpp"
#include <string.h>

Parser::Parser(int _argc, char *_argv[]) {
  this->cmd = "";
  this->list = "default";
  this->name = "";
  this->path = "";
  this->help = false;
  this->vArgs = {};

  if (_argc < 2) {
    this->cmd = "";
    this->help = true;
    return;
  }

  this->cmd = _argv[2];

  for (int i = 0; i < _argc; i++) {
    if (0 == strcmp(_argv[i], "-l") || 0 == strcmp(_argv[i], "--list")) {
      if (++i < _argc) {
        this->list = _argv[i];
      } else {
        this->help = true;
        return;
      }
    } else if (0 == strcmp(_argv[i], "-q") ||
               0 == strcmp(_argv[i], "--query")) {
      if (++i < _argc) {
        this->query = _argv[i];
      } else {
        this->help = true;
        return;
      }
    } else
      this->vArgs.push_back(_argv[i]);
  }
}
