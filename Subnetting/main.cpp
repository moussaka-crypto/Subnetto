#include "IPAdressManagement.h"
using namespace std;

int main() {
	srand(time(NULL));

	IPAdressManagement Ipv4Problem("192.168.1.64", 26, 4);
	Ipv4Problem.clientProgramm();
	//Ipv4Problem.create_subnets_question();

	return 0;
}