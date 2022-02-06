//read

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
int lineTL;
std::string keyFax[99999]; 
std::string lineT;

void faxRead(std::string faxF)
{
  
  int verifyFaxF=1;
  std::string line;
  std::ifstream fileF (faxF);
  if(fileF.is_open())
  {
    while(std::getline(fileF,line))
    {
      
      std::string checkTC=line;

      lineT=lineT+line;
    }
    verifyFaxF=2;
    fileF.close();
  }

  if(verifyFaxF==1)
  {

    std::cout<<"ERROR: COULDN'T READ FAX FILE"<<std::endl;
  }
  splitFax();
}

void splitFax()
{
  
  int lFax=0;
  int tFax=0;
  int ttFax=1;
  lineTL=lineT.length();
  while(lFax<lineTL)
  { 

    if(ttFax==3)
    {

    ttFax=1;
    tFax+=1;
    }

    if(ttFax==1 || ttFax==2)
    {

    keyFax[lFax]=lineT[tFax];
    tFax+=1;
    }
    ttFax+=1;
    lFax+=1;
  }
  outputFax();
}
