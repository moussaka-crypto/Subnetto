#include "IPAdressManagement.h"
#include <sstream>
#include "VariadicTable.h"
#include <string>
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
	std::cout << "----------------VLSM Subnetting Task----------------\n\n";
	print_IPV4();
	print_Sub();
	hosts.print_Hosts(); 
	std::cout << "Solve this Problem using VLSM Subnetting (Classless).\n";
	std::cout << "Press Enter to view Solution ...\n\n";
	std::cin.get();
	std::cin.get();
	std::vector<int> IP = IPv4.getAdd();
	std::vector<int> No_of_Hosts;
	std::vector<int> networkAdress = IP;
	std::vector<int> broadCastAdress = IP;
	std::vector<int> lastIP = IP;
	std::vector<int> firstIP = IP;
	VariadicTable<std::string,std::string, std::string, std::string, std::string,std::string> vt({ "Hostname","Network Address", "First IP", "Last IP","Broadcast Address", "Subnetmask"});
	for (auto it = hosts.HostSet.rbegin(); it != hosts.HostSet.rend(); it++) {
		int host = nearest_binary_base_hosts(it->first);
		std::fill(networkAdress.rbegin(), networkAdress.rbegin() + host, 0);
		std::fill(broadCastAdress.rbegin(), broadCastAdress.rbegin() + host, 1);
		firstIP = networkAdress;
		lastIP = broadCastAdress;
		*(firstIP.end() - 1) = 1;
		*(lastIP.end() - 1) = 0;

		std::string netWork= IPV4(networkAdress).get_IP();
		std::string broad = IPV4(broadCastAdress).get_IP();
		std::string first = IPV4(firstIP).get_IP();
		std::string last = IPV4(lastIP).get_IP();
		std::string sub = "\\"+std::to_string(32 - host);
		vt.addRow(it->second, netWork, first, last, broad,sub);

		IP = broadCastAdress;
		
		for (auto it = IP.rbegin() + host; it != IP.rend(); it++) {
			if (*it == 0) {
				*it = 1;
				std::fill(IP.rbegin(), it, 0);
				break;
			}
				
		}
		networkAdress = IP;
		broadCastAdress = IP;
		firstIP = IP;
		lastIP = IP;

	}
	vt.print(std::cout);
	
}
void IPAdressManagement::create_subnets_question() {
	print_IPV4();
	print_Sub();
	std::vector<int> IP = IPv4.getAdd();
	int sub = Subnet_mask.get_slash();


	int hosts = pow(2, (32 - sub));
	int r = (hosts / 10) + (rand() % (hosts/4 - (hosts /10) + 1));

	std::cout << "First Determine the subnet of this IP Adress.\nThen create as many Subnets as possible to support " << r <<" Hosts"<< std::endl;
	std::vector<int> network = IP;
	int binary = nearest_binary_base_hosts(r);
	std::fill(network.rbegin(), network.rbegin() + binary-1, 0);
	int end = 32 - sub - binary + 1;
	std::vector<int> s(IP.begin() + sub, IP.begin() + sub + end-1);
	for (auto i : s){
		std::cout << i;
	}
	std::cout << std::endl;
	
	
}



void IPAdressManagement::clientProgramm() {
	try {
		while (true)
		{
		menu:
			std::cout << "*************************************************************************************\n";
			std::cout << "				      SUBNETTO  by Nilusche Liyanaarachchi  (c)					       \n";
			std::cout << "*************************************************************************************\n";
			std::cout << "Main Menu\n\n";
			std::cout << "1) Work with IP Version 4\n";
			std::cout << "2) Work with IP Version 6\n";
			std::cout << "3) Shutdown program\n\n";
			int i = 0;
			std::cin >> i;

			if (i == 1) {
			Ipv4:
				system("cls");
				std::cout << "*************************************************************************************\n";
				std::cout << "                  Subnettingquestions-solver  by Nilusche Liyanaarachchi  (c)        \n";
				std::cout << "*************************************************************************************\n";
				std::cout << "IP VERSION 4 Menu\n\n";
				std::cout << "1) Input IP Version 4 IP address\n";
				std::cout << "2) Identify the addressrange of an IPV4 address to a given subnetmask\n";
				std::cout << "3) Determine the subnet of given IP address\n";
				std::cout << "4) VLSM Subnetting Question and Solver\n";
				std::cout << "5) Go Back to Menu\n\n";
				int l = 0;
				std::cin >> l;

				if (l == 1) {
					
					std::string IP = "";
					std::cout << "IP: ";
					std::cin>>IP;
					update_IPV4(IP);
					std::cout << "reading IP ... Press Enter\n";
					std::cin.get();
					std::cin.get();
					goto Ipv4;
				}
				if (l == 2) {
					range_of_IPV4();
					std::cout << "Press Enter to continue\n";
					std::cin.get();
					std::cin.get();
					goto Ipv4;
				}
				if (l == 3) {
					std::cout << "Input desired Subnet Mask in '\\notations' (without \\ symbol): ";
					int notation = 0;
					std::cin >> notation;
					this->Subnet_mask.set_Subnet(notation);
					std::cout << "Press Enter to continue\n";
					std::cin.get();
					std::cin.get();
					determine_subnet_IPV4();	
					std::cout << "Press Enter to go Back\n";
					std::cin.get();
					std::cin.get();
					goto Ipv4;
				}
				if (l == 4) {
				VLSM:
					system("cls");
					std::cout << "*************************************************************************************\n";
					std::cout << "                  Subnettingquestions-solver  by Nilusche Liyanaarachchi  (c)        \n";
					std::cout << "*************************************************************************************\n";
					std::cout << "VLSM Subetting\n\n";
					std::cout << "1) Generate random VLSM Subnetting tasks (random Hosts and random IP)\n";
					std::cout << "2) Generate random VLSM Subnetting tasks (random Hosts but custom IP)\n";
					std::cout << "3) Create custom VLSM Task (custom number of Hosts and custom IP)\n";
					std::cout << "4) Go back to Main Menu\n";

					int k = 0;
					std::cin >> k;
					if (k == 1) {
						randomize_IPV4();
						randomize_Subnet();
						generate_HostNumbers();
						print_task_VLSM();
						std::cin.get();
						goto VLSM;
					}
					if (k == 2) {
						std::string IP2 = "";
						std::cout << "Input IP: ";
						std::cin >> IP2;
						randomize_Subnet();
						update_IPV4(IP2);
					VLSM2:
						system("cls");
						generate_HostNumbers();
						print_task_VLSM();
						std::cin.get();
						std::cout << "1) get new Task with same IP Address\n";
						std::cout << "2) Go Back\n";
						int h = 0;
						std::cin >> h;
						if (h == 1) {
							goto VLSM2;
						}
						else
						{
							goto VLSM;
						}
						
					}
					if (k == 3) {
						std::string IP2 = "";
						std::cout << "Input IP: ";
						std::cin >> IP2;
						std::cin.ignore();
						int sub = 0;
						std::cout <<  "Input desired Subnetmask in CIDR Notation (without \\ symbol): ";
						std::cin >> sub;
						this->read_hostNumbers();
						
						update_IPV4(IP2);
						this->Subnet_mask.set_Subnet(sub);
					VLSM3:
						print_task_VLSM();
						std::cin.get();
						std::cout << "1) get new Task with same IP Address and Subnet\n";
						std::cout << "2) get new Task with different IP Address and same Subnet\n";
						std::cout << "3) Go Back\n";
						int h = 0;
						std::cin >> h;
						if (h == 1) {
							goto VLSM3;
						}
						if (h == 2) {
							randomize_IPV4();
							goto VLSM3;
						}
						else
						{
							goto VLSM;
						}
					}
					if (k == 4) {
						system("cls");
						goto menu;
					}
					else {
						std::cout << "invalid Input\n";
						std::cout << "Press Enter to go Back\n";
						std::cin.get();
						std::cin.get();
						goto VLSM;
					}
				}
				if (l == 5) {
					system("cls");
					goto menu;
				}
				else
				{
					std::cout << "invalid Input\n";
					std::cout << "Press Enter to go Back\n";
					std::cin.get();
					std::cin.get();
					goto Ipv4;
				}
			}
			else if (i == 2) {
			Ipv6:
				system("cls");
				std::cout << "*************************************************************************************\n";
				std::cout << "                  Subnettingquestions-solver  by Nilusche Liyanaarachchi  (c)        \n";
				std::cout << "*************************************************************************************\n";
				std::cout << "IP VERSION 6 Menu (Additional Functions coming soon)\n\n";
				std::cout << "1) Input IPV6 IP\n";
				std::cout << "2) Convert IPV4 address to IPV6 (6to4 Rule)\n";
				std::cout << "3) Identify the addressrange of an IPV6 address to a given subnetmask\n";
				std::cout << "4) Go Back to Main Menu\n";
				int l = 0;
				std::cin >> l;
				if (l == 1) {
					std::string IP = "";
					std::cout << "Input IP in this Format: 'XXXX:XXXX:XXXX:XXXX:XXXX:XXXX:XXXX'\n";
					std::cout << "Abbreviation with '::' are allowed, others are not.\n";
					std::cout << "Valid Example: ABCD:ABCD:ABCD:ABCD:ABCD:ABCD:ABCD\n";
					std::cout << "Valid Example: ABCD:EFAB::ABCD:EFAB\n";
					std::cout << "Invalid Example: AB:CDE:ABC::\n\n";
					std::cout << "IP: ";
					std::cin >> IP;
					IPV6 Ip(IP);
					Ip.printAdd();
					update_IPV6(IP);
					std::cin.get();
					std::cin.get();
					goto Ipv6;
				}
				if (l == 2) {
					std::string IP = "";
					std::cout << "Input IP: ";
					std::cin >> IP;
					IPV4 Ip(IP);
					Ip.printAdd();
					this->IPv6.convert6to4(Ip);
					print_IPV6();
					std::cin.get();
					std::cin.get();
					goto Ipv6;
				}
				if (l == 3) {
					range_of_IPV6();
					std::cout << "Press Enter to continue\n";
					std::cin.get();
					std::cin.get();
					goto Ipv6;
				}
				if (l == 4) {
					system("cls");
					goto menu;
				}
				else
				{
					std::cout << "invalid Input\n";
					std::cout << "Press Enter to go Back\n";
					std::cin.get();
					std::cin.get();
					goto Ipv6;
				}
			}
			else {
				break;
			}
		}
		
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Something went wrong. Restart Again" << std::endl;
	}


}

void IPAdressManagement::update_IPV4(std::string IP) {
	IPv4.init_IP(IP);
}
void IPAdressManagement::update_IPV6(std::string IP) {
	IPv6.init_IP(IP);
}

void IPAdressManagement::randomize_Subnet() {
	int r = 20 + rand() % (30 - 19 + 1);
	Subnet_mask.set_Subnet(r);
}

void IPAdressManagement::randomize_IPV4() {
	IPv4.randomize();
}
void IPAdressManagement::randomize_IPV6() {
	IPv6.randomize();
}

void IPAdressManagement::print_Sub() {
	Subnet_mask.print_Subnet();
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


	std::cout << "find Subnetaddress of: ...\n";
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
			bool last_octett = false;
			for (auto i = 0; i < seglist2.size();i++) {
				if (i == octettposition) {
					last_octett = true;
					IPnew += std::to_string(counter);
					if (i + 1 != seglist2.size())
						IPnew += ".";
					continue;
				}
				if (!last_octett)
					IPnew += std::to_string(seglist2[i]);
				else
					IPnew += std::to_string(0);
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

void IPAdressManagement::range_of_IPV6() {
	std::cout << "Make sure to Input the IP Adress before continueing.\n";
	std::cout << "1) Input IPV6 Address\n";
	std::cout << "2) Continue with saved Addressed\n";
	std::cout << "3) Abort process\n";
	
	int i = 0;
	std::cin >> i;
	if (i == 1) {
		std::string IP;
		std::cout << "Input IP in this Format: 'XXXX:XXXX:XXXX:XXXX:XXXX:XXXX:XXXX'\n";
		std::cout << "Abbreviation with '::' are allowed, others are not.\n";
		std::cout << "Valid Example: ABCD:ABCD:ABCD:ABCD:ABCD:ABCD:ABCD\n";
		std::cout << "Valid Example: ABCD:EFAB::ABCD:EFAB\n";
		std::cout << "Invalid Example: AB:CDE:ABC::\n\n";
		std::cout << "IP: ";
		std::cin >> IP;
		update_IPV6(IP);
		IPv6.printAdd();
	}
	else if (i == 2) {
		IPv6.printAdd();
	}
	else {
		return;
	}

	std::cout << "Input desired Subnetmask in CIDR Notation (without '/' symbol): ";
	int s = 0;
	std::cin >> s;
	while ((s < 1 || s>128)) {
		std::cout << "Invalid Mask.\nMask: ";
		int tmp = 0;
		std::cin >> tmp;
		s = tmp;
		std::cin.ignore();
	}
	std::cout << "Entered Mask: /" << s << std::endl;

	std::vector<int> ip6 = IPv6.getAdd();
	std::vector<int> network_add(ip6.begin(), ip6.begin() + s);
	VariadicTable<std::string> vt1({ "Networkaddress"});
	VariadicTable<std::string> vt2({ "First IP"});
	VariadicTable<std::string> vt3({ "Last IP"});
	VariadicTable<std::string> vt4({ "Broadcastaddress"});
	std::fill(ip6.begin()+s, ip6.end(), 0);
	IPV6 net(ip6);
	auto it = ip6.end() - 1;
	*it = 1;
	IPV6 first(ip6);
	std::fill(ip6.begin() + s, ip6.end(),1);
	IPV6 broad(ip6);
	*it = 0;
	IPV6 last(ip6);

	vt1.addRow(net.get_IP());
	vt2.addRow(first.get_IP());
	vt3.addRow(last.get_IP());
	vt4.addRow(broad.get_IP());
	vt1.print(std::cout);
	vt2.print(std::cout);
	vt3.print(std::cout);
	vt4.print(std::cout);
}

void IPAdressManagement::range_of_IPV4() {
	std::cout << "Make sure to Input the IP Adress before continueing.\n";
	std::cout << "1) Input IPV4 Address\n";
	std::cout << "2) Continue with saved Addressed\n";
	std::cout << "3) Abort process\n";

	int i = 0;
	std::cin >> i;
	if (i == 1) {
		std::string IP;
		std::cout << "IP: ";
		std::cin >> IP;
		update_IPV4(IP);
		IPv4.printAdd();
	}
	else if (i == 2) {
		IPv4.printAdd();
	}
	else {
		return;
	}

	std::cout << "Input desired Subnetmask in CIDR Notation (without '/' symbol): ";
	int s = 0;
	std::cin >> s;
	while ((s < 1 || s>32)) {
		std::cout << "Invalid Mask.\nMask: ";
		int tmp = 0;
		std::cin >> tmp;
		s = tmp;
		std::cin.ignore();
	}
	std::cout << "Entered Mask: /" << s << std::endl;

	std::vector<int> ip4 = IPv4.getAdd();
	std::vector<int> network_add(ip4.begin(), ip4.begin() + s);
	VariadicTable<std::string, std::string, std::string, std::string> vt1({ "Networkaddress", "First IP", "Last IP", "Broadcastaddress" });
	std::fill(ip4.begin() + s, ip4.end(), 0);
	IPV4 net(ip4);
	auto it = ip4.end() - 1;
	*it = 1;
	IPV4 first(ip4);
	std::fill(ip4.begin() + s, ip4.end(), 1);
	IPV4 broad(ip4);
	*it = 0;
	IPV4 last(ip4);

	vt1.addRow(net.get_IP(), first.get_IP(), last.get_IP(), broad.get_IP());
	vt1.print(std::cout);
}