#include "./fn.hpp"
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

  Json::Value data = Load("./test.json");

  if (parser.cmd == "add") {
    add(data, parser.query, parser.name, parser.list, parser.vArgs,
        parser.help);
  } else {
    std::cout << "h msg" << std::endl;
  }

  Save("./test.json", data);
  return 0;
}
