#ifndef _IP_H
#define _IP_H
#include "IPAdressContainer.h"
enum IPversion {IPV4,IPV6};

class IPAdressManagement {
private:
	IPAdressContainer IP;
	MaskContainer Subnet_mask;
	void init_IP(IPversion V);
	bool validate();
public: 
	void extract_IP(char* stream);
	void convert_toIPV4();
	void convert_toIPV6();
	
};

#endif _IP_H
