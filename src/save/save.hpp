#ifndef SAVE
#define SAVE

#include "../json/json.h"
#include <fstream>
#include <iostream>

#include <fstream>

Json::Value Load(const char *_path);
void Save(Json::Value &_data);

#endif // !SAVE
