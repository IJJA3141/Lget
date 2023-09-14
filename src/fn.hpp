#ifndef FN
#define FN

#include <string>
#include <vector>

void add(const char *_list, const char *_query,
         std::vector<std::string> &_vArgs);
void remove(const char *_list, const char *_query, std::vector<std::string> &_);
void make(const char *_list, const char *_path,
          std::vector<std::string> &_vArgs);
void install(const char *_list, std::vector<std::string> &_vArgs);
void uninstall(const char *_list, const char *_query,
               std::vector<std::string> &_vArgs);
void show(const char *_list, const char *_query,
          std::vector<std::string> &_vArgs);
void path();

#endif // !FN
