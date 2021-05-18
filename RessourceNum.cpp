#include "mediath.h"
#include "RessourceNum.h"


RessourceNum::RessourceNum(int a)
{
    _type = "RessourceNum" ;
    
    cout << "Adding a digital ressource .. \n" <<endl ;
    cin.ignore();

    cout << "Enter the new digital ressource item's name : " << endl ;
    getline(cin, _nom);

    cout << "Enter the new digital ressource item's author :"<< endl ;
    getline(cin, _autheur);

    cout << "Enter the new digital ressource item's file type :"<< endl ;
    getline(cin, _typeFile);

    cout << "Enter the new  digital ressource item's size : "<< endl ;
    getline(cin, _taille);

    cout << "Enter the new digital ressource item's path : "<< endl ;
    getline(cin, _chemin);

    cout << "Enter the new digital ressource item's id : "<< endl ;
    getline(cin, _id);
 
    cout << "Digital ressource added successfully !\n" <<endl ;
}
void RessourceNum::show()
{
    cout << "Item's type : Digital ressource " << endl ;

    cout << "Digital ressource's name :" << _nom << endl ;
    
    cout << "Digital ressource's author :" << _autheur << endl ;

    cout << "Digital ressource's file type :"<< _typeFile << endl ;

    cout << "Digital ressource's size" << _taille << endl ;

     cout << "Digital ressource's path" << _chemin << endl ;

    cout << "Digital ressource's ID" << _id << endl;

}


void RessourceNum::load(string Filename,int position)
{
    ifstream txtFile(Filename) ; 
    if (txtFile)
    {
        txtFile.seekg(position, ios::beg) ;
        _type = "RessourceNum" ;
        getline(txtFile ,_nom );
        getline(txtFile ,_autheur );
        getline(txtFile ,_typeFile); 
        getline(txtFile ,_taille);
        getline(txtFile ,_chemin); 
        getline(txtFile ,_id ) ;
        txtFile.close() ;
    }
    else 
    {
         cout << "ERROR : Failed to open file : " << Filename << endl ;
    }
}

void RessourceNum::save(string Filename)
{
    ofstream txtFile(Filename) ;
    if(txtFile)
    {
    txtFile << _nom <<endl;
    txtFile << _autheur <<endl;
    txtFile << _typeFile <<endl;
    txtFile << _taille <<endl;
    txtFile << _chemin <<endl;
    txtFile << _id <<endl;
    txtFile.close() ;

    cout << "Done !" << endl;
    cout << "" << endl;
    }
    else 
    {
         cout << "ERROR : Failed to open file : " << Filename << endl ;
    }
}


int RessourceNum::search(string chaine)
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
    found = _nom.find(chaine);
    if (found!=string::npos)
     {
        r=1;
        return r; 
    } 
    found = _typeFile.find(chaine);
    if (found!=string::npos)
    {
        r=1; 
        return r; 
    } 
    found = _taille.find(chaine);
    if (found!=string::npos)
    {
        r=1; 
        return r; 
    } 
    found = _chemin.find(chaine);
    if (found!=string::npos)
    {
        r=1; 
        return r; 
    } 
    return r; 
}

string RessourceNum::showType()
{
    return _type;
}

string RessourceNum::showId()
{
    return _id;
}

void RessourceNum::setId(string ID)
{
    _id = ID;
}