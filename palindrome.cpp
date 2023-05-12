# include <iostream>
# include <string>


// execution starts from here
int main(int argc, char** argv){
	std::string str; // stores the string
	
	// asking for user input
	std::cout << "Enter your string: ";
	std::getline(std::cin, str);
	
	// checking if the string is equal to it's reverse'
	if(str == std::string(str.rbegin(), str.rend())) std::cout << "\nPalindrome string.";
	else std::cout << "\nNot a palindrome string.";
	
	return 0;
}
