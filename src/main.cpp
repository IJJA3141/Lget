#include "./fn.hpp"
#include "./load-save.hpp"
#include "./parser.hpp"

#include "json/json.h"
#include <iostream>
#include <string>
#include <windows.h>

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
  Pparser par(_argc, _argv);
  Parser parser(_argc, _argv);

  Json::Value data = Load("./test.json");

  if (parser.cmd == "add") {
    add(data, parser.query, parser.name, parser.list, parser.vArgs,
        parser.help);
  } else if (parser.cmd == "remove") {
    rm(data, parser.name, parser.list, parser.vArgs, parser.help);
  } else if (parser.cmd == "delete") {
    del(data, parser.list, parser.vArgs, parser.help);
  } else if (parser.cmd == "new") {
    make(data, parser.list, parser.path, parser.vArgs, parser.help);
  } else if (parser.cmd == "list") {
    list(data, parser.list, parser.vArgs, parser.help);
  } else if (parser.cmd == "install") {
    install(data, parser.list, parser.help);
  } else if (parser.cmd == "uninstall") {
    uninstall(data, parser.list, parser.help);
  } else {
    std::cout << "h msg" << std::endl;
    exit(-1);
  }

  Save("./test.json", data);
  return 0;
}
