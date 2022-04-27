 // c1.h (程序名)
 #include<cstring>
 #include <windows.h> 
 #include<malloc.h>
 #include<conio.h>
 #include<cstdlib> 
 #include<cmath> 
 #include<iostream>
 using namespace std;
  
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
