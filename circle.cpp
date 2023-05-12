# include <iostream>

// defining the value of pi
# define PI 3.141592

// execution starts from here
int main(int argc, char** argv){
	// variable declaration
	float radius;
	
	// asking for the radius of circle
	std::cout << "Enter the radius of the circle: ";
	std::cin >> radius;
	
	// printing the area with formula: pi*r^2
	std::cout << "\nThe area of the circle is: " << PI*radius*radius;
	// printing the area with formula: 2*pi*r
	std::cout << "\nThe perimeter of the circle is: " << PI*radius*2;
	
	return 0;
}
