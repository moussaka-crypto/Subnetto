#include "IPAdressManagement.h"
#include <sstream>
IPAdressManagement::IPAdressManagement (std::string IP, int subnet, int version) {
	if (version != 4 && version != 6)
		throw std::invalid_argument("Wrong IP Version entered");
	if (version == 4) {
		IPv4.init_IP(IP);
		Subnet_mask.set_Subnet(subnet);
	}
	else if (version == 6)
		IPv6.init_IP(IP);
}

void IPAdressManagement::read_hostNumbers() {
	hosts.read_Hosts();
}
void IPAdressManagement::generate_HostNumbers() {

	int num =3+(std::rand() % (7 - 3 + 1));
	hosts.generate_Hosts(num, Subnet_mask.get_slash());
}

void IPAdressManagement::print_IPV4() {
	IPv4.printAdd();

}
void IPAdressManagement::print_IPV6() {
	IPv6.printAdd();
}
void IPAdressManagement::print_task_VLSM() {
	std::cout << "++++++++++++++++++\tVLSM Subnetting Task\t ++++++++++++++++++\n\n";
	print_IPV4();
	hosts.print_Hosts(); 
	std::cout << "Solve this Problem using VLSM Subnetting (Classless).\n";
}

void IPAdressManagement::update_IPV4(std::string IP) {
	IPv4.init_IP(IP);
}
void IPAdressManagement::update_IPV6(std::string IP) {
	IPv4.init_IP(IP);
}

void IPAdressManagement::randomize_IPV4() {
	IPv4.randomize();
}
void IPAdressManagement::randomize_IPV6() {
	IPv6.randomize();
}

void IPAdressManagement::determine_subnet_IPV4(){
	std::map<int, int> table;
	table.insert({ 128,128 });
	table.insert({ 192,64 });
	table.insert({ 224,32 });
	table.insert({ 240,16 });
	table.insert({ 248,8 });
	table.insert({ 252,4 });
	table.insert({ 254,2 });
	table.insert({ 255,1 });


	std::cout << "find Subnetadress of: ...\n";
	IPv4.printAdd();
	Subnet_mask.print_Subnet();
	std::cout << "\n";

	int slash = Subnet_mask.get_slash();
	std::string subnetstring = Subnet_mask.get_subnet_string();
	std::stringstream pars(subnetstring);
	std::string segment;
	std::vector <int> seglist;
	while (std::getline(pars, segment, '.')) {
		seglist.push_back(stoi(segment));
	}
	int octettposition = 0;
	for (auto it = seglist.begin(); it != seglist.end(); it++) {
		if (*it != 255)
			break;
		octettposition++;
	}

	std::string ip = IPv4.get_IP();
	std::stringstream pars2(ip);
	std::string segment2;
	std::vector <int> seglist2;
	while (std::getline(pars2, segment2, '.')) {
		seglist2.push_back(stoi(segment2));
	}
	for (int i = 0; i < seglist2.size(); i++) {
		if (i == octettposition) {
			int val = seglist[octettposition];
			if (val == 0) {
				std::cout << "Valid subnet found: " << std::endl;
				std::string ip;
				ip = std::to_string(seglist2[0]) + "." + std::to_string(seglist2[2]) + "." + std::to_string(seglist2[0]) + ".0";
				IPV4 tmp(ip);
				tmp.printAdd();
				std::cout << "\n";
				return;
			}
			auto it = table.find(val);
			if (it == table.end())
				throw std::range_error("Invalid map");
			int subVal = it->second;
			int val_ofIP = seglist2[octettposition];

			int counter=0;
			while (counter <val_ofIP) {
				counter += subVal;
			}
			counter -= subVal;
			
			std::string IPnew = "";
			for (auto i = 0; i < seglist2.size();i++) {
				if (i == octettposition) {
					IPnew += std::to_string(counter);
					if (i + 1 != seglist2.size())
						IPnew += ".";
					continue;
				}
				IPnew += std::to_string(seglist2[i]);
				if (i + 1 != seglist2.size())
					IPnew+= ".";

			}
			std::cout << "Subnet found:\n";
			IPV4 tmp(IPnew);
			tmp.printAdd();
			std::cout << "\n";
			break;
		}
	}


}