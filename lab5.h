#include<iostream>
#include<cstring>

using namespace std;

class HugeInt{
    friend ostream &operator <<(ostream&,const HugeInt &);
    friend istream &operator >>(istream&,HugeInt &);
    public:
	HugeInt(){
	    for(int i=0;i<50;i++)
	    {
		a[i]=48;
	    }	
	}
	HugeInt(char k[50]){
		strl=strlen(k);		
		for(int i=0;i<strl;i++)
		{
		    a[i]=k[i];
		}
		for(int i=strl;i<50;i++)
		{
		   a[i]=48;
		}
	}
	HugeInt(int num){
		int i=0,turn[8];
		for(i=0;i<8;i++)
		{
		   a[i]=num%10+48;
		   num=num/10;
		}
		for(i=0;i<8;i++)
		{
		    turn[i]=a[7-i];
		}
		for(i=0;i<8;i++)
		{
		    a[i]=turn[i];
		}
		for(i=8;i<50;i++)
		{
		    a[i]=48;
		}
	}
	HugeInt & operator =(const HugeInt & num);
	HugeInt & operator -(HugeInt & num);
	HugeInt & operator +(HugeInt & num);
        /*void inverse()
	{
	    int i;
	    char turn[50];
	    for(i=0;i<strl;i++)
	    {
		turn[strl-1-i]=a[i];
	    }
	    for(i=0;i<50;i++)
	    {
		a[i]=turn[i];
	    }
	}*/
    private:
	char a[50],b[50],c[50];
	int strl;
	string str;
};


