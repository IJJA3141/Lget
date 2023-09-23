#include "./parser.hpp"
#include "./msg.hpp"

#include <string.h>

Parser::Parser(int _argc, char *_argv[]) {
  this->cmd = "";
  this->list = "default";
  this->name = "";
  this->path = "";
  this->help = false;
  this->vArgs = {};

  if (_argc < 2) {
    this->cmd = "help";
    return;
  }

  this->cmd = _argv[1];

  for (int i = 2; i < _argc; i++) {
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
    } else if (0 == strcmp(_argv[i], "-n") || 0 == strcmp(_argv[i], "--name")) {
      if (++i < _argc) {
        this->name = _argv[i];
      } else {
        this->help = true;
        return;
      }
    } else
      this->vArgs.push_back(_argv[i]);
  }
}

Pparser::Pparser(int _argc, char *_argv[]) {
  if (_argc < 2) {
    std::cout << ERR_MSG_0("") << std::endl;
    exit(-1);
  }

  this->path_ = _argv[0];
  this->str_ = _argv[1];

  if (this->str_ == "new") {
    this->cmd = Pparser::CMD::NEW;
  } else if (this->str_ == "remove") {
    this->cmd = Pparser::CMD::REMOVE;
  } else if (this->str_ == "add") {
    this->cmd = Pparser::CMD::ADD;
  } else if (this->str_ == "delete") {
    this->cmd = Pparser::CMD::DELETE;
  } else if (this->str_ == "install") {
    this->cmd = Pparser::CMD::INSTALL;
  } else if (this->str_ == "uninstall") {
    this->cmd = Pparser::CMD::UNINSTALL;
  } else if (this->str_ == "list") {
    this->cmd = Pparser::CMD::SHOW;
  } else if (this->str_ == "export") {
    this->cmd = Pparser::CMD::EXPORT;
  } else if (this->str_ == "import") {
    this->cmd = Pparser::CMD::IMPORT;
  } else if (this->str_ == "copy") {
    this->cmd = Pparser::CMD::COPY;
  } else if (this->str_ == "edit") {
    this->cmd = Pparser::CMD::EDIT;
  } else {
    if (this->str_.compare(0, 1, "-") == 0) {
      if (this->str_.compare(1, 1, "-") == 0) {
        if (this->str_ == "--version") {
          std::cout << VERSION << std::endl;
          exit(0);
        } else if (this->str_ == "--info") {
          std::cout << INFO << std::endl;
          exit(0);
        } else if (this->str_ == "--help") {
          std::cout << ERR_MSG_0("") << std::endl;
          exit(0);
        } else {
          this->str_ =
              "Argument name was not recognized for the current command: '" +
              this->str_ + "'\n";
          std::cout << ERR_MSG_0(+this->str_ +) << std::endl;
          exit(-1);
        }
      } else {
        if (this->str_ == "-v") {
          std::cout << VERSION << std::endl;
          exit(0);
        } else if (this->str_ == "-i") {
          std::cout << INFO << std::endl;
          exit(0);
        } else if (this->str_ == "-?") {
          std::cout << ERR_MSG_0("") << std::endl;
          exit(0);
        } else {
          this->str_ =
              "Argument alias was not recognized for the current command: '" +
              this->str_ + "'\n";
          std::cout << ERR_MSG_0(+this->str_ +) << std::endl;
        }
      }
    } else {
      this->str_ = "Unrecognized command: '" + this->str_ + "'\n";
      std::cout << ERR_MSG_0(+this->str_ +) << std::endl;
      exit(-1);
    }
  }

  if (this->cmd == Pparser::CMD::NEW)
    this->nw(_argc - 2, _argv + 2);
  else if (this->cmd == Pparser::CMD::DELETE)
    this->del(_argc - 2, _argv + 2);
  else if (this->cmd == Pparser::CMD::ADD)
    this->add(_argc - 2, _argv + 2);
  else if (this->cmd == Pparser::CMD::REMOVE)
    this->remove(_argc - 2, _argv + 2);
  else if (this->cmd == Pparser::CMD::INSTALL)
    this->install(_argc - 2, _argv + 2);
  else if (this->cmd == Pparser::CMD::UNINSTALL)
    this->uninstall(_argc - 2, _argv + 2);
  else if (this->cmd == Pparser::CMD::SHOW)
    this->show(_argc - 2, _argv + 2);
  else if (this->cmd == Pparser::CMD::EXPORT)
    this->exprt(_argc - 2, _argv + 2);
  else if (this->cmd == Pparser::CMD::IMPORT)
    this->import(_argc - 2, _argv + 2);
  else if (this->cmd == Pparser::CMD::COPY)
    this->copy(_argc - 2, _argv + 2);
  else
    this->edit(_argc - 2, _argv + 2);

  return;
}

void Pparser::nw(int _argc, char *_argv[]) {
  std::string path = "";
  std::string list = "";
  std::string source = "";

  for (int i = 0; i < _argc; i++) {
    this->str_ = _argv[i];

    if (this->str_.compare(0, 1, "-") == 0) {
      if (this->str_.compare(1, 1, "-") == 0) {
        if (this->str_ == "--source") {
          if (source == "") {
            if (++i < _argc)
              source = std::string(_argv[i]);
            else {
              std::cout << ERR_MSG_1("Argument value required, but none found: "
                                     "'--source'\n")
                        << std::endl;
              exit(-1);
            }
          } else {
            std::cout << ERR_MSG_1(
                "Argument provided more times than allowed : 'source'\n");
            exit(-1);
          }
        } else if (this->str_ == "--help") {
          std::cout << ERR_MSG_1("") << std::endl;
          exit(0);
        } else if (this->str_ == "--list") {
          if (list == "") {
            if (++i < _argc)
              list = std::string(_argv[i]);
            else {
              std::cout << ERR_MSG_1("Argument value required, but none found: "
                                     "'--list'\n")
                        << std::endl;
              exit(-1);
            }
          } else {
            std::cout << ERR_MSG_1(
                "Argument provided more times than allowed : 'list'\n");
            exit(-1);
          }
        } else if (this->str_ == "--path") {
          if (path == "") {
            if (++i < _argc)
              path = std::string(_argv[i]);
            else {
              std::cout << ERR_MSG_1("Argument value required, but none found: "
                                     "'--path'\n")
                        << std::endl;
              exit(-1);
            }
          } else {
            std::cout << ERR_MSG_1(
                "Argument provided more times than allowed : 'path'\n");
            exit(-1);
          }
        } else {
          this->str_ =
              "Argument name was not recognized for the current command: '" +
              this->str_ + "'\n";
          std::cout << ERR_MSG_1(+this->str_ +) << std::endl;
          exit(-1);
        }
      } else {
        if (this->str_ == "-s") {
          if (source == "") {
            if (++i < _argc)
              source = std::string(_argv[i]);
            else {
              std::cout << ERR_MSG_1("Argument value required, but none found: "
                                     "'-s'\n")
                        << std::endl;
              exit(-1);
            }
          } else {
            std::cout << ERR_MSG_1(
                "Argument provided more times than allowed : 'source'\n");
            exit(-1);
          }
        } else if (this->str_ == "-?") {
          std::cout << ERR_MSG_1("") << std::endl;
          exit(0);
        } else if (this->str_ == "-l") {
          if (list == "") {
            if (++i < _argc)
              list = std::string(_argv[i]);
            else {
              std::cout << ERR_MSG_1("Argument value required, but none found: "
                                     "'-l'\n")
                        << std::endl;
              exit(-1);
            }
          } else {
            std::cout << ERR_MSG_1(
                "Argument provided more times than allowed : 'list'\n");
            exit(-1);
          }
        } else if (this->str_ == "-p") {
          if (path == "") {
            if (++i < _argc)
              path = std::string(_argv[i]);
            else {
              std::cout << ERR_MSG_1("Argument value required, but none found: "
                                     "'--path'\n")
                        << std::endl;
              exit(-1);
            }
          } else {
            std::cout << ERR_MSG_1(
                "Argument provided more times than allowed : 'path'\n");
            exit(-1);
          }
        } else {
          this->str_ =
              "Argument alias was not recognized for the current command: '" +
              this->str_ + "'\n";
          std::cout << ERR_MSG_1(+this->str_ +) << std::endl;
          exit(-1);
        }
      }
    } else {
      if (list == "")
        list = this->str_;
      else if (path == "")
        path = this->str_;
      else if (source == "")
        source = this->str_;
      else {
        this->str_ = "Found a positional argument when none was expected: '" +
                     this->str_ + "'";
        std::cout << ERR_MSG_1(+this->str_ +) << std::endl;
        exit(-1);
      }
    }
  }

  if (list == "") {
    std::cout << "Please enter a list name: ";
    std::cin >> list;
  }
  if (path == "") {
    std::cout << "Please enter a path: ";
    std::cin >> path;
  }

  if (path.compare(1, 1, ":") != 0) {
    std::cout << this->path_ << std::endl;
  }

  std::cout << list << "\n"
            << path << "\n"
            << source << "\nend of this\n"
            << std::endl;

  return;
}

void Pparser::del(int _argc, char *_argv[]) { return; };
void Pparser::add(int _argc, char *_argv[]) { return; };
void Pparser::remove(int _argc, char *_argv[]) { return; };
void Pparser::install(int _argc, char *_argv[]) { return; };
void Pparser::uninstall(int _argc, char *_argv[]) { return; };
void Pparser::show(int _argc, char *_argv[]) { return; };
void Pparser::exprt(int _argc, char *_argv[]) { return; };
void Pparser::import(int _argc, char *_argv[]) { return; };
void Pparser::copy(int _argc, char *_argv[]) { return; };
void Pparser::edit(int _argc, char *_argv[]) { return; };
