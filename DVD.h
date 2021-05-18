#ifndef DVD_H
#define DVD_H

#include "mediath.h"
#include "Digital.h"

using namespace std;

class DVD :  public Digital
{
    public :
        DVD(){};
        DVD(int a);
        void show();
        void load(string Filename, int position);
        void save(string Filename);
        int search(string chaine); // indefinie
        string showType(); // indefinie
        string showId(); // indefinie
        void setId(string ID);
    
    private:
        string _nbrChapitres ;
} ;


#endif