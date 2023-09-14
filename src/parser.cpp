#include "./parser.hpp"
#include <string.h>

void parse(int _argc, char *_argv[]) {
  if (_argc <= 1) {
    std::cout << "qqchose" << std::endl;
    exit(0);
  }
  const char *command = _argv[1];

  const char *list = nullptr;
  const char *query = nullptr;
  const char *nickname = nullptr;
  const char *path = nullptr;
  bool help = false;
  std::vector<std::string> vArgs;

  for (int i = 2; i < _argc; i++) {
    if (0 == strcmp(_argv[i], "-l") || 0 == strcmp(_argv[i], "--list")) {
      if (++i < _argc) {
        list = _argv[i];
      } else {
        std::cout << "bad list" << std::endl;
        exit(100);
      }
    } else if (0 == strcmp(_argv[i], "-q") ||
               0 == strcmp(_argv[i], "--query")) {
      if (++i < _argc) {
        query = _argv[i];
      } else {
        std::cout << "bad query" << std::endl;
        exit(101);
      }
    } else if (0 == strcmp(_argv[i], "-n") ||
               0 == strcmp(_argv[i], "--nickname")) {
      if (++i < _argc) {
        nickname = _argv[i];
      } else {
        std::cout << "bad nickname" << std::endl;
        exit(102);
      }
    } else if (0 == strcmp(_argv[i], "-p") || 0 == strcmp(_argv[i], "--path")) {
      if (++i < _argc) {
        path = _argv[i];
      } else {
        std::cout << "bad path" << std::endl;
        exit(103);
      }
    } else if (0 == strcmp(_argv[i], "-?") || 0 == strcmp(_argv[i], "--help")) {
      help = true;
    } else
      vArgs.push_back(_argv[i]);
  }

  if (0 == strcmp(command, "add")) {
    if (help) {
      std::cout << "specific help message" << std::endl;
      exit(001);  
    }
    add(list, query, vArgs);
  } else if (0 == strcmp(command, "remove")) {
    if (help) {
      std::cout << "specific help message" << std::endl;
      exit(001);
    }
    remove(list, query, vArgs);
  } else if (0 == strcmp(command, "make")) {
    if (help) {
      std::cout << "specific help message" << std::endl;
      exit(001);
    }
  } else if (0 == strcmp(command, "install")) {
    if (help) {
      std::cout << "specific help message" << std::endl;
      exit(001);
    }
  } else if (0 == strcmp(command, "uninstall")) {
    if (help) {
      std::cout << "specific help message" << std::endl;
      exit(001);
    }
  } else if (0 == strcmp(command, "status")) {
    if (help) {
      std::cout << "specific help message" << std::endl;
      exit(001);
    }
  } else if (0 == strcmp(command, "path")) {
    if (help) {
      std::cout << "specific help message" << std::endl;
      exit(001);
    }
  } else {
  }
  return;
}
