#ifndef _MASK_H
#define _MASK_H
#include <exception>
#include <iostream>
class MaskContainer {
private:
	int suffix;
	int mask[32];
	void validate_suffix(int suffix);
public:
	MaskContainer(){}
	MaskContainer(int suffix){
		validate_suffix(suffix);
		std::fill(std::begin(mask), std::begin(mask) + 32, 1);
	}
	~MaskContainer(){}

	MaskContainer& operator=(const MaskContainer& orig);
	std::string convert_to_dec();
};

#endif 

