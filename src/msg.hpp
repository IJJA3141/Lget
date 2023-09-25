#ifndef MY_MSG
#define MY_MSG

#define VERSION "01.00.01"

#define HEADER                                                                 \
  "Lget v" VERSION "\n"                                                        \
  "\n"

#define FOOTER                                                                 \
  "\n"                                                                         \
  "More help can be found at: https://github.com/IJJA3141/Lget\n"

#define ERR_MSG(_arg)                                                          \
  "" HEADER ""                                                                 \
  "" _arg ""                                                                   \
  "Lget is a command line utility managing lists of winget packages.\n"        \
  "\n"                                                                         \
  "usage: Lget  [<command>] [<options>]\n"                                     \
  "\n"                                                                         \
  "The following commands are available:\n"                                    \
  "  new        Creates the given list\n"                                      \
  "  delete     Delete the given list\n"                                       \
  "  add        Adds the given package to a given list\n"                      \
  "  remove     Removes the given packge from a given list\n"                  \
  "  install    Installs the given package\n"                                  \
  "  uninstall  Uninstalls the given package\n"                                \
  "  list       Display installed packages\n"                                  \
  "  export     Exports a list of the installed packages\n"                    \
  "  import     Installs all the packages in a file\n"                         \
  "  edit       Edit the given list\n"                                         \
  "\n"                                                                         \
  "For more details on a specific command, pass it the help argument. "        \
  "[-?]\n"                                                                     \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  -v,--version              Display the version of the tool\n"              \
  "  -i,--info                 Display general info of the tool\n"             \
  "  -?,--help                 Shows help about the selected "                 \
  "command"                                                                    \
  "" FOOTER ""

#define ERR_MSG_NEW(_arg)                                                      \
  "" HEADER ""                                                                 \
  "" _arg ""                                                                   \
  "Creates a new list to hold packages.\n"                                     \
  "\n"                                                                         \
  "usage: lget new [[-l] <list> [-p <path>]] [<options>]\n"                    \
  "\n"                                                                         \
  "The following arguments are available:\n"                                   \
  "  -l,--list                   The list name used to create the list\n"      \
  "  -p,--path                   The path where the list will install it's "   \
  "packages\n"                                                                 \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  -s,--source                 The list used as a patern\n"                  \
  "  -?,--help                   Shows help about the selected command\n"      \
  "" FOOTER ""

#define ERR_MSG_DELETE(_arg)                                                   \
  "" HEADER ""                                                                 \
  "" _arg ""                                                                   \
  "Deletes a list.\n"                                                          \
  "\n"                                                                         \
  "usage: lget delete [[-l] <list>] [options]\n"                               \
  "\n"                                                                         \
  "The following arguments are available:\n"                                   \
  "  -l,--list                   The list that will be deleted\n"              \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  -y,--yes                    Doesn't ask for confirmation\n"               \
  "  -?,--help                   Shows help about the selected command\n"      \
  "" FOOTER ""

#define ERR_MSG_ADD(_arg)                                                      \
  "" HEADER ""                                                                 \
  "" _arg ""                                                                   \
  "Add package to a given list.\n"                                             \
  "\n"                                                                         \
  "usage: lget add [[-n] <nickname>] [[-q] <query>] [options]\n"               \
  "\n"                                                                         \
  "The following arguments are available:\n"                                   \
  "  -n,--nickname               Nickname of the package\n"                    \
  "  -q,--query                  Query of the package\n"                       \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  -l,--list                   Specify the list at which the package will "  \
  "be added\n"                                                                 \
  "  -?,--help                   Shows help about the selected command\n"      \
  "" FOOTER ""

#define ERR_MSG_REMOVE(_arg)                                                   \
  "" HEADER ""                                                                 \
  "" _arg ""                                                                   \
  "Removes a package from a given list.\n"                                     \
  "\n"                                                                         \
  "usage: lget remove [[-n] <nickname>] [[-l] <list>] [options]\n"             \
  "\n"                                                                         \
  "The following arguments are available:\n"                                   \
  "  -n,--nickname               Nickname of the package\n"                    \
  "  -l,--list                   List from which the package will be "         \
  "removed\n"                                                                  \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  -y,--yes                    Doesn't ask for confirmation\n"               \
  "  -?,--help                   Shows help about the selected command\n"      \
  "" FOOTER ""

#define ERR_MSG_INSTALL(_arg)                                                  \
  "" HEADER ""                                                                 \
  "" _arg ""                                                                   \
  "Installs all packages from a given list.\n"                                 \
  "\n"                                                                         \
  "usage: lget install [[-l] <list>] [options]\n"                              \
  "\n"                                                                         \
  "The following arguments are available:\n"                                   \
  "  -l,--list                   List from which packages will be "            \
  "installed\n"                                                                \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  -?,--help                   Shows help about the selected command\n"      \
  "" FOOTER ""

#define ERR_MSG_UNINSTALL(_arg)                                                \
  "" HEADER ""                                                                 \
  "" _arg ""                                                                   \
  "Uninstalls all packages from a given list.\n"                               \
  "\n"                                                                         \
  "usage: lget uninstall [[-l] <list>] [options]\n"                            \
  "\n"                                                                         \
  "The following arguments are available:\n"                                   \
  "  -l,--list                   List from which packages will be "            \
  "uninstalled\n"                                                              \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  -y,--yes                    Doesn't ask for confirmation\n"               \
  "  -?,--help                   Shows help about the selected command\n"      \
  "" FOOTER ""

#define ERR_MSG_LIST(_arg)                                                     \
  "" HEADER ""                                                                 \
  "" _arg ""                                                                   \
  "Shows all the list and the packages in them.\n"                             \
  "\n"                                                                         \
  "usage: lget list [options]\n"                                               \
  "\n"                                                                         \
  "No arguments are required\n"                                                \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  -l,--list                   Gives a scop to the list command\n"           \
  "  -?,--help                   Shows help about the selected command\n"      \
  "" FOOTER ""

#endif // !MY_MSG
