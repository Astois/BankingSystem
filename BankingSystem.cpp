#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

void Register() {
    string name;
    string password;
    string password2;
    string email;
    string phone;
    

    cout << "what is your name?: ";
    cin >> name;
    cout << "what do you want Your Password to be?: ";
    cin >> password;
    cout << "Confirm Your Password: ";
    cin >> password2;
     while(password2 != password){
        cout << "Passwords do not match, please try again: ";
        cin >> password2;

    }
    cout << "what email do you want to use?";
    cin >> email;
    char Symbol = '@';
    while (email.find(Symbol) == string::npos){
        cout << "Invalid email, please try again: ";
        cin >> email;
    }


    cout << "what phone number do you want to use?";
    cin >> phone;
    string first2numbers = "07";
    while (phone.find(first2numbers) == string::npos){
        cout << "Invalid phone number, please try again: ";
        cin >> phone;
    }


    //Create and Write data to a text file
    ofstream MyFile(name+".txt");
    MyFile << name << endl << password << endl << email << endl << phone;
    MyFile.close();


}
void Login(){
    string Name, Password, na, pw;

    cout << "Enter your Name: "; cin >> Name;
    cout << "Enter Password: "; cin >> Password;
    ifstream read(Name+".txt");
    getline(read, na);
    getline(read, pw);

    if(Name == na && Password == pw){
        cout << "Login Successful!" << endl; }

    else{
        cout << "Login Unsuccessful!" << endl;
    }

    read.close();
    }

int main() {
    int answ;
    cout << "Do you want to Register(1) or Login(2)...";
    cin >> answ;
    if (answ == 1) {
        Register();
    }
    else{
        Login();
    }


char c;
std::cin >> c;
return 0;

}