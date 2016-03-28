#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
class matching
{
  public:
  fstream f1,f2;
  string l1[100];
  string l2[100];
  int c1,c2;
  string buf;
  void load();
  void sort();
  void match();
};

void matching::load(){
		c1=0,c2=0;			
		f1.open("d1.txt",ios::in);
		while(!f1.eof())
		{
			getline(f1,buf);
			l1[c1++]=buf;
		}
		f2.open("d2.txt",ios::in);
		while(!f2.eof())
		{
			getline(f2,buf);
			l2[c2++]=buf;
		}
      }


void matching::sort(){
			string temp;
			for(int i=0;i<c1;i++)
			{
				for(int j=i+1;j<c1;j++)
				{
					if(l1[i]>l1[j])
					{
						temp=l1[i];
						l1[i]=l1[j];
						l1[j]=temp;
					}
				}
			}
			for(int i=0;i<c2;i++)
			{
				for(int j=i+1;j<c2;j++)
				{
					if(l2[i]>l2[j])
					{
						temp=l2[i];
						l2[i]=l2[j];
						l2[j]=temp;
					}
				}
			}
     }

void matching::match(){
		int count=0;
		for(int i=0;i<c1;i++)
		{
			for(int j=0;j<c2;j++)
			{
				if(l1[i]==l2[j])
				{
					cout<<l1[i]<<endl;
					count++;
				}
			}
		}
		cout<<"the total number of strings matched are:"<<count<<endl;
	}

int main()
{
 matching m;
 m.load();
 m.sort();
 m.match();
 return 0;
}


	
	
						
