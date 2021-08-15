#ifndef _IP_ADRESS_H
#define _IP_ADRESS_H
#include <string>
#include <vector>
#include <iostream>
class IPAdress;
class IPV4;
class IPV6;

#define LONGINT long long int;

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
	std::string toStringAddBinary();
	void dumpAdress() { Add.clear(); }

};

class IPV4 :public IPAdress {
private:
	std::string toStringAddDecimal();
public:
	void init_IP(std::string Ip)override;
	void printAdd()override;
	IPV4() { Add.assign(32, 0); }

};

class IPV6 :public IPAdress {
private:
	std::string toStringAddHex();
public:
	void init_IP(std::string Ip)override;
	void printAdd()override;
	
	IPV6(IPV4 ipv4) { convert6to4(ipv4); }
	IPV6() { Add.assign(112, 0); }
	
};

#endif _IP_ADRESS_H
