#include<iostream>
#include<cmath>

using namespace std;

const int MAXLIST = 10000;
struct list
{
	int n;	
	int nodes[MAXLIST];
};
list ds;

void Nhap(list& ds)
{
	cout << "Nhap vao so luong phan tu: ";
	cin >> ds.n;
	for (int i = 0; i < ds.n; i++)
	{
		cout << "Nhap vao phan tu thu " << i + 1 << " :";
		cin >> ds.nodes[i];
	}
}

void Xuat(list ds)
{
	cout << "Danh sach: ";
	for (int i = 0; i < ds.n; i++)
	{
		cout << ds.nodes[i] << " ";
	}
}

int Check_snt(int x)
{
	if (x < 2)
	{
		return 0;
	}
	else
	{
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

int Xep_snt(list &ds)
{
	int last_index = ds.n-1;
	int first_index = 0;
	while(first_index < last_index)
	{
		if (Check_snt(ds.nodes[first_index]) == 1)
		{
			first_index ++;
		}
		else
		{
			swap(ds.nodes[first_index], ds.nodes[last_index]);
			last_index --;
		}
	}
	return first_index;
}
void BubbleSort(list &ds)
{
	for (int i = Xep_snt(ds); i <= ds.n - 1; i++)
	{
		for (int j = i; j <= ds.n - 1; j++)
		{
				if (ds.nodes[i] > ds.nodes[j])
				{
					swap(ds.nodes[i], ds.nodes[j]);
				}
		}
	}
}
int main()
{
	list ds;
	Nhap(ds);
	Xuat(ds);
	Xep_snt(ds);
	Xuat(ds);
	BubbleSort(ds);
	Xuat(ds);
	system("pause");
	return 0;
}