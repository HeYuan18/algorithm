/*************************************************************************
	> File Name: rsa.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月21日 星期三 09时11分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"rsa.h"
#include"stdfx.h"

#define p 67
#define q 89

const static int n = p * q;
const static int fn = (p - 1) * (q - 1);
static int e  = 0;
static int d = 0;
char nMD5[1024];

int getFn()
{
    return fn;
}

int getE()
{
	return e = getRelaPrime(fn);
}

int getD()
{
	int y = 0;
	gcdEx(e, fn, &d, &y);
	return d < 0 ? (d += fn) : d;
}

void generateKey(KEY *publicKey, KEY *privateKey)
{
	publicKey->n = n;
	publicKey->ed = getE();

	privateKey->n = n;
	privateKey->ed = getD();
}


int publicKeyEncrypt(KEY publicKey, int m)
{
    return powerMOD(m, publicKey.ed, publicKey.n);
}

int publicKeyDecrypt(KEY publicKey, int c)
{
    return powerMOD(c, publicKey.ed, publicKey.n);
}

int privateKeyEncrypt(KEY privateKey, int m)
{
    return powerMOD(m, privateKey.ed, privateKey.n);
}

int privateKeyDecrypt(KEY privateKey, int c)
{
    return powerMOD(c, privateKey.ed, privateKey.n);
}

char* digitalSignature(int m)
{
    memset(nMD5, 0, sizeof(nMD5));
    sprintf(nMD5, "%d", m);

    return getMD5(nMD5);
}

int digitalSignatureAuthentication(KEY publicKey, int c, char sigStr[], char** sigAuStr)
{
    int m = publicKeyDecrypt(publicKey, c);
    memset(nMD5, 0, sizeof(nMD5));
    sprintf(nMD5, "%d", m);

    *sigAuStr = getMD5(nMD5);

    return strcmp(sigStr, *sigAuStr);
}
