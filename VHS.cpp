#include "mediath.h"
#include "VHS.h"


VHS::VHS(int a)
{
    cout << "Adding a VHS.. \n" <<endl ;
    _type = "VHS";
    
    cin.ignore();
    cout << "Enter the new VHS item's author"<< endl ;
    //getline(cin,_autheur,'\n');
    getline(cin, _autheur);

    cout << "Enter the new VHS item's duration"<< endl ;
    getline(cin, _duree);

    cout << "Enter the new VHS item's house of production"<< endl ;
    getline(cin, _maisonProduc);
 
    cout << "VHS added successfully !\n" <<endl ;
}

void VHS::show()
{
    cout << "Item's type : VHS " << endl ;
    
    cout << "VHS's author :" << _autheur << endl ;

    cout << "VHS's duration :"<< _duree << endl ;


    cout << "VHS's Production studio" << _maisonProduc << endl ;

    cout << "VHS's ID" << _id << endl;

}


void VHS::load(string Filename,int position)
{
    ifstream txtFile(Filename) ; 
    if (txtFile)
    {
        txtFile.seekg(position, ios::beg) ;
        _type = "VHS" ;
        getline(txtFile ,_autheur );
        getline(txtFile ,_duree); 
        getline(txtFile ,_maisonProduc);
        getline(txtFile ,_id ) ;
        txtFile.close() ;
    }
    else 
    {
         cout << "ERROR : Failed to open file : " << Filename << endl ;
    }
}

void VHS::save(string Filename)
{
    ofstream txtFile(Filename) ;
    if(txtFile)
    {
    txtFile << _autheur <<endl;
    txtFile << _duree <<endl;
    txtFile << _maisonProduc <<endl;
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


int VHS::search(string chaine)
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
    return r; 
}

string VHS::showType()
{
    return _type;
}

string VHS::showId()
{
    return _id;
}

void VHS::setId(string ID)
{
    _id = ID;
}