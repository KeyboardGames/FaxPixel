//.bmp(24-bit) to .fax

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include "bitmap/bitmap_image.hpp"
#include "convert.hpp"

void faxConvert(std::string fileBMP, std::string fileF);

void faxConvert(std::string fileBMP, std::string fileF)
{
  std::ofstream outputA;
  outputA.open(fileF.c_str());
  bitmap_image image(fileBMP);

  if(!image)
  {
    std::cout<<"Error - Failed to open: "<<fileBMP<<""<<std::endl;
    exit(1);
   }

  unsigned int total_number_of_pixels=0;

  const unsigned int height=image.height();
  const unsigned int width=image.width();
  
  for(std::size_t y=0; y<height; y++)
  {
    for(std::size_t x=0; x<width; x++)
    {
      rgb_t colour;
      std::size_t redC=colour.red;
      std::size_t greenC=colour.green;
      std::size_t blueC=colour.blue;

      image.get_pixel(x, y, colour);

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
      if(colour.red>=150 && colour.blue>=150 && colour.green<=150)
      {
        outputA<<"yP ";
        total_number_of_pixels++;
      }
      //magenta
      if(colour.red>=150 && colour.blue>=150 && colour.green<=150)
      {
        outputA<<"mP ";
        total_number_of_pixels++;
      }
      //cyan
      if(colour.red<=150 && colour.blue>=150 && colour.green>=150)
      {
        outputA<<"cP ";
        total_number_of_pixels++;
      }
      }
      outputA<<"EN ";
   }
   outputA.close();
}
