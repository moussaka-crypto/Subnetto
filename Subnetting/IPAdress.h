#ifndef _IP_ADRESS_H
#define _IP_ADRESS_H
#include <string>
#include <vector>
#include <iostream>
class IPAdress;
class IPV4;
class IPV6;

class IPAdress {
protected:
	std::vector<int> Add;
	
public:
	IPAdress() {}
	IPAdress(const IPAdress& orig) {
		this->Add = orig.Add;
	}
	IPAdress(int size) { Add.assign(size, 0); }
	~IPAdress() { dumpAdress(); }
	IPAdress& operator=(const IPAdress& orig);
	void convert6to4(IPV4 ipv4);
	std::vector<int> getAdd()const { return Add; }
	virtual void init_IP(std::string Ip) {};
	virtual void printAdd();
	virtual void randomize(){ }
	std::string toStringAddBinary();
	void dumpAdress() { Add.clear(); }
	
};

class IPV4 : public IPAdress {
private:
	std::string toStringAddDecimal();
public:
	void init_IP(std::string Ip) override;
	void printAdd() override;
	void randomize() override;
	IPV4() { Add.assign(32, 0); }
	IPV4(std::string IP) { 
		Add.assign(32, 0);
		init_IP(IP); 
	}
	IPV4(std::vector<int> ip) { this->Add = ip; }
	std::string get_IP();
	
};

class IPV6 : public IPAdress {
private:
	std::string toStringAddHex();
public:
	void init_IP(std::string Ip) override;
	void printAdd() override;
	IPV6(IPV4 ipv4) { convert6to4(ipv4); }
	IPV6() { Add.assign(128, 0); }
	IPV6(std::string IP) { 
		Add.assign(128, 0);
		init_IP(IP); 
	}
	IPV6(std::vector<int> ip) { this->Add = ip; }
	std::string get_IP();
	
};

#endif _IP_ADRESS_H
