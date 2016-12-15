#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <mutex>

bool isFolder(std::string path);

void countBytes(std::mutex &sMutex, bool &status, size_t &bytes, std::string path);
void timeProcess(std::mutex &sMutex, bool &status);

size_t openFolder(std::string path);

#endif
