#ifndef _HOSTS_
#define _HOSTS_
#include <map>
#include <iostream>

class Hosts {
public:
	std::multimap<int, std::string > HostSet;
	Hosts(){}
	Hosts(const Hosts& orig) { this->HostSet = orig.HostSet; }
	Hosts& operator=(const Hosts& orig) { this->HostSet = orig.HostSet; return *this; }
	void read_Hosts();
	void generate_Hosts(int Num_of_Hosts, int mask);
	void print_Hosts();
	
};

#endif