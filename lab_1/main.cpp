// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

/*
Author: Nikolaenko Konstantin
Group: 9305
IDE: Clion (JetBrains)
Task: E = A & B + C + D
*/

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

const int Nmax = 10; // Size of the universum
char U[Nmax + 1] = { "0123456789" }; // Universum

struct Set // Description of Set class
{
	char el;
	Set *next;

	Set(char e = 0, Set *n = nullptr);
};

Set::Set(char e, Set *n) {
	el = e;
	next = n;
}

void print_set(char arrA[], char arrB[], char arrC[], char arrD[])
{
	cout << endl << "A: ";
	for (int i = 0; (unsigned)i < strlen(arrA); ++i) cout << arrA[i] << " ";
	cout << endl << "B: ";
	for (int i = 0; (unsigned)i < strlen(arrB); ++i) cout << arrB[i] << " ";
	cout << endl << "C: ";
	for (int i = 0; (unsigned)i < strlen(arrC); ++i) cout << arrC[i] << " ";
	cout << endl << "D: ";
	for (int i = 0; (unsigned)i < strlen(arrD); ++i) cout << arrD[i] << " ";
	cout << endl << endl;
}

void arr_generate(char arr[], char c)
{
	int k{ 0 };

	for (int i = 0; i < Nmax; i++) {
		if (rand() % 2) {
			arr[k++] = i + '0';
		}
	}

	arr[k] = 0;
}

// The Array block //

int set_belongs(char A[], char elem, int A_size)
{
	for (int i = 0; i < A_size; i++) {
		if (elem == A[i]) return 1;
	}

	return 0;
}


void set_print(char A[])
{
	cout << endl << "The result for arrays:" << endl;
	for (int i = 0; (unsigned)i < strlen(A); ++i) {
		cout << A[i] << " ";
	}
}

// End of the array block

// The list block //

Set *array_to_list(char arr[])
{
	Set *hl = nullptr;

	if (arr[0] != '\0') {

		hl = new Set(arr[0]);
		Set *tmp = hl;

		for (int i = 1; (unsigned)i < strlen(arr); ++i, tmp = tmp->next) {
			tmp->next = new Set(arr[i]);
		}

	}

	return hl;
}

void print_list(Set *hl)
{
	cout << endl << "The result for lists:" << endl;

	for (Set *p = hl; p; p = p->next) {
		cout << p->el << " ";
	}

}

bool set_belongs_list(Set *arr, char elem)
{
	for (Set *p = arr; p; p = p->next) {
		if (elem == p->el) return true;
	}

	return false;
}

Set *find_list(Set *pA, Set *pB, Set *pC, Set *pD)
{
	Set *pR = nullptr;
	int cnt{ 0 };
	Set *tmp = pR;

	for (Set *p = pA; p; p = p->next) {
		for (Set *f = pB; f; f = f->next) {
			if ((p->el == f->el) && (cnt == 0)) {
				pR = new Set(p->el);
				tmp = pR;
				cnt++;
			}
			else if (p->el == f->el) {
				tmp->next = new Set(p->el);
				tmp = tmp->next;
			}
		}
	}

	for (Set *p = pC; p; p = p->next) {
		if (!set_belongs_list(pR, p->el)) {
			tmp->next = new Set(p->el);
			tmp = tmp->next;
		}
	}

	for (Set *p = pD; p; p = p->next) {
		if (!set_belongs_list(pR, p->el)) {
			tmp->next = new Set(p->el);
			tmp = tmp->next;
		}
	}

	return pR;
}

void free_list(Set *p)
{
	Set *cur = p->next;

	while (cur) {
		Set *tmp = cur;
		cur = cur->next;
		delete tmp;
	}

	delete p;
}

// End of the list block //

// Block for bits //

void set_to_bits(char arr[], bool barr[])
{
	for (int i = 0; i < 10; ++i) {
		barr[i] = false;
	}

	for (int i = 0;arr[i]; ++i) {
		barr[arr[i] - '0'] = 1;
	}
}

void print_bits_to_set(bool barr[])
{
	cout << endl << "The result for bit vectors: " << endl;
	for (int i = 0; i < 10; ++i) {
		if (barr[i]) cout << U[i] << " ";
	}
}

// End block of bits //

// Block for machine words //

long str_to_machine_word(char arr[])
{
	long res{ 0 };

	for (int i = 0; arr[i]; ++i) res |= (1 << (arr[i] - '0'));

	return res;
}

void print_res(long num)
{
	cout << endl << "The result for machine word is:" << endl;

	for (int i = 0; i < 10; ++i) if ((num >> i) & 1) cout << char(i + '0') << " ";

	cout << endl;
}

// End block of machine words //

int main()
{
	long mA, mB, mC, mD, mE;
	bool bA[10], bB[10], bC[10], bD[10], bE[11];

	// Generating the sets //

	srand(time(0));

	char A[11] = { 0 }; arr_generate(A, 'A'); 
	char B[11] = { 0 }; arr_generate(B, 'B'); 
	char C[11] = { 0 }; arr_generate(C, 'C'); 
	char D[11] = { 0 }; arr_generate(D, 'D');
	char E[11] = { 0 };

	int kod = 1;
	// End of the generating block //

	unsigned int begin_time;
	unsigned int end_time;

	while (kod)
	{
		cout << "0 - EXIT\n1 - Array\n2 - List\n3 - Bits\n4 - Mashin word" << endl;
		cout << "Input mode: ";
		cin >> kod;

		print_set(A, B, C, D);

		if (kod == 1)
		{
			// Array block //

			int t;

			begin_time = clock();

			for (int l = 0; l < 1000000; l++) {

				int tmp{ 0 };
				// E = E | A & B
				for (int i = 0; (unsigned)i < strlen(A); ++i) {
					for (int j = 0; (unsigned)j < strlen(B); ++j) {
						if (A[i] == B[j]) {
							E[tmp++] = A[i];
							break;
						}
					}
				}

				E[tmp] = '\0';

				int tmp1 = strlen(E);

				// E = E | C | D
				for (int i = 0; (unsigned)i < strlen(C); ++i)
					if (set_belongs(E, C[i], strlen(E)) == 0) E[tmp1++] = C[i];

				for (int i = 0; (unsigned)i < strlen(D); ++i)
					if (set_belongs(E, D[i], strlen(E)) == 0) E[tmp1++] = D[i];


				E[tmp1] = '\0';
				if(l < 999999) 
					for (int r = 0; r < strlen(E); r++) E[r] = '0';

				t = tmp;
			}

			end_time = clock();

			cout << endl << "Result time for arrays " << (end_time - begin_time) << " ticks";
			set_print(E);
			for (int i = 0; i < strlen(E); i++) E[i] = '0';
			cout << endl;
		}
		else if (kod == 2)
		{
			// List block //

			Set *pA = array_to_list(A);
			Set *pB = array_to_list(B);
			Set *pC = array_to_list(C);
			Set *pD = array_to_list(D);
			Set *pE;

			begin_time = clock();
			for (int l = 0; l < 1000000; l++) {
				pE = find_list(pA, pB, pC, pD);
			}

			end_time = clock();

			cout << endl << "Result time for lists " << end_time - begin_time << " ticks";

			print_list(pE);
			cout << endl;

			free_list(pA); free_list(pB); free_list(pC); free_list(pD); free_list(pE);
		}
		else if (kod == 3)
		{
			// Block for bits //

			set_to_bits(A, bA); set_to_bits(B, bB); set_to_bits(C, bC); set_to_bits(D, bD);

			for (int i = 0; i < 10; ++i) {
				bE[i] = 0;
			}

			begin_time = clock();

			for (int l = 0; l < 1000000; l++) {
				for (int i = 0; i < 10; ++i) {
					bE[i] = ((bA[i] && bB[i]) || bC[i] || bD[i]);
				}
			}

			end_time = clock();

			cout << endl << "Result time for bits " << end_time - begin_time << " ticks";

			print_bits_to_set(bE);
			cout << endl;
		}
		else if (kod == 4)
		{
			// Block for machine words //

			mA = str_to_machine_word(A);
			mB = str_to_machine_word(B);
			mC = str_to_machine_word(C);
			mD = str_to_machine_word(D);

			begin_time = clock();

			for(int l = 0; l < 1000000; l++)
				mE = (mA & mB) | mC | mD;

			end_time = clock();

			cout << endl << "Result time for words " << end_time - begin_time << " ticks";

			print_res(mE);
			cout << endl;
		}

		char c;
		cout << endl << "To continue, enter any char" << endl;
		cin >> c;
		
		system("cls");
	}
	
	cout << "EXIT" << endl;
	cin.get();
	return 0;
}

