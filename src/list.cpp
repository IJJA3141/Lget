#include "./list.hpp"

/*
default             C:\test\exemple
-----------------------------------------
name                quey
name2               q
asupernameforaquery long.queyr.micrro
*/

std::ostream &operator<<(std::ostream &_stream, const List &_list) {
  int left = 20, right = 20;

  if (_list.name.size() > left)
    left = _list.name.size();
  if (_list.path.size() > right)
    right = _list.path.size();

  for (std::pair<std::string, std::string> _pair : _list.vpNQ) {
    if (_pair.first.size() > left)
      left = _pair.first.size();
    if (_pair.second.size() > right)
      right = _pair.second.size();
  }

  _stream << _list.name << std::string(left - _list.name.size() + 1, ' ')
          << _list.path << "\n"
          << std::string(left + 1 + right, '-') << "\n";
  for (std::pair<std::string, std::string> _pair : _list.vpNQ)
    _stream << _pair.first << std::string(left - _pair.first.size() + 1, ' ')
            << _pair.second << "\n";

  return _stream;
}
