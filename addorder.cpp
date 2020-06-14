#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void addorder (string orderfile){
	ifstream fin;
	ofstream fout;
	fin.open(orderfile);	
	int  i=0;
	int k=0;
	string s;
	cout << "Enter the order you want to put('price(integer) /n deadline(minutes) /n address(one word) "<<endl;
	while (!fin.eof()){//считаем количество строк в файле
		getline(fin, s);
		k++;
	}
	k--;
	Order*a = new Order[k+1];//выделяем память
	fin.close();
	fin.open(orderfile);	
	for (i=0; i<k; i++){//считываем из файла данные в массив 
		fin >> a[i].ido;
		fin >> a[i].price ;
		fin >> a[i].deadline;
		fin >> a[i].dtime;
		fin >> a[i].address;
		fin >> a[i].courierid;
	}
	int j, l;
	int ido;
	l=0;
	int price;
	int deadline, dtime;
	string address;
	int courierid=0;		
	while(l==0){
		l=1;
		cin >>price>>deadline>> address;//спрашиваем данные о добавляемом заказе, остальные данные присваиваем автоматически
		if(deadline<10){
			cout << "Sorry, we can't deliver your order that fast. Please, try again"<<endl;
			l=0;
		}
	}		
	ido=k+1;
	dtime=deadline;
	while(l==0){//проверка на совпадение id
		l=1;
		for(j=0;j<k;j++){
			if (a[j].ido==ido){
				ido=ido+1;
				l=0;
			}
		}
	}					
	fin.close();
	a[k].ido=ido;//последнему объекту массива присваиваем ссчитанные данные
	a[k].price=price;
	a[k].deadline=deadline;
	a[k].dtime=dtime;
	a[k].address=address;
	a[k].courierid=courierid;
	fout.open(orderfile, ios::out);
	for (i=0; i<k+1; i++){//перезаписываем в файл массив
		fout << a[i].ido <<" "<<a[i].price<<" "<<a[i].deadline<<" "<<a[i].dtime<<" "<<a[i].address<<" "<<a[i].courierid<<endl;
	}
	fout.close();
	delete [] a;//уборка
}
