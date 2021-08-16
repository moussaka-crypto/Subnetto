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
public:
	Mask() { 
		mask.assign(32, 0);
		slash = 32; 
		std::fill(std::begin(mask), std::begin(mask) + slash, 1);
	}
	Mask(const Mask& M) {
		this->mask = M.mask;
		this->slash = M.slash;
	}
	Mask(int slash){
		mask.assign(32, 0);
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
		mask.clear();
		mask.reserve(32);
		validate_notation(slash);
		std::fill(std::begin(mask), std::begin(mask) + slash, 1);
	}
	void print_Subnet();
};

#endif 

