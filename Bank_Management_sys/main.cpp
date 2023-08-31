#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#define bal 100
#define num 50
#define names 50
#include <cstdlib>
using namespace std;

class Bank {
private:
    string accountName[names], accountType[names];
    int total, balance[bal];
    vector<int> accountNumbers; // Use std::vector for account numbers
    int nextAccountNumber, nextAccountbal;      // Member variable for next account number

public:
    Bank() : total(0), nextAccountNumber(01234567), nextAccountbal(0){} // Initialize nextAccountNumber
    void accountInfo();
    void deposit();
    void withdrawal();
    void balanceInquiry();
    void createAccount();
    void login();
    void dashboard();
    void exit();
};
void Bank :: exit(){
	cout << "Thank You for using our system!\n";
	system("exit");
}
void Bank::createAccount() {
    cout << "Enter Account name: ";
    getline(cin, accountName[total]);
    cout << "Type of account: ";
    getline(cin, accountType[total]);
    accountNumbers.push_back(nextAccountNumber); // Use push_back for vectors
    cout << "Account number: " << accountNumbers.back() << endl;
	for (int i =0; i < total; i++){
		string newAccount=accountName[total];
		string newType = accountType[total];
		if(newAccount == accountName[i]){
			cout << "Account Name exist\n";
		}
	}
    nextAccountNumber++; // Increment next account number
    total++;             // Increment total accounts
}

void Bank::accountInfo() {
    cout << "=====================================\n";
    cout << "|                                   |\n";
    cout << "|          Account Details          |\n";
    cout << "|                                   |\n";
    cout << "=====================================\n\n";
    for (int i=0; i < total; i++){
    cout << "Account name: " << accountName[i] << endl;
    cout << "Accout Type: " << accountType[i] << endl;
    cout << "Account Number: " << accountNumbers.back() << endl;
    cout << "Account Balance: " << balance[nextAccountbal - 1] << endl;
}
}

void Bank::deposit() {
	int min= 500;
	int max = 50000;
    cout << "=====================================\n";
    cout << "|                                   |\n";
    cout << "|              Deposit              |\n";
    cout << "|                                   |\n";
    cout << "=====================================\n\n";
    
    cout << "Enter Amount to Deposit: ";
    cin >> balance[nextAccountbal];
    cin.ignore();
    	int newbalance=balance[nextAccountbal];
    	if(newbalance <= min){
    		cout << "Invalid. The minimum amount is 500\n";
		}else if(newbalance  > max){
			cout << "Account maximum deposit reach\n";
		}else{
			cout << "Deposit Successfully\n";	
		}
		cout << newbalance << endl; 
		nextAccountbal++;
}
void Bank::withdrawal() {
    if (nextAccountbal == 0) {
        cout << "No amount to withdraw";
    } else {
        int min = 500;
        int max = 20000;
        float deduction = 2;
        int withdraw;
        cout << "=====================================\n";
        cout << "|                                   |\n";
        cout << "|            Withdrawal             |\n";
        cout << "|                                   |\n";
        cout << "| Available balance: " << balance[nextAccountbal - 1]<<setw(12)<<"|\n";
        cout << "=====================================\n\n";

        cout << "Enter amount: ";
        cin >> withdraw;
        cin.ignore();

        if (withdraw < min) {
            cout << "Invalid. You need to withdraw at least 500 for remaining balance.\n";
        } else if (withdraw > max) {
            cout << "Account maximum withdrawal limit exceeded.\n";
        } else if (withdraw > balance[nextAccountbal - 1]) {
            cout << "Insufficient balance for withdrawal.\n";
        } else {
            cout << "Withdrawal successful.\n";
            balance[nextAccountbal - 1] -= withdraw;
        }
    }
    cout << balance[nextAccountbal -1] << endl;
}
void Bank ::  balanceInquiry(){
	int input;
	cout << "=====================================\n";
    cout << "|                                   |\n";
    cout << "|          Balance Inquiry          |\n";
    cout << "|                                   |\n";
    cout << "=====================================\n\n";
    
    cout << "Input account number: ";
    cin >> input;
    cin.ignore();
    
    if(input != accountNumbers.back()){
    	cout << "Invalid acount number";
    	return;
	}else{
		cout << "Available Balance: "<< balance[nextAccountbal -1];
	}
}
void Bank :: dashboard(){
	int input;
	cout << "=====================================\n";
    cout << "|                                   |\n";
    cout << "|            Dashboard  	         |\n";
    cout << "|                                   |\n";
    cout << "=====================================\n\n";
    while(true){
    cout << "=====================================\n";
    cout << "|"<<setw(28)<<"1. View Account info" << setw(10)<< "| \n";
    cout << "|"<<setw(18)<<"2. Deposit"<< setw(19)<<"|\n";
    cout << "|"<<setw(19)<<"3. Withdraw" << setw(19)<<"| \n";
    cout << "|"<<setw(24)<<"4. About system "   << setw(14)<<"| \n";
    cout << "|"<<setw(16)<<"5. exit "   << setw(22)<<"| \n";
    cout << "|"<<setw(37)<<" |\n";
    cout << "|"<<setw(37)<<" |\n";
    cout << "=====================================\n";
    cout << "Input Trasaction: ";
    cin>>input;
    cin.ignore();
    switch(input){
    	case 1:
    		system("cls");
    		accountInfo();
    		break;
    	case 2:
    		system("cls");
    		deposit();
    		break;
    	case 3:
    		system("cls");
    		withdrawal();
    		break;
    	case 5:
    		system("cls");
    		return;
    		break;
	}
}
}
void Bank :: login(){ 
string name;
int accountnumber;
int defaultpass = 0000;
string defaultname = "user";
	cout << "=====================================\n";
    cout << "|                                   |\n";
    cout << "|              Login                |\n";
    cout << "|                                   |\n";
    cout << "=====================================\n\n";
    
    cout << "Account holder name: ";
    getline(cin, name);
    cout <<"Input account number: ";
    cin >> accountnumber;
    cin.ignore();
    
    for (int i=0; i< total; i++){
    if (name == accountName[i] && accountnumber == accountNumbers.back()){
    	dashboard();
	}else {
		cout <<"Invalid account\n";
	}
    	}
}
int main(int argc, char** argv) {
    Bank bank;
 int input; 
ask:
while (true){
	
	cout << "=====================================\n";
    cout << "|                                   |\n";
    cout << "|      Banking Management System    |\n";
    cout << "|                                   |\n";
    cout << "=====================================\n\n";
   
    cout << "=====================================\n";
    cout << "|"<<setw(17)<<"1. Login" << setw(21)<< "| \n";
    cout << "|"<<setw(27)<<"2. Open an Account"<< setw(10)<<"|\n";
    cout << "|"<<setw(27)<<"3. Balance Inquiry" << setw(11)<<"| \n";
    cout << "|"<<setw(17)<<"4. exit "   << setw(21)<<"| \n";
    cout << "|"<<setw(37)<<" |\n";
    cout << "|"<<setw(37)<<" |\n";
    cout << "====================================\n";
    cout << "Input Trasaction: ";
    cin>>input;
    cin.ignore();
   
    	switch(input){
    		case 1:
    		system("cls");
    		bank.login();
    	    break;
    	case 2: 
    	    system("cls");
    	    bank.createAccount();
    	    break;
    	case 3: 
    		system("cls");
    		bank.balanceInquiry();
    		break;
    	case 4:
    	bank.exit();
    	return 0;
    	break;
    
		default:
			goto ask;
		}
		
	}


    return 0;
}
 

