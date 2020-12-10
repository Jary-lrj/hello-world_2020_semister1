//--by Ruijie Li 2020-12-10, strings-match algorithm practice demo.Allrights reserved.
//Version 1:a low-efficiency string-match algorithm.Time complexibility:O(mn)
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int StringMatch(char c1[],char c2[]) {
	//i,j is index of two strings,c1 is the main string while c2 is the matching string.
	int i = 0, j = 0;
	while (c1[i] != '\0' && c2[j] != '\0') {
		if (c1[i] == c2[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (c2[j] == '\0')
		return i - j;
	else
		return -1;
}
int main() {
	char string_1[30], string_2[30];
	scanf("%s", string_1);
	scanf("%s", string_2);
	cout << StringMatch(string_1, string_2) << endl;
	return 0;
}
