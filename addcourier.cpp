#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"

using namespace std;

void addcourier (string courierfile)
{//Добавление курьеров
	ifstream fin;
	ofstream fout;
	fin.open(courierfile);	
	int  i=0;
	int k=0;
	string s;
	cout << "Enter the courier you want to put('name /n phone /n car(0 or 1)')"<<endl;
	while (!fin.eof()){//Считаем количество строк в тексте=количество видов объектов
		getline(fin, s);
		k++;
	}
	k--;
	Courier *a = new Courier[k+1];//Выделяем память на массив типа  struct(с запасом)
	//fin.seekg( 0 );//Не забываем вернуть курсор в начало
	fin.close();//Убираем за собой
	fin.open(courierfile);	
	for (i=0; i<k; i++){
		fin >> a[i].idc;
		fin >> a[i].name ;
		fin >> a[i].phone;
		fin >> a[i].orderid1;
		fin >> a[i].orderid2
		fin >> a[i].car;
		fin >> a[i].deliverytime;
		//Считываем элементы из файла, заодно выводим на экран все текущие элементы
	}
	int j;
	string name;
	string phone;
	int idc;
	int car;		
	cin >> name >> phone >> car; 
	idc=k+1;
	int f=0;
	while(f==0){
		f=1;
		for (i=0; i<k; i++){
			if (a[i].idc== idc){ 
				f=0;
				idc=idc+1;
				fin.close();	
			}
			if (a[i].name== name){ // сравниваем параметры
				cout <<"courier with same name already exists. Try the other one"<<endl;
				fin.close();
				exit(0);	
			}
			if (a[i].phone== phone){ // сравниваем параметры
				cout <<"courier with same phone already exists. Try the other one"<<endl;
				fin.close();
				exit(0);	
			}
		}
	}
	fin.close();//Готовимся полностью очистить файл
	a[k].idc=idc;
	a[k].name=name;
	a[k].phone=phone;
	a[k].car=car;
	a[k].deliverytime=0;
	a[k].orderid1=0;
	a[k].orderid2=0;
	fout.open(courierfile, ios::out);//Мы снова в файле, но он теперь пустой
	for (i=0; i<k+1; i++){//Переписываем весь дополненный массив в документ
		fout << a[i].idc <<" "<<a[i].name<<" "<<a[i].phone<<" "<<a[i].orderid1<<" "a[i].orderid2<<" "<<a[i].car<<" "<<a[i].deliverytime<<endl;
	}
	fout.close();//Убираем за собой
	delete [] a;//Убираем за собойх2
}
