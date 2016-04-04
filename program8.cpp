#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;
string merge(vector<string> fn, int left, int right)
	{
		
     
		if(left==right)
		{
			cout<<fn[left];
			return fn[left];
		}
		if((right-left)==1)
		{
			string s1,s2;
			string s3=fn[left]+"a";
    ifstream if1(fn[0].c_str());
		ifstream if2(fn[1].c_str());
		ofstream  of(s3.c_str());
			//if1.open();
			//if2.open(fn[1].c_str());
			getline(if1,s1);
			getline(if2,s2);
			while(!if1.eof() && !if2.eof())
			{
				if(s1<s2)
				{
					of<<s1;
					getline(if1,s1);
				}
				else if(s1>s2)
				{
					of<<s2;
					getline(if2,s2);
				}
				else
				{
					of<<s1;
					getline(if1,s1);
					getline(if2,s2);
				}
			}
			return of;
		}
		else
		{
      string f1,f2;
      vector <string> temp;
			mid=(left+right)/2;
			f1=merge(fn,left,mid);
			f2=merge(fn,mid+1,right);
			temp.push_back(f1);
				temp.push_back(f2);
			return (temp,0,1);

		}
	}
	int main()
	{
	int left=0,right=7;
	vector <string> fn1;
	
	fn1.push_back("a1.txt");
	fn1.push_back("a2.txt");
	fn1.push_back("a3.txt");
	fn1.push_back("a4.txt");
	fn1.push_back("a5.txt");
	fn1.push_back("a6.txt");
	fn1.push_back("a7.txt");
	fn1.push_back("a8.txt");
  merge(fn1,0,7);
	}


