void addcourier(string courierfile)
{//Добавление курьеров
	ifstream fin;
	ofstream fout;
	fin.open(courierfile);
	int  i = 0;
	int k = 0;
	string s;
	cout << "Enter the courier you want to put('name /n phone /n idc /n car(0 or 1)')" << endl;
	while (!fin.eof()) {//Считаем количество строк в тексте=количество видов объектов
		getline(fin, s);
		k++;
	}
	k--;
	Courier* a = new Courier[k + 1];//Выделяем память на массив типа  struct(с запасом)
	//fin.seekg( 0 );//Не забываем вернуть курсор в начало
	fin.close();//Убираем за собой
	fin.open(courierfile);
	for (i = 0; i < k; i++) {
		fin >> a[i].idc;
		fin >> a[i].name;
		fin >> a[i].phone;
		fin >> a[i].orderid1;
		fin >> a[i].orderid2;
		fin >> a[i].car;
		fin >> a[i].deliverytime;
		//Считываем элементы из файла, заодно выводим на экран все текущие элементы
	}
	int j;
	string name;
	string phone;
	string idc;
	int car;
	cin >> name >> phone >> idc >> car;
	for (i = 0; i < k; i++) {
		if (a[i].idc == idc) {//Сравниваем параметры 
			cout << "courier with same id already exists. Try the other one" << endl;
			fin.close();
			exit(0);
		}
		if (a[i].name == name) {//Сравниваем параметры 
			cout << "courier with same name already exists. Try the other one" << endl;
			fin.close();
			exit(0);
		}
		if (a[i].phone == phone) {//Сравниваем параметры 
			cout << "courier with same phone already exists. Try the other one" << endl;
			fin.close();
			exit(0);
		}
	}
	fin.close();//Готовимся полностью очистить файл
	a[k].idc = idc;
	a[k].name = name;
	a[k].phone = phone;
	a[k].car = car;
	a[k].deliverytime = 30 - 20 * car; // время доставки для одного курьера, 10 мин. с машиной, 30 мин. без машины, так как car принимает значение 1, если есть машина, 0 - если нет
	a[k].orderid1 = "0";
	a[k].orderid2 = "0";
	fout.open(courierfile, ios::out);//Мы снова в файле, но он теперь пустой
	for (i = 0; i < k + 1; i++) {//Переписываем весь дополненный массив в документ
		fout << a[i].idc << " " << a[i].name << " " << a[i].phone << " " << a[i].orderid1 << " "a[i].orderid2 << " " << a[i].car << " " << a[i].deliverytime << endl;
	}
	fout.close();//Убираем за собой
	delete[] a;//Убираем за собойх2
}
