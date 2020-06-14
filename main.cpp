#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
int main(){
	string courierfile;
	string orderfile;
	cout << "Good morning."<<endl;//доброе утро
	string s;
	int n, m;
	int k=0;
	int l=0;
	fstream fin;
	while (k==0){//считываение имени файла с данными о курьерах 
		cout << "---------------Please enter new courier database name:(txt file!)- print '0' if you cant---------------"<<endl;
		cin >> s;
		if (s=="0")//{выход
			cout<<" Thank you, see you later"<<endl; 
			exit(0);
		}
		courierfile=s;
		fin.open(courierfile);
		if(!fin.is_open()){//существует ли такой файл
			cout <<"---------------Sorry, database can not be found. Please try again---------------"<<endl;
		}
		else{	
			cout<<"---------------Courier database changed sucsessfully---------------"<<endl;
			k=1;
		}
		fin.close();
	}
	k=0;
	while (k==0){//ввод базы данных для заказов
		cout << "---------------Please enter new order database name:(txt file!)- print '0' if you cant---------------"<<endl;
		cin >> s;
		if (s=="0"){
			cout<<"Great, see you later"<<endl; 
			exit(0);
			
		}
		s;
		fin.open(s);
		if(!fin.is_open()){//существует ли этот файл
			cout <<"---------------Sorry, database can not be found. Please try again---------------"<<endl;
		}
		else{	
			cout<<"---------------Order database changed sucsessfully---------------"<<endl;
			k=1;
			orderfile=s;
		}
		fin.close();
	}
	int g;
	k=0;
	while (k==0){//главное меню
		cout <<"---------------------------------------"<<endl;
		cout <<"Your courier database name right now is: "<< courierfile<<endl;	
		cout <<"Your order database name right now is: "<< orderfile<<endl;
		cout <<"Press 42- to see help"<<endl;
		cout <<"---------------------------------------"<<endl;
		cin >> n;
		oselect(courierfile, orderfile);//функция распределения заказов по курьерам, работает автоматически каждую итерацию
		switch (n){
		case 42://справка
			cout <<"---------------Press:---------------"<<endl;	
			cout <<"0- to start time"<<endl;
			cout <<"1- to start work with couriers"<<endl;
			cout <<"2- to start work with orders"<<endl;
			cout <<"3- to show courier list"<<endl;
			cout <<"4- to show order list"<<endl;
			cout <<"100- to end up program"<<endl;
		break;
		case 0://промотать время вперед на n минут
			runtime(courierfile, orderfile);
		break;
		case 100://конец программы
			k=1;
			cout<<"＼(￣▽￣)／ (*¯︶¯*) ＼(＾▽＾)／ Thank you, see you soon＼(￣▽￣)／ (*¯︶¯*) ＼(＾▽＾)／"<<endl; 
		break;
		case 3://вывод всех курьеров
			allcourierwrite(courierfile);
		break;
		case 4://вывод всех заказов
			allorderwrite(orderfile);
		break;
		case 1://работа с курьерами
			l=0;
			system("cls");//переход на новую страницу
			while(l==0){//меню раоботы с курьерами
				cout <<"---------------------------------------"<<endl;
				cout <<"Your courier database name right now is: "<< courierfile<<endl;	
				cout <<"Your order database name right now is: "<< orderfile<<endl;
				cout <<"Press 42- to see help"<<endl;
				cin>>m;
				oselect(courierfile, orderfile);//распределение заказов по курьерам
				switch (m){
				case 42://справка
					cout <<"---------------Press:---------------"<<endl;	
					cout <<"1- to add courier"<<endl;
					cout <<"2- to fire courier"<<endl;
					cout <<"3- to find courier with id"<<endl;
					cout <<"4- to find courier by his name"<<endl;
					cout <<"5- to find courier by his phone"<<endl;
					cout <<"6- to show courier list"<<endl;
					cout <<"7- to clear courier list"<<endl;
					cout <<"99- to change courier database"<<endl;
					cout <<"0- to return to main menu"<<endl;
				break;
				case 0://выход в главное меню
					l=1;
				break;
				case 1://добавить курьера
					addcourier(courierfile);
				break;
				case 2://удалить курьера
					courierdeleting(courierfile, orderfile);
				break;
				case 3://найти курьера по id
					csearchid(courierfile);
				break;
				case 4://найти по имени
					csearchname(courierfile);
				break;
				case 5://найти по телефону
					csearchphone(courierfile);
				break;
				case 6://вывести список курьеров
					allcourierwrite(courierfile);
				break;
				case 7://очистить список курьеров
					allcourierclear(courierfile, orderfile);
				break;
				case 99://смена базы данных курьеров(аналогично первой)
					g=0;
					while (g==0){
						cout << "---------------Please enter new courier database name:(txt file!)- print '0' if you cant---------------"<<endl;	
						cin >> s;
						if (s=="0"){
							g==1;
						}
						fin.open(s);
						if(!fin.is_open()){
							cout <<"---------------Sorry, database can not be found. Please try again---------------"<<endl;
						}
						else{	
							cout<<"---------------Courier database changed sucsessfully---------------"<<endl;
							g=1;
							courierfile=s;
						}
						fin.close();
					}
				break;
				}
			}
			system("cls");//переход на новую страницу
		break;
		case 2://работа с заказами
			l=0;
			system("cls");//новая страница
			while(l==0){
				cout <<"---------------------------------------"<<endl;
				cout <<"Your courier database name right now is: "<< courierfile<<endl;	
				cout <<"Your order database name right now is: "<< orderfile<<endl;
				cout <<"Press 42- to see help"<<endl;
				oselect(courierfile, orderfile);//распределение заказов
				cin>>m;
				switch (m){
				case 42://справка
					cout <<"1- to add order"<<endl;
					cout <<"2- to find order with id"<<endl;
					cout <<"3- to show order list"<<endl;
					cout <<"4- to clear order list"<<endl;
					cout <<"99- to change order database"<<endl;		
					cout <<"0- to do to the main menu"<<endl;
				break;
				case 0://в главное меню
					l=1;
				break;
				case 1://добавить заказ
					addorder(orderfile);
				break;
				case 2://найти по id
					osearchid(orderfile);
				break;
				case 3://вывести список заказов
					allorderwrite(orderfile);
				break;
				case 4://очистить файл заказов
					allorderclear(courierfile, orderfile);
				break;
				case 99://смена файла(аналогично начальной
					g=0;
					while (g==0){
						cout << "---------------Please enter new order database name:(txt file!)- print '0' if you cant---------------"<<endl;	
						cin >> s;
						if (s=="0"){
							g==1;
						}
						fin.open(s);
						if(!fin.is_open()){
							cout <<"---------------Sorry, database can not be found. Please try again---------------"<<endl;
						}
						else{	
							cout<<"---------------Order database changed sucsessfully---------------"<<endl;
							g=1;
							orderfile=s;
						}
						fin.close();
					}
				break;
				}
			}
			system("cls");
		break;
		default://неправильный ввод
			cout<<"You uncorrect data. Please, try again"<<endl;
		break;
		}
	}
	return 0;
}

