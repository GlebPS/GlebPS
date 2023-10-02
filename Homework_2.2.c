{\rtf1\ansi\ansicpg1251\cocoartf2709
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Online C compiler to run C program online\
#include <stdio.h>\
\
//  2.	\uc0\u1052 \u1072 \u1090 \u1088 \u1080 \u1094 \u1099  \u1087 \u1088 \u1077 \u1076 \u1089 \u1090 \u1072 \u1074 \u1083 \u1077 \u1085 \u1099  \u1074  \u1074 \u1080 \u1076 \u1077  \u1076 \u1074 \u1091 \u1084 \u1077 \u1088 \u1085 \u1099 \u1093  \u1084 \u1072 \u1089 \u1089 \u1080 \u1074 \u1086 \u1074 . \u1056 \u1077 \u1072 \u1083 \u1080 \u1079 \u1086 \u1074 \u1072 \u1090 \u1100  \u1092 \u1091 \u1085 \u1082 \u1094 \u1080 \u1080 , \u1082 \u1086 \u1090 \u1086 \u1088 \u1099 \u1077  \u1074 \u1086 \u1079 \u1074 \u1088 \u1072 \u1097 \u1072 \u1102 \u1090  \u1085 \u1086 \u1074 \u1099 \u1081  \u1084 \u1072 \u1089 \u1089 \u1080 \u1074 \
//   1.	\uc0\u1057 \u1083 \u1086 \u1078 \u1077 \u1085 \u1080 \u1077  \u1080  \u1074 \u1099 \u1095 \u1080 \u1090 \u1072 \u1085 \u1080 \u1077  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \
//   2.	\uc0\u1059 \u1084 \u1085 \u1086 \u1078 \u1077 \u1085 \u1080 \u1077  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \u1099  \u1085 \u1072  \u1095 \u1080 \u1089 \u1083 \u1086 \
//   3.	\uc0\u1055 \u1088 \u1086 \u1080 \u1079 \u1074 \u1077 \u1076 \u1077 \u1085 \u1080 \u1077  \u1076 \u1074 \u1091 \u1093  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \
//   4.	\uc0\u1058 \u1088 \u1072 \u1085 \u1089 \u1087 \u1086 \u1085 \u1080 \u1088 \u1086 \u1074 \u1072 \u1085 \u1085 \u1072 \u1103  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \u1072 \
//   5.	\uc0\u1060 \u1091 \u1085 \u1082 \u1094 \u1080 \u1103  \u1076 \u1083 \u1103  \u1086 \u1087 \u1088 \u1077 \u1076 \u1077 \u1083 \u1077 \u1085 \u1080 \u1103  \u1088 \u1072 \u1074 \u1077 \u1085 \u1089 \u1090 \u1074 \u1072  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \
//   6.	\uc0\u1060 \u1091 \u1085 \u1082 \u1094 \u1080 \u1080  \u1076 \u1086 \u1083 \u1078 \u1085 \u1099  \u1080 \u1084 \u1077 \u1090 \u1100  \u1087 \u1088 \u1086 \u1074 \u1077 \u1088 \u1082 \u1091  \u1085 \u1072  \u1074 \u1086 \u1079 \u1084 \u1086 \u1078 \u1085 \u1086 \u1089 \u1090 \u1100  \u1086 \u1089 \u1091 \u1097 \u1077 \u1089 \u1090 \u1074 \u1083 \u1077 \u1085 \u1080 \u1103  \u1086 \u1087 \u1077 \u1088 \u1072 \u1094 \u1080 \u1080 \
//   7.	\uc0\u1044 \u1083 \u1103  \u1086 \u1087 \u1088 \u1077 \u1076 \u1077 \u1083 \u1077 \u1085 \u1080 \u1103  \u1088 \u1072 \u1079 \u1084 \u1077 \u1088 \u1072  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \u1099  \u1080 \u1089 \u1087 \u1086 \u1083 \u1100 \u1079 \u1091 \u1077 \u1090 \u1089 \u1103  \u1092 \u1091 \u1085 \u1082 \u1094 \u1080 \u1103  sizeof()\
\
int addMatrix(int a[][3], int b[][3], int result[][3], int rows, int cols) \{\
    for (int i = 0; i < rows; i++) \{\
        for (int j = 0; j < cols; j++) \{\
            result[i][j] = a[i][j] + b[i][j];\
        \}\
    \}\
\}\
\
int subtractMatrix(int a[][3], int b[][3], int result[][3], int rows, int cols) \{\
    for (int i = 0; i < rows; i++) \{\
        for (int j = 0; j < cols; j++) \{\
            result[i][j] = a[i][j] - b[i][j];\
        \}\
    \}\
\}\
\
int multiplyMatrixByScalar(int a[][3], int scalar, int result[][3], int rows, int cols) \{\
    for (int i = 0; i < rows; i++) \{\
        for (int j = 0; j < cols; j++) \{\
            result[i][j] = a[i][j] * scalar;\
        \}\
    \}\
\}\
\
int multiplyMatrix(int a[][3], int b[][3], int result[][3], int rows1, int cols1, int rows2, int cols2) \{\
    if (cols1 != rows2) \{\
        printf("\uc0\u1053 \u1077 \u1074 \u1086 \u1079 \u1084 \u1086 \u1078 \u1085 \u1086  \u1087 \u1077 \u1088 \u1077 \u1084 \u1085 \u1086 \u1078 \u1080 \u1090 \u1100  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \u1099 \\n");\
        return;\
    \}\
    for (int i = 0; i < rows1; i++) \{\
        for (int j = 0; j < cols2; j++) \{\
            result[i][j] = 0;\
            for (int k = 0; k < cols1; k++) \{\
                result[i][j] += a[i][k] * b[k][j];\
            \}\
        \}\
    \}\
\}\
\
int transposeMatrix(int a[][3], int result[][3], int rows, int cols) \{\
    for (int i = 0; i < rows; i++) \{\
        for (int j = 0; j < cols; j++) \{\
            result[j][i] = a[i][j];\
        \}\
    \}\
\}\
\
int areMatricesEqual(int a[][3], int b[][3], int rows, int cols) \{\
    for (int i = 0; i < rows; i++) \{\
        for (int j = 0; j < cols; j++) \{\
            if (a[i][j] != b[i][j]) \{\
                return 0;\
            \}\
        \}\
    \}\
    return 1;\
\}\
\
int printMatrix(int a[][3], int rows, int cols) \{\
    for (int i = 0; i < rows; i++) \{\
        for (int j = 0; j < cols; j++) \{\
            printf("%d ", a[i][j]);\
        \}\
        printf("\\n");\
    \}\
\}\
\
int main() \{\
    int a[3][3] = \{\{1, 2, 3\}, \{4, 5, 6\}, \{7, 8, 9\}\};\
    int b[3][3] = \{\{9, 8, 7\}, \{6, 5, 4\}, \{3, 2, 1\}\};\
    int c[3][3];\
\
    // \uc0\u1057 \u1083 \u1086 \u1078 \u1077 \u1085 \u1080 \u1077  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \
    addMatrix(a, b, c, 3, 3);\
    printf("a + b:\\n");\
    printMatrix(c, 3, 3);\
\
    // \uc0\u1042 \u1099 \u1095 \u1080 \u1090 \u1072 \u1085 \u1080 \u1077  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \
    subtractMatrix(a, b, c, 3, 3);\
    printf("\\na - b:\\n");\
    printMatrix(c, 3, 3);\
\
    // \uc0\u1059 \u1084 \u1085 \u1086 \u1078 \u1077 \u1085 \u1080 \u1077  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \u1099  \u1085 \u1072  \u1095 \u1080 \u1089 \u1083 \u1086 \
    multiplyMatrixByScalar(a, 2, c, 3, 3);\
    printf("\\na * 2:\\n");\
    printMatrix(c, 3, 3);\
\
    // \uc0\u1059 \u1084 \u1085 \u1086 \u1078 \u1077 \u1085 \u1080 \u1077  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \
    int d[3][2] = \{\{1, 2\}, \{3, 4\}, \{5, 6\}\};\
    int e[2][4] = \{\{1, 2, 3, 4\}, \{5, 6, 7, 8\}\};\
    int f[3][4];\
    multiplyMatrix(d, e, f, 3, 2, 2, 4);\
    printf("\\nd * e:\\n");\
    printMatrix(f, 3, 4);\
\
    // \uc0\u1058 \u1088 \u1072 \u1085 \u1089 \u1087 \u1086 \u1085 \u1080 \u1088 \u1086 \u1074 \u1072 \u1085 \u1080 \u1077 \
    transposeMatrix(a, c, 3, 3);\
    printf("\\n\uc0\u1058 \u1088 \u1072 \u1085 \u1089 \u1087 \u1086 \u1085 \u1080 \u1088 \u1086 \u1074 \u1072 \u1085 \u1085 \u1072 \u1103  a:\\n");\
    printMatrix(c, 3, 3);\
\
    // \uc0\u1055 \u1088 \u1086 \u1074 \u1077 \u1088 \u1082 \u1072  \u1088 \u1072 \u1074 \u1077 \u1085 \u1089 \u1090 \u1074 \u1072  \u1084 \u1072 \u1090 \u1088 \u1080 \u1094 \
    printf("\\na == b: %d\\n", areMatricesEqual(a, b, 3, 3));\
    printf("a == a: %d\\n", areMatricesEqual(a, a, 3, 3));\
\
    return 0;\
\}}