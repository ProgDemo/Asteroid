#include <iostream>
#include "Analyze.h"

int main()
{
    analyzeWeight("input.txt", 1000);
    analyzeDistance("input.txt");
    analyzeDistanceFromEarth("input.txt");

    analyzeDistance("bad.txt");
    analyzeDistance("");
    return 0;
}
