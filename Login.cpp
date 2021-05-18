#include "Login.h"


int finish   =  0 ;

LoginManager :: LoginManager()
{
    _access = 0 ;
    _end = 0 ;
}

void LoginManager::login() 
{
    string decision ;

    cout << "Please enter password. \nPassword : "<< endl ;
    cin  >> _PasswordAttempt ;

    while (_end != 2)
    {
        if ( _PasswordAttempt == "123456789")
        {   
            if (finish == 0)
            {
                cout << "You have logged in successfully " << endl ;
                _access = 1 ; 
                finish = 1 ;   
                
            }
            return ;
        }
        else 
        {
            cout << "The password is incorrect" << endl;
            cout << "If you want to check in as a client press[y] , press anything else otherwise "<< endl;
            cin >> decision ;

            if (decision == "y")
            {
                _access = 0 ;
                return ;
            }
            else
            {   
                _end ++;
                login();
            }
            
            
        }   
    }
    if (finish == 0 )
    {
        finish = 1;
        cout <<"Password wrong three times , Checking in as a client .." << endl ;
    }
    _access = 0 ;
    return ;
}


/*bool LoginManager::check(string word , string Filename ) 
{
    string line ;
    ifstream txtFile(Filename) ;
    if (txtFile)
    {
        while (txtFile.peek() != EOF)
        {
            txtFile >> line;  
            if (line == word )
                return true ;

        }
        return false ;
    }
    else 
    {
        cout << " Error : Cannot open file " << endl ;
        return false ;
    }
}*/


int LoginManager::access()
{
    return _access ;
}



