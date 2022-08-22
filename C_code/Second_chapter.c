// Data types, operations and expressions

#include <limits.h>
#include <float.h>
#include "stdio.h"
#include "./First_chapter.c"


inline int htoi(char s[]);
void squeeze(char s1[], char s2[]);
int any(char s1[], char s2[]);

int htoi(char s[]) {
	int i, n;
	n = 0;
	int j = 0;

	for (i = 2; ((s[i] >= '0') && (s[i] <= 'F')) || ((s[i] >= 'a') && (s[i] <= 'f')); i++) {
		j = s[i] - '0';
		if ((s[i] >= 'A') && (s[i] <= 'F')) {
			j -= 7;
		}
		else if (s[i] >= 'a') {
			j -= 39;
		}
		n = 16 * n + j;
	}
	return n;
}

void squeeze(char s1[], char s2[]) {
	int i, j, k;
	for (i = 0; s2[i] != '\0'; i++) {
		k = 0;
		for (j = 0; s1[j] != '\0'; j++) {
			if (s1[j] != s2[i]) {
				s1[k++] = s1[j];
			}
			
		}
		s1[j] = '\0';
	}
}

int any(char s1[], char s2[]) {
	int i, j, k, ans = 1000;
	char let;
	for (i = 0; s2[i] != '\0'; i++) {
		k = 0;
		for (j = 0; s1[j] != '\0'; j++) {
			if (s1[j] != s2[i]) {
				k++;
			}
			else if ((ans > k) && (s1[j] == s2[i])) {
				ans = k;
			}
		}		
	}
	return ans > 0 ? ans : -1;
}

/* Напишите программу для определения диапозонов переменных типов char, short, int и long(как signed, так и unsigned) 
путем вывода соответствующих значений из заголовочных файлов, а также с помощью непосредственного вычисления.
Для второго способа усложним задачу: определите еще и диапозоны вещественных типов */

//int main() {
//	printf("Type\t\t\t\t Min\t\t\t\t Max");
//	printf("\nInt\t\t        %16d\t        %16d", INT_MIN, INT_MAX);
//	printf("\nLong\t\t        %16ld\t        %16ld", LONG_MIN, LONG_MAX);
//	printf("\nSChar\t\t        %16d\t          %14d", SCHAR_MIN, SCHAR_MAX);
//	printf("\nUChar\t\t        %16d\t          %14d", 0, UCHAR_MAX);
//	printf("\nShort\t\t        %16d\t          %14d", SHRT_MIN, SHRT_MAX);
//	printf("\nULong\t\t        %16d\t          %14u", 0, ULONG_MAX);
//	printf("\nUShort\t\t        %16d\t          %14u\n\n", 0, USHRT_MAX);
//	printf("Float numbers:\n");
//	printf("Type\t\t Accuracy\t\t Min\t\t\t Max");
//	printf("\nFloat\t     %12d         %11.3f        %12.3f", FLT_DIG, FLT_TRUE_MIN, FLT_MAX);
//	printf("\nDouble\t     %12d         %11.3f        \n\nMAX: %9.3f", DBL_DIG, DBL_MIN, DBL_MAX);
//	return 0;
//}

/*Напишите функцию htoi(s), которая преобразует строку 
шестнадцетиричных цифр (учитывая необязательные элементы 0х или 0Х) в ее целочисленный эквивалент
В число допустимых цифр входят десятичные цифры от 0 до 9, а также буквы a-f и A-F*/

//int main(void) {
//	char hex[MAXLINE];
//	int len;
//	while ((len = getline(hex, MAXLINE)) > 1) {
//		printf("%d\n", htoi(hex));
//	}
//  return 0;
//}


/* Напишите альтернативную версию функций squeeze(s1, s2), которая бы удаляла из строки s1 
все символы, встречающиеся в s2*/

//int main(void) {
//	char line1[MAXLINE]; // s1
//	char line2[MAXLINE]; // s2
//	getline(line1, MAXLINE);
//	getline(line2, MAXLINE);
//	squeeze(line1, line2);
//	printf("%s", line1);
//	return 0;
//}

/* Напишите функцию any(s1, s2), возвращающую номер первой позиции в строке s1, 
в которой находится какой-либо из символов строки s2, 
либо -1, если строка s1 не содержит ни одного символа из s2*/


//int main(void) {
//	char line1[MAXLINE]; // s1
//	char line2[MAXLINE]; // s2
//	getline(line1, MAXLINE);
//	getline(line2, MAXLINE);
//	printf("%d", any(line1, line2));
//	return 0;
//}