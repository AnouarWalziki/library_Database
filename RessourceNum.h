#ifndef RessourceNum_H
#define RessourceNum_H

#include "mediath.h"
#include "Digital.h"

using namespace std;

class RessourceNum  : public Ressource
{
    public :
        RessourceNum(){};
        RessourceNum(int a);
        void show();
        void load(string Filename, int position);
        void save(string Filename);
        int search(string chaine);
        string showType(); 
        string showId(); 
        
    private :
        string _type;
        string _nom ;
        string _autheur;
        string _typeFile;
        string _taille ;
        string _chemin ;
        string _id ;
} ;


#endif