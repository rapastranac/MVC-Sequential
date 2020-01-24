#ifndef MAIN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define MAIN_H

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "util.h"
#include <mutex>
#include <thread>

#include "ParGreedy.h"

extern size_t maxThreads;
extern size_t maxDepth;
extern size_t measured_Depth;
extern size_t MVCSize;
extern size_t leaves;
extern size_t numThreads;
std::vector<int> MVC(ParGreedy&, std::vector<int>&, int, int, int);

void printResults(std::vector<int>& VCMin, double elapsed_secs);
#endif