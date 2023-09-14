#include "./load-save.hpp"
#include "./parser.hpp"

#include "json/json.h"
#include <iostream>
#include <string>

//
// entry point
//      ║
//      ╟─>> argc, argv
//      ║                  :Pars args
//      ╟─<< struct args
//      ║
//      ║
//      ║
//      ╟─>> path
//      ║                  :Load file
//      ╟─<< file
//      ║
//      ║
//      ║
//      ╟─>> cmd, file, args, options
//      ║                  :Exec
//      ╟─<< ?file
//      ║
//      ║
//      ║
//      ╟─>> path, file
//      ║                  :Save file
//      ╟─<< void
//      ║
//   end point
//

int main(int _argc, char *_argv[]) {
  Parser parser(_argc, _argv);

  if (Parser::cmd::NONE == parser.command) {
  }

  Json::Value data = Load("./test.json");

  if (Parser::cmd::ADD == parser.command) {
  } else if (Parser::cmd::REMOVE == parser.command) {
  } else {
  }

  Save("./test.json", data);

  return 0;
}
