# include <iostream>
# include <string>

// reverses the order of words in the string
// str -> the string to be reversed
std::string reverse(std::string str){
	// variable declaration
	std::string reversed = "", temp = "";
	
	// looping through the string
	for(int itr = (int)str.size() - 1; itr >= -1; itr--){
		// if the current index of string is blank or the index is out of bounds
		if(str[itr] == ' ' || itr == -1){
			// appending reverse of temp to reversed and clearing it
			reversed += std::string(temp.rbegin(), temp.rend()) + " ";
			temp = "";
			continue;
		}
		
		// adding the character to temp if it is not a blank
		temp += str[itr];
	}
	
	// returning the reversed string
	return reversed;
}

// execution starts from here
int main(int argc, char** argv){
	std::string str; // stores the string given by user
	
	// asks user for the string
	std::cout << "Enter your string: ";
	std::getline(std::cin, str);
	
	// prints the reverse and the flipped string
	std::cout << "The flipped string is " << std::string(str.rbegin(), str.rend());
	std::cout << "\nThe reversed string is " << reverse(str);
	return 0;
}
