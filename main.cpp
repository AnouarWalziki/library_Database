#include "mediath.h"
#include "Login.h"
#include <typeinfo>
#include<limits>

using namespace std;

int flag = 0 ; // if equals 1 we show the startup message
int leave = 0; // if equals 0 we quit the program

int main()
{
   Mediatheque* M;
   M = new Mediatheque(); // creating a library object
   LoginManager *L;
   L = new LoginManager();


   string id ; // id of the element to delete
   int choice ; // user command choice

   
   if (flag ==0)
   {
       flag = 1;
       cout << "+-----------------------------+" << endl;
       cout << "|Library database manager V0.0|" << endl;
       cout << "|Programmed by :              |" << endl;
       cout << "|Anouar WALZIKI               |" << endl;
       cout << "|&                            |" << endl;
       cout << "|Souhail Assal                |" << endl;
       cout << "+-----------------------------+" << endl;
       cout << "" << endl;
       cout << "--------------------------------------" << endl;
       L->login();
       cout << "--------------------------------------" << endl;
   }
   while (leave != 1)
   {
       if (L->access() == 1)
       {
            cout << "" << endl;
            cout <<"+-----------+" << endl;
            cout <<"| Main menu |:" << endl;
            cout <<"+-----------+" << endl;
            cout << "" << endl;

            cout << "Please choose one of the following commands to execute :" << endl;
            cout << "" << endl;

            cout << "1.Add a new object"<< endl ;
            cout << "2.Load items from a text file" << endl;        
            cout << "3.Search for an object"<< endl ;
            cout << "4.Display all items at the database (items's type and id)" << endl;
            cout << "5.Show an item's details" << endl;
            cout << "6.Clear log" << endl ;
            cout << "7.Delete an item" << endl;
            cout << "8.Save current items" << endl;
            cout << "9.Reload database " << endl;
            cout << "10.Reset the database" << endl;
            cout << "11.Exit" << endl ;

            cout << "" << endl;
            cout << "Your choice : ";
            
            cin >> choice ;

            while(1) 
                {
                if(cin.fail() | (choice<1 | choice>11)) // test if user typed a valid number or not
                    {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "" << endl;
                    cout << "You have entered wrong input"<<endl;
                    cout << "Please enter a valid choice :";
                    cin >> choice ;
                    cout << "" << endl;
                    }
                if(!cin.fail() && ((choice>=1 && choice<=11)) )
                break;
                }
            

            cout << "--------------------------------------" << endl;
            
            switch (choice)
            {
                case 1:
                    M->add();
                    break;
                case 2:
                    M->loadM();
                    break;            
                case 3 :
                    M->search ();
                    break;
                case 4 :
                    M->list() ;
                    break;
                case 5 :
                    M->showM();
                    break;
                case 6:
                    M->clear();
                    break;
                case 7 :
                    M->deleteId();
                    break ;
                case 8:
                    M->saveM();
                    break;
                case 9:
                    M->reLoad();
                    break;
                case 10:
                    M->reset();
                    break;
                case 11:
                    leave = M->quit(M) ; 
                    break;         
            }
        }
        else
        {
            cout << "" << endl;
            cout <<"+-----------+" << endl;
            cout <<"| Main menu |:" << endl;
            cout <<"+-----------+" << endl;
            cout << "" << endl;

            cout << "Please choose one of the following commands to execute :" << endl;
            cout << "" << endl;

            cout << "1.Load items from a text file" << endl;        
            cout << "2.Search for an object"<< endl ;
            cout << "3.Display all items at the database (items's type and id)" << endl;
            cout << "4.Show an item's details" << endl;
            cout << "5.Clear log" << endl ;
            cout << "6.Save current items" << endl;
            cout << "7.Reload database " << endl;
            cout << "8.Exit" << endl ;

            cout << "" << endl;
            cout << "Your choice : ";
            
            cin >> choice ;

            while(1) 
                {
                if(cin.fail() | (choice<1 | choice>8)) // test if user typed a valid number or not
                    {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "" << endl;
                    cout << "You have entered wrong input"<<endl;
                    cout << "Please enter a valid choice :";
                    cin >> choice ;
                    cout << "" << endl;
                    }
                if(!cin.fail() && ((choice>=1 && choice<=8)) )
                break;
                }
            

            cout << "--------------------------------------" << endl;
            
            switch (choice)
            {
                case 1:
                    M->loadM();
                    break;            
                case 2 :
                    M->search ();
                    break;
                case 3 :
                    M->list() ;
                    break;
                case 4 :
                    M->showM();
                    break;
                case 5:
                    M->clear();
                    break;
                case 6:
                    M->saveM();
                    break;
                case 7:
                    M->reLoad();
                    break;
                case 8:
                    leave = M->quit(M) ; 
                    break;         
            }
        }   
   }
    return 0;
}