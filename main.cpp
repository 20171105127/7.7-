#include <cstdlib>
#include<stdio.h>

struct student
{
    
    int numbers;    //编号
    char name[10];    //名字
    char sex[10];     //性别
    int dateofbirt;   //出生日期
    char class1[15];   //班级
    char phoneNo[15];   //电话号
    int judge1;    //裁判
    int judge2;
    int judge3;
    int judge4;
    int judge5;
    int score;    //成绩
};
int main()
{
    struct student s[100];
    FILE *fp1,*fp2;
    int i=0,j;
    
    fp1 =fopen("/Users/S20171105127/Desktop/student1.csv","r");
    if(fp1==NULL)
    {
        printf("error\n");
        exit(-1);
    }
    else
    {
        fscanf(fp1,"%*[^\n]%*c");
        while(!feof(fp1))
        {
            fscanf(fp1,"%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%d,%d,%d,%d",
                   &s[i].numbers,&s[i].name,&s[i].sex,&s[i].dateofbirt,&s[i].class1,
                   &s[i].phoneNo,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            i++;
        }
        j=i;
        
        for(i=0;i<j;i++)
        {
            printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d\n",s[i].numbers,
                   s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,s[i].phoneNo,
                   s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
        }
        
        fclose(fp1);
    }
    
