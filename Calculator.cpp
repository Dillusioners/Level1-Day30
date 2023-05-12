# include <iostream>
# include <limits>


// fixes std::cin if bad input is provided
void fixCin(){
	if(std::cin.fail()){
		// clearing std::cin from bad to good
		std::cin.clear();
		// removing all of the bad input from std::cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}	
}

// printing the menu
void printMenu(){
	std::cout << "\n\nThe following options are avaliable in the menu:\n";
	std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n>> ";	
}

// execution starts from here
int main(int argc, char** argv){
	// variable declaration
	int choice, a, b;
	bool run = true;
	
	while(run){
		// asking for user choice
		printMenu();
		std::cin >> choice;
		fixCin();
		
		// checking if user choice is out of menu bounds
		if(choice > 5 || choice < 1) continue;
		// checks if user choice is 5
		if(choice == 5) break;
		
		// asking user for input
		std::cout << "\nEnter two numbers:\n";
		std::cin >> a >> b;
		
		switch(choice){
			// adding			
			case 1: {
				std::cout << a << " + " << b << " = " << a + b;
				break;	
			}
			// subtracting
			case 2: {
				std::cout << a << " - " << b << " = " << a - b;
				break;	
			}
			// multiplying
			case 3: {
				std::cout << a << " * " << b << " = " << a * b;
				break;	
			}
			// dividing
			case 4: {
				std::cout << a << " / " << b << " = " << a / (float)b;
				break;	
			}
		}	
	}
	
	return 0;
}
