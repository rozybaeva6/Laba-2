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
        int dtime;
	void addorder (string orderfile);
	void osearchid(string orderfile); // поиск по id
	void runtime(string courierfile, string orderfile); // время
	void oselect(string courierfile, string orderfile); // распределение заказов по курьерам
	void allorderclear(string courierfile, string orderfile);
	void allorderwrite(string orderfile);
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
	void courierdeleting(string courierfile, string orderfile); // Удаление по id
	void csearchname(string courierfile); // поиск по имени 
	void csearchid(string courierfile); // поиск по id
	void csearchphone(string courierfile); // поиск по телефону
	void allcourierwrite(string courierfile); //Вывести все элементы на экран
	void oselect(string courierfile, string orderfile);
	void runtime(string courierfile, string orderfile);
	void allcourierclear(string courierfile, string orderfile); //Очистить файл с данными
};

void allorderclear(string courierfile, string orderfile);
void allcourierwrite(string courierfile);
void allcourierclear(string courierfile, string orderfile);
void allcourierwrite(string courierfile);
void courierdeleting(string courierfile, string orderfile);
void oselect(string courierfile, string orderfile); 
void addorder (string orderfile);
void osearchid(string orderfile);
void runtime(string courierfile, string orderfile); 
void csearchid(string courierfile);
void csearchname(string courierfile);
void csearchphone(string courierfile); 
void addcourier(string courierfile);
