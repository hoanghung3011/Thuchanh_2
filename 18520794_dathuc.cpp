#include <iostream>
#include <string.h>
using namespace std;
typedef struct dathuc
{
	int hs;
	int sm;
}DT;
typedef struct node
{
	DT data;
	struct node *next;
};
typedef struct list
{
	node *head;
	node *tail;
};
void createlist(list &l)
{
	l.head = NULL;
	l.tail = NULL;
}
node* createnode(DT x)
{
	node *p;
	p = new node;
	if (p == NULL) exit(1);
	p->data = x;
	p->next = NULL;
	return p;
}
void addtail(list &l, node* p)
{
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = l.head;
	}
	else
	{
		p->next = l.head;
		l.head = p;

	}
}
void input(list &l)
{
	int hs, sm;
	DT bac;
	cout << "Nhap bac cua da thuc : " << endl;
	cin >> sm;
	for (int i = 0; i <= sm; i++)
	{
		cout << "Nhap he so cua x^ " << i << " = " << endl;
		cin >> hs;
		bac.hs = hs;
		bac.sm = i;
		node *p = createnode(bac);
		addtail(l, p);
	}
}
void output(list l)
{
	node* p;
	p = l.head;
	while (p != NULL && p!= l.tail)
	{	
		if (p->data.hs != 0) cout << p->data.hs << "x^" << p->data.sm ;
		p = p->next;
		if (p->data.sm == 0) cout << " + " << p->data.hs;
		if (p->data.hs)
		{
			if (p->data.hs > 0 && p->data.sm > 0 ) cout << " + ";
			if (p->data.hs > 0 && p->data.sm == 0) cout << " ";
		}
	}

}
void cong(list &l, list l1, list l2)
{
	node *p, *q;
	p = new node;
	q = new node;
	if (l1.head->data.hs > l2.head->data.sm)
	{
		l = l1;
		p = l2.head;
	}
	else
	{
		l = l2;
		p = l1.head;
	}
	q = l.head;
	while (q->data.sm > p->data.sm) q = q->next;
	while (q != NULL)
	{
		q->data.hs += p->data.hs;
		p = p->next;
		q = q->next;
	}

}
int main()
{
	list l, l1, l2;
	createlist(l);
	createlist(l1);
	createlist(l2);
	cout << "Nhap P(x) : " << endl;
	input(l1);
	cout << "Nhap Q(x) : " << endl;
	input(l2);
	cout << "P(x) = ";
	output(l1);
	cout << endl;
	cout << "Q(x) = ";
	output(l2);
	cout << endl;
	cong(l, l1, l2);
	cout << " Tong = " ;
	output(l);
	return 0;
}
