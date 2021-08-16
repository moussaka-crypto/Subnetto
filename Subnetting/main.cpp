#include "IPAdressManagement.h"
#include "Utility.h"

int main() {
	srand(time(NULL));

	

	Hosts host;
	host.generate_Hosts(5, 24);
	host.print_Hosts();

	return 0;
}