/*************************************************************************
	> File Name: RSAtest.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月21日 星期三 09时59分42秒
 ************************************************************************/

#include<stdio.h>
#include"rsa.h"

int main()
{
    KEY PublicKey, PrivateKey;
    int m = 0, c = 0, mm = 0;

    printf("请输入要加密的消息<1~1000>: ");
    scanf("%d", &m);

    generateKey(&PublicKey, &PrivateKey);
    printf("公钥：(%d, %d), 私钥：(%d, %d), 明文: %d\n",
            PublicKey.n, PublicKey.ed, PrivateKey.n, PrivateKey.ed, m);
    printf("================================RSA================================\n");
    
    c = publicKeyEncrypt(PublicKey, m);
    printf("公钥加密：%d\n", c);
    mm = privateKeyDecrypt(PrivateKey, c);
    printf("私钥解密: %d\n", mm);
    printf("================================RSA================================\n");
    c = privateKeyEncrypt(PrivateKey, m);
    printf("私钥加密：%d\n", c);
    mm = publicKeyDecrypt(PublicKey, c);
    printf("公钥解密: %d\n", mm);
    printf("============================数字签名认证===========================\n");
    char* SigStr = digitalSignature(m);
    char* SigAuStr = NULL;
    if(digitalSignatureAuthentication(PublicKey, c, SigStr, &SigAuStr) == 0)
    {
        printf("^.^签名认证通过\n");
    }
    else
    {
        printf("@.@签名认证失败\n");
    }
    printf("明文%d生成的消息摘要是: \t%s\n", m, SigStr);
    printf("密文%d解密后生成的消息摘要是: %s\n", c, SigAuStr);

    return 0;
}
