#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;
bool End_Range(FILE* f)
{
	int tmp;
	tmp = fgetc(f);
	tmp = fgetc(f);
	if (tmp != '\'') fseek(f, -2, 1);
	else fseek(f, 1, 1);
	return tmp == '\'' ? true : false;
}
void Natural_Merging_Sort(char* name) {
	int s1, s2, mark;
	char autor[20], autor_[20], naz[100], number[100], izd[100], page[100], cost[100];
	char  naz_[100], number_[100], izd_[100], page_[100], cost_[100];
	FILE* A, * B, * C;
	s1 = s2 = 1;
	while (s1 > 0 && s2 > 0) {
		mark = 1;
		s1 = 0;
		s2 = 0;
		A = fopen(name, "r");
		B = fopen("B.txt", "w");
		C = fopen("C.txt", "w");
		fscanf(A, "%s", &autor);
		fscanf(A, "%s", &naz);
		fscanf(A, "%s", &number);
		fscanf(A, "%s", &izd);
		fscanf(A, "%s", &page);
		fscanf(A, "%s", &cost);
		if (!feof(A)) {
			fprintf(B, "%s", autor);
			fprintf(B, " ");
			fprintf(B, "%s", naz);
			fprintf(B, " ");
			fprintf(B, "%s", number);
			fprintf(B, " ");
			fprintf(B, "%s", izd);
			fprintf(B, " ");
			fprintf(B, "%s", page);
			fprintf(B, " ");
			fprintf(B, "%s", cost);
		}
		if (!feof(A)) { 
			fscanf(A, "%s", &autor_);
			fscanf(A, "%s", &naz_);
			fscanf(A, "%s", &number_);
			fscanf(A, "%s", &izd_);
			fscanf(A, "%s", &page_);
			fscanf(A, "%s", &cost_);
		}
		while (!feof(A)) {
			if (izd_[0] < izd[0]) {
				switch (mark) {
				case 1: {fprintf(B, "' "); mark = 2; s1++; break; }
				case 2: {fprintf(C, "' "); mark = 1; s2++; break; }
				}
			}
			if (mark == 1) { 
				fprintf(B, "%s", autor_);
				fprintf(B, " ");
				fprintf(B, "%s", naz_);
				fprintf(B, " ");
				fprintf(B, "%s", number_);
				fprintf(B, " ");
				fprintf(B, "%s", izd_);
				fprintf(B, " ");
				fprintf(B, "%s", page_);
				fprintf(B, " ");
				fprintf(B, "%s", cost_);
				s1++; 
			}
			else { 
				fprintf(C, "%s", autor_);
				fprintf(C, " ");
				fprintf(C, "%s", naz_);
				fprintf(C, " ");
				fprintf(C, "%s", number_);
				fprintf(C, " ");
				fprintf(C, "%s", izd_);
				fprintf(C, " ");
				fprintf(C, "%s", page_);
				fprintf(C, " ");
				fprintf(C, "%s", cost_);
				s2++; 
			}
			izd[0] = izd_[0];
			fscanf(A, "%s", &autor_);
			fscanf(A, "%s", &naz_);
			fscanf(A, "%s", &number_);
			fscanf(A, "%s", &izd_);
			fscanf(A, "%s", &page_);
			fscanf(A, "%s", &cost_);
		}
		if (s2 > 0 && mark == 2) { fprintf(C, "'"); }
		if (s1 > 0 && mark == 1) { fprintf(B, "'"); }
		fclose(C);
		fclose(B);
		fclose(A);
		A = fopen(name, "w");
		B = fopen("B.txt", "r");
		C = fopen("C.txt", "r");
		if (!feof(B)) { 
			fscanf(B, "%s", &autor);
			fscanf(B, "%s", &naz);
			fscanf(B, "%s", &number);
			fscanf(B, "%s", &izd);
			fscanf(B, "%s", &page);
			fscanf(B, "%s", &cost);
		}
		if (!feof(C)) { 
			fscanf(C, "%s", &autor_);
			fscanf(C, "%s", &naz_);
			fscanf(C, "%s", &number_);
			fscanf(C, "%s", &izd_);
			fscanf(C, "%s", &page_);
			fscanf(C, "%s", &cost_);
		}
		bool file1, file2;
		while (!feof(B) && !feof(C)) {
			file1 = file2 = false;
			while (!file1 && !file2) {
				if (autor <= autor_) {
					fprintf(A, "%s", autor);
					fprintf(A, " ");
					fprintf(A, "%s", naz);
					fprintf(A, " ");
					fprintf(A, "%s", number);
					fprintf(A, " ");
					fprintf(A, "%s", izd);
					fprintf(A, " ");
					fprintf(A, "%s", page);
					fprintf(A, " ");
					fprintf(A, "%s", cost);
					file1 = End_Range(B);
					fscanf(B, "%s", &autor);
					fscanf(B, "%s", &naz);
					fscanf(B, "%s", &number);
					fscanf(B, "%s", &izd);
					fscanf(B, "%s", &page);
					fscanf(B, "%s", &cost);
				}
				else {
					fprintf(A, "%s", autor_);
					fprintf(A, " ");
					fprintf(A, "%s", naz_);
					fprintf(A, " ");
					fprintf(A, "%s", number_);
					fprintf(A, " ");
					fprintf(A, "%s", izd_);
					fprintf(A, " ");
					fprintf(A, "%s", page_);
					fprintf(A, " ");
					fprintf(A, "%s", cost_);
					file2 = End_Range(C);
					fscanf(C, "%s", &autor_);
					fscanf(C, "%s", &naz_);
					fscanf(C, "%s", &number_);
					fscanf(C, "%s", &izd_);
					fscanf(C, "%s", &page_);
					fscanf(C, "%s", &cost_);
				}
			}
			while (!file1) {
				fprintf(A, "%s", autor);
				fprintf(A, " ");
				fprintf(A, "%s", naz);
				fprintf(A, " ");
				fprintf(A, "%s", number);
				fprintf(A, " ");
				fprintf(A, "%s", izd);
				fprintf(A, " ");
				fprintf(A, "%s", page);
				fprintf(A, " ");
				fprintf(A, "%s", cost);
				file1 = End_Range(B);
				fscanf(B, "%s", &autor);
				fscanf(B, "%s", &naz);
				fscanf(B, "%s", &number);
				fscanf(B, "%s", &izd);
				fscanf(B, "%s", &page);
				fscanf(B, "%s", &cost);
			}
			while (!file2) {
				fprintf(A, "%s", autor_);
				fprintf(A, " ");
				fprintf(A, "%s", naz_);
				fprintf(A, " ");
				fprintf(A, "%s", number_);
				fprintf(A, " ");
				fprintf(A, "%s", izd_);
				fprintf(A, " ");
				fprintf(A, "%s", page_);
				fprintf(A, " ");
				fprintf(A, "%s", cost_);
				file2 = End_Range(C);
				fscanf(C, "%s", &autor_);
				fscanf(C, "%s", &naz_);
				fscanf(C, "%s", &number_);
				fscanf(C, "%s", &izd_);
				fscanf(C, "%s", &page_);
				fscanf(C, "%s", &cost_);
			}
		}
		file1 = file2 = false;
		while (!file1 && !feof(B)) {
			fprintf(A, "%s", autor);
			fprintf(A, " ");
			fprintf(A, "%s", naz);
			fprintf(A, " ");
			fprintf(A, "%s", number);
			fprintf(A, " ");
			fprintf(A, "%s", izd);
			fprintf(A, " ");
			fprintf(A, "%s", page);
			fprintf(A, " ");
			fprintf(A, "%s", cost);
			file1 = End_Range(B);
			fscanf(B, "%s", &autor);
			fscanf(B, "%s", &naz);
			fscanf(B, "%s", &number);
			fscanf(B, "%s", &izd);
			fscanf(B, "%s", &page);
			fscanf(B, "%s", &cost);
		}
		while (!file2 && !feof(C)) {
			fprintf(A, "%s", autor_);
			fprintf(A, " ");
			fprintf(A, "%s", naz_);
			fprintf(A, " ");
			fprintf(A, "%s", number_);
			fprintf(A, " ");
			fprintf(A, "%s", izd_);
			fprintf(A, " ");
			fprintf(A, "%s", page_);
			fprintf(A, " ");
			fprintf(A, "%s", cost_);
			file2 = End_Range(C);
			fscanf(C, "%s", &autor_);
			fscanf(C, "%s", &naz_);
			fscanf(C, "%s", &number_);
			fscanf(C, "%s", &izd_);
			fscanf(C, "%s", &page_);
			fscanf(C, "%s", &cost_);
		}
		fclose(C);
		fclose(B);
		fclose(A);
	}
	remove("B.txt");
	remove("C.txt");
}
int main()
{
	setlocale(LC_ALL, "rus");
	char c[256] = "A.txt";
	Natural_Merging_Sort(c);
	return 0;
}

