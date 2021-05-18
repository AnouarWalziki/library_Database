#ifndef MEDIATH_H
#define MEDIATH_H


#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>

#include "Ressource.h"
#include "Livre.h"
#include "Revue.h"
#include "Digital.h"
#include "CD.h"
#include "DVD.h"
#include "VHS.h"
#include "RessourceNum.h"
#include "Login.h"


using namespace std;

class Mediatheque
{
    public:
    Mediatheque();
    ~Mediatheque();
    void add();
    void loadM();
    void reLoad();
    void saveM(LoginManager *user);
    void showM();
    void search();
    void clear();
    void reset();
    void deleteId();
    void list() ;
    int quit(Mediatheque *M);
   

    vector<Ressource*> _objects;
    vector<Ressource*> _Recherche;
    int _searchOn;
    string _currentFile;

    
};

#endif