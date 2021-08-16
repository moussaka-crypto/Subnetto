#include "Mask.h"
#include "Utility.h"
void Mask::validate_notation(int suffix) {
	if (suffix > 32 && suffix < 0)
		throw std::invalid_argument("/Notation invalid");
}
std::string Mask::convert_to_dec() {
	std::vector<int>decimal;
	for (int i = 0; i < mask.size(); i += 8) {
		int dec = 0;
		std::string tmp = "";
		for (int j = i; j < i + 8; j++) {
			tmp += std::to_string(mask[j]);
		}
		dec = stoi(tmp);
		decimal.push_back(binaryToDecimal(dec));
	}


	std::string ret = "";
	for (auto i = 0; i < decimal.size(); i++) {
		ret += std::to_string(decimal[i]);
		if (i + 1 != decimal.size())
			ret += ".";
	}
	return ret;
}
std::string Mask::Subnet_To_Binary(){
	std::string ret = "";
	for (auto i = 0; i < mask.size(); i += 8) {
		for (int j = i; j < i + 8; j++) {
			ret += std::to_string(this->mask[j]);
		}
		ret += ".";
	}
	return ret.substr(0, ret.size() - 1);
}


void Mask::print_Subnet() {
	std::cout << "Mask Bin " << Subnet_To_Binary() << "\t" << convert_to_dec() << "\t\\"<<slash<<std::endl;
}

void Mask::set_subnet_string() {
	this->subnet = convert_to_dec();
}
std::string  Mask::get_subnet_string() {
	this->subnet = convert_to_dec();
	return subnet;
}



