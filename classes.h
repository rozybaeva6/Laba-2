#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Order {
private:
	int ido;
        int price;
        int deadline;
        string address;
        int courierid;
        int dtime;
public:
	friend void allorderclear(string courierfile, string orderfile);
	friend void allorderwrite(string orderfile);
	friend void allcourierclear(string courierfile, string orderfile);
	friend void courierdeleting(string courierfile, string orderfile);
       friend  void oselect(string courierfile, string orderfile);
	friend void addorder (string orderfile);
	friend void osearchid(string orderfile);
	friend void runtime(string courierfile, string orderfile);
};
class Courier {
private:
	int idc;	
	string name;
	string phone;
	int orderid1;
	int orderid2;
	int car; 
	int deliverytime;
public:
	friend void allorderclear(string courierfile, string orderfile);
	friend void runtime(string courierfile, string orderfile);
	friend void csearchid(string courierfile);
	friend void addcourier(string courierfile);
	friend void courierdeleting(string courierfile, string orderfile);
	friend void csearchname(string courierfile);	
	friend void csearchphone(string courierfile);	
	friend void allcourierclear(string courierfile, string orderfile);
	friend void allcourierwrite(string namefile);
	friend void oselect(string courierfile, string orderfile);
};
void allorderwrite(string orderfile);
void allorderclear(string courierfile, string orderfile);
void allcourierwrite(string courierfile);
void allcourierclear(string courierfile, string orderfile);
void courierdeleting(string courierfile, string orderfile);
void oselect(string courierfile, string orderfile);
void addorder (string orderfile);
void osearchid(string orderfile);
void runtime(string courierfile, string orderfile);
void csearchid(string courierfile);
void csearchname(string courierfile);
void csearchphone(string courierfile);
void addcourier(string courierfile);
