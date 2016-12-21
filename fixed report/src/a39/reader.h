#ifndef READER_H
#define READER_H

#include <iostream>

bool isFolder(std::string path);

void countBytes(bool &status, size_t &bytes, std::string path);
void timeProcess(bool &status);

size_t openFolder(std::string path);

#endif
