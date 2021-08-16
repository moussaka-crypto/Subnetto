#ifndef _HOSTS_
#define _HOSTS_
#include <map>
#include <iostream>
class Hosts {
private:
	std::map<std::string, int > HostSet;
public:
	void read_Hosts();
	void generate_Hosts(int Num_of_Hosts, int mask);
	void print_Hosts();
	
};

#endif