#ifndef DIGITAL_H
#define DIGITAL_H

#include "mediath.h"
#include "Ressource.h"

class Digital : virtual public Ressource
{
    public :
        Digital(){};
        string _type;
        string _duree ;
        string _autheur ;
        string _maisonProduc ;
        string _id ;


} ;

#endif