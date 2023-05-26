#include<iostream>
#include<string>
using namespace std;

struct node {
	int info;
	node* next;
};
typedef node* PTR;

PTR create_node(int x) {
	PTR p = new node;
	if (p == NULL) {
		cout << "\nKhong du vung nho de cap phat!";
		return NULL;
	}
	else {
		p->info = x;
		p->next = NULL;
		return p;
	}
}

void Themcuoi(PTR &first, PTR p) {
	if (first == NULL) {
		first = p;
	}
	else {
		for (PTR k = first; k != NULL; k = k->next) {
			if (k->next == NULL) {
				k->next = p;
				break;
			}
		}
	}
}

void NhapDL(PTR& first) {
	while (true) {
		int x;
		cout << "\nNhap gia tri phan tu can them: ";
		cin >> x;
		if (x < 0) {
			break;
		}
		PTR p = create_node(x);
		Themcuoi(first, p);
	}
}

void Xuat(PTR first) {
	for (PTR k = first; k != NULL; k = k->next) {
		cout << k->info << " ";
	}
}

void xoa(PTR& first, int x) {
	if (first == NULL) {
		cout << "\nDanh sach rong!";
	}
	else {
		PTR p = first, q = NULL;
		while( p != NULL){
			if (p->info == x) {
				if (q == NULL) {
					first = p->next;
				}
				else {
					q->next = p->next;
				}
				PTR temp = p;
				p = p->next;
				delete temp;
			}
			else {
				q = p;
				p = p->next;
			}
		}
	}
}


int main() {
	PTR first = NULL;
	NhapDL(first);
	cout << "\n\nDanh sach cac phan tu: ";
	Xuat(first);
	cout << endl;

	int x;
	cout << "\nNhap gia tri phan tu muon xoa: ";
	cin >> x;
	xoa(first, x);
	Xuat(first);
	cout << endl;

	system("pause");
	return 0;
}
