/*
Author : mohamed eprahim mohamed

Section : 14

ID : 20221117

TA : Belal

Date : 28 Oct 2023

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<string> split(string s, char t)
{
	vector<string>v1;
	string str = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == t)
		{
			v1.push_back(str);
			str = "";
		}
		else {
			str += s[i];
		}
	}

	v1.push_back(str);
	return v1;
}


int main()
{
	cout << "Enter string : ";
	string s;
	cin >> s;
	char t;
	cout << "Enter delimiter : ";
	cin >> t;
	vector<string>v;

	v = split(s, t);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}