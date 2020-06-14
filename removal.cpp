void courierdeleting(string courierfile){//Удаление элементов
	ifstream fin;
	ofstream fout;	
	fin.open(courierfile);	
	int  i=0;
	int k=0;
	cout <<"Enter the id you want to delete"<<endl;
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
		cout << a[i].idc<<" " <<a[i].name <<" " << a[i].phone <<" " << a[i].orderid1<<" " << a[i].orderid2 <<endl;
	}
	string idc;
	int tmp=-1;
	cout << "What id do you want us to delete?"<< endl;
	cin >> idc;//Считываем данные об удаляемом типе объектов
	for (i=0; i<k; i++){ 
//cout<<a[i].form<<endl<<form;
		if (a[i].idc== idc){//Ищем соответствующий id
			tmp=i;
		}
	}
	fin.close();	
	if (tmp>-1){//Если мы нашли id
		fout.open(courierfile, ios::out);//открываем пустой файл
		for (i=0; i<k; i++){//Запись измененного массива в файл
			if(i!=tmp){//Доп. условие - если количество равно нулю, записано не будет
				fout << a[i].idc <<" "<<a[i].name<<" "<<a[i].phone<<" "<<a[i].orderid1<<" " << a[i].orderid2<<" "<<a[i].car<<" "<<a[i].deliverytime<<endl;
			}
		}
		fout.close();
	}
	else{
		cout<<"We don't have courier with this id. Please? try again"<<endl;
	}
	delete[]a;
	fin.open(orderfile);	
	k=0;
	while (!fin.eof()){
		getline(fin, s);
		k++;
	}
	k--;
	Order *a = new Order[k+1];//Выделяем память на массив типа  struct(с запасом)
	fin.close();
	fin.open(orderfile);
	for (i=0; i<k; i++){
	}
	string ido;
	fin.close();
	fout.open(courierfile, ios::out);
	for (i=0; i<k; i++){ 
//cout<<a[i].form<<endl<<form;
		if (a[i].courierid== idc){//Ищем соответствующий id
			a[i].courierid="0";
		}
	}
	for (i=0; i<k; i++){//Запись измененного массива в файл
		fout << a[i].idc <<" "<<a[i].name<<" "<<a[i].phone<<" "<<a[i].orderid1<<" " << a[i].orderid2<<" "<<a[i].car<<" "<<a[i].deliverytime<<endl;
	}
	fout.close();
	delete[]a;
	
}
void csearchname(string courierfile){//Удаление элементов
	ifstream fin;
	ofstream fout;	
	fin.open(courierfile);	
	int  i=0;
	int k=0;
	cout <<"Enter the name you want to find"<<endl;
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
	string name;
	cin >>name;//Считываем данные об удаляемом типе объектов
	for (i=0; i<k; i++){ 
		if (a[i].name== name){//Ищем соответствующее имя
			cout << a[i].idc<<" " <<a[i].name <<" " << a[i].phone <<" " << a[i].orderid1<<" " << a[i].orderid2 <<endl;
			tmp=1;		
		} 
	}
	if (tmp==-1){
		cout<<"There's no such name"<<endl;
	}	
	fout.close();
	delete[]a;
}

