#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define LEN sizeof(struct Student) 
struct Student
{
	char name[10];//定义姓名 
	char sex[4];//定义性别 
	long int num;//定义长整型学号 
	int age;//定义年龄  
	char classname[20];//定义班级 
	char nativeplace[20]; //定义籍贯
	struct Student *next;
}*head,*p1,*p2,*p;
void menu()//菜单函数，随时调用 
{
	printf("***************【学生籍贯信息记录簿】***************\n");
	printf("*                   0.退出系统                     *\n");
	printf("*                   1.录入信息                     *\n");
	printf("*                   2.保存信息                     *\n");
	printf("*                   3.查询信息                     *\n");
	printf("*                   4.浏览信息                     *\n");
	printf("*                   5.增加信息                     *\n");
	printf("*                   6.修改信息                     *\n");
	printf("*                   7.删除信息                     *\n");
	printf("*                   8.读取信息                     *\n");
	printf("****************************************************\n");
	printf("\t\t请输入一个数<0-8>\n");
} 

int n;
void Browse();
void Choice();
struct Student * Input()          //建立基础的学生信息库 
{
	long int i; 
    p1=(struct Student *)malloc(LEN);
    p2=p1;
    printf("输入学生学号(输入0结束)："); 
	scanf("%ld",&i);
	if(i!=0)
	{
		printf("请输入学生姓名  性别  学号  年龄  班级  籍贯：");
		scanf("%s%s%ld%d%s%s",p1->name,p1->sex,&p1->num,&p1->age,p1->classname,p1->nativeplace);
		head=NULL;
		printf("信息录入成功\n\n");
		while(1)
		{
			n=n+1;
			if(n==1)
				head=p1;
			else
			p2->next=p1;
		p2=p1;
		printf("输入学生学号(输入0结束)："); 
		scanf("%ld",&i);
		if(i==0)
			{
				break; 
			} 
			else
			{
				p1=(struct Student *)malloc(LEN);	
				printf("请输入学生姓名  性别  学号  年龄  班级  籍贯：");
				scanf("%s%s%ld%d%s%s",p1->name,p1->sex,&p1->num,&p1->age,p1->classname,p1->nativeplace);
				printf("信息录入成功\n\n");
			}
		}
		p2->next=NULL;
		return head;
	}
	
}
void Add()              //添加学生信息
{
	p1=(struct Student *)malloc(LEN);         //开辟存储空间
	if(n==0)                                     //判断链表开头
		head=p1;                                 //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
	else p2->next=p1;   
	do
	{
		printf("请输入要添加的学生姓名  性别  学号  年龄  班级  籍贯：");
		scanf("%s%s%ld%d%s%s",p1->name,p1->sex,&p1->num,&p1->age,p1->classname,p1->nativeplace);
		p2=p1;                                       //p2指向p1所在的地址
		p2->next=NULL;                              //链表结束标志
		n+=1; 
	}while(p!=NULL); 
	printf("添加成功！\n");                                  
}
void Save()
{
	FILE *fp;//打开文件 
	fp=fopen("E:\\各类项目\\C语言学生籍贯信息记录簿\\学生籍贯信息记录簿.txt","wb");
	if(fp==NULL)
	{
		printf("打开文件失败！\n"); 
	} 
	p=head;
	while(p!=NULL)
	{
		if(fwrite(p,LEN,1,fp)!=1)
		{
			printf("文件书写错误！\n");
			fclose(fp);
			break;
		}
		p=p->next;
	}
	fclose(fp);
	printf("\n******************* 保存完成！ *********************\n");
}
void Read()
{
	FILE *fp;
	if((fp=fopen("E:\\各类项目\\C语言学生籍贯信息记录簿\\学生籍贯信息记录簿.txt","rb+"))==NULL)
	{
		printf("无法打开文件!");
		exit(0);
	}
    do
	{ 
		p1=(struct Student*)malloc(LEN);
		if(n==0)                             //判断链表开头
			head=p1;                         //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
		else
			p2->next=p1;
		fread(p1,LEN,1,fp);
		p2=p1;
		n=n+1;
    }while(p2->next!=NULL);
    fclose(fp);
	printf("读取完成!\n\n");
	Browse();
} 
void Delete()
{
	if(n!=0)
	{
		char a[20];
		printf("请输入要删除的学生姓名：");
		scanf("%s",&a);
		p=head;
		if(strcmp(head->name,a)==0)
		{
			p1=head;
			head=head->next;
			free(p1);
			printf("数据已经被删除\n");n--;
		}
		else
		{
			do
			{
				if(strcmp(p->name,a)==0)
				{   p1=p;
					p2->next=p->next;
					free(p1);break;
				}
				p2=p;  //不满足if表示这不是要删除的那一个节点，l暂时指向p  之后p再指向下一个节点，如果这个是要删除的节点那么l指向这个节点的next的地址
				p=p->next;
			}while(p!=NULL);
			printf("数据已经被删除\n");n--;
		}
	}
	else
		printf("没有任何学生的数据!\n");
    	
}
void Amend()
{
	if(n!=0)
	{
		int c;
		char a[20];
		printf("请输入要修改的学生姓名：");
		scanf("%s",&a);
		p=head;
		do
		{
			if(strcmp(a,p->name)==0)
			{
				printf("被修改人信息如下：\n");
				printf("姓名   性别   学号    年龄     班级            籍贯\n") ;
				printf("%s  %s  %ld   %d  %s  %s\n\n",p->name,p->sex,p->num,p->age,p->classname,p->nativeplace);
				break;
			}
			p=p->next;                            ////指针指向下一个节点
		}while(p!=NULL);
		printf("*******************【修改信息】******************\n");
		printf("*                  1. 修改姓名                  *\n");
		printf("*                  2. 修改性别                  *\n");
		printf("*                  3. 修改学号                  *\n");
		printf("*                  4. 修改年龄                  *\n");
		printf("*                  5. 修改班级                  *\n");
		printf("*                  6. 修改籍贯                  *\n");
		printf("*                  7. 退出修改                  *\n");
		printf("*************************************************\n");
		printf("\t\t请输入一个数<1-7>\n");
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			printf("姓名修改为：");
			scanf("%s",&p->name);break;
		case 2:
			printf("性别修改为：");
			scanf("%s",&p->sex);break;
		case 3:
			printf("学号修改为：");
			scanf("%ld",&p->num);break;
		case 4:
			printf("年龄修改为：");
			scanf("%d",&p->age);break;
		case 5:
			printf("班级修改为：");
			scanf("%s",&p->classname);break;
		case 6:
			printf("籍贯修改为：");
			scanf("%s",&p->nativeplace);break;
		case 7:
			printf("退出成功！\n");
			menu();
			Choice();
			break;
		default:
			printf("选择错误，重新输入\n");
			break;
		}
		printf("\n\n操作成功!\n\n");
	}
	else
		printf("您还没有添加数据哟!\n");
}

void Browse()//浏览信息 
 {
    if(n!=0)
	{
		p=head;                                   //p先指向开头
		printf("共录入%d位学生信息：\n\n",n);
		printf("姓名     性别   学号    年龄     班级            籍贯\n\n");
		do
		{
			printf("%s\t  %s  %ld   %d  %s  %s\n\n",p->name,p->sex,p->num,p->age,p->classname,p->nativeplace); 
			p=p->next;                            //p打印结束 把p指向next以判断下一个区域有没有内容
		}while(p!=NULL);//只要p指向的内存区域有数据 就打印内容
	}
	else
		printf("您还没有添加数据哦!\n");
}
//查找学生信息
void Search()
{
	void Byname();		
	void Bynum();
	void Byclassname();
	void Bynativeplace();
	int n;
	while(1)
	{	
		printf("*                  0.返回上一级                    *\n");
		printf("*                  1.按姓名查询                    *\n");
		printf("*                  2.按学号查询                    *\n");
		printf("*                  3.按班级查询                    *\n");
		printf("*                  4.按籍贯查询                    *\n");
		printf("****************************************************\n");
		printf("\t\t请输入一个数<0-4>\n");
		scanf("%d",&n);
		switch(n)
		{
			case 0:
				system("cls");
				menu();
				Choice();
				break; 
			case 1: 
				Byname(); 
				break;
			case 2:
				Bynum();
				break;
			case 3: 
				Byclassname();
				break;
			case 4: 
				Bynativeplace();
				break;
			default:
				printf("选择错误，重新输入\n");
				break;
	    }
	 	system("pause");
		system("cls");
	} 
}
//按姓名查询 
	void Byname()
	{
		int i=0;
		int flag=0; 
		char a[20];
		printf("请输入要查询的学生姓名：");
		scanf("%s",&a);
		p1=head;
		while(p1!=NULL)
		{
		if(strcmp(a,p1->name)==0)
		{
		flag=1;
		break; 
		}
		else
		p1=p1->next;
		} 
			if(flag==1)
			{
			printf("姓名   性别   学号    年龄     班级            籍贯\n\n");
				printf("%s  %s  %ld   %d  %s  %s\n\n",p1->name,p1->sex,p1->num,p1->age,p1->classname,p1->nativeplace);
			}
			else 
			printf("\n该学生不存在！\n\n");
	} 
//按学号查询
	void Bynum()
	{
		long int i;
		int flag=0; 
		printf("请输入要查询的学生学号：");
		scanf("%ld",&i);
		p1=head;
		while(p1!=NULL)
		{
		if(p1->num==i)
		{
		flag=1;
		break; 
		}
		else
		p1=p1->next;
		} 
			if(flag==1)
			{
			printf("姓名   性别   学号    年龄     班级            籍贯\n\n");
				printf("%s  %s  %ld   %d  %s  %s\n\n",p1->name,p1->sex,p1->num,p1->age,p1->classname,p1->nativeplace);
			}
			else
			printf("\n该学号的学生不存在！\n\n");
	} 

//按班级查询
 	void Byclassname()
	{
		char b[20];
		int flag=0; 
		printf("请输入要查询的学生班级：");
		scanf("%s",&b);
		p1=head;
		while(p1!=NULL)
		{
		if(strcmp(b,p1->classname)==0)
			{
			printf("姓名     性别   学号    年龄     班级            籍贯\n\n");
			printf("%s\t  %s  %ld   %d  %s  %s\n\n",p1->name,p1->sex,p1->num,p1->age,p1->classname,p1->nativeplace);
	 		flag=1;
			}
			p1=p1->next;
		} 						
		if(flag==0)
		printf("\n该班级的学生不存在！\n\n");
	}
//按籍贯查询
	void Bynativeplace() 
	{
		char c[20];
		int flag=0; 
		printf("请输入要查询的学生籍贯：");
		scanf("%s",&c);
		p1=head;
		while(p1!=NULL)
		{
		if(strcmp(c,p1->nativeplace)==0)
		{
		flag=1;
		break; 
		}
		else
		p1=p1->next;
		} 
			if(flag==1)
			{
			printf("姓名     性别   学号    年龄     班级            籍贯\n\n");
				printf("%s\t  %s  %ld   %d  %s  %s\n\n",p1->name,p1->sex,p1->num,p1->age,p1->classname,p1->nativeplace);
			}
			else 
			printf("\n该籍贯的学生不存在！\n\n");
	} 

void Choice()
{
	int ch=0;
	scanf("%d",&ch);
	//判断输入的字符是什么字符 
	switch (ch)
	{
		case 0: 
			printf("退出成功!\n"); 
			break;
		case 1:
			printf("*******************【录入信息】*********************\n\n");
			head=Input();
			system("pause");
			break;
		case 2:
			printf("*******************【保存信息】*********************\n");
			Save();
			break;
		case 3: 
			printf("*******************【查询信息】*********************\n");
			Search();
			break;
		case 4: 
			printf("*******************【浏览信息】*********************\n\n");
			Browse();        
			break;
		case 5: 
			printf("*******************【增加信息】*********************\n\n");
			Add();
			break;
		case 6: 
			printf("*******************【修改信息】*********************\n\n");
			Amend();
			break;
		case 7: 
			printf("*******************【删除信息】*********************\n\n");
			Delete();
			break;	
		case 8: 
			printf("*******************【读取信息】*********************\n\n");
			Read(); 
			break;		
		default:
			printf("选择错误，重新输入\n");
			break;
	}
}
int main()
{
	while(1)
	{
		menu();
		Choice();
		system("pause"); 
		system("cls");//头文件为 #include<stdlib.h>清屏功能
	}	
} 
