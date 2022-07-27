#include <iostream>

int main(){
	char value = 65; //ASCII character code for 'A'
	std::cout << "value : " << value << std::endl;
	std::cout << "value(int) : " << static_cast<int>(value) << std::endl;
	return 0;
}