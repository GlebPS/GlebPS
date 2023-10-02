{\rtf1\ansi\ansicpg1251\cocoartf2709
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Online C compiler to run C program online\
#include <stdio.h>\
\
//  4.	\uc0\u1044 \u1072 \u1085 \u1086  \u1085 \u1072 \u1090 \u1091 \u1088 \u1072 \u1083 \u1100 \u1085 \u1086 \u1077  \u1095 \u1080 \u1089 \u1083 \u1086  n. \u1042 \u1099 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1074 \u1089 \u1077  \u1095 \u1080 \u1089 \u1083 \u1072  \u1086 \u1090  1 \u1076 \u1086  n. \u1056 \u1077 \u1072 \u1083 \u1080 \u1079 \u1086 \u1074 \u1072 \u1090 \u1100  \u1087 \u1088 \u1080  \u1087 \u1086 \u1084 \u1086 \u1097 \u1080  \u1088 \u1077 \u1082 \u1091 \u1088 \u1089 \u1080 \u1080 .)\
\
int printNumbers(int n) \{\
    if (n == 0) \{ // \uc0\u1073 \u1072 \u1079 \u1086 \u1074 \u1099 \u1081  \u1089 \u1083 \u1091 \u1095 \u1072 \u1081 \
        return;\
    \} else \{\
        printNumbers(n - 1); // \uc0\u1088 \u1077 \u1082 \u1091 \u1088 \u1089 \u1080 \u1074 \u1085 \u1099 \u1081  \u1074 \u1099 \u1079 \u1086 \u1074 \
        printf("%d ", n);\
    \}\
\}\
\
int main() \{\
    int n;\
    printf("\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1085 \u1072 \u1090 \u1091 \u1088 \u1072 \u1083 \u1100 \u1085 \u1086 \u1077  \u1095 \u1080 \u1089 \u1083 \u1086 : ");\
    scanf("%d", &n);\
\
    printf("\uc0\u1063 \u1080 \u1089 \u1083 \u1072  \u1086 \u1090  1 \u1076 \u1086  %d: ", n);\
    printNumbers(n);\
\
    return 0;\
\}}