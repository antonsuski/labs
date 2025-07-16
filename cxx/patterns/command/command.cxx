#include "command.hxx"

#include <iostream>

class base_obj
{
	public:
	std::string name {"base_obj"};
};

command::command()
{
	std::cout << "user deault command constructor\n";
}

command::~command()
{
	std::cout << "command destructor\n";
}

class command_print_name : command
{

}
