#ifndef CD_H
#define CD_H

#include "mediath.h"
#include "Digital.h"

using namespace std;

class CD :  public Digital 
{
    public :
        CD(){};
        CD(int a);
        void show();
        void load(string Filename, int position);
        void save(string Filename);
        int search(string chaine);
        string showType(); 
        string showId(); 
        void setId(string ID);
        
    private :
        string _nbrPiste;
} ;


#endif