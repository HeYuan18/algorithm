/*************************************************************************
	> File Name: stdfx.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月21日 星期三 09时59分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<openssl/md5.h>
#include"stdfx.h"

int isPrime(int a, int b)
{
	int tmp;
	while(b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}

	return a == 1 ? a : 0;
}

int getRelaPrime(int n)
{
	int res = sqrt(n);

	while(1)
	{
		if(isPrime(res, n))
		{
			return res;
		}

		--res;
	}
	return 0;
}

int gcdEx(int a, int b, int *x, int *y) 
 {
     if(b==0)
     {
         *x = 1;
         *y = 0;
         return a;
     }
     else
     {
         int r = gcdEx(b, a%b, x, y);
         int t = *x;
         *x = *y;
         *y = t - a/b * (*y);
         return r;
     }
 }

int biginterMod(char n[], int m)
{
    int ans = 0;
    int len = strlen(n);
    for(int i = 0; i < len; ++i)
    {
        ans = (10 * ans + n[i] - '0') % m;
    }

    return ans;
}

int powerMOD(int x, int y, int z)
{
    int ans = 1;
    x = x % z;

    while(y > 0)
    {
        if(y % 2 == 1)
        {
            ans = (ans * x) % z;
        }

        y /= 2;
        x = (x * x) % z;
    }

    return ans;
}

char* getMD5(char m[])
{
    MD5_CTX ctx;
    unsigned char md[16];
    char* outmd = NULL;
    outmd = (char*)malloc(sizeof(char) * 32 + 1);

    memset(md, 0, sizeof(md));
    memset(outmd, 0, 33);
    outmd[32] = '\n';

    MD5_Init(&ctx);
    MD5_Update(&ctx, m, strlen(m));
    MD5_Final(md, &ctx);

    for(int i = 0, j = 0; i < 16; ++i, ++j)
    {
        sprintf(outmd + (j * 2), "%02x", md[i]);
    }
    
    return outmd;
}
