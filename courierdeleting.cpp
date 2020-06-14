#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;

void courierdeleting(string courierfile, string orderfile){//удаление курьера
	ifstream fin;
	ofstream fout;	
	fin.open(courierfile);	
	int  i=0;
	int k=0;
	cout <<"Enter the id you want to delete"<<endl;
	string s;
	int x1,x2;
	while (!fin.eof()){//считываем количество строк в файле курьеров
		getline(fin, s);
		k++;
	}
	k--;
	Courier *a = new Courier[k+1];//создаем массив курьеров
	fin.close();
	fin.open(courierfile);
	for (i=0; i<k; i++){
		fin >> a[i].idc;//считываем в массив данные из файла
		fin >> a[i].name ;
		fin >> a[i].phone;
		fin >> a[i].orderid1;
		fin >> a[i].orderid2;
		fin >> a[i].car;
		fin >> a[i].deliverytime;
	}
	int idc;
	int tmp=-1;
	cin >> idc;//считываем удаляемый id
	for (i=0; i<k; i++){ 
		if (a[i].idc== idc){
			tmp=i;
			x1=a[i].orderid1;//запоминаем номера его заказов
			x2=a[i].orderid2;
		}
	}
	fin.close();	
	if (tmp>-1){//если такой курьер нашелся
		fout.open(courierfile, ios::out);
		for (i=0; i<k; i++){
			if(i!=tmp){//всех курьеров не с его id заносим в файл
				fout << a[i].idc <<" "<<a[i].name<<" "<<a[i].phone<<" "<<a[i].orderid1<<" " << a[i].orderid2<<" "<<a[i].car<<" "<<a[i].deliverytime<<endl;
			}
		}
		fout.close();
	}
	else{//если не нашелся, то не перезаписываем файл
		cout<<"We don't have courier with this id. Please? try again"<<endl;
	}
	delete[]a;//уборка
	fin.open(orderfile);//начинаем работу с файлом заказов
	k=0;
	while (!fin.eof()){//считываем количество строк
		getline(fin, s);
		k++;
	}
	k--;
	Order *b = new Order[k+1];//создаем массив заказов
	fin.close();
	fin.open(orderfile);
	for (i=0; i<k; i++){
		fin >> b[i].ido;//считываем заказы из файла
		fin >> b[i].price;
		fin >> b[i].deadline;
		fin >> b[i].dtime;
		fin >> b[i].address;
		fin >> b[i].courierid;
		if ((b[i].ido==x1)||(b[i].ido==x1)){//заказы удаленного курьера делаем свободными
			b[i].courierid=0;
		}	
	}
	fin.close();
	fout.open(orderfile, ios::out);
	for (i=0; i<k; i++){ //перезаписываем массив заказов
		fout << b[i].ido<<" " <<b[i].price <<" " << b[i].deadline <<" " <<b[i].dtime <<" " << b[i].address<<" " << b[i].courierid<<endl;
	}
	fout.close();
	delete[]b;//уборка

}

