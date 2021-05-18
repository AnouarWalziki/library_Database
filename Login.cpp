#include "Login.h"




LoginManager :: LoginManager()
{
    _access = 0 ;
}

void LoginManager::login() 
{
    cout << "Please Enter your username. \nUsername : "<< endl ;
    cin  >> _UsernameAttempt ;

    cout << "Please Enter your password. \nPassword : "<< endl ;
    cin  >> _PasswordAttempt ;

    if (check(_UsernameAttempt , "username.txt") & check(_PasswordAttempt , "password.txt" ))
    {
        cout << "You have logged in successfully " << endl ;
        _access = 1 ; 
    }
    else 
    {
        cout << "The username or the password is incorrect" << endl;
        _access = 0 ;
    }

}


bool LoginManager::check(string word , string Filename ) 
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
}

int main()
{
    LoginManager *app ;
    app = new LoginManager ;
    app->login() ;
    return 0;
}

