#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define LEN sizeof(struct Student) 
struct Student
{
	char name[10];//�������� 
	char sex[4];//�����Ա� 
	long int num;//���峤����ѧ�� 
	int age;//��������  
	char classname[20];//����༶ 
	char nativeplace[20]; //���弮��
	struct Student *next;
}*head,*p1,*p2,*p;
void menu()//�˵���������ʱ���� 
{
	printf("***************��ѧ��������Ϣ��¼����***************\n");
	printf("*                   0.�˳�ϵͳ                     *\n");
	printf("*                   1.¼����Ϣ                     *\n");
	printf("*                   2.������Ϣ                     *\n");
	printf("*                   3.��ѯ��Ϣ                     *\n");
	printf("*                   4.�����Ϣ                     *\n");
	printf("*                   5.������Ϣ                     *\n");
	printf("*                   6.�޸���Ϣ                     *\n");
	printf("*                   7.ɾ����Ϣ                     *\n");
	printf("*                   8.��ȡ��Ϣ                     *\n");
	printf("****************************************************\n");
	printf("\t\t������һ����<0-8>\n");
} 

int n;
void Browse();
void Choice();
struct Student * Input()          //����������ѧ����Ϣ�� 
{
	long int i; 
    p1=(struct Student *)malloc(LEN);
    p2=p1;
    printf("����ѧ��ѧ��(����0����)��"); 
	scanf("%ld",&i);
	if(i!=0)
	{
		printf("������ѧ������  �Ա�  ѧ��  ����  �༶  ���᣺");
		scanf("%s%s%ld%d%s%s",p1->name,p1->sex,&p1->num,&p1->age,p1->classname,p1->nativeplace);
		head=NULL;
		printf("��Ϣ¼��ɹ�\n\n");
		while(1)
		{
			n=n+1;
			if(n==1)
				head=p1;
			else
			p2->next=p1;
		p2=p1;
		printf("����ѧ��ѧ��(����0����)��"); 
		scanf("%ld",&i);
		if(i==0)
			{
				break; 
			} 
			else
			{
				p1=(struct Student *)malloc(LEN);	
				printf("������ѧ������  �Ա�  ѧ��  ����  �༶  ���᣺");
				scanf("%s%s%ld%d%s%s",p1->name,p1->sex,&p1->num,&p1->age,p1->classname,p1->nativeplace);
				printf("��Ϣ¼��ɹ�\n\n");
			}
		}
		p2->next=NULL;
		return head;
	}
	
}
void Add()              //���ѧ����Ϣ
{
	p1=(struct Student *)malloc(LEN);         //���ٴ洢�ռ�
	if(n==0)                                     //�ж�����ͷ
		head=p1;                                 //n=0����������ǵ�һ������     //p2�Ľ�β��ָ��ĵ�ַ��p1
	else p2->next=p1;   
	do
	{
		printf("������Ҫ��ӵ�ѧ������  �Ա�  ѧ��  ����  �༶  ���᣺");
		scanf("%s%s%ld%d%s%s",p1->name,p1->sex,&p1->num,&p1->age,p1->classname,p1->nativeplace);
		p2=p1;                                       //p2ָ��p1���ڵĵ�ַ
		p2->next=NULL;                              //���������־
		n+=1; 
	}while(p!=NULL); 
	printf("��ӳɹ���\n");                                  
}
void Save()
{
	FILE *fp;//���ļ� 
	fp=fopen("E:\\������Ŀ\\C����ѧ��������Ϣ��¼��\\ѧ��������Ϣ��¼��.txt","wb");
	if(fp==NULL)
	{
		printf("���ļ�ʧ�ܣ�\n"); 
	} 
	p=head;
	while(p!=NULL)
	{
		if(fwrite(p,LEN,1,fp)!=1)
		{
			printf("�ļ���д����\n");
			fclose(fp);
			break;
		}
		p=p->next;
	}
	fclose(fp);
	printf("\n******************* ������ɣ� *********************\n");
}
void Read()
{
	FILE *fp;
	if((fp=fopen("E:\\������Ŀ\\C����ѧ��������Ϣ��¼��\\ѧ��������Ϣ��¼��.txt","rb+"))==NULL)
	{
		printf("�޷����ļ�!");
		exit(0);
	}
    do
	{ 
		p1=(struct Student*)malloc(LEN);
		if(n==0)                             //�ж�����ͷ
			head=p1;                         //n=0����������ǵ�һ������     //p2�Ľ�β��ָ��ĵ�ַ��p1
		else
			p2->next=p1;
		fread(p1,LEN,1,fp);
		p2=p1;
		n=n+1;
    }while(p2->next!=NULL);
    fclose(fp);
	printf("��ȡ���!\n\n");
	Browse();
} 
void Delete()
{
	if(n!=0)
	{
		char a[20];
		printf("������Ҫɾ����ѧ��������");
		scanf("%s",&a);
		p=head;
		if(strcmp(head->name,a)==0)
		{
			p1=head;
			head=head->next;
			free(p1);
			printf("�����Ѿ���ɾ��\n");n--;
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
				p2=p;  //������if��ʾ�ⲻ��Ҫɾ������һ���ڵ㣬l��ʱָ��p  ֮��p��ָ����һ���ڵ㣬��������Ҫɾ���Ľڵ���ôlָ������ڵ��next�ĵ�ַ
				p=p->next;
			}while(p!=NULL);
			printf("�����Ѿ���ɾ��\n");n--;
		}
	}
	else
		printf("û���κ�ѧ��������!\n");
    	
}
void Amend()
{
	if(n!=0)
	{
		int c;
		char a[20];
		printf("������Ҫ�޸ĵ�ѧ��������");
		scanf("%s",&a);
		p=head;
		do
		{
			if(strcmp(a,p->name)==0)
			{
				printf("���޸�����Ϣ���£�\n");
				printf("����   �Ա�   ѧ��    ����     �༶            ����\n") ;
				printf("%s  %s  %ld   %d  %s  %s\n\n",p->name,p->sex,p->num,p->age,p->classname,p->nativeplace);
				break;
			}
			p=p->next;                            ////ָ��ָ����һ���ڵ�
		}while(p!=NULL);
		printf("*******************���޸���Ϣ��******************\n");
		printf("*                  1. �޸�����                  *\n");
		printf("*                  2. �޸��Ա�                  *\n");
		printf("*                  3. �޸�ѧ��                  *\n");
		printf("*                  4. �޸�����                  *\n");
		printf("*                  5. �޸İ༶                  *\n");
		printf("*                  6. �޸ļ���                  *\n");
		printf("*                  7. �˳��޸�                  *\n");
		printf("*************************************************\n");
		printf("\t\t������һ����<1-7>\n");
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			printf("�����޸�Ϊ��");
			scanf("%s",&p->name);break;
		case 2:
			printf("�Ա��޸�Ϊ��");
			scanf("%s",&p->sex);break;
		case 3:
			printf("ѧ���޸�Ϊ��");
			scanf("%ld",&p->num);break;
		case 4:
			printf("�����޸�Ϊ��");
			scanf("%d",&p->age);break;
		case 5:
			printf("�༶�޸�Ϊ��");
			scanf("%s",&p->classname);break;
		case 6:
			printf("�����޸�Ϊ��");
			scanf("%s",&p->nativeplace);break;
		case 7:
			printf("�˳��ɹ���\n");
			menu();
			Choice();
			break;
		default:
			printf("ѡ�������������\n");
			break;
		}
		printf("\n\n�����ɹ�!\n\n");
	}
	else
		printf("����û���������Ӵ!\n");
}

void Browse()//�����Ϣ 
 {
    if(n!=0)
	{
		p=head;                                   //p��ָ��ͷ
		printf("��¼��%dλѧ����Ϣ��\n\n",n);
		printf("����     �Ա�   ѧ��    ����     �༶            ����\n\n");
		do
		{
			printf("%s\t  %s  %ld   %d  %s  %s\n\n",p->name,p->sex,p->num,p->age,p->classname,p->nativeplace); 
			p=p->next;                            //p��ӡ���� ��pָ��next���ж���һ��������û������
		}while(p!=NULL);//ֻҪpָ����ڴ����������� �ʹ�ӡ����
	}
	else
		printf("����û���������Ŷ!\n");
}
//����ѧ����Ϣ
void Search()
{
	void Byname();		
	void Bynum();
	void Byclassname();
	void Bynativeplace();
	int n;
	while(1)
	{	
		printf("*                  0.������һ��                    *\n");
		printf("*                  1.��������ѯ                    *\n");
		printf("*                  2.��ѧ�Ų�ѯ                    *\n");
		printf("*                  3.���༶��ѯ                    *\n");
		printf("*                  4.�������ѯ                    *\n");
		printf("****************************************************\n");
		printf("\t\t������һ����<0-4>\n");
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
				printf("ѡ�������������\n");
				break;
	    }
	 	system("pause");
		system("cls");
	} 
}
//��������ѯ 
	void Byname()
	{
		int i=0;
		int flag=0; 
		char a[20];
		printf("������Ҫ��ѯ��ѧ��������");
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
			printf("����   �Ա�   ѧ��    ����     �༶            ����\n\n");
				printf("%s  %s  %ld   %d  %s  %s\n\n",p1->name,p1->sex,p1->num,p1->age,p1->classname,p1->nativeplace);
			}
			else 
			printf("\n��ѧ�������ڣ�\n\n");
	} 
//��ѧ�Ų�ѯ
	void Bynum()
	{
		long int i;
		int flag=0; 
		printf("������Ҫ��ѯ��ѧ��ѧ�ţ�");
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
			printf("����   �Ա�   ѧ��    ����     �༶            ����\n\n");
				printf("%s  %s  %ld   %d  %s  %s\n\n",p1->name,p1->sex,p1->num,p1->age,p1->classname,p1->nativeplace);
			}
			else
			printf("\n��ѧ�ŵ�ѧ�������ڣ�\n\n");
	} 

//���༶��ѯ
 	void Byclassname()
	{
		char b[20];
		int flag=0; 
		printf("������Ҫ��ѯ��ѧ���༶��");
		scanf("%s",&b);
		p1=head;
		while(p1!=NULL)
		{
		if(strcmp(b,p1->classname)==0)
			{
			printf("����     �Ա�   ѧ��    ����     �༶            ����\n\n");
			printf("%s\t  %s  %ld   %d  %s  %s\n\n",p1->name,p1->sex,p1->num,p1->age,p1->classname,p1->nativeplace);
	 		flag=1;
			}
			p1=p1->next;
		} 						
		if(flag==0)
		printf("\n�ð༶��ѧ�������ڣ�\n\n");
	}
//�������ѯ
	void Bynativeplace() 
	{
		char c[20];
		int flag=0; 
		printf("������Ҫ��ѯ��ѧ�����᣺");
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
			printf("����     �Ա�   ѧ��    ����     �༶            ����\n\n");
				printf("%s\t  %s  %ld   %d  %s  %s\n\n",p1->name,p1->sex,p1->num,p1->age,p1->classname,p1->nativeplace);
			}
			else 
			printf("\n�ü����ѧ�������ڣ�\n\n");
	} 

void Choice()
{
	int ch=0;
	scanf("%d",&ch);
	//�ж�������ַ���ʲô�ַ� 
	switch (ch)
	{
		case 0: 
			printf("�˳��ɹ�!\n"); 
			break;
		case 1:
			printf("*******************��¼����Ϣ��*********************\n\n");
			head=Input();
			system("pause");
			break;
		case 2:
			printf("*******************��������Ϣ��*********************\n");
			Save();
			break;
		case 3: 
			printf("*******************����ѯ��Ϣ��*********************\n");
			Search();
			break;
		case 4: 
			printf("*******************�������Ϣ��*********************\n\n");
			Browse();        
			break;
		case 5: 
			printf("*******************��������Ϣ��*********************\n\n");
			Add();
			break;
		case 6: 
			printf("*******************���޸���Ϣ��*********************\n\n");
			Amend();
			break;
		case 7: 
			printf("*******************��ɾ����Ϣ��*********************\n\n");
			Delete();
			break;	
		case 8: 
			printf("*******************����ȡ��Ϣ��*********************\n\n");
			Read(); 
			break;		
		default:
			printf("ѡ�������������\n");
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
		system("cls");//ͷ�ļ�Ϊ #include<stdlib.h>��������
	}	
} 
