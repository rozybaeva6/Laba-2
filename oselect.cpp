#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void oselect(string courierfile, string orderfile)
{ 
	ifstream fin;
	ofstream fout;	
	fin.open(orderfile);	
	int  i=0;
	int k=0;
	string s;
	while (!fin.eof()){//количество строк в файле заказов
		getline(fin, s);
		k++;
	}
	k--;
	Order *a = new Order[k+1];//массив заказов
	fin.close();
	fin.open(orderfile);
	int nul=0;
	for (i=0; i<k; i++){
		fin >> a[i].ido;//заносим заказы в массив
		fin >> a[i].price;
		fin >> a[i].deadline;
		fin >> a[i].dtime;
		fin >> a[i].address;
		fin >> a[i].courierid;
		if(a[i].courierid==0){//считаем заказы без курьера
			nul++;
		}	
	}
	int j;
	int x;
	for(i=0;i<k;i++){//сортируем заказы по возрастанию крайнего срока доставки, для более эффективного распределения
		for(j=0;j<k-1;j++){//метод пузырька
			if(a[j].deadline>a[j+1].deadline){
				x=a[j].ido;
				a[j].ido=a[j+1].ido;
				a[j+1].ido=x;
				
				x=a[j].price;
				a[j].price=a[j+1].price;
				a[j+1].price=x;
				
				x=a[j].deadline;
				a[j].deadline=a[j+1].deadline;
				a[j+1].deadline=x;
				
				x=a[j].dtime;
				a[j].dtime=a[j+1].dtime;
				a[j+1].dtime=x;
				
				s=a[j].address;
				a[j].address=a[j+1].address;
				a[j+1].address=s;
				
				x=a[j].courierid;
				a[j].courierid=a[j+1].courierid;
				a[j+1].courierid=x;
			}
		}
	}	
	string w;	
	fin.close();
	fin.open(courierfile);
	j=0;
	while (!fin.eof()){//теперь считаем курьеров
		getline(fin, w);
		j++;
	}
	j--;
	Courier *b=new Courier[j+1];//создаем массив курьеров
	fin.close();
	fin.open(courierfile);
	for (i=0; i<j; i++){
		fin >> b[i].idc;//считываем массив из файла курьеров
		fin >> b[i].name ;
		fin >> b[i].phone;
		fin >> b[i].orderid1;
		fin >> b[i].orderid2;
		fin >> b[i].car;
		fin >> b[i].deliverytime;
	}
	int tmp=0;
	i=0;
	int f;
	int m=0;
	int t=0;
	for(i=0;i<k;i++){,,идем по массиву заказов
		if(a[i].courierid==0){//ищем заказы без курьера
			f=0;//флаг
			for (m=0;m<j;m++){//идем по массиву курьеров
			 	if((f==0)&&(b[m].orderid1==0)&&(a[i].deadline>30-20*b[m].car)){//если этот заказ еще не присвоили, курьер свободен и достаточно быстрый 
			 		b[m].orderid1=a[i].ido;//присваиваем соответствующие id
				 	a[i].courierid=b[m].idc;
			 		tmp++;//считаем распределенные заказы
			 		b[m].deliverytime=30-20*b[m].car;//теперь число не нулевое
			 		a[i].dtime=b[m].deliverytime;
			 		f=1;//флаг, теперь этот заказ назначен
				}	
			}
		}	
	}
	if(tmp<nul){//если еще остались нераспределенные заказы
		for(i=0;i<k;i++){//идем по заказам	
			if(a[i].courierid==0)	{//ищем свободные	
				f=0;//флаг
				for (m=0;m<j;m++){//идем по курьерам	
				 	if((f==0)&&(b[m].orderid2==0)&&(a[i].deadline>b[m].deliverytime+30-b[m].car*20)){//если заказ еще не присвоили, и незанятый курьер успеет после выполнения своего текущего заказа
				 		b[m].orderid2=a[i].ido;//присваиваем нужные id
					 	a[i].courierid=b[m].idc;
					 	a[i].dtime=b[m].deliverytime+30-20*b[m].car;//время доставки этого заказа
				 		f=1;//флаг, теперь заказ назначен
				 		tmp++;
					}	
				}
			}	
		}
	}
	fin.close();
	fout.open(courierfile, ios::out);//перезаписываем курьеров
	for (i=0; i<j; i++){
		fout << b[i].idc <<" "<<b[i].name<<" "<<b[i].phone<<" "<<b[i].orderid1<<" "<<b[i].orderid2<<" "<<b[i].car<<" "<<b[i].deliverytime<<endl;
	}
	fout.close();
	delete [] b;
	fout.open(orderfile, ios::out);//перезаписываем заказы
	for (i=0; i<k; i++){
		fout << a[i].ido <<" "<<a[i].price<<" "<<a[i].deadline<<" "<<a[i].dtime<<" "<<a[i].address<<" "<<a[i].courierid<<endl;
	}
	fout.close();
	delete [] a;	//уборка
					
}

