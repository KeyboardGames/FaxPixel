//.bmp(24-bit) to .fax

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include "bitmap/bitmap_image.hpp"
#include "convert.hpp"
int startV=0;

void cutFax(int startI);
void convertFax(std::string fileBMP, std::string fileF);

void cutFax(int startI)
{
  startV=startI;
}

void convertFax(std::string fileBMP, std::string fileF)
{
  std::ofstream outputA;
  outputA.open(fileF.c_str());
  bitmap_image image(fileBMP);

  if(!image)
  {
    printf("Error - Failed to open: input.bmp\n");
    exit(1);
   }

  unsigned int total_number_of_pixels=0;

  const unsigned int height=image.height();
  const unsigned int width=image.width();

  std::size_t heightF;
  std::size_t widthF;
  
  int verifyT=2;
  if(startV==0)
  {
    verifyT=1;
  }
  if(verifyT==1)
  {
    heightF=height/20;
    widthF=width/10;
  }
  if(verifyT==2)
  {
    int startVV=startV*2;
    heightF=height/startVV;
    widthF=width/startV;
  }
  
  for(std::size_t y=0; y<heightF; y++)
  {
    for(std::size_t x=0; x<widthF; x++)
    {
      rgb_t colour;
      std::size_t redC=colour.red;
      std::size_t greenC=colour.green;
      std::size_t blueC=colour.blue;

      image.get_pixel(x, y, colour);
      std::cout<<"red: "<<redC<<", green: "<<greenC<<", blue: "<<blueC<<""<<std::endl;

      //white
      if(colour.red>=150 && colour.blue>=150 && colour.green>=150)
      { 
        outputA<<"wP ";
        total_number_of_pixels++;
      }
      //black
      if(colour.red<=150 && colour.blue<=150 && colour.green<=150)
      { 
        outputA<<"dP ";
        total_number_of_pixels++;
      }
      //blue
      if(colour.red<=150 && colour.blue>=150 && colour.green<=150)
      {
        outputA<<"bP ";
        total_number_of_pixels++;
      }
      //red
      if(colour.red>=150 && colour.blue<=150 && colour.green<=150)
      {
        outputA<<"rP ";
        total_number_of_pixels++;
      }
      //green
      if(colour.red<=150 && colour.blue<=150 && colour.green>=150)
      {
        outputA<<"gP ";
        total_number_of_pixels++;
      }
      //yellow
      if(colour.red<=150 && colour.blue>=150 && colour.green>=150)
      {
        outputA<<"yP ";
        total_number_of_pixels++;
      }
      }
      outputA<<"EN ";
   }
   outputA.close();

   std::cout<<"Total Amount of Pixels: "<<total_number_of_pixels<<""<<std::endl;
}