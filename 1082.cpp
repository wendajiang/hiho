
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
 
int main(){
	char str[200];
	char lower_str[200];
	string s1="marshtomp";
	string s2="fjxmlhx";
	while(cin.getline(str,200)){
		string tmp(str);   //原始字符串 
		//char *s0=strlwr(str);   //将大写字符串转化为小写 
		
		string s=tmp;  //都为小写的原始字符串
		for(int i=0; i<s.size(); i++){
			s[i] = tolower(s[i]);
		}//for
		
		int len=s.length();  //len存储要求的字符串长度
		int position=s.find(s1);
 
		while(position !=-1){  //说明字符串中有要替换的 
			tmp = tmp.replace(position, 9, s2);
			s = s.replace(position, 9, s2);
			position=s.find(s1);
		}
		cout<<tmp<<endl; 
	}//while
	return 0;
}
