#define _CRT_SECURE_NO_WARNINGS 

#include"head.h"

//int main()
//{
//	int arr[3] = { 0,1,2 };
//	int* pa = arr;
//	int a = 0;
//	int* p = &a;
//	printf("%d\n%d\n%d\n", *(arr+1), *(pa + 2), *p);
//	return 0;
//}


//int my_strlen(char* str)
//{
//	char* astr = str;
//	if (*astr != '\0')
//	{
//		return 1 + my_strlen(astr + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int str2(char* str)
//{
//	char* vp = NULL;
//	int n = 0;
//	for (vp = &str[0]; vp < &str[3];)
//	{
//		*vp++ = 0;
//		n++;
//	}
//	return n;
//}
//
//int main()
//{
//	char arr[] = "abc";
//	int n = my_strlen(arr);
//	printf("%d\n", n);
//	int m = str2(arr);
//	printf("%s\n", arr);
//	printf("%d\n", m);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct slist
{
	int id;
	struct slist* next;
}L;

//����һ���ڵ� 
L* create_node(int data)
{
	//��ÿ���ڵ����ṹ��һ���Ŀռ��С 
	L* p = malloc(sizeof(L));
	if (NULL == p)
	{
		printf("malloc error!\n");
		return NULL;
	}
	//���ڽṹ����δ��ʼ����ʱ��һ���������ݣ�����Ҫ�� 
	memset(p, 0, sizeof(L));
	//��ʼ����һ���ڵ� 
	p->id = data;
	//���ڵ�ĺ��ָ������ΪNULL 
	p->next = NULL;
}

//�����β�� 
void tail_insert(L* pH, L* new)
{
	//��ȡ��ǰ��λ�� 
	L* p = pH;
	//�����ǰλ�õ���һ���ڵ㲻Ϊ�� 
	while (NULL != p->next)
	{
		//�ƶ�����һ���ڵ� 
		p = p->next;
	}
	//�����������ѭ���������Ѿ�����NULL�����λ��
	//��ʱֱ�Ӱ��²���Ľڵ㸳ֵ��NULL���λ�� 
	p->next = new;
}

//�����ͷ�� 
void top_insert(L* pH, L* new)
{
	L* p = pH;
	new->next = p->next;
	p->next = new;
}

//����ı��� 
void Print_node(L* pH)
{
	//��ȡ��ǰ��λ�� 
	L* p = pH;
	//��ȡ��һ���ڵ��λ�� 
	p = p->next;
	//�����ǰλ�õ���һ���ڵ㲻Ϊ�� 
	while (NULL != p->next)
	{
		//(1)��ӡ�ڵ������ 
		printf("id:%d\n", p->id);
		//(2)�ƶ�����һ���ڵ�,���������Ϊ�棬���ظ�(1)����(2) 
		p = p->next;
	}
	//�����ǰλ�õ���һ���ڵ�Ϊ�գ����ӡ����
	//˵��ֻ��һ���ڵ� 
	printf("id:%d\n", p->id);
}

//ɾ�������еĽڵ� 
int detele_list_node(L* pH, int data)
{
	//��ȡ��ǰͷ�ڵ��λ�� 
	L* p = pH;
	L* prev = NULL;
	while (NULL != p->next)
	{
		//���浱ǰ�ڵ��ǰһ���ڵ��ָ�� 
		prev = p;
		//Ȼ���õ�ǰ��ָ����������ƶ� 
		p = p->next;
		//�жϣ��ҵ���Ҫɾ��������  
		if (p->id == data)
		{
			//���������һ������ͨ�ڵ㣬����һ����β�ڵ�
			if (p->next != NULL)  //��ͨ�ڵ����� 
			{
				prev->next = p->next;
				free(p);
			}
			else //β�ڵ����� 
			{
				prev->next = NULL; //�����β�ڵ����һ���ڵ��ָ����ָ��� 
				free(p);
			}
			return 0;
		}
	}
	printf("û��Ҫɾ���Ľڵ�\n");
	return -1;
}

void trave_list(L* pH)
{
	//�����һ���ڵ��λ�� 
	L* p = pH->next;
	L* pBack;
	int i = 0;
	if (p->next == NULL || p == NULL)
		return;

	while (NULL != p->next) //�������� 
	{
		//�����һ���ڵ����һ���ڵ� 
		pBack = p->next;
		//�ҵ���һ����Ч�ڵ�,��ʵ����ͷָ�����һ���ڵ� 
		if (p == pH->next)
		{
			//��һ����Ч�ڵ�������һ���ڵ㣬����Ҫָ��NULL 
			p->next = NULL;
		}
		else
		{
			/*
			new->next = p->next ;
			p->next = new ;
			*/
			p->next = pH->next; //β������ 
		}
		pH->next = p; //ͷ������ 
		p = pBack; //����һ���ڵ� 
	}
	top_insert(pH, p); //�������һ���ڵ� 
}

<<<<<<< HEAD
int main(int argc, char** argv)
{
	//������һ���ڵ� 
	int i;
	L* header = create_node(0);
	L* n;
	for (i = 1; i < 10; i++)
	{
		n = create_node(i);
		tail_insert(header, n);
	}
	Print_node(header);
	detele_list_node(header, 5);
	putchar('\n');
	Print_node(header);
	putchar('\n');
	trave_list(header);
	Print_node(header);
=======
int str2(char* str)
{
	char* vp = NULL;
	int n = 0;
	for (vp = &str[0]; vp < &str[3];)
	{
		*vp++ = 0;
		n++;
	}
	return n;
}

int main()
{
	char arr[] = "abc";
	int n = my_strlen(arr);
	printf("%d\n", n);
	int m = str2(arr);
	printf("%s\n", arr);
	printf("%d\n", m);
>>>>>>> e953a62a943bddc5551a604332d375f88da6c23e
	return 0;
}