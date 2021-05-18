#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

class Ressource
{
    public:
    Ressource(); 
    ~Ressource();
    virtual  void show()=0;
    virtual  void load(string Filename, int position)=0;
    virtual  void save(string Filename)=0;
    virtual int search(string chaine)=0;
    virtual string showType()=0;
    virtual string showId()=0;
    virtual void setId(string ID)=0;
};

#endif