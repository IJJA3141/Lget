#ifndef MY_MSG
#define MY_MSG

#define VERSION "01.00.01"

#define ERR_MSG_0(_arg)                                                        \
  "Lget v" VERSION "\n"                                                        \
  "\n" _arg                                                                    \
  "Lget is a command line utility managing lists of winget packages.\n"        \
  "\n"                                                                         \
  "usage: Lget  [<command>] [<options>]\n"                                     \
  "\n"                                                                         \
  "The following commands are available:\n"                                    \
  "  new        Creates the given list\n"                                      \
  "  remove     Removes the given packge from a  given list\n"                 \
  "  add        Adds the given package to a given list\n"                      \
  "  delete     Delete the given list\n"                                       \
  "  install    Installs the given package\n"                                  \
  "  uninstall  Uninstalls the given package\n"                                \
  "  list       Display installed packages\n"                                  \
  "  export     Exports a list of the installed packages\n"                    \
  "  import     Installs all the packages in a file\n"                         \
  "  copy       Copies the given list in a new one\n"                          \
  "  edit       Edit the given list\n"                                         \
  "\n"                                                                         \
  "For more details on a specific command, pass it the help argument. [-?]\n"  \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  -v,--version              Display the version of the tool\n"              \
  "  -i,--info                 Display general info of the tool\n"             \
  "  -?,--help                 Shows help about the selected command\n"        \
  "\n"                                                                         \
  "More help can be found at: https://github.com/IJJA3141/Lget\n"

#define INFO ""

#endif // !MY_MSG
