#include <bits/stdc++.h>
using namespace std;
void nhap(int* A, int N) {
	for(int i=0; i<N; i++) {
		*(A+i) = rand() %100;
	}
}

void xuat(int* A, int N) {
	for(int i=0; i<N; i++) {
		cout << *(A+i) << " ";
	}
}

int main() {
	int N = rand() %100;

	int* A = new int[N];
	nhap(A, N);
	cout << endl;
	xuat(A, N);
}
