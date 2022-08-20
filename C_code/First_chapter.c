#include "stdio.h"

//int main(void) {
//	printf("Hello world!");
//	getch();
//	return 0;
//}

//int main() {
//	int c;
//	//while (c = (getchar() != EOF)) {
//	//	putchar(c);
//	//}
//	c = EOF;
//	putchar(c);
//}


// ������ ��������
#define MAXLINE 100

int getline(char line[], int maxline);
void copy(char to[], char from[]);
int getstr(char line[], int maxline);
int len(char s[]);
void reverse(char s[], char f[]);
void delete_space(char s[]);


int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

int getstr(char s[], int lim)
{
	int c = 0, i, k;
	for (i = 0, k = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 1) {
			s[k] = c;
			k++;
		}
	}
	if (c == '\n') {
		s[k] = c;
		++k;
	}
	s[k] = '\0';
	return k;
}


void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}

int len(char s[]) {
	int i = 0;
	while ((s[i] != '\0') && (s[i] != '\n')) {
		i++;
	}
	return i;
}

void reverse(char s[], char f[]) {
	int length = len(s) - 1;
	int j = 0, i = length;
	for (i, j; i >= 0; i--, j++) {
		f[j] = s[i];
	}
	f[j] = '\0';
}

void delete_space(char s[]) {
	int length = len(s);
	int i = length - 1;
	char flag = 0;
	int j = length - 1;
	for (i; i >= 0; i--) {
		if (((s[i] == ' ') || (s[i] == '\t')) && (!flag)) {
			j = i;
		}
		else {
			flag = 1;
		}
	}
	s[j] = '\0';
}


//int main() {
//	int space = 0, tab = 0, eol = 0, c;
//	while ((c = getchar()) != '0') {
//		switch (c){
//		case ' ': space++; break;
//		case '\t': tab++; break;
//		case '\n': eol++; break;
//		} 
//	}
//	printf("%d %d %d", space, tab, eol);
//}


//int main() {
//	int space = 0, tab = 0, eol = 0, c;
//	while ((c = getchar()) != '0') {
//		switch (c) {
//		case '\t':
//		case '\b': c = "\\"; break;
//		}
//		putchar(c);
//	}
//}


/*�������� ���������, ���������� �����������
������ ������������� �������� ��������*/

//int main() {
//	int ndigit[10];
//	int c, nwhite = 0, nother = 0;
//	for (int i = 0; i < 10; i++) {
//		ndigit[i] = 0;
//	}
//
//	while ((c = getchar()) != '/') {
//		if (c >= '0' && c <= '9') {
//			ndigit[c - '0']++;
//		}
//		else if (c == ' ' || c == '\n') {
//			nwhite++;
//		}
//		else {
//			nother++;
//		}
//	}
//	for (int i = 0; i < 10; i++) {
//		printf("\n%d", i);
//		for (int j = 0; j < ndigit[i]; j++) {
//			printf("-");
//		}
//	}
//	printf("\nWhite: ");
//	for (int i = 0; i < nwhite; i++) {
//		printf("-");
//	}
//	printf("\nOther: ");
//	for (int i = 0; i < nother; i++) {
//		printf("-");
//	}
//	
//}


//Revise the main routine of the longest - 
//line program so it will correctly print the length of arbitrary 
//long input lines, and as much as possible of the text.
// ����� � https://newbie-clang.blogspot.com/2014/01/116.html*/ 


//
//int main(void) {
//    int len;    /* ����� ������� ������ */
//    int max;    /* ����� ������������ �� ������������� ����� */
//    char line[MAXLINE]; /* ������� ������ */
//    char longest[MAXLINE];      /* ����� ������� ������ */
//    char temp[MAXLINE]; /* ��� ���������� �������� ��������� ������ */
//
//    /* ��������������� � ���, ��� ��������� ����� ����� �����
//     * �����, ��� ��������� � MAXLINE
//     * wait = 1 - ���������� �������� ������ ������ MAXLINE
//     * wait = 0 - ���������� �������� ������ ������ ��� ����� MAXLINE*/
//    int wait = 0;
//
//    int iNt = 0; /* ������������� ����� ���������� ������ */
//
//    int i; /* ��� for-����� */
//    for (i = 0; i < MAXLINE; ++i)
//        line[i] = longest[i] = temp[i] = 0;
//
//    max = 0;
//    /* ���� �� ��� ������ */
//    while ((len = getstr(line, MAXLINE)) > 1) {
//        if (line[len - 1] != '\n') {
//            if (wait == 0)
//                copy(temp, line);
//            iNt = iNt + len;
//            if (max < iNt)
//                max = iNt;
//            wait = 1;
//        }
//
//        else {
//            if (wait == 1) {
//                if (max < (iNt + len)) {
//                    max = iNt + len;
//                    copy(longest, temp);
//                }
//                wait = 0;
//            }
//            else if (len > max) {
//                max = len;
//                copy(longest, line);
//            }
//            iNt = 0;
//        }
//    }
//    if (max > 0)        /* ���� �� ���� ���� ������? */
//    {
//        printf("%s\n", longest);
//        printf("Len: %d\n", max);
//    }
//
//    return 0;
//}
//

//�������� ��������� ������ ���� �������� �����,
//���������� ����� 80 ��������.

//int main() {
//	int len;
//	char line[MAXLINE];
//	while ((len = getline(line, MAXLINE)) > 0) {
//		if (len > 80) {
//			printf("String is longer than 80 chars: %s", line);
//		}
//	}
//}

/*�������� ������� reverse(s), ������� ������������ ���� ��������� �������� s � �������� �������.
�������������� �� ��� ��������� ��������� ������� �� ��������� ����� ��������� ��� ������ ������� �������� ������ �� �������*/


//int main() {
//	char line[MAXLINE];
//	char rev[MAXLINE];
//	int len = 0;
//	while ((len = getline(line, MAXLINE)) > 0) {
//		reverse(line, rev);
//		printf("Reversed string: %s\n", rev);
//	}
//	return 0;
//}

/*�������� ��������� ��� �������� ������ �������� � ��������� � ������ 
������ ����������� ������ �������� ������,
������� �� ����� ������� ��������� ������ ������*/

//int main() {
//	char line[MAXLINE];
//	char rev[MAXLINE];
//	int len = 0;
//	while ((len = getline(line, MAXLINE)) > 0) {
//		delete_space(line);
//		printf("Modified string: %s ", line);
//	}
//	return 0;
//}