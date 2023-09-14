#ifndef SAVE
#define SAVE

#include "json/json.h"
#include <fstream>
#include <iostream>

Json::Value Load(const char *_path);
void Save(const char *_path, Json::Value &_data);

#endif // !SAVE
