#define _CRT_SECURE_NO_WARNINGS 

#include"head.h"

//int main()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;//��i��10��ʱ��Խ�����
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

int main()
{
	//Test();
	struct S2* ps = (struct S2*)malloc(sizeof(struct S2) + 40);
	return 0;
}