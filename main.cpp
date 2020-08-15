#include <iostream>
#include<math.h>
using namespace std;

int gcd(int a,int b){
    int temp;
    while(1){
        temp=a%b;
        if(temp==0)
            return b;
        a=b;
        b=temp;
        }
    }

int decryption(int x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;


    if (x == 0) return 0;

    while (y > 0)
    {

        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}


int main()
{
    double p=17;
    double q=11;
    double N= p*q;
    double n_0 =(p-1)*(q-1);
    double e =7;
    while(e<n_0){
        if (gcd(e, n_0)==1)
            break;
        else
            e++;
    }

    double d =(n_0+1)/e;
    double M = 88;
    cout<<"plain text "<<M<<endl;
    double c = pow(M,e);
    c = fmod(c,N);
    cout<<"encrypted data :  "<<c<<endl;
    int m = decryption(c,d,N);
    cout<<"decrypted data : "<<m<<endl;

    return 0;
}
