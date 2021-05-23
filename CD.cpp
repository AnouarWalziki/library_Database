#include "mediath.h"
#include "CD.h"

CD::CD(int a)
{
    cout << "Adding a CD ...\n" <<endl ;
    _type = "CD";
    cin.ignore();

    cout << "Enter the new CD item's author " << endl ;
    getline(cin,_autheur);

    cout << "Enter the new CD item's duration"<< endl ;
    getline(cin, _duree);

    cout << "Enter the new CD item's Production studio" << endl ;
    getline(cin,_maisonProduc);
    
    cout << "Enter the new CD item's number of tracks" << endl ;
    getline(cin,_nbrPiste);

    cout << "CD added successfully !\n" <<endl ;

}


void CD::show()
{
    cout << "Item's type : CD" << endl;
    cout << "CD's author :" << _autheur << endl ;
    cout << "CD's duration :"<< _duree << endl ;
    cout << "CD's Production studio :" << _maisonProduc << endl ;
    cout << "CD's number of tracks :" << _nbrPiste <<endl ;
    cout << "CD's id :" << _id << endl;
}

void CD::load(string Filename, int position)
{
    ifstream txtFile(Filename , ios::app) ;
    if(txtFile)    
    {
        txtFile.seekg(position, ios::beg);
        _type = "CD";
        getline(txtFile ,_autheur);
        getline(txtFile ,_duree );
        getline(txtFile ,_maisonProduc );
        getline(txtFile ,_nbrPiste );
        getline(txtFile ,_id);
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier : " << Filename << endl;
    }
}

void CD::save(string Filename)
{
    ofstream txtFile(Filename, ios::app);
    if(txtFile)    
    {
        txtFile << _type <<endl;
        txtFile << _autheur <<endl;
        txtFile << _duree <<endl;
        txtFile << _maisonProduc <<endl;
        txtFile <<  _nbrPiste << endl;
        txtFile << _id  <<endl;

        txtFile.close();
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier : " << Filename << endl;
    } 
}

int CD::search(string chaine)
{
    int r = 0;
    size_t found;
    found = _type.find(chaine);
    if (found!=string::npos)
    {
        r=1;
        return r; 
    } 
    found = _autheur.find(chaine);
    if (found!=string::npos)
    {
        r=1; 
        return r; 
    } 
    found = _duree.find(chaine);
    if (found!=string::npos)
     {
        r=1;
        return r; 
    } 
    found = _maisonProduc.find(chaine);
    if (found!=string::npos)
    {
        r=1; 
        return r; 
    } 
    found = _nbrPiste.find(chaine);
    if (found!=string::npos)
    {
        r=1;
        return r; 
    } 
    return r; 
}

string CD::showType()
{
    return _type;
}

string CD::showId()
{
    return _id;
}

void CD::setId(string ID)
{
    _id = ID;
}