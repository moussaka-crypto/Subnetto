#ifndef _UTILITY_H
#define _UTILITY_H
#include<vector>
#include <sstream>

std::vector<int> decToBinary(int n);
int binaryToDecimal(int n);
std::string extractHex(std::vector<int>);
std::string extractHexV2(std::vector<int>);
std::vector<int> hex_to_char(char c);
int countFreq_ofString(std::string& pat, std::string& txt);
void elongateIPV6(std::string& Ip);
int countFreq_ofString(std::string& pat, std::string& txt);
int nearest_binary_base_subnets(int num);
int nearest_binary_base_hosts(int num);

#endif

