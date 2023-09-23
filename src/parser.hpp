#ifndef PARSER
#define PARSER

#include "./list.hpp"

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

class Pparser {
public:
  enum CMD {
    NEW,
    DELETE,
    ADD,
    REMOVE,
    INSTALL,
    UNINSTALL,
    SHOW,
    EXPORT,
    IMPORT,
    COPY,
    EDIT,
  };

  CMD cmd;
  bool help;
  std::vector<List> vLists;
  std::vector<std::string> vArgs;

  Pparser(int _argc, char *_argv[]);

private:
  const char *path_;
  std::string str_;

  void nw(int _argc, char *_argv[]);
  void del(int _argc, char *_argv[]);
  void add(int _argc, char *_argv[]);
  void remove(int _argc, char *_argv[]);
  void install(int _argc, char *_argv[]);
  void uninstall(int _argc, char *_argv[]);
  void show(int _argc, char *_argv[]);
  void exprt(int _argc, char *_argv[]);
  void import(int _argc, char *_argv[]);
  void copy(int _argc, char *_argv[]);
  void edit(int _argc, char *_argv[]);
};

#endif // !PARSER
