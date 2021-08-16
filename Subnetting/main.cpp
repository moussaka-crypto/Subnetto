#include "IPAdressManagement.h"
using namespace std;

int main() {
	srand(time(NULL));

	IPAdressManagement Ipv4Problem("200.100.48.0", 22, 4);
	Ipv4Problem.clientProgramm();
	return 0;
}