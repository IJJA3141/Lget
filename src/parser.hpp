#ifndef PARSER
#define PARSER

#include <string>
#include <vector>

struct Parser {
public:
  bool help;
  std::string cmd;
  std::string list;
  std::string query;
  std::string path;
  std::string name;
  std::vector<std::string> vArgs;

  Parser(int _argc, char *_argv[]);
};

#endif // !PARSER
