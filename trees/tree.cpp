#include <iostream>
using namespace std;


struct tree
{
	int info;
	tree* L, * R;
};


// tree creation
void ADDDDP(tree* p, int x)
{
	tree* q;
	if (x < p->info)
		if (p->L == 0)
		{
			q = new(tree);
			q->info = x;
			q->L = 0;
			q->R = 0;
			p->L = q;
		}
		else
			ADDDDP(p->L, x);
	else
		if (p->R == 0)
		{
			q = new(tree);
			q->info = x;
			q->L = 0;
			q->R = 0;
			p->R = q;
		}
		else
			ADDDDP(p->R, x);
}


// tree traversal
void P_traversal(tree* t)
{
	if (t != 0)
	{
		cout << t->info << '\t';
		P_traversal(t->L);
		P_traversal(t->R);
	}
}


// tree output
void Print_Tree(tree* p, int tab)
{
	if (p != 0)
	{
		if (p->R != 0)
			Print_Tree(p->R, tab + 1);

		for (int i = 0; i < tab; i++)
			cout << '\t';
		cout << p->info << endl;

		if (p->L != 0)
			Print_Tree(p->L, tab + 1);
	}
	else
		cout << endl;
}


void main()
{
	tree* t;
	int x; cin >> x;
	t = new(tree);
	t->info = x;
	t->L = 0;
	t->R = 0;
	cin >> x;

	while (x != 0)
	{
		ADDDDP(t, x);
		cin >> x;
	}


	Print_Tree(t, 0);


	system("pause");
}