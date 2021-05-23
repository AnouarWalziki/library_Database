#include "mediath.h"
#include "Livre.h"

Livre::Livre(int a) 
{
    _type = "Livre";

    cout << "Adding a Book ...\n" <<endl ;
    cin.ignore();
    cout << "Enter the new Book item's author"<< endl ;
    //getline(cin,_autheur,'\n');
    getline(cin, _autheur);

    cout << "Enter the new Book item's publication date"<< endl ;
    getline(cin, _date);

    cout << "Enter the new Book item's number of pages"<< endl ;
    getline(cin, _nbrPage);

    cout << "Enter the new Book item's collection"<< endl ;
    getline(cin, _collection);

    cout << "Enter the new Book item's title"<< endl ;
    getline(cin, _titre);

    cout << "Enter the new Book item's summary"<< endl ;
    getline(cin, _resume);
 
    cout << "Book added successfully !\n" <<endl ;

}

void Livre::show()
{
    cout << "Item's type : Book" << endl;
    cout << "Book's title :"<< _titre << endl ;
    cout << "Book's author :"<< _autheur << endl ;
    cout << "Book's publication date :"<< _date << endl ;
    cout << "Book's number of pages :"<< _nbrPage << endl ;
    cout << "Book's collection :"<< _collection << endl ;
    cout << "Book's summary :"<< _resume << endl ;
    cout << "Book's id :"<< _id << endl ;
}

void Livre::load(string Filename,int position)
{
    //int p(0);
    ifstream txtFile(Filename , ios::app) ;
    if(txtFile)    
    {
        txtFile.seekg(position, ios::beg);
        _type = "Livre";
        getline(txtFile ,_titre);
        getline(txtFile ,_autheur);
        getline(txtFile ,_date);
        getline(txtFile ,_nbrPage);
        getline(txtFile ,_collection );
        getline(txtFile ,_resume);
        getline(txtFile ,_id);
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier : " << Filename << endl;
        //return 0;
    }

}

void Livre::save(string Filename)
{
    ofstream txtFile(Filename , ios::app) ;
    if(txtFile)    
    {
        txtFile << _type <<endl;
        txtFile <<  _titre <<endl;
        txtFile <<  _autheur <<endl;
        txtFile << _date  <<endl;
        txtFile << _nbrPage <<endl;
        txtFile <<  _collection <<endl;
        txtFile <<  _resume <<endl;
        txtFile << _id <<endl;

        txtFile.close();
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier : " << Filename << endl;
    }  
   
}

int Livre::search(string chaine)
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
    found = _date.find(chaine);
    if (found!=string::npos)
     {
        r=1;
        return r; 
    } 
    found = _nbrPage.find(chaine);
    if (found!=string::npos)
    {
        r=1; 
        return r; 
    } 
    found = _collection.find(chaine);
    if (found!=string::npos)
    {
        r=1;
        return r; 
    } 
    found = _titre.find(chaine);
    if (found!=string::npos)
    {
        r=1;
        return r; 
    } 
    found = _resume.find(chaine);
    if (found!=string::npos)
    {
        r=1;
        return r; 
        
    } 
    return r; 
}

string Livre::showType()
{
    return _type;
}

void Livre::setId(string ID)
{
    _id = ID;
}

string Livre::showId()
{
    return _id;
}