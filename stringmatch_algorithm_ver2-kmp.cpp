//--by Ruijie Li 2020-12-10, strings-match algorithm practice demo.Allrights reserved.
//Version 2:a elementary KMP alrorithm of string-matching. O(m+n)
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int public_longest_prefix[30];
int KMP(char c1[], char c2[]) {
	//i,j is index of current char.
	int i = 0, j = 0;
	while (c1[i] != '\0' && c2[j] != '\0') {
		//if the current chars are equal,go forward.
		if (j == -1 || c1[i] == c2[j]) {
			i++;
			j++;
		}
		//else the pin to the target string back to the public longest prefix.
		//in other words,the target string moves right public_longest_prefix[j] steps.
		//this can simplify move times and improve its efficiency.
		//first you need to know what PMT is on behalf of,that's my public_longest_prefix.
		//see it:https://www.zhihu.com/question/21923021
		else {
			j = public_longest_prefix[j];
		}
	}
	if (c2[j] == '\0')
		return i - j;
	else
		return -1;
}
//the function of getting next[i]
int getNext(char c[],int next[]) {
	next[0] = -1;
	int i = 0, j = -1;
	while (c[i] != '\0') {
		if (j == -1 || c[i] == c[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
	return 0;
}
int main() {
	char c1[30], c2[30];
	scanf("%s", c1);
	scanf("%s", c2);
	getNext(c1, public_longest_prefix);
	cout << KMP(c1, c2) << endl;
	return 0;
}
