#include"lab5.h"

using namespace std;
ostream & operator  << (ostream &out,const HugeInt &num)
{
    int i;
    for(i=49;i>=0;i--)
        if(num.a[i]!=48)
            break;
    int count=i;
    for(i=count;i>=0;i--)
        out<<num.a[i];
    return out;
}
istream & operator >> (istream &in,HugeInt &num)
{
    char turn[50];
    for(int i=0;i<50;i++)
        turn[i]=48;
    in >> num.a;
    num.strl=strlen(num.a);
    for(int i=0;i<num.strl;i++)
    {
        turn[num.strl-1-i]=num.a[i];
    }
    for(int i=0;i<num.strl;i++)
    {
        num.a[i]=turn[i];
    }
    for(int i=0;i<50;i++)
        num.b[i]=num.a[i];
    return in;
}
HugeInt & HugeInt::operator = (const HugeInt &num)
{
    for(int i=0;i<50;i++)
    {
        this->b[i]=num.b[i];
        this->a[i]=num.b[i];
    }
    return *this;
}
HugeInt & HugeInt::operator - (HugeInt &num)
{
    int i=0;
    int A[50],B[50],C[50];
    for(i=0;i<50;i++)
    {
        A[i]=this->a[i]-48;
        B[i]=num.a[i]-48;
    }
    for(i=0;i<50;i++)
    {
        C[i]=A[i]-B[i];
        if(C[i]<0)
        {
            A[i+1]=A[i+1]-1;
            C[i]=C[i]+10;
	    cout<<C[i];
        }
    }
    for(i=0;i<50;i++)
        num.b[i]=C[i]+48;
    return num;
}


HugeInt & HugeInt::operator + (HugeInt &num)
{
    int i=0,n;
    n=strlen(num.a);
    for(i=0;i<50;i++)
    {
        num.b[i]=num.a[i]+this->a[i]-48;
    }
    for(i=0;i<49;i++)
    {
        if(num.b[i]>=58)
        {
            num.b[i]=num.b[i]-10;
            num.b[i+1]=num.b[i+1]+1;
        }
    }
    return num;
}

