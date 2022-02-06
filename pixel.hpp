//read

#ifndef pixel_INCLUDE
#define pixel_INCLUDE

void faxRead(std::string faxF);
void splitFax();
void chopFax();

extern int lineTL;
extern std::string lineT;
extern std::string keyFax[999];

#endif