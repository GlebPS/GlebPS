{\rtf1\ansi\ansicpg1251\cocoartf2709
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Online C compiler to run C program online\
#include <stdio.h>\
\
//  1.\uc0\u1056 \u1077 \u1072 \u1083 \u1080 \u1079 \u1086 \u1074 \u1072 \u1090 \u1100  \u1092 \u1091 \u1085 \u1082 \u1094 \u1080 \u1102 , \u1082 \u1086 \u1090 \u1086 \u1088 \u1072 \u1103  \u1074 \u1086 \u1079 \u1074 \u1088 \u1072 \u1097 \u1072 \u1077 \u1090  \u1077 \u1076 \u1080 \u1085 \u1080 \u1095 \u1085 \u1091 \u1102  \u1082 \u1074 \u1072 \u1076 \u1088 \u1072 \u1090 \u1085 \u1091 \u1102  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \u1091  \u1079 \u1072 \u1076 \u1072 \u1085 \u1085 \u1086 \u1075 \u1086  \u1088 \u1072 \u1079 \u1084 \u1077 \u1088 \u1072 .\
\
#include <stdio.h>\
\
int FIdentityMatrix(int n, int matrix[n][n]) \{\
    for (int i = 0; i < n; i++) \{\
        for (int j = 0; j < n; j++) \{\
            if (i == j) \{\
                matrix[i][j] = 1; // \uc0\u1069 \u1083 \u1077 \u1084 \u1077 \u1085 \u1090 \u1099  \u1075 \u1083 \u1072 \u1074 \u1085 \u1086 \u1081  \u1076 \u1080 \u1072 \u1075 \u1086 \u1085 \u1072 \u1083 \u1080  \u1088 \u1072 \u1074 \u1085 \u1099  1\
            \} else \{\
                matrix[i][j] = 0; // \uc0\u1054 \u1089 \u1090 \u1072 \u1083 \u1100 \u1085 \u1099 \u1077  \u1101 \u1083 \u1077 \u1084 \u1077 \u1085 \u1090 \u1099  \u1088 \u1072 \u1074 \u1085 \u1099  0\
            \}\
        \}\
    \}\
\}\
\
int main() \{\
    int n;\
    printf("\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1088 \u1072 \u1079 \u1084 \u1077 \u1088  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \u1099 : ");\
    scanf("%d", &n);\
\
    int identityMatrix[n][n];\
\
    FIdentityMatrix(n, identityMatrix);\
\
    printf("\uc0\u1045 \u1076 \u1080 \u1085 \u1080 \u1095 \u1085 \u1072 \u1103  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \u1072  %d x %d:\\n", n, n);\
    for (int i = 0; i < n; i++) \{\
        for (int j = 0; j < n; j++) \{\
            printf("%d ", identityMatrix[i][j]);\
        \}\
        printf("\\n");\
    \}\
\
    return 0;\
\}\
}