#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void osearchid(string orderfile){//поиск заказа по id
	ifstream fin;
	ofstream fout;	
	fin.open(orderfile);	
	int  i=0;
	int k=0;
	cout <<"Enter the id you want to find"<<endl;
	string s;
	while (!fin.eof()){//количество строк
		getline(fin, s);
		k++;
	}
	k--;
	Order *a = new Order[k+1];//массив из заказов
	fin.close();
	fin.open(orderfile);
	for (i=0; i<k; i++){
		fin >> a[i].ido;//заносим данные из файла в массив
		fin >> a[i].price;
		fin >> a[i].deadline;
		fin >> a[i].dtime;
		fin >> a[i].address;
		fin >> a[i].courierid;
	}
	int tmp=-1;
	int ido;
	cin >>ido;//искомый id
	for (i=0; i<k; i++){ 
		if (a[i].ido== ido){//ищем id, выводим, если есть 
			cout << a[i].ido<<" " <<a[i].price <<" " << a[i].deadline <<" "<< a[i].dtime <<" " << a[i].address<<" " << a[i].courierid <<endl;
			tmp=1;		
		} 
	}
	if (tmp==-1){//если не было совпадений
		cout<<"---------------There's no such id---------------"<<endl;
	}	
	fout.close();
	delete[]a;//уборка
}

