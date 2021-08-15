#ifndef _IP_H
#define _IP_H
#include "IPAdress.h"
#include "MaskContainer.h"


class IPAdressManagement {
private:
	IPAdress IP;
	MaskContainer Subnet_mask;
	bool IPversion; //true == IPV4, false== IPV6
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
	IPAdressManagement(IPAdress IP, MaskContainer Subnet_mask, bool IPversion) : IP{ IP }, Subnet_mask{ Subnet_mask }, IPversion{ IPversion }{}



	//void extract_IP(char* stream);
	//void convert_toIPV4();
	//void convert_toIPV6();
	
};

#endif _IP_H
