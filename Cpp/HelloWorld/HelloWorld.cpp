#include <iostream>
#include <filesystem>
int main()
{
	std::cout << "Hello World!" << std::endl;
	std::filesystem::path currentDir = std::filesystem::current_path();
	std::cout << "Current directory: " << currentDir << std::endl;
	char temp;
	std::cin >> temp;
	return 0;
}