#include "Hosts.h"
#include <iomanip>
#include <string>
#include "VariadicTable.h"
void Hosts::read_Hosts() {
	HostSet.clear();
	int n;
	std::cout << "Input number of Organisations/Subnets: ...\n";
	std::cin >> n;
	std::cin.ignore();
	for (int i = 0; i < n; i++) {
		std::string Hostname = "";
		int num_of_Host = 0;
		std::cout << "Hostname: "; std::cin >> Hostname; std::cin.ignore();
		std::cout << "Supported number of hosts: "; std::cin >> num_of_Host; std::cin.ignore();
		HostSet.insert({num_of_Host,Hostname });
	}

	std::cout << "Input was succesfull" << std::endl;
}

void Hosts::generate_Hosts(int Num_of_Hosts, int mask) {
	HostSet.clear();
	int maximum_number_of_Hosts = pow(2, (32 - mask))+1;
	for (int i = 0; i < Num_of_Hosts; i++) {
		std::string Hostname = "Host ";
		Hostname += std::to_string(i);
		int range = maximum_number_of_Hosts - 2 + 1;
		if (range == 0)
			break;
		int num_of_Host = 2 + (std::rand() % (range));
		maximum_number_of_Hosts -= num_of_Host;
		if (maximum_number_of_Hosts <= 0)
			break;
		HostSet.insert({ num_of_Host,Hostname});
	}
}

void Hosts::print_Hosts() {

	VariadicTable<std::string, int> vt({ "Hostname", "Number of Hosts" });
	for (auto it = HostSet.begin(); it != HostSet.end(); it++) {
		vt.addRow(it->second, it->first);
	}
	vt.print(std::cout);
	
}