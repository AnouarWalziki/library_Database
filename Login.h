#ifndef LOGIN_H
#define LOGIN_H


#include <iostream>
#include <fstream>

using namespace std;

class LoginManager
{
    public :
        LoginManager() ;
        void login() ;
        bool check(string word , string Filename ) ;


    private : 
        string _Password;
        string _Username;
        string _UsernameAttempt;
        string _PasswordAttempt;
        int _access ; 
} ;


























#endif