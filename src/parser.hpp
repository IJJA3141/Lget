#ifndef PARSER
#define PARSER

#include <string>
#include <vector>

struct Parser {
public:
  enum cmd {
    NONE,
    ADD,
    REMOVE,

  };

  Parser::cmd command;
  bool help;
  std::string list;
  std::string query;
  std::string path;
  std::string name;
  std::vector<std::string> vArgs;

  Parser(int _argc, char *_argv[]);
};

#endif // !PARSER
