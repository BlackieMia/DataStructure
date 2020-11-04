using namespace std;
#include <string>
#define MAXSIZE 100

//KMP算法---------------------------------------------
void GetNext(string s, int next[]) {
	int index=0, k=-1;
	next[0] = -1;
	while (index < s.length() - 1) {
		if (k == -1 || s[index] == s[k]) {
			index++;
			k++;
			next[index] = k;
		}
		else k = next[k];
	}
}

int KMPIndex(string s, string t) {
	int indexs = 0, indext = 0;
	int next[MAXSIZE];
	GetNext(t, next);
	while (indexs < s.length() || indext < t.length()) {
		if (indext == -1 || s[indexs] == t[indext]) {
			indexs++;
			indext++;
		}
		else indext = next[indext];
	}
	if (indext == t.length()) 
		return indext - t.length();
	else 
		return -1;
}


//改进后的KMP算法---------------------------------------------
void GetNextval(string s, int nextval[]) {
	int index = 0, k = -1;
	nextval[0] = -1;
	while (index < s.length() - 1) {
		if (k == -1 || s[index] == s[k]) {
			index++;
			k++;
			if (s[index] != s[k])
				nextval[index] = k;
			else
				nextval[index] = nextval[k];
		}
		else k = nextval[k];
	}
}

int KMPIndexPlus(string s, string t) {
	int indexs = 0, indext = 0;
	int nextval[MAXSIZE];
	GetNext(t, nextval);
	while (indexs < s.length() || indext < t.length()) {
		if (indext == -1 || s[indexs] == t[indext]) {
			indexs++;
			indext++;
		}
		else indext = nextval[indext];
	}
	if (indext == t.length())
		return indext - t.length();
	else
		return -1;
}