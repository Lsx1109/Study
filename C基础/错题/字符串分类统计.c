/*
题目描述
输入一行字符，分别统计出其中英文字母、数字、空格和其他字符的个数。

输入
一行字符,长度不超过200

输出
统计值

样例输入
aklsjflj123 sadf918u324 asdf91u32oasdf/.';123
样例输出
23 16 2 4
*/

#include<stdio.h>
int main()
{
    int letter = 0,number = 0,blank = 0,others = 0,c;        //分别为字母、数字、空格、其他
    while((c = getchar()) != '\n'){
        if(c >= 'A' && c<='Z' || c >= 'a' && c <= 'z')    //判断是否为字母
            letter++;
        else if(c >= '0' && c <= '9')                     //判断是都为数字
            number++;
        else if(c == ' ')                                 //判断是否为空格
            blank++;
        else                                              //其他
            others++;
    }
    printf("%d %d %d %d\n",letter,number,blank,others);
    return 0;
}
