#ifndef _IP_H
#define _IP_H
#include "IPAdress.h"
#include "Mask.h"
#include "Hosts.h"

class IPAdressManagement {
private:
	IPAdress IP;
	Mask Subnet_mask;
	bool IPversion; //true == IPV4, false== IPV6
	Hosts hosts;
	//void initiate_IPV(int Version);
	//bool validate();
public: 
	IPAdressManagement(const IPAdressManagement &orig) {
		this->IP = orig.IP;
		this->Subnet_mask = orig.Subnet_mask;
	}
	IPAdressManagement& operator=(const IPAdressManagement& IP_M) {
		this->IP = IP_M.IP;
		this->Subnet_mask = IP_M.Subnet_mask;
		return *this;
	}
	IPAdressManagement(IPAdress IP, Mask Subnet_mask, bool IPversion) : IP{ IP }, Subnet_mask{ Subnet_mask }, IPversion{ IPversion }{}


	void get_HostNumbers() {

	}


	
};

#endif _IP_H
