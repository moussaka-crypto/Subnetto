#include "MaskContainer.h"

void MaskContainer::validate_suffix(int suffix) {
	if (suffix > 32 && suffix < 0)
		throw std::invalid_argument("/Notation invalid");
}
std::string MaskContainer::convert_to_dec() {
	return "";
}
MaskContainer& MaskContainer::operator=(const MaskContainer& orig) {
	return *this;
}

