#ifndef SAVE
#define SAVE

#include "json/json.h"
#include <fstream>
#include <iostream>

Json::Value Load(const char *_path);
void Save(Json::Value &_data, const char *_path);

#endif // !SAVE
