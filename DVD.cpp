#include "mediath.h"
#include "DVD.h"

DVD::DVD(int a)
{
    cout << "Adding a DVD ...\n" <<endl ;
    _type = "DVD";
    cin.ignore();

    cout << "Enter the new DVD item's author " << endl ;
    getline(cin,_autheur);

    cout << "Enter the new DVD item's duration"<< endl ;
    getline(cin,_duree);

    cout << "Enter the new DVD item's Production studio" << endl ;
    getline(cin,_maisonProduc);
    
    cout << "Enter the new DVD item's number of chapiters" << endl ;
    getline(cin,_nbrChapitres);

    cout << "Enter the new DVD item's id" << endl ;
    getline(cin,_id);

    cout << "DVD added successfully !\n" <<endl ;

}

void DVD::show()
{
    cout << "Item's type : DVD" << endl;
    cout << "DVD's author :" << _autheur << endl ;
    cout << "DVD's duration :"<< _duree << endl ;
    cout << "DVD's Production studio" << _maisonProduc << endl ;
    cout << "DVD's number of tracks" << _nbrChapitres << endl ;
    cout << "DVD's id" << _id << endl ;
}

void DVD::load(string Filename, int position)
{
    ifstream txtFile(Filename , ios::app) ;
    if(txtFile)    
    {
        txtFile.seekg(position, ios::beg);
        _type = "DVD";
        getline(txtFile,_autheur) ;
        getline(txtFile, _duree);
        getline(txtFile,_maisonProduc) ;
        getline(txtFile,  _nbrChapitres);
        getline(txtFile, _id );
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier : " << Filename << endl;
    }
}

void DVD::save(string Filename)
{
    ofstream txtFile(Filename, ios::app);
    if(txtFile)    
    {
        txtFile << "DVD" <<endl;
        txtFile << _autheur <<endl;
        txtFile << _duree <<endl;
        txtFile << _maisonProduc <<endl;
        txtFile <<  _nbrChapitres << endl;
        txtFile << _id  <<endl;

        txtFile.close();

        cout << "Done !" << endl;
        cout << "" << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier : " << Filename << endl;
    }
}
int DVD::search(string chaine)
{
    int r = 0;
    size_t found;
    found = _type.find(chaine); //Necessary ???
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
    found = _nbrChapitres.find(chaine);
    if (found!=string::npos)
    {
        r=1;
        return r; 
    } 
    return r; 
}

string DVD::showType()
{
    return _type;
}

string DVD::showId()
{
    return _id;
}