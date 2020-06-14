#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void runtime(string courierfile, string orderfile){//перемотка времени вперед
	ifstream fin;
	ofstream fout;	
	int  i=0;
	int n;
	int k=0;
	string s;
	cout<<"Please, enter time(in minutes) you want to go:"<<endl;
	int l=0;
	int j;
	cin >>n;//СКОЛЬКО МИНУТ
	for (int g=0;g<n;g++){//идем в цикле по одной минуте за раз
	fin.open(courierfile);
	l=0;
	while (!fin.eof()){//считываем количество курьеров
		getline(fin, s);
		l++;
	}
	l--;
	fin.close();
	fin.open(courierfile);
	Courier *b = new Courier[l+1];
	for (i=0; i<l; i++){//считываем курьеров
		fin >> b[i].idc;
		fin >> b[i].name ;
		fin >> b[i].phone;
		fin >> b[i].orderid1;
		fin >> b[i].orderid2;
		fin >> b[i].car;
		fin >> b[i].deliverytime;
	}
	fin.close();
	fin.open(orderfile);
	k=0;
	while (!fin.eof()){//считываем количество заказов
		getline(fin, s);
		k++;
	}
	k--;
	fin.close();
	fin.open(orderfile);
	Order *a = new Order[k+1];
	for (i=0; i<k; i++){//считываем заказы
		fin >> a[i].ido;
		fin >> a[i].price;
		fin >> a[i].deadline;
		fin >> a[i].dtime;
		fin >> a[i].address;
		fin >> a[i].courierid;
	}
	fin.close();
	fout.open(orderfile, ios::out);
	for (i=0; i<k; i++){ //идем по массиву заказов
		a[i].dtime=a[i].dtime-1;//уменьшаем дедлайн и время до доставки на минуту
		a[i].deadline=a[i].deadline-1;

		
		if (a[i].dtime>=1){//если заказ еще не доставлен, записываем аго в файл
			fout << a[i].ido <<" "<<a[i].price<<" "<<a[i].deadline<<" "<<a[i].dtime<<" "<<a[i].address<<" "<<a[i].courierid<<endl;
		}
		else{//если заказ доставлен 
			if(a[i].courierid==0){
				a[i].deadline=-10;//заказ так и не распределили
			}
			else{
				a[i].deadline=-20;//заказ взял курьер и доставил
			}
		} 
	}
	fout.close();
	fout.open(courierfile, ios::out); 
	for(j=0;j<l;j++){//идем по массиву курьеров
		b[j].deliverytime=b[j].deliverytime-1;//уменьшаем время доставки на единицу
		if (b[j].deliverytime==0){//если только что оно стало нулем, значит сейчас доставлялся заказ
			b[j].orderid1=b[j].orderid2;//начинает доставлять второй заказ
			b[j].orderid2=0;//освобождает место для второго заказа
			if(b[j].orderid1>0){
				b[j].deliverytime=30-20*b[j].car;//в зависимости от скорости, определяем время доставки
			}
			else{
				b[j].deliverytime=0;//если нет заказов, время доставки=0 
			}					
		}
		if(b[j].deliverytime<0)//держим числа у людей без заказов больше нуля
		{b[j].deliverytime=0;}
		fout << b[j].idc<<" " <<b[j].name <<" " << b[j].phone <<" " << b[j].orderid1<<" " << b[j].orderid2 <<" " << b[j].car<<" " << b[j].deliverytime<<endl;	
 //переписываем данные о курьерах
	}		
	cout<<" "<<g+1<<" minutes passed"<<endl;//выводим сообщение о прошедших миутах
	fout.close();
	for (i=0; i<k; i++){ //идем по массиву заказов
		if(a[i].deadline==-10){//если у заказа прошел дадлайн
			cout<<"----------------ATTENTION: Sorry, order "<<a[i].ido<<" wasn't delivered----------------"<<endl;
		}
		if(a[i].deadline==-20){//Если заказ был доставлен
			cout <<"---------------ATTENTION: Order "<<a[i].ido<<" was delivered--------------"<<endl;
		} 
	}
	delete[]a;//уборка
	delete[]b;
	}
}

