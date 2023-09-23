#ifndef MY_MSG
#define MY_MSG

#define VERSION "01.00.01"

#define HEADER                                                                 \
  "Lget v" VERSION "\n"                                                        \
  "\n"

#define FOOTER                                                                 \
  "\n"                                                                         \
  "More help can be found at: https://github.com/IJJA3141/Lget\n"

#define ERR_MSG_0(_arg)                                                        \
  "" HEADER ""                                                                 \
  "" _arg ""                                                                   \
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
  "For more details on a specific command, pass it the help argument. "        \
  "[-?]\n"                                                                     \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  -v,--version              Display the version of the tool\n"              \
  "  -i,--info                 Display general info of the tool\n"             \
  "  -?,--help                 Shows help about the selected "                 \
  "command"                                                                    \
  "" FOOTER ""

#define ERR_MSG_1(_arg)                                                        \
  "" HEADER ""                                                                 \
  "" _arg ""                                                                   \
  "Searches for packages from configured sources.\n"                           \
  "\n"                                                                         \
  "usage: winget search [[-q] <query>] [<options>]\n"                          \
  "\n"                                                                         \
  "The following command aliases are available:\n"                             \
  "  find\n"                                                                   \
  "\n"                                                                         \
  "The following arguments are available:\n"                                   \
  "  -q,--query                  The query used to search for a package\n"     \
  "\n"                                                                         \
  "The following options are available:\n"                                     \
  "  --id                        Filter results by id\n"                       \
  "  --name                      Filter results by name\n"                     \
  "  --moniker                   Filter results by moniker\n"                  \
  "  --tag                       Filter results by tag\n"                      \
  "  --cmd,--command             Filter results by command\n"                  \
  "  -s,--source                 Find package using the specified "            \
  "source\n"                                                                   \
  "  -n,--count                  Show no more than specified number of "       \
  "results (between 1 and 1000)\n"                                             \
  "  -e,--exact                  Find package using exact match\n"             \
  "  --header                    Optional Windows-Package-Manager REST "       \
  "source HTTP header\n"                                                       \
  "  --accept-source-agreements  Accept all source agreements during "         \
  "source operations\n"                                                        \
  "  --versions                  Show available versions of the package\n"     \
  "  -?,--help                   Shows help about the selected command\n"      \
  "  --wait                      Prompts the user to press any key "           \
  "before "                                                                    \
  "exiting\n"                                                                  \
  "  --logs,--open-logs          Open the default logs location\n"             \
  "  --verbose,--verbose-logs    Enables verbose logging for winget\n"         \
  "  --disable-interactivity     Disable interactive prompts\n"                \
  "\n"                                                                         \
  "More help can be found at: https://aka.ms/winget-command-search"            \
  "" FOOTER ""

#define INFO ""

#endif // !MY_MSG
