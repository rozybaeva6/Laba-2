#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Order {
public:
	string ido;
	int price;
	int deadline;
	string address;
	string courierid;
	int weight;
	void addorder(string orderfile);
	void osearchid(string orderfile); // поиск по id
};

class Courier {
public:
	string idc;
	string name;
	string phone;
	string orderid1; // текущий заказ
	string orderid2; // будущий заказ
	int car;
	int deliverytime;
	void addcourier(string courierfile);
	void courierdeleting(string courierfile); // Удаление по id
	void csearchname(string courierfile); // поиск по имени 
	void csearchphone(string courierfile); // поиск по телефону
	void allcourierclear(string courierfile); //Очистить файл с данными
	};
