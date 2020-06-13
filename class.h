#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Order {
public:
	int ido;
        int price;
        int deadline;
        string address;
        int courierid;
        int weight;
	void addorder (string orderfile);
	void osearchid(string orderfile); // поиск по id
	void runtime(string orderfile); // время
	void oselect(string courierfile, string orderfile); // распределение заказов по курьерам
};

class Courier {
public:
	int idc;	
	string name;
	string phone;
	int orderid1; // текущий заказ
	int orderid2; // будущий заказ
	int car; 
	int deliverytime;
	void addcourier (string courierfile);
	void courierdeleting(string courierfile); // Удаление по id
	void csearchname(string courierfile); // поиск по имени 
	void allcourierclear(string courierfile); //Очистить файл с данными
	void csearchid(string courierfile); // поиск по id
	void allcourierwrite(string courierfile);
	void oselect(string courierfile, string orderfile);
};
