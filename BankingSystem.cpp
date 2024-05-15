#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;
string NameUNI;
void Register(){
    string Name, Password, Password1, Email, PhoneNumber;

    cout << "Enter Your Name: ";
    cin >> Name;
    cout << "Enter Your Password: ";
    cin >> Password;
    cout << "confirm Password: ";
    cin >> Password1;
    while(Password != Password1){
        cout << "Password Not Matched" << endl;
        cout << "confirm Password: ";
        cin >> Password1;

    }

    cout << "Enter Your Email: ";
    cin >> Email;
    char Symbol = '@';
    while (Email.find(Symbol) == string::npos){
        cout << "Invalid Email!";
        cout << "Enter Your Email: ";
        cin >> Email;
    }

    cout << "Enter Your Phone Number: ";
    cin >> PhoneNumber;
    string first2numbers = "07";
    while (PhoneNumber.find(first2numbers) == string::npos){
        cout << "Invalid Number!";
        cout << "Enter Your Phone Number: ";
        cin >> PhoneNumber;
    }
//THIS CREATES THE FILES THAT STORE THE USERLOGIN AND USERBANK DATA
    ofstream Myfile("E:\\Library\\C++\\BankingSystem\\UserLogin\\" + Name + ".txt");
    Myfile << Name << endl << Password << endl << Email << endl << PhoneNumber << endl;
    Myfile.close();

    ofstream MyData("E:\\Library\\C++\\BankingSystem\\UserData\\" + Name + "Data.txt");
    float Balance = 10;
    int CardNumber = rand() %9999999999999999 + 11111111111111111;
    int SortCode = rand() %999999 + 100000;
    MyData << Balance << endl << CardNumber << endl << SortCode;
    MyData.close();
    cout << "Account Created Successfully!";


}
void Login(){
    string Name, Password, Pw;

    cout << "Enter Your Name: ";
    cin >> NameUNI;
    ifstream read("E:\\Library\\C++\\BankingSystem\\UserLogin\\" + NameUNI + ".txt");
    getline(read, Name);
    getline(read, Password);
    read.close();

    cout << "Enter Your Password: ";
    cin >> Pw;
    while(Pw != Password){
        cout << "Incorrect Password!";
        cout << "Enter Your Password Again: ";
        cin >> Pw;
    }
    if(Pw == Password){
        string Balance;
        string CardNumber, SortCode;
        cout << "Login Successful!"<< endl;
        cout << "Welcome " << Name << "!" << endl;
        ifstream MyData("E:\\Library\\C++\\BankingSystem\\UserData\\" + NameUNI + "Data.txt");
        getline(MyData, Balance);
        getline(MyData, CardNumber);
        getline(MyData, SortCode);
        MyData.close();
        cout << "Balance: " << Balance << endl;
        cout << "CardNumber: " << CardNumber << endl;
        cout << "SortCode: " << SortCode << endl;
    }

}

void Transfer(){
    string Tname, Tbalance, Tcardnumber, Tsortcode, Sortcode;
    int TransferAmmount, Tbalancei;
    cout << "What is the name of the user you want to transfer to? "<< endl;
    cin >> Tname;
    ifstream TDetails("E:\\Library\\C++\\BankingSystem\\UserData\\" + Tname + "Data.txt");
    getline(TDetails, Tbalance);
    getline(TDetails, Tcardnumber);
    getline(TDetails, Tsortcode);
    Tbalancei = stoi(Tbalance);
    TDetails.close();
    cout << "What is the users sortcode? " << endl;
    cin >> Sortcode;
    while(Sortcode != Tsortcode){
        cout << "Incorrect Try again! "<< endl;
        cout << "Enter Sortcode: ";
    }
    if(Sortcode == Sortcode){
        string LoggedBalance, LoggedCardnumber, LoggedSortcode;
        int LoggedBalancei;
        LoggedBalancei = stoi(LoggedBalance);
        cout << "How much would you like to transfer? ";
        cin >> TransferAmmount;
        ifstream LoggedUser("E:\\Library\\C++\\BankingSystem\\UserData\\" + NameUNI + "Data.txt");
        getline(LoggedUser, LoggedBalance);
        LoggedUser.close();
        while(LoggedBalancei < TransferAmmount){
            cout << "You do not have enough money to transfer that amount! "<< endl;
        }
        if(LoggedBalancei >= TransferAmmount){
            LoggedBalancei = LoggedBalancei - TransferAmmount;
            ofstream LoggedUser("E:\\Library\\C++\\BankingSystem\\UserData\\" + NameUNI + "Data.txt");
            LoggedUser << LoggedBalancei << endl << LoggedCardnumber << endl << LoggedSortcode;
            LoggedUser.close();

            ofstream Tuser("E:\\Library\\C++\\BankingSystem\\UserData\\" + Tname + "Data.txt");
            Tbalancei = TransferAmmount + Tbalancei;
            Tuser << Tbalancei << endl << Tcardnumber << endl << Tsortcode;


        }


    }

}

int main(){
    int Choice;
    int Tchoice;
    cout << "Register(1) or Login(2)";
    cin >> Choice;
    if(Choice == 1){
        Register();

    }
    else{
        Login();
        cout << "do you want to transfer funds? (1) or (2) to exit"<< endl;
        cin >> Tchoice;
        if(Tchoice == 1){
            Transfer();
        }
        else{
            cout << "Goodbye"<< endl;
        
        }
    }
    char c;
    std::cin >> c;
    return 0;
}