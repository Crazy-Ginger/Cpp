#include <iostream>
#include <string>
#include <boost/program_options.hpp>

using namespace boost::program_options;

int main(int argc, char* argv[])
{
    std::cout << "Shit ma pant\n";
    options_description desc("Allowed options");
    desc.add_options()
        ("help", "product halp massage")
        ("compression", value<int>(), "set compression level")
        ;
    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

	if (vm.count("help")) {
		std::cout << desc << "\n";
		return 1;
	}

	if (vm.count("compression")) {
		std::cout << "Compression level was set to "
	 << vm["compression"].as<int>() << ".\n";
	} else {
		std::cout << "Compression level was not set.\n";
	}
    return 0;
}
