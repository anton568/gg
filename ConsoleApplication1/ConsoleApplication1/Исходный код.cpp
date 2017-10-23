
#include <iostream>
using namespace std;
struct chel  //структура одного элемента группы -человека
{
	int numb;//номер человека
	chel *next;//указател на след человека
};
class Krug
{
private:
	chel *nach, *res;

public:
	Krug(){
		nach = new(chel); res = NULL;
	};
	~Krug(){
		delete nach;
	};
	void POSTROENIE(int);
	void VYVOD();
	chel *POISK(int, int, int, int, int);
	void Delete();
	void OCHISTKA();


};

int main()
{
	Krug A;
	int el, n, m, k, d, l, h;
	//chel *Res_Zn;//
	cout << "Vvedi kolichestvo chelovek" << endl;
	cin >> n;
	k = n;
	d = 1;
	l = 0;
	h = 0;
	cout << "Vvedi nomer udalaemogo cheloveka" << endl;
	cin >> m;
	el = m;
	A.POSTROENIE(n);


	//A.VYVOD();

	//cout << "\nВведите элемент удаляемого звена: ";
	//cin >> el;
	//A.POISK(el, m, d, h, k);
	while (k != 1)
	{
		if (A.POISK(el, m, d, h, k) != NULL)
		{
			A.Delete(); //A.VYVOD();
		}
		else  cout << "Zvena s el v kolce net!";
		k--;
		d++;
	}
	//A.OCHISTKA();
	return 0;
}

/*void Krug::POSTROENIE()
//Построение кольцевого списка с удаленным заглавным звеном.
//phead - указатель на заглавное звено.
{
chel *t;
int  el;

t = nach; (*t).next = NULL;
cout << "Вводите элементы кольца: ";
cin >> el;
while (el != 0)
{
(*t).next = new (chel);
t = (*t).next; (*t).numb = el;
cin >> el;
}
(*t).next = (*nach).next;
}*/
void Krug::POSTROENIE(int n)
//Построение кольцевого списка с удаленным заглавным звеном.
//phead - указатель на заглавное звено.
{

	int el;//колличество, номер удалемого
	chel *t;
	nach = new (chel);//выделяем  память для обьекта
	t = nach;
	for (int i = 0; i < n; i++)//записываем людей в список
	{
		if (i != n - 1)		{
			(*t).numb = i + 1; //номер человека
			(*t).next = new (chel); //выделяем память для адреса след обьекта
			t = (*t).next;
		}
		else	{               //последний человек
			(*t).numb = i + 1;
			//(*t).next = new (chel);
			//t = nach;
			//(*t).next = (*nach).next;
			(*t).next = nach;


		}
	}
	int i;                                            //
	i = 0;                                            //
	for (t = nach; i < n; t = (*t).next)              //вывод
	{                                                 //
		//
		//(*t).next2 = (*t).next;                     //
		cout << (*t).numb << " ";				      //
		cout << (*t).next << " ";
		i++;                                          //
	}
}


/*void Krug::VYVOD()
//Вывод содержимого кольцевого списка с удаленным заглавным звеном.
//phead - указатель на заглавное звено.
{
chel *t;
/*t = (*nach).next;
cout << "Kolco: ";
if (t != NULL)
{
cout << (*t).numb << " ";
t = (*t).next;
while (t != (*nach).next)
{
cout << (*t).numb << " ";
t = (*t).next;
}
}
else  cout << "пусто!\n";

}*/

chel *Krug::POISK(int el, int m, int d, int h, int k)
//Поиск элемента el в кольцевом списке phead.
//Если элемент найден, то Res содержит указатель на звено,
//содержащее элемент el. В противном случае - NULL.
{
	//int el;
	chel *t;
	int e, a, j;
	a = 0;
	if (h = 0)
	{
		(*t).next = (*nach).next;
		h++;
	}
	res = NULL;
	e = 1;
	//t =(*nach).next;
	cout << (*nach).numb << " ";
	for (e = 1; e < m; e++)
	{
		t = (*t).next;

	}
	if (e == m)
	{
		res = t;
		t = (*t).next;

	}
	cout << res << " ";
	//if ((*t).numb == el) res = t;
	//else  t = (*t).next;
	//if (res == NULL && (*t).numb == el)
	//res = t;


	return res;
}


void Krug::Delete()
//Удаление звена, на которое указывает ссылка Res,
//из кольцевого списка с удаленным заглавным звеном,
//заданного указателем phead.
{
	chel *z, *q;
	if ((*res).next != nach)
	{
		q = (*res).next;
		(*res).numb = (*((*res).next)).numb;
		(*res).next = (*((*res).next)).next;
		delete q;
	}
	else  if ((*res).next == res)
	{
		//В кольце единственное звено.
		q = (*nach).next; (*nach).next = NULL;
		delete q;
		cout << "kolco pusto!";
	}
	else
	{
		//Удаляется "последнее" звено кольца.
		z = nach; q = (*nach).next;
		while (q != res)
		{
			z = q; q = (*q).next;
		}
		(*z).next = (*((*z).next)).next;
		delete q;
	}

}


void Krug::OCHISTKA()
{
	chel *q, *q1;// Рабочие указатели.
	q = nach;
	q1 = (*q).next; // Указатель q1 "опережает" указатель q.
	do {
		q = q1;
		q1 = (*q1).next;
		delete q;
	} while (q1 != (*nach).next);
}