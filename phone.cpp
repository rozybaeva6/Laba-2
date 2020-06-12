void csearchphone(string courierfile){//Удаление элементов
	ifstream fin;
	ofstream fout;	
	fin.open(courierfile);	
	int  i=0;
	int k=0;
	cout <<"Enter the phone you want to find"<<endl;
	string s;
	while (!fin.eof()){
		getline(fin, s);
		k++;
	}
	k--;
	Courier *a = new Courier[k+1];//Выделяем память на массив типа  struct(с запасом)
	fin.close();
	fin.open(courierfile);
	for (i=0; i<k; i++){
		fin >> a[i].idc;
		fin >> a[i].name ;
		fin >> a[i].phone;
		fin >> a[i].orderid1;
		fin >> a[i].orderid2;
		fin >> a[i].car;
		fin >> a[i].deliverytime;
	}
	int tmp=-1;
	string phone;
	cin >>phone;//Считываем данные об удаляемом типе объектов
	for (i=0; i<k; i++){ 
		if (a[i].phone== phone){//Ищем соответствующее имя
			cout << a[i].idc<<" " <<a[i].name <<" " << a[i].phone <<" " << a[i].orderid1<<" " << a[i].orderid2 <<endl;
			tmp=1;		
		} 
	}
	if (tmp==-1){
		cout <<"There's no such phone"<<endl;
	}	
	fout.close();
	delete[]a;
}

void allcourierclear(string courierfile){//Очистить файл с данными
	ofstream f;
	f.open(courierfile, ios::out);
	f.close();
}

