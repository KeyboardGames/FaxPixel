//output

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "fax.hpp"
#include "pixel.hpp"

void outputFax()
{
  int iC=0;
  int endFaxL=1;
  lineTL=lineT.length();
  while(iC<lineTL)
  {
    
    //space
    if(keyFax[iC]==("s") && keyFax[iC+1]==("P"))
    {

      std::cout<<" ";
    }

    //black
    if(keyFax[iC]==("d") && keyFax[iC+1]==("P"))
    {
      
      std::cout<<"\033[1;30m█\033[0m";
    }

    //red
    if(keyFax[iC]==("r") && keyFax[iC+1]==("P"))
    {
      
      std::cout<<"\033[1;31m█\033[0m";
    }
    
    //green
    if(keyFax[iC]==("g") && keyFax[iC+1]==("P"))
    {

      std::cout<<"\033[1;32m█\033[0m";
    }

    //yellow
    if(keyFax[iC]==("y") && keyFax[iC+1]==("P"))
    {

      std::cout<<"\033[1;33m█\033[0m";
    }

    //blue
    if(keyFax[iC]==("b") && keyFax[iC+1]==("P"))
    {

      std::cout<<"\033[1;34m█\033[0m";
    }

    //magenta
    if(keyFax[iC]==("m") && keyFax[iC+1]==("P"))
    {

      std::cout<<"\033[1;35m█\033[0m";
    }

    //cyan
    if(keyFax[iC]==("c") && keyFax[iC+1]==("P"))
    {

      std::cout<<"\033[1;36m█\033[0m";
    }

    //white
    if(keyFax[iC]==("w") && keyFax[iC+1]==("P"))
    {

      std::cout<<"\033[1;37m█\033[0m";
    }

    //end
    if(keyFax[iC]==("E") && keyFax[iC+1]==("N"))
    {

      std::cout<<""<<std::endl;
      endFaxL=2;
    }
    iC+=1;
  }

  if(endFaxL==1)
  {

  std::cout<<""<<std::endl;
  }
  endFaxL=1;
}
