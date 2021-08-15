#include "IPAdressManagement.h"
#include "Utility.h"

int main() {
	srand(time(NULL));
	IPV4 ip;
	ip.init_IP("224.92.17.31");
	ip.printAdd();
	IPV6 ip2;
	ip2.init_IP("0001::");
	ip2.printAdd();




	return 0;
}