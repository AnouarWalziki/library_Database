#ifndef VHS_H
#define VHS_H

#include "mediath.h"
#include "Digital.h"

using namespace std;

class VHS : public Digital
{
      public :
      VHS(){};
      VHS(int a); 
      void show();
      void load(string Filename, int position);
      void save(string Filename);
      int search(string chaine);
      string showType(); 
      string showId(); 

} ;

#endif