#include "Utility.h"
#include <iostream>
#include <algorithm>

std::vector<int> decToBinary(int n)
{
	std::vector<int> binaryNum(8);
	int i = 0;
	while (n > 0) {
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	reverse(binaryNum.begin(), binaryNum.end());
	return binaryNum;
}

int binaryToDecimal(int n)
{
	int num = n;
	int dec_value = 0;
	int base = 1;
	int temp = num;

	while (temp) {
		int last_digit = temp % 10;
		temp = temp / 10;
		dec_value += last_digit * base;
		base = base * 2;
	}
	return dec_value;
}

std::vector<int> hex_to_char(char c) {

	char ch = toupper(c);
	if (('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'F')) {
		
		int hexVal = 0x00;
		if ('0' <= ch && ch <= '9')
			hexVal = ch - '0';
		else
			hexVal = ch - 'A' + 10;

		std::vector<int> res = {};
		for (int i = 3; i >= 0; --i) {
			res.push_back((hexVal >> i) & 1);
		}
		return res;
	}
	return {};
}

std::string extractHex(std::vector<int>_2_Bytes) {
	if (_2_Bytes.size() != 16)
		throw std::range_error("Invalid Bytes size");

	std::string ret = "";
	for (int i = 0; i < _2_Bytes.size(); i += 4) {
		std::stringstream res;
		std::copy(_2_Bytes.begin()+i, _2_Bytes.begin()+i+4, std::ostream_iterator<int>(res));
		std::string bitString = res.str().c_str();
		int m = std::stoi(bitString.c_str(), nullptr, 2);
		std::stringstream pars;
		pars << std::hex << m;
		ret += pars.str();
	}
	std::transform(ret.begin(), ret.end(), ret.begin(), ::toupper);
	return ret;
}

std::string extractHexV2(std::vector<int>_1_Byte) {
	if(_1_Byte.size()!=8)
		throw std::range_error("Invalid Bytes size");

	std::string ret = "";
	for (int i = 0; i < _1_Byte.size(); i += 4) {
		std::stringstream res;
		std::copy(_1_Byte.begin() + i, _1_Byte.begin() + i + 4, std::ostream_iterator<int>(res));
		std::string bitString = res.str().c_str();
		int m = std::stoi(bitString.c_str(), nullptr, 2);
		std::stringstream pars;
		pars << std::hex << m;
		ret += pars.str();
	}
	std::transform(ret.begin(), ret.end(), ret.begin(), ::toupper);
	return ret;
}

void elongateIPV6(std::string& Ip) {
	std::string front = "";
	std::string target = "::";
	int pos = 0;
	for (auto i = 0; i < Ip.length(); i++) {
		if (Ip[i] == ':' && i + 1 < Ip.length() && Ip[i + 1] == ':')
			break;
		front += Ip[i];
		pos++;
	}
	std::string rest(Ip.begin() + pos+2, Ip.end());

	std::stringstream first(front);
	std::stringstream second(rest);
	std::string segment;
	std::vector<std::string> first_Vec;
	std::vector <std::string> sec_Vec;
	while (std::getline(first, segment, ':')) {
		first_Vec.push_back(segment);
	}
	while (std::getline(second, segment, ':')) {
		sec_Vec.push_back(segment);
	}
	int num_of_2Bytes = first_Vec.size() + sec_Vec.size();
	for (int i = 0; i < 7 - num_of_2Bytes; i++) {
		front += ":0000";
	}
	front += ":" + rest;
	Ip = front;
}

int countFreq_ofString(std::string& pat, std::string& txt)
{
	int M = pat.length();
	int N = txt.length();
	int res = 0;
	for (int i = 0; i <= N - M; i++)
	{
		int j;
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;
		if (j == M)
		{
			res++;
			j = 0;
		}
	}
	return res;
}

int nearest_binary_base_subnets(int num) {
	int base = 0;
	int i = 1;
	for (; i < 32; i++) {
		base = pow(2, i);
		if (base == num)
			return i;
		if (base > num)
			break;
	}
	return i;
}

int nearest_binary_base_hosts(int num) {
	int base = 0;
	int i = 1;
	for (; i < 32; i++) {
		base = pow(2, i) - 2;
		if (base == num)
			return i;
		if (base > num)
			break;
	}
	return i;
}