#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Order {
private:
	int ido; // id заказа
        int price; // цена заказа
        int deadline; // срок доставки заказа
        string address; // адрес доставки
        int courierid; // id сотрудника
        int dtime; // время доставки заказа
public:
	friend void allorderclear(string courierfile, string orderfile); // очистить файл заказов
	friend void allorderwrite(string orderfile); // вывести список заказов
        friend void oselect(string courierfile, string orderfile); // распределение заказов по курьерам
	friend void addorder (string orderfile); // добавить заказ
	friend void osearchid(string orderfile); // поиск по id
	friend void runtime(string courierfile, string orderfile); // промотать время вперед на n минут
};
class Courier {
private: 
	int idc; // id сотрудника	
	string name; // имя сотрудника
	string phone; // телефон сотрудника
	int orderid1; // текущий заказ
	int orderid2; // будущущий заказ
	int car; // машина для доставки
	int deliverytime; // время через которое курьер освободится
public:
	friend void runtime(string courierfile, string orderfile); // промотать время вперед на n минут
	friend void csearchid(string courierfile); // найти курьера по id
	friend void addcourier(string courierfile); // добавить курьера
	friend void courierdeleting(string courierfile, string orderfile); // удалить курьера
	friend void csearchname(string courierfile); // найти курьера по имени
	friend void csearchphone(string courierfile); // найти курьера по телефону
	friend void allcourierclear(string courierfile, string orderfile); // очистить список курьеров
	friend void allcourierwrite(string namefile); // вывести список курьеров
	friend void oselect(string courierfile, string orderfile); // распределение заказов по курьерам
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
