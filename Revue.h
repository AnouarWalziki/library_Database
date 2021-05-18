#ifndef REVUE_H
#define REVUE_H

#include "mediath.h"
#include "Livre.h"

class Revue : public Livre 
{
    public :
        Revue(){};
        Revue(int a);
        void show();
        void load(string Filename,int position);
        void save(string Filename);
        int search(string chaine); 
        string showType(); 
        string showId(); 
        void setId(string ID);

    private :
        string _editeur ;
        string _nbrArticle ;
        //vector <string> _tabArticle ;

} ;

#endif