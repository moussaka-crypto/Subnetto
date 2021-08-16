#include "IPAdressManagement.h"
#include "Utility.h"

int main() {
	srand(time(NULL));

	IPAdressManagement Ipv4Problem("198.168.1.130", 25, 4);
	Ipv4Problem.determine_subnet_IPV4();
	/*Ipv4Problem.generate_HostNumbers();
	Ipv4Problem.print_task_VLSM();*/
	return 0;
}