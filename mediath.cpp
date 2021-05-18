#include "mediath.h"

int searchWarning = 1; // if equals 1, show switching from library database to research data base warning
int IdCounter = 0; //usefull for defining item's id 
int loadCounter = 0;
int Load = 0;

Mediatheque::Mediatheque()
{
    cout << "Launching the Library database manager ..." << endl;
    _objects.clear();
    cout << "--------------------------------------" << endl;

}


Mediatheque::~Mediatheque()
{
    cout << "Deleting the media library database ..." << endl;
    for (int i=0; i< _objects.size(); i++)
    {
        delete _objects.at(i);
    }
    for (int i=0; i< _Recherche.size(); i++)
    {
        delete _Recherche.at(i);
    }
     _objects.clear();
     _Recherche.clear();
}


void Mediatheque::add()
{
    int type(0);

    if (_searchOn ==1)
    {
        //_Recherche.push_back(livre);
        cout << "You can't add an item, you are in search mode." << endl;
        cout << "" << endl;
    }
    else
    {
        ofstream txtFile("objects.txt" , ios::app) ;

        cout << "Please select the new item's type by typing the number that matches your choice :"<< endl ;
        cout << "1 - Book"<< endl;
        cout << "2 - Magazine"<< endl;
        cout << "3 - CD"<< endl;
        cout << "4 - DVD"<< endl;
        cout << "5 - VHS "<< endl;
        cout << "6 - Digital ressource" << endl;
        cout << "" << endl;
        cout << "Your choice :";
        cin >> type;
        cout << "--------------------------------------" << endl;

        switch(type)
        {
            case 1:
                Livre *livre;
                livre = new Livre(0);
                livre->setId(to_string(IdCounter));
                IdCounter++;
                 _objects.push_back(livre);
                
                
                break; 
            case 2:
                Revue *revue;
                revue = new Revue(0);
                revue->setId(to_string(IdCounter));
                IdCounter++;
                _objects.push_back(revue);
               
                break;  

            case 3:
                CD *cd;
                cd = new CD(0);
                cd->setId(to_string(IdCounter));
                IdCounter++;
                _objects.push_back(cd);
                break;

            case 4:
                DVD *dvd;               
                dvd = new DVD(0);
                dvd->setId(to_string(IdCounter));
                IdCounter++;
                _objects.push_back(dvd);
                break;

            case 5:
                VHS *vhs;
                vhs = new VHS(0);
                vhs->setId(to_string(IdCounter));
                IdCounter++;
                _objects.push_back(vhs);
                break;  

            case 6:
                RessourceNum *rsn;
                rsn= new RessourceNum(0);
                cd->setId(to_string(IdCounter));
                IdCounter++;
                _objects.push_back(rsn);
                break;  
        }

    }
    cout << "--------------------------------------" << endl;
} 


void Mediatheque::loadM()
{
    string type;
    int position(0);

    ifstream Idfile("Id.txt");
    if(Idfile)
    {
        Idfile >> IdCounter;
    
        Idfile.close() ;
    }
    else 
    {
        cout << "ERROR : Failed to open file : " << "Id.txt"<< endl ;
    }

    if (_searchOn ==1)
    {
        //_Recherche.push_back(livre);
        cout << "You can't load items, you are in search mode." << endl;
        cout << "" << endl;
    }
    else
    {
        cout << "Please type the text file name from where you want to load items : ";
        cin >> _currentFile;
        cout << "" << endl;

        cout << "Loading items from the following text file : " << _currentFile <<endl;
        cout << "" << endl;

        ifstream txtFile(_currentFile , ios::app) ;
        if(txtFile)    
        {
            while(txtFile.peek() != EOF)
            {
                getline(txtFile ,type);
                position = txtFile.tellg();

                if (type =="Livre")
                {
                    Livre *livre;
                    livre = new Livre();
                    livre->load(_currentFile,position);
                    _objects.push_back(livre);
                    loadCounter++;
                }

                if (type =="CD")
                {
                    CD *cd;
                    cd = new CD();
                    cd->load(_currentFile,position);
                    _objects.push_back(cd);
                    loadCounter++;
                }

                if (type =="DVD")
                {
                    DVD *dvd;
                    dvd = new DVD();
                    dvd->load(_currentFile,position);
                    _objects.push_back(dvd);
                    loadCounter++;
                }

                if (type == "Revue")
                {
                    Revue *revue;
                    revue = new Revue();
                    revue->load(_currentFile,position);
                    _objects.push_back(revue);
                    loadCounter++;
                }

                if (type == "Revue")
                {
                    VHS *vhs;
                    vhs = new VHS();
                    vhs->load(_currentFile,position);
                    _objects.push_back(vhs);
                    loadCounter++;
                }
            
            }

            txtFile.close();
            Load = 1;
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier : " << _currentFile << endl;
        }

        if (loadCounter != 0)
        {
            cout << loadCounter << " item(s) was(were) loaded!" << endl;

        }
        else
        {
            cout << "No item(s) was(were) loaded)!" << endl;
        }
    }
    cout << "--------------------------------------" << endl;

}


void Mediatheque::reLoad()
{
    int position = 0;
    string type;

    if (Load == 0)
    {
        cout << "No file have been loaded yet ! Please first, use \"load\" option in the main menu. " << endl;
        cout << "--------------------------------------" << endl;
        return;
    }
    _objects.clear(); //deleting all current database items

    cout << "Updating database items ..." << endl;
    cout << "" << endl;
    
    ifstream txtFile(_currentFile , ios::app) ; //adding items from file used to first load items into the database
        if(txtFile)    
        {
            while(txtFile.peek() != EOF)
            {
                getline(txtFile ,type);
                position = txtFile.tellg();

                if (type =="Livre")
                {
                    Livre *livre;
                    livre = new Livre();
                    livre->load(_currentFile,position);
                    _objects.push_back(livre);
                }

                if (type =="CD")
                {
                    CD *cd;
                    cd = new CD();
                    cd->load(_currentFile,position);
                    _objects.push_back(cd);
                }

                if (type =="DVD")
                {
                    DVD *dvd;
                    dvd = new DVD();
                    dvd->load(_currentFile,position);
                    _objects.push_back(dvd);
                }

                if (type == "Revue")
                {
                    Revue *revue;
                    revue = new Revue();
                    revue->load(_currentFile,position);
                    _objects.push_back(revue);
                }

                if (type == "Revue")
                {
                    VHS *vhs;
                    vhs = new VHS();
                    vhs->load(_currentFile,position);
                    _objects.push_back(vhs);
                }
            
            }

            txtFile.close();
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier : " << _currentFile << endl;
        }

        cout << "" << endl;
        cout <<"Database updated !" << endl;
        cout << "--------------------------------------" << endl;

}


void Mediatheque::saveM(LoginManager *user)
{
    string decision;
    string Filename;
    cout << "Please type the text file name where you want to save current items :" <<endl;
    cin >> Filename;

    ofstream Idfile("Id.txt");
    if(Idfile)
    {
        Idfile << IdCounter <<endl;
    
        Idfile.close() ;
    }
    else 
    {
        cout << "ERROR : Failed to open file : " << "Id.txt"<< endl ;
    }

    if (_searchOn == 1)
    {
            if (Filename == "items.txt")
            {
                cout << "You can't save search result to database file !" << endl;
                cout << "--------------------------------------" << endl;
                return;
            }
            else
            {
                std::ofstream ofs;
                ofs.open(Filename, std::ofstream::out | std::ofstream::trunc);  // clearing text file
                ofs.close();

                cout << "Saving current items in the following text file :" << Filename <<endl;

                for (int i=0; i< _Recherche.size(); i++)
                {
                    _Recherche.at(i)->save(Filename);
                }
                
                cout << "Search result(s) has(have) been saved !" << endl;
                cout << "--------------------------------------" << endl;
                return;
            } 
    }
    else if (_searchOn ==0)
    {
        if (user->access() == 0)
        {
            if (Filename == "items.txt")
            {
                cout << "You can't save search result to database file !" << endl;
                return;
            }
            else
            {
                std::ofstream ofs;
                ofs.open(Filename, std::ofstream::out | std::ofstream::trunc);  // clearing text file
                ofs.close();

                cout << "Saving current items in the following text file :" << Filename <<endl;

                for (int i=0; i< _objects.size(); i++)
                {
                    _objects.at(i)->save(Filename);
                }

                cout << "\n The database has been saved !" << endl;
                cout << "--------------------------------------" << endl;
                return;
                
            } 
        }
        else if (user->access() == 1)
        {
            if (Filename == "items.txt")
            {
                cout << "Are you sure you want to update the database ? [Y]es or [N]o : ";
                cin >> decision;
                while(1)
                {
                    if (decision == "Y")
                    {
                        std::ofstream ofs;
                        ofs.open(Filename, std::ofstream::out | std::ofstream::trunc);  // clearing text file
                        ofs.close();

                        for (int i=0; i< _objects.size(); i++)
                        {
                            _objects.at(i)->save(Filename);
                        }


                        cout << "\n The database has been updated !" << endl;
                        cout << "--------------------------------------" << endl;
                        return;
                    } 
                    else if (decision == "N")
                    {
                        cout << "Returning to the main menu." << endl;
                        cout << "--------------------------------------" << endl;
                        return;
                    }
                    else 
                    {
                        cout << "Please type a valid choice : ";
                        cin >> decision;
                    }
                }
            }
            else if (Filename != "items.txt")
            {
                std::ofstream ofs;
                ofs.open(Filename, std::ofstream::out | std::ofstream::trunc);  // clearing text file
                ofs.close();

                for (int i=0; i< _objects.size(); i++)
                {
                    _objects.at(i)->save(Filename);
                }

                cout << "\n The database has been saved !" << endl;
                cout << "--------------------------------------" << endl;
                return;
            }
        }

    }  
}


void Mediatheque::showM()
{
    string id; //id of the item that user want to see it's details

    if (_objects.empty())
    {
        cout << "This database is empty"<< endl ;
    }
    else
    {
        cout << "Please type the item's id : ";
        cin >> id;
        cout << "" << endl;

        for (int i=0; i< _objects.size(); i++)
        {
            if (id == _objects.at(i)->showId())
            {
                _objects.at(i)->show();
                cout << "" << endl;
            }
        }
    }
    

    cout << "--------------------------------------" << endl;
}


void Mediatheque::search() 
{
    int i = 0;
    int found =0;
    string chaine;
    vector<Ressource*> _RechercheTmp;
    
    cout << "Please type your search :";
    cin >> chaine;

    if (_searchOn ==0) //first search
    {
        for (int i=0; i< _objects.size(); i++)
        {
            if ((_objects.at(i))->search(chaine) == 1)
            {
                _Recherche.push_back(_objects.at(i));
                found++;
            }
        }
        if (found != 0)
        {
            if (searchWarning == 1)
            {
                cout << "" << endl;
                cout <<"+----------------------------------------------------------------------------------+" << endl;
                cout <<"|Please note that all commands from now on will be applied to the research results.|" << endl;
                cout <<"|To restore your database please choose \"Clear log\" at the main menu.              |" << endl;
                cout <<"+----------------------------------------------------------------------------------+" << endl;
                cout << "" << endl;
                searchWarning = 0;
            }
            _searchOn = 1;
        }      
    }
    else // case for a second or more searches
    {
        for (int i=0; i< _Recherche.size(); i++)
        {
            if ((_Recherche.at(i))->search(chaine) == 1)
            {
                _RechercheTmp.push_back(_Recherche.at(i));
                found++;
            }
        }

        if(found != 0)
        {
            _Recherche.clear(); //-----------------
            for (int i=0; i< _RechercheTmp.size(); i++)
            {
                _Recherche.push_back(_RechercheTmp.at(i));
            }           
        }
        _RechercheTmp.clear(); //--------------
    } 

    if (found != 0)
    {
        cout << found << " item(s) was(were) found !" << endl;
        _searchOn = 1;
    }
    else
    {
        cout << "No item(s) match(s) you search !" << endl;
    }

    
    cout << "--------------------------------------" << endl;
}


void Mediatheque::clear()
{
    string decision ;
    cout << "Are you sure? [Y]es or [N]o : ";
    cin >> decision;

    while (decision!="Y" && decision!="N")
    {
        cout << "Please enter a valid choice : ";
        cin >> decision;
    }

    if (decision =="Y")
    {
        _Recherche.clear(); // clears research data

        _searchOn = 0; // turn off search mode

        searchWarning = 1;

        cout << "" << endl;
        cout << "All research data have been deleted !" << endl;

        cout << "" << endl;
        cout << "Current library database restored !" << endl;
        cout << "--------------------------------------" << endl;
    }
    if (decision =="N")
    {
        cout << "Switching back to main menu ..." << endl;
        cout << "--------------------------------------" << endl;  
    }
    
}


void Mediatheque::reset()
{    
    string decision ;
    cout << "Are you sure? [Y]es or [N]o : ";
    cin >> decision;
    cout << "" << endl;

    while (decision!="Y" && decision!="N")
    {
        cout << "Please enter a valid choice : ";
        cin >> decision;
        cout << "" << endl;
    }
    if (decision =="Y")
    {
        cout << "Deleting all items from the database ..." << endl;
        IdCounter = 0;
        loadCounter = 0;
        _Recherche.clear();
        _searchOn=0;
        Load = 0;
        _objects.clear();
        cout << "" << endl;
        cout << "Done !" << endl;
    }
    if (decision =="N")
    {
        cout << "Switching back to main menu ..." << endl;
    }
    cout << "--------------------------------------" << endl;
}


void Mediatheque::deleteId()
{
    string id;
    cout << "Please enter the item's id : ";
    cin >> id ;
    cout << "" << endl;

    for (int i=0; i< _objects.size(); i++)
    {
        string  chaine = _objects.at(i)->showId();
        if ( chaine == id ) 
            {
               _objects.erase(_objects.begin() + i);
               cout << "The item with the id : \" "<< id << " \" is deleted. \n" << endl ;
               return;
            }
    }
    cout << "There is no item in this database with this id."<< endl ;

    cout << "--------------------------------------" << endl;
}


void Mediatheque::list() 
{
    if (_objects.empty())
    {
        cout << "This database is empty"<< endl ;
    }
    else
    {
        cout << "Entire object database :" << endl;
        cout << "" << endl;

        if (_searchOn ==1)
        {
            for (int i=0; i< _Recherche.size(); i++)
            {
            cout << (_Recherche.at(i))->showType() << endl;
            cout << (_Recherche.at(i))->showId() << endl;
            cout << "" << endl;
            }
        }
        else
        {
            for (int i=0; i< _objects.size(); i++)
            {
            cout << (_objects.at(i))->showType() << endl;
            cout << (_objects.at(i))->showId() << endl;
            cout << "" << endl;
            }
        }
    }
    cout << "--------------------------------------" << endl;     
}


int Mediatheque::quit(Mediatheque *M) 
{ 
    string decision ;
    cout << "Are you sure? [Y]es or [N]o : ";
    cin >> decision;

    while (decision!="Y" && decision!="N")
    {
        cout << "Please enter a valid choice : "; 
        cin >> decision;
    }

    if (decision =="Y")
    {
        //cout << "Deleting allocated ressources ..." << endl;
        cout << "" << endl;
        delete M;
        cout << "" << endl;
        cout << "Successfully Completed!" << endl;
        cout << "" << endl;
        cout << "Thank you for using this database" << endl;
        cout << "--------------------------------------" << endl;  
        return 1; // quit programm 
    }
    if (decision =="N")
    {
        cout << "" << endl;
        cout << "Switching back to main menu ..." << endl;
        cout << "--------------------------------------" << endl;  
        return 0; // go back to main
    }
    return 0; // will be ignored
}




