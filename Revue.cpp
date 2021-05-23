#include "mediath.h"
#include "Revue.h"

Revue::Revue(int a ) 
{
    cout << "Adding a magazine... \n" << endl;
    cin.ignore() ;

    _type = "Revue";

    cout << "Enter the new magazine item's author"<< endl ;
    getline(cin,_autheur);

    cout << "Enter the new magazine item's publication date"<< endl ;
    getline(cin,_date);

    cout << "Enter the new magazine item's number of pages"<< endl ;
    getline(cin,_nbrPage);

    cout << "Enter the new magazine item's collection"<< endl ;
    getline(cin,_collection);

    cout << "Enter the new magazine item's title"<< endl ;
    getline(cin,_titre);

    cout << "Enter the new magazine item's summary"<< endl ;
    getline(cin,_resume);

    cout << "Enter the new magazine item's editor "<< endl ;
    getline(cin,_editeur);

    cout << "Enter the new magazine item's nombre of articles "<< endl ;
    getline(cin, _nbrArticle);

    cout << "Magazine added successfully !\n" <<endl ;

}

void Revue::show()
{
    cout << "Item's type : Magazine " << _type  << endl ;

    cout << "Magazine's Author :" << _autheur << endl;

    cout << "Magazine's date :" << _date << endl;

    cout << "Magazine's nombre of pages :" << _nbrPage << endl;

    cout << "Magazine's collection :" << _collection<< endl;

    cout << "Magazine's title :" << _titre << endl;

    cout << "Magazine's summary :" << _resume << endl;

    cout << "Magazine's editor :" << _editeur << endl;

    cout << "Magazine's nombre of articles : " << _nbrArticle << endl;

    cout << "Magazine's id :" << _id << endl;

}

 void Revue::load(string Filename,int position)
 {
    ifstream txtFile(Filename , ios::app) ;
    if(txtFile)
    { 
        txtFile.seekg(position, ios::beg) ;
        _type = "Revue";
        getline(txtFile ,_autheur); 
        getline(txtFile ,_date );
        getline(txtFile ,_nbrPage);
        getline(txtFile ,_collection); 
        getline(txtFile ,_titre) ;
        getline(txtFile ,_resume) ; 
        getline(txtFile ,_editeur);
        getline(txtFile , _nbrArticle);  
        getline(txtFile ,_id ) ;
        txtFile.close() ;
    }

    else 
    {
        cout << "ERROR : Failed to open file : " << Filename << endl ;
    }
 }

 void Revue::save(string Filename)
 {
    ofstream txtFile(Filename, ios::app) ;
    if (txtFile)
    {   txtFile << _type <<endl;
        txtFile << _autheur <<endl;
        txtFile << _date <<endl;
        txtFile << _nbrPage <<endl;
        txtFile << _collection <<endl;
        txtFile << _titre <<endl;
        txtFile << _resume  <<endl;
        txtFile << _editeur  <<endl;
        txtFile << _nbrArticle  <<endl;
        txtFile << _id <<endl;

        txtFile.close() ;
    }
    else 
    {
         cout << "ERROR : Failed to open file : " << Filename << endl ;
    }
    

 }

 int Revue::search(string chaine)
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
    found = _editeur.find(chaine);
    if (found!=string::npos)
    {
        r=1;
        return r; 
        
    }
    found = _nbrArticle.find(chaine);
    if (found!=string::npos)
    {
        r=1;
        return r; 
        
    } 
    return r; 
}

string Revue::showType()
{
    return _type ;
} 

string Revue::showId()
{
    return _id;
}

void Revue::setId(string ID)
{
    _id = ID;
}