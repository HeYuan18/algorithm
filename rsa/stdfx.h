/*************************************************************************
	> File Name: stdfx.h
	> Author: 
	> Mail: 
	> Created Time: 2018年11月21日 星期三 09时59分19秒
 ************************************************************************/

#ifndef _STDFX_H
#define _STDFX_H

int isPrime(int a, int b);  //判断a,b是否互质
int getRelaPrime(int n);    //求1～n范围内与n互质的数
int gcdEx(int a, int b, int *x, int *y);    //欧拉扩展方程, 求解二元一次方程的解
int biginterMod(char n[], int m);   //大整数取模
int powerMOD(int x, int y, int z);  //快速幂取模运算
char* getMD5(char m[]);     //获取MD5值

#endif
