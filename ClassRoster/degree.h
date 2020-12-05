#pragma once
#include <string>

/* C. Define an enumerated data type DegreeProgram for the degree programs 
      containing the data type values SECURITY, NETWORK, and SOFTWARE. */
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// array to return corresponding string value of enums
static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };