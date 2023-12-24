#include "IPAdress.h"
#include "Utility.h"
#include <sstream>
#include <algorithm>
#include <stdlib.h>
IPAdress& IPAdress::operator=(const IPAdress& orig) {
	std::move(orig.Add.begin(), orig.Add.end(), this->Add.begin());
	return *this;
}



void IPV4::init_IP(std::string Ip) {
	Add.clear();
	Add.assign(32, 0);
	std::string target = ",";

	if (Ip.find(target) != std::string::npos) {
		if (countFreq_ofString(target, Ip) > 0)
			throw std::invalid_argument("IPV4 IP invalid. Check IP for invalid ','");
		
	}

	std::stringstream pars(Ip);
	std::string segment;
	std::vector <int> seglist;
	while (std::getline(pars, segment, '.')) {
		seglist.push_back(stoi(segment));
	}

	auto is_valid = find_if(seglist.begin(), seglist.end(), [](int check) {return check > 255; });
	if (is_valid != seglist.end())
		throw std::invalid_argument("Invalid IP");
	int i = 0;
	int increment = 0;

	for (auto it = seglist.begin(); it != seglist.end();it++) {
		std::vector<int> byte_ = decToBinary(*it);
		std::move(byte_.begin(), byte_.end(), Add.begin()+increment);
		increment += 8;
	}
	
}



void IPV6::init_IP(std::string Ip) {
	Add.clear();
	Add.assign(128, 0);
	int pos = 0, increment = 0;
	std::string target = "::";

	if (Ip.find(target) != std::string::npos) {
		if (countFreq_ofString(target,Ip) > 1)
			throw std::invalid_argument("IPV6 IP invalid. Check IP for invalid '::'.");
		elongateIPV6(Ip);
	}
	

	std::stringstream pars(Ip);
	std::string segment;
	std::vector <std::string> seglist;
	while (std::getline(pars, segment, ':')) {
		seglist.push_back((segment));
	}
	
	for (auto i = 0; i < seglist.size();i++){ 
		for (int j = 0; j < seglist[i].size(); j++) {
			char c = seglist[i][j];
			std::vector<int> byte_ = hex_to_char(c);
			std::move(byte_.begin(), byte_.end(), Add.begin() + increment);
			increment += 4;
		}
	}
}


std::string IPAdress::toStringAddBinary() {
	std::string ret = "";
	for (auto i = 0; i < Add.size(); i+=8) {
		for (int j = i; j <i+ 8; j++) {
			ret += std::to_string(this->Add[j]);
		}
		ret += ".";
	}
	return ret.substr(0, ret.size() - 1);
}


std::string IPV4::toStringAddDecimal() {
	std::vector<int>decimal;
	for (int i = 0; i < Add.size();i+=8 ) {
		int dec = 0;
		std::string tmp = "";
		for (int j = i; j <i+ 8; j++) {
			tmp += std::to_string(Add[j]);
		}
		dec = stoi(tmp);
		decimal.push_back(binaryToDecimal(dec));
	}


	std::string ret = "";
	for (auto i = 0; i < decimal.size();i++) {
		ret += std::to_string(decimal[i]);
		if (i + 1 != decimal.size())
			ret += ".";
	}
	return ret;

}

std::string IPV6::toStringAddHex() {
	std::string ret = "";
	for (int i = 0; i < Add.size(); i+=16) {
		
		std::vector<int> _2_bytes(Add.begin()+i, Add.begin()+i + 16);
		ret += extractHex(_2_bytes);
		if (i + 16 != Add.size())
			ret += ":";
		
	}
	return ret;
}

void IPAdress::convert6to4(IPV4 ipv4) {
	std::vector<int> binary_Ip_4 = ipv4.getAdd();
	std::string ret = "";
	for (int i = 0; i < binary_Ip_4.size(); i+=8) {
		std::vector<int> _1_Byte(binary_Ip_4.begin() + i, binary_Ip_4.begin() + i + 8);
		ret += extractHexV2(_1_Byte);
		
	}
	std::string first(ret.begin(), ret.begin() + 4);
	std::string second(ret.begin()+4, ret.begin() + 8);
	std::string res = "2002:" + first + ":" + second + "::";
	this->init_IP(res);
}

void IPAdress::printAdd() {
	std::cout << "Bin " <<toStringAddBinary() <<std::endl;
}
void IPV4::printAdd() {
	std::cout << "IPV4 Bin " << toStringAddBinary() << " \t" << toStringAddDecimal() << std::endl;
}

void IPV6::printAdd() {
	std::cout <<"IPV6 " << toStringAddHex() << std::endl;
}


void IPV4::randomize() {
	Add.clear();
	Add.assign(32, 0); 
	int octett1 = rand() % (192 - 0 + 1);
	int octett2 = rand() % (192 - 0 + 1);
	int octett3 = rand() % (192 - 0 + 1);
	int octett4 = rand() % (192 - 0 + 1);
	std::string ip;
	ip += std::to_string(octett1) + "." + std::to_string(octett2) + "." + std::to_string(octett3) + "."+ std::to_string(octett4);
	init_IP(ip);
}


std::string IPV4::get_IP() {
	return toStringAddDecimal();
}

std::string IPV6::get_IP() {
	return toStringAddHex();
}
