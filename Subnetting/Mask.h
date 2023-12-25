#ifndef _MASK_H
#define _MASK_H
#include <exception>
#include <iostream>
#include <vector>

class Mask {
private:
	int slash;
	std::vector<int> mask;
	void validate_notation(int slash);
	std::string convert_to_dec();
	std::string Subnet_To_Binary();
	std::string subnet;

public:
	Mask() { 
		this->mask.assign(32, 0);
		this->slash = 32;
		std::fill(std::begin(mask), std::begin(mask) + slash, 1);
		this->subnet = get_subnet_string();
	}
	Mask(const Mask& M) {
		this->mask = M.mask;
		this->slash = M.slash;
		this->subnet = get_subnet_string();
	}
	Mask(int slash){
		mask.assign(32, 0);
		this->slash = slash;
		validate_notation(slash);
		std::fill(std::begin(mask), std::begin(mask) + slash, 1);
	}
	~Mask(){}
	Mask& operator=(const Mask& orig) {
		this->mask = orig.mask;
		this->slash = orig.slash;
		return *this;
	}
	void set_Subnet(int slash) {
		this->mask.clear();
		this->mask.assign(32, 0);
		validate_notation(slash);
		this->slash = slash;
		this->subnet = get_subnet_string();
		std::fill(std::begin(mask), std::begin(mask) + slash, 1);
	}
	int get_slash()const { return slash; }
	void print_Subnet();
	void set_subnet_string();
	std::string get_subnet_string();
};

#endif 

