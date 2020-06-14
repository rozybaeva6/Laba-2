#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void allcourierclear(string courierfile, string orderfile){
	ofstream f;
	f.open(courierfile, ios::out);
	f.close();
	ifstream fin;
	ofstream fout;	
	fin.open(orderfile);	
	int  i=0;
	int k=0;
	string s;
	while (!fin.eof()){
		getline(fin, s);
		k++;
	}
	k--;
	Order *a = new Order[k+1];
	fin.close();
	fin.open(orderfile);
	for (i=0; i<k; i++){
		fin >> a[i].ido;
		fin >> a[i].price;
		fin >> a[i].deadline;
		fin >> a[i].dtime;
		fin >> a[i].address;
		fin >> a[i].courierid;
	}
	for (i=0; i<k; i++){ 
		fout << a[i].ido<<" " <<a[i].price <<" " << a[i].deadline <<" "<< a[i].dtime <<" " << a[i].address<<" " << 0 <<endl;
	} 
	fout.close();
	delete[]a;

}
