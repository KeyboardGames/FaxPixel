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

  system("clear");
  
 // cout<<"\033[1;31m███\033[0m";
 // cout<<"\033[1;34m███\033[0m\n";
  faxRead("color.fax");
  return 0;
}