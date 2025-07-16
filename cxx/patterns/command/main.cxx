#include "command.hxx"
#include <memory>
#include <iostream>
#include <array>

class ttt
{
	enum unit {
		undef = 0,
		cross,
		zerro,
		max
	};

	std::array <unit, 9> board {};
};

int main (int argc, char** argv)
{
	using std::cout;
	std::unique_ptr<command> cmd_ptr { new (std::nothrow) command () };
	cout << "Hello, pattern \"command\"\n";
}

