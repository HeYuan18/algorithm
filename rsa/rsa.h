/*************************************************************************
	> File Name: rsa.h
	> Author: 
	> Mail: 
	> Created Time: 2018年11月21日 星期三 10时43分11秒
 ************************************************************************/

#ifndef _RSA_H
#define _RSA_H

typedef struct key{
    int n;
    int ed;
}KEY;

int getFn();    //返回fn
int getE();  //计算1~fn内且与fn互质的数
int getD();  //计算e的模反元素
void generateKey(KEY *publicKey, KEY *privateKey); //生成密钥对
int publicKeyEncrypt(KEY publicKey, int m);     //公钥加密
int publicKeyDecrypt(KEY publicKey, int em);    //公钥解密
int privateKeyEncrypt(KEY privateKey, int m);   //私钥加密
int privateKeyDecrypt(KEY privateKey, int em);  //私钥解密
char* digitalSignature(int m);    //数字签名
int digitalSignatureAuthentication(KEY PublicKey, int c, char sigStr[], char** sigAuStr);   //数字签名认证

#endif
