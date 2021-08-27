#ifndef _IP_H
#define _IP_H
#include "IPAdress.h"
#include "Mask.h"
#include "Hosts.h"
#include "Utility.h"
class IPAdressManagement {
private:
	IPV4 IPv4;
	IPV6 IPv6;
	Mask Subnet_mask;
	Hosts hosts;
	//void initiate_IPV(int Version);
	//bool validate();
public: 
	IPAdressManagement(const IPAdressManagement &orig) {
		this->IPv4 = orig.IPv4;
		this->IPv6 = orig.IPv6;
		this->Subnet_mask = orig.Subnet_mask;
		this->IPv4 = orig.IPv4;
		this->hosts = orig.hosts;
	}
	IPAdressManagement& operator=(const IPAdressManagement& orig) {
		this->IPv4 = orig.IPv4;
		this->IPv6 = orig.IPv6;
		this->Subnet_mask = orig.Subnet_mask;
		this->IPv4 = orig.IPv4;
		this->hosts = orig.hosts;
		return *this;
	}
	IPAdressManagement(IPV4 IPv4, Mask Subnet_mask, bool IPversion) : IPv4{ IPv4 }, Subnet_mask{ Subnet_mask }{}
	IPAdressManagement(std::string IP, int subnet, int version);
	void randomize_IPV4();
	void randomize_IPV6();
	void randomize_Subnet();
	void update_IPV4(std::string IP);
	void update_IPV6(std::string IP);
	void read_hostNumbers();
	void generate_HostNumbers();
	void print_IPV4();
	void print_IPV6();
	void print_task_VLSM();
	void determine_subnet_IPV4();
	void create_subnets_question();
	void range_of_IPV6();
	void range_of_IPV4();
	void clientProgramm();
	void print_Sub();
};

#endif _IP_H
