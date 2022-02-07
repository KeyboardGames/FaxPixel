//main

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "pixel.hpp"
#include "fax.hpp"

using namespace std;

int main()
{

  faxRead("test.fax");
  faxNext();
  faxRead("color.fax");
  return 0;
}