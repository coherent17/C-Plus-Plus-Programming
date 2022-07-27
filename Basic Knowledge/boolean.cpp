#include <iostream>

int main(){
	bool red_light = true;
	bool green_light = false;

	std::cout << "red_light : " << red_light << std::endl;
	std::cout << "green_light : " << green_light << std::endl;


	//not print true/false instead of 1/0
	std::cout << std::boolalpha;
	std::cout << "red_light : " << red_light << std::endl;
	std::cout << "green_light : " << green_light << std::endl;	
	return 0;
}