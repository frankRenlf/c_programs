#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<string.h>    //�ַ���ͷ�ļ� 
int a[1000001];     //�����������涨��������Դ�һ�㣨�ܶ�ࣩܶ 
void kuaisu_sheng(int left,int right)
{
    int i = left;     //�������¼���� 
    int j = right;
    int key = a[i];    //��¼�ο�ֵ 
    if(left>=right)  //�������������ڻ��ߵ����ұߵ������ʹ����Ѿ��������һ������
        return ;
    while(i<j)   //�����ڵ�����Ѱ��һ��
    {
        while(i<j&&key<=a[j])   //��Ѱ�ҽ������������ǣ�1���ҵ�һ��С�ڻ��ߴ���key���������ڻ�С��ȡ�������������ǽ���2��û�з�������1�ģ�����i��j�Ĵ�Сû�з�ת 
            j--;    //��ǰѰ��
        a[i]=a[j];     //�ҵ�һ������������Ͱ�������ǰ��ı����ߵ�i��ֵ�������һ��ѭ����key��a[left]����ô���Ǹ�key��
        while(i<j&&key>=a[i])   //����i�ڵ�������ǰѰ�ң�ͬ�ϣ�����ע����key�Ĵ�С��ϵֹͣѭ���������෴����Ϊ����˼���ǰ����������ӣ������������ߵ�����С��key�Ĺ�ϵ�෴
            i++;
        a[j]=a[i];
    }
    a[i]=key;                  //���ڵ���������һ���Ժ�Ͱ��м���key�ع�
    kuaisu_sheng(left,i-1);     //�����ͬ���ķ�ʽ�Էֳ�������ߵ�С�����ͬ�ϵ�����
    kuaisu_sheng(i+1,right);    //��ͬ���ķ�ʽ�Էֳ������ұߵ�С�����ͬ�ϵ�����
                               //��Ȼ�����ܻ���ֺܶ�����ң�ֱ��ÿһ���i = j Ϊֹ
}
void kuaisu_jiang(int left,int right)
{
    if(left>=right)
        return ;
    int i=left;
    int j=right;
    int key=a[i]; 
    while(i<j)  
    {
        while(i<j&&key>=a[j])   //˳������� 
            j--;    
        a[i]=a[j];    
        while(i<j&&key<=a[i])   //��������������ô�Ŀ��Զ�����������ĺ����� 
        i++;
        a[j]=a[i];
    }
    a[i]=key;              
    kuaisu_jiang(left,i-1);
    kuaisu_jiang(i+1,right);
}
//int main()
//{
//    int n,i,choice;
//    printf("��������С����(By STY)\n\n");
//    printf("�����ǽ���\n");
//    printf("����ѡ��1 ��\n");
//    printf("����ѡ��2 ��\n");
//    printf("������:(1~2)\n");
//    printf("�˳��밴��0 ��(�ڼ�����)�������س���ллʹ�ã�\n");
//    scanf("%d", &choice);
//    while(choice != 0)
//    {
//        memset(a,0,sizeof(a));    //������� 
//        if(choice==1)
//        {
//            printf("������Ҫ��������ָ���:\n");
//            scanf("%d", &n);
//            printf("������%d������:\n", n);
//            for(int ii=0;ii<n;ii++)
//                scanf("%d",&a[ii]);
//            kuaisu_sheng(0,n);    //���ú��� 
//            printf("�����\n");
//            for(i=1;i<n;i++)      //ѭ����� 
//                printf("%d ",a[i]);
//            printf("%d(����)\n\n\n\n",a[i]);
//        }
//        else if(choice==2)
//        {
//            printf("������Ҫ��������ָ���:\n");
//            scanf("%d", &n);
//            printf("������%d������:\n", n);
//            for(int ii=0;ii<n;ii++)
//                scanf("%d",&a[ii]);
//            kuaisu_jiang(0,n);
//            printf("�����\n");
//            for(i=0;i<n-1;i++)
//                printf("%d ",a[i]);
//            printf("%d(����)\n\n\n\n",a[i]);
//        }
//        else
//            printf("����Ц��!\n");
//
//        printf("��������С����(By STY)\n\n");
//        printf("�����ǽ���\n");
//        printf("����ѡ��1��\n");
//        printf("����ѡ��2��\n");
//        printf("������:(1~2)\n");
//        printf("�˳��밴��0��(�ڼ�����)�������س���ллʹ�ã�\n");      
//    }
//    return 0;   
//}
//ENDING 
