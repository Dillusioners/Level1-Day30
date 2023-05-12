# include <iostream>
# include <limits>
# include <vector>

// decleration of fix_cin
void fix_cin();

// class customer to store all the users in the bank
class Customer{
	private:
		// name -> stores the name of customer
		// password -> stores the password of the customer's account
		// balance -> stores the balance in account
		std::string name, password;
		int balance;
		
	public:
		// constructor of the Customer class
		// n -> name 
		// p -> password
		// b -> balance
		Customer(std::string n, std::string p, int b);
		// sets the value of a Customer variable equal to another Customer variable
		Customer operator= (Customer);
		
		// returns the name of customer
		std::string getName();
		// returns the password of customer
		std::string getPassword();
		// returns the balance of customer
		int getBalance();
		
		// sets the name of customer
		// n -> name
		void setName(std::string n);
		// sets the password of the customer
		// p -> password
		void setPassword(std::string p);
		// sets the balance of the customer
		// b -> balance
		void setBalance(int b);
};

// Following are the inititalizations of Customer class functions:

Customer::Customer(std::string n, std::string p, int b){
	// setting all details
	name = n;
	password = p;
	balance = b;	
}

Customer Customer::operator=(Customer c2){
	// copying all the data from other customer to here
	name = c2.getName();
	password = c2.getPassword();
	balance = c2.getBalance();
	return *this;
}

std::string Customer::getName(){
	return name; // returns name
}

std::string Customer::getPassword(){
	return password; // returns password
}

int Customer::getBalance(){
	return balance; // returns balance
}

void Customer::setName(std::string n){
	name = n; // sets name	
}

void Customer::setPassword(std::string p){
	password = p; // sets password
}

void Customer::setBalance(int b){
	balance = b; // sets balance
}

// Customer class functions end here

// class Bank for the structure of the bank
class Bank{
	private:
		// users -> all the accounts created by users 
		// logged -> stores whether user is logged in or not
		// logged_user -> stores the data of the currently logged in user
	
		std::vector<Customer> users;
		bool logged;
		Customer *logged_user;
		
	public:
		// Constructor of the bank
		Bank();
		
		// main method from where the bank's features are accessed'
		bool main();
		// registers a user in the bank
		void register_();
		// logs in a user in the bank
		void login();
		// deposits money in the user's account'
		void deposit();
		// withdraws money from user's account'
		void withdraw();
};

// Initialization of all Bank functions below

Bank::Bank(){
	// Inilializing variables
	logged = false;
	logged_user = new Customer("", "", 0);
}

bool Bank::main(){
	int choice; // stores user choice
	
	// welcome message screen
	std::cout << "\nWelcome to Dillusioners Bank!\n\n";
	// this line is only printed if user is logged in
	if(logged)
	std::cout <<"Welcome " << logged_user->getName() 
	                <<". Your current bank balance is $" << logged_user->getBalance() << '\n';
	// prints the menu itself
	std::cout << "The following are your options:\n";
	std::cout << "1. Register\n";
	std::cout << "2. Login\n";
	std::cout << "3. Deposit\n";
	std::cout << "4. Withdraw\n";
	std::cout << "5. Exit\n";
	std::cout << ">> ";
	std::cin >> choice;
	fix_cin();
	
	// switch case for user choice
	switch(choice){
		// Exit
		case 5: {
			// exits from program
			std::cout << "Thanks for checking out the back!";
			return false;	
		}
		
		// Register
		case 1: {
			// registers the user
			register_();
			break;
		}
		
		// Login
		case 2: {
			// logs in the user
			login();
			break;
		}
		
		// Deposit
		case 3: {
			// kick out if not logged in
			if(logged) deposit();
			else std::cout << "Login / Register to access funds!\n";
			break;	
		}
		
		// Withdraw
		case 4: {
			// kicks out if not logged in
			if(logged) withdraw();
			else std::cout << "Login / Register to access funds!\n";
			break;
		}
		
		// Not matching with any choice
		default: {
			std::cout << "Invalid input provided!\n";	
		}
	}
	
	// Returns true as the user has not exited from program
	return true;
}

void Bank::register_(){
	// variable declaration
	std::string n, p;
	int b;
	
	// asks user for name, pass and balance
	std::cout << "Enter your name: ";
	std::cin >> n;
	std::cout << "Enter your password: ";
	std::cin >> p;
	std::cout << "Enter your balance: ";
	std::cin >> b;
	fix_cin();
	
	// logs in the user to the bank
	logged = true;
	// creates a customer user
	Customer *c = new Customer(n, p, b);
	// logs customer in users vector
	users.push_back(*c);
	// updates the currently logged user
	logged_user = c;
	std::cout << "Successfully registered!\n";
}

void Bank::login(){
	// variable declaration
	std::string n, p;
	
	// asks user for name and password
	std::cout << "Enter your name: ";
	std::cin >> n;
	std::cout << "Enter your password: ";
	std::cin >> p;
	
	// loops through all the users
	for(auto i = users.begin(); i != users.end(); i++){
		// if the name and pass matched with the current iteration
		if(n == i->getName() && p == i->getPassword()){
			// log into the bank
			std::cout << "Successfully logged in!\n";
			*logged_user = *i;
			logged = true;
			return;
		}	
	}
	// runs when no matching user or password was provided
	std::cout << "Couldnot log in!\n";
}

void Bank::deposit(){
	int d;
	
	// asks for cash to deposits
	std::cout << "How much you want to deposit?: ";
	std::cin >> d;
	fix_cin();
	
	// if cash is negative, it is made positive
	if(d < 0) d *= -1;
	
	// updates the balance of the user
	logged_user->setBalance(logged_user->getBalance() + d);	
}

void Bank::withdraw(){
	int d;
	
	// asks for cash amount to withdraw
	std::cout << "How much you want to withdraw?: ";
	std::cin >> d;
	fix_cin();
	
	// if cash if negative, make it posititve
	if(d < 0) d *= -1;
	
	// updates the balance amount
	logged_user->setBalance(logged_user->getBalance() - d);
}

// fixes std::cin if bad input is provided
void fix_cin(){
	if(std::cin.fail()){
		// clears std::cin and removes all the bad input from it
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}	
}

// execution starts from here
int main(int argc, char** argv){
	// variable declaration
	Bank bank;
	bool run = true;
	
	// running the program
	while(run){
		run = bank.main();	
	}
	return 0;
}
