/* 
ID: wikioi_2 
LANG: C++ 
PROG: crypt1 
*/  
  
# include<cstdio>  
# include<iostream>  
  
using namespace std;  
  
int hash[10];  
  
  
int check ( int x )  
    {  
        while (x)  
            {  
                if (!hash[x%10])  
                    return 1;  
                    x = x/10;  
  
  
            }  
            return 0;  
    }  
  
int main(void)  
{  
    freopen("crypt1.in","r",stdin);  
    freopen("crypt1.out","w",stdout);  
    int sum = 0;  
    int n;cin>>n;  
    int t;  
    for ( int i = 0;i < n;i++ )  
        {  
            cin>>t;  
            hash[t] = 1;  
        }  
    for ( int i = 100;i < 1000;i++ )  
        {  
            if ( check(i))  
                continue;  
            for ( int j = 10;j < 100;j++ )  
                {  
                    int m = i*j;  
                    if ( m>9999 )break;  
                    if ( check(j)||check(m))  
                        continue;  
  
                    int fm = (j%10)*i;  
                    if ( fm<100||fm>=1000 )  
                        continue;  
  
                    int sm = (j/10)*i;  
                    if ( sm<100||sm>=1000 )  
                        continue;  
  
                    if ( check(sm)||check(fm) )  
                        continue;  
                    //if ( m == sm*10+fm )  
                        sum++;  
  
                }  
        }  
  
    cout<<sum<<endl;  
  
  
    return 0;  
}  
