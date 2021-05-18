#ifndef LIVRE_H
#define LIVRE_H

#include "mediath.h"
#include "Ressource.h"

using namespace std;

class Livre :  public Ressource
{
    public :
        Livre(int a);
        Livre(){};
        void show();
        void load(string Filename,int position);
        void save(string Filename);
        int search(string chaine);
        string showType();
        string showId();
        void setId(string ID);

    protected :
        string _type; //a ajouter pour les autres
        string _autheur ;
        string _date ;
        string _nbrPage ;
        string _collection ;
        string _titre ; 
        string _resume ;
        string _id ;


} ;

#endif

