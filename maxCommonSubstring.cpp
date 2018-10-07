#include <iostream>

using namespace std;

const int MAXLINE = 100;


// Max Common Substring
// String and length
// maxLen init 0




int mcs(string s1, int l1, string s2, int l2, int maxLen){
	if(l1 < 1 || l2 < 1) return maxLen;
	
	if(s1[l1 - 1] == s2[l2 - 1]){
		maxLen++;
		//cout << s1[l1 - 1];
		maxLen = mcs(s1, l1 - 1, s2, l2 -1, maxLen);
	}if(s1[l1 - 1] != s2[l2 - 1] ){	
		int	m1 = mcs(s1, l1 - 1, s2, l2, maxLen);
		int	m2 = mcs(s1, l1, s2, l2 - 1, maxLen);
		maxLen = (m1 >= m2 ? m1: m2);
	}
	
	return maxLen;
}


int main(){
	string s1 = "987w654u321j";
	string s2 = "wuj";
	
	for(int i = 0; i < 100; ++i)
		for(int j = 0; j < 100; ++j)
			record[i][j] = -1;
	
	cout << mcs(s1, 12, s2, 3, 0);
	return 0;
}