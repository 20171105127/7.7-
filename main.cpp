#include <cstdlib>
#include<stdio.h>
struct student
{
    int numbers;    //编号
    char name[10];    //名字
    char sex[10];     //性别
    int dateofbirt;   //出生日期
    char class1[10];   //班级
    char phoneNo[10];   //电话号
    int judge1;
    int judge2;
    int judge3;
    int judge4;
    int judge5;   //裁判
    int score;    //成绩
};
int main()
{
    struct student s[100];               //定义结构数组
    FILE *fp1,*fp2;                 //俩个文件指针
    int i=0,j;
    fp1 =fopen("/Users/S20171105127/Desktop/student1.csv","r");          //读取文件
    if(fp1==NULL)         //文件为空
    {
        printf("找不到文件\n");
        exit(-1);
    }
    else
    {
        fscanf(fp1,"%*[^\n]%*c");            //换行
        while(!feof(fp1))              //feof在fp1指向的文件结束时输出0
        {
            fscanf(fp1,"%d,",&s[i].numbers);
            fscanf(fp1,"%[^,],",s[i].name);
            fscanf(fp1,"%[^,],",s[i].sex);
            fscanf(fp1,"%d,",&s[i].dateofbirt);
            fscanf(fp1,"%[^,],",s[i].class1);
            fscanf(fp1,"%[^,],",s[i].phoneNo);
            fscanf(fp1,"%d,",&s[i].judge1);
            fscanf(fp1,"%d,",&s[i].judge2);
            fscanf(fp1,"%d,",&s[i].judge3);
            fscanf(fp1,"%d,",&s[i].judge4);
            fscanf(fp1,"%d,",&s[i].judge5);
            i++;
        }
        j=i;
        for(i=0;i<j;i++)
        {
            printf("%d",s[i].numbers);
            printf("%s",s[i].name);
            printf("%s",s[i].sex);
            printf("%d",s[i].dateofbirt);
            printf("%s",s[i].class1);
            printf("%s",s[i].phoneNo);
            printf("%d",s[i].judge1);
            printf("%d",s[i].judge2);
            printf("%d",s[i].judge3);
            printf("%d",s[i].judge4);
            printf("%d\n",s[i].judge5);
        }
        fclose(fp1);              //关闭文件
    }
    j=i;
    int max[100],min[100];
    for(i=0;i<j;i++)
    {
        max[i]=min[i]=s[i].judge1;          //最大值给第一个数
    }
    j=i;
    for(i=0;i<j;i++)
    {
        if(s[i].judge2>max[i])
            max[i]=s[i].judge2;
        if(s[i].judge3>max[i])
            max[i]=s[i].judge3;
        if(s[i].judge4>max[i])
            max[i]=s[i].judge4;
        if(s[i].judge5>max[i])
            max[i]=s[i].judge5;
    }
    j=i;
    for(i=0;i<j;i++)
    {
        if(s[i].judge2<min[i])
            min[i]=s[i].judge2;
        if(s[i].judge3<min[i])
            min[i]=s[i].judge3;
        if(s[i].judge4<min[i])
            min[i]=s[i].judge4;
        if(s[i].judge5<min[i])
            min[i]=s[i].judge5;
    }               //最值
    j=i;
    for(i=0;i<j;i++)
    {
        s[i].score=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;       //平均值
    }
    j=i;
    i=0;
    fp2=fopen("/Users/S20171105127/Desktop/student2.csv","w");         //写入文件
    fprintf(fp2,"numbers,");
    fprintf(fp2,"name,");
    fprintf(fp2,"sex,");
    fprintf(fp2,"dateofbirth,");
    fprintf(fp2,"class,");
    fprintf(fp2,"phoneNo,");
    fprintf(fp2,"judge1,");
    fprintf(fp2,"judge2,");
    fprintf(fp2,"judge3,");
    fprintf(fp2,"judge4,");
    fprintf(fp2,"judge5,");
    fprintf(fp2,"score\n");
    while(i<j)
    {
        fprintf(fp2,"%d,",s[i].numbers);
        fprintf(fp2,"%s,",s[i].name);
        fprintf(fp2,"%s,",s[i].sex);
        fprintf(fp2,"%d,",s[i].dateofbirt);
        fprintf(fp2,"%s,",s[i].class1);
        fprintf(fp2,"%s,",s[i].phoneNo);
        fprintf(fp2,"%d,",s[i].judge1);
        fprintf(fp2,"%d,",s[i].judge2);
        fprintf(fp2,"%d,",s[i].judge3);
        fprintf(fp2,"%d,",s[i].judge4);
        fprintf(fp2,"%d,",s[i].judge5);
        fprintf(fp2,"%d\n",s[i].score);
        i++;
    }
    fclose(fp2);               //关闭文件
    return 0;
}
