#define _CRT_SECURE_NO_WARNINGS 

#include "head.h"

void test1()
{
	int n = 0;
	while (~scanf("%d", &n))
	{
		int answer = 0;
		int tmp = 0;
		while (n--)
		{
			scanf("%d", &tmp);
			answer ^= tmp;
		}
		printf("%d\n", answer);
	}
}


int findPeakElement(int* nums, int numsLen) {
	// write code here
	int i = numsLen;
	while (numsLen)
	{
		if (nums[numsLen - 2] > nums[numsLen - 1] && nums[numsLen - 2] > nums[numsLen - 3])
		{
			return numsLen - 2;
		}
		else if (nums[numsLen - 2] < nums[numsLen - 1] && numsLen - 1 == i - 1)
		{
			return numsLen - 1;
		}
		else if (nums[numsLen - 3] > nums[numsLen - 2] && numsLen - 3 == 0)
		{
			return numsLen - 3;
		}
		else if (nums[numsLen - 2] < nums[numsLen - 3])
		{
			numsLen--;
			continue;
		}
		else if (nums[numsLen - 2] > nums[numsLen - 3])
		{
			numsLen -= 2;
			continue;
		}
	}
	return 0;
}

void test2()
{
	int arr[] = { 2,4,1,2,9,8,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d", findPeakElement(arr, len));
}


void test3()
{
	long n = 0, k = 0;
	while (~scanf("%ld %ld", &n, &k))
	{
		if (k == 0)
		{
			printf("%ld\n", n * n);
			continue;
		}
		long count = 0;
		for (long y = k + 1; y <= n; y++)
		{
			count += ((n / y) * (y - k)) + ((n % y < k) ? 0 : (n % y - k + 1));
		}
		printf("%ld\n", count);
	}
}

void test4()
{
	char arr[100];
	int k = 0;
	while (scanf("%s", arr) != EOF)
	{
		scanf("%d", &k);
		arr[k] = '\0';
		printf("%s\n", arr);
	}
}

int lengthOfLongestSubstring(char* s) {
	int len = strlen(s);
	int map[127] = { 0 };
	int l = 0;//leftSide
	int r = 0;//rightSide
	int max = 0;
	while (r < len)
	{
		if (map[s[r]] == 0)
		{
			map[s[r++]]++;
		}
		else
		{
			map[s[l++]]--;
		}
		max = r - l > max ? r - l : max;
	}
	return max;
}

char* convert_success(char* s, int numRows) {
	if (numRows == 1) return s;

	int step = numRows * 2 - 2; // ���
	int index = 0;// ��¼s���±�
	int len = strlen(s);
	int add = 0; // ��ʵ�ļ��
	char static ret[1000] = { 0 };
	int k = 0;
	for (int i = 0; i < numRows; i++) // i��ʾ�к�
	{
		index = i;
		add = i * 2;
		while (index < len)//�����ַ������ȼ�����һ��
		{
			ret[k] = s[index]; // ��ǰ�еĵ�һ����ĸ
			k++;
			add = step - add;// ��һ�μ����step -2*i���ڶ�����2*i, 
			index += (i == 0 || i == numRows - 1) ? step : add; // 0�к����һ��ʹ��step��࣬����ʹ��add���
		}
	}
	ret[k] = '\0';
	return ret;
}

char* convert_false(char* s, int numRows) {
	if (numRows == 1) return s;

	int step = numRows * 2 - 2; // ���
	int index = 0;// ��¼s���±�
	int len = strlen(s);
	int add = 0; // ��ʵ�ļ��
	char* ret = (char*)malloc(sizeof(char) * len);
	int k = 0;
	for (int i = 0; i < numRows; i++) // i��ʾ�к�
	{
		index = i;
		add = i * 2;
		while (index < len)//�����ַ������ȼ�����һ��
		{
			ret[k] = s[index]; // ��ǰ�еĵ�һ����ĸ
			k++;
			add = step - add;// ��һ�μ����step -2*i���ڶ�����2*i, 
			index += (i == 0 || i == numRows - 1) ? step : add; // 0�к����һ��ʹ��step��࣬����ʹ��add���
		}
	}
	ret[k] = '\0';
	return ret;
}


int reverse(int x) {
	int tmp = 0;
	int y = 0;
	int arr[31] = { 0 };
	for (tmp = 0; x != 0; tmp++)
	{
		arr[tmp] = (x % 10);
		x /= 10;
	}
	for (int i = 0; i < tmp; i++)
	{
		if (y < INT_MIN / 10 || y > INT_MAX / 10) {
			return 0;
		}
		y = y * 10 + arr[i];

	}
	return y;
}

int reverse_2(int x) {
	int rev = 0;
	while (x != 0) {
		if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
			return 0;
		}
		int digit = x % 10;
		x /= 10;
		rev = rev * 10 + digit;
	}
	return rev;
}


int isPalindrome(int x) {
	char a[100];

	sprintf(a, "%d", x);//������x��ת��Ϊ�ַ�������a��

	int left = 0, right = 0;//������ͷβ���������ж������������������
	right = strlen(a) - 1;//�����0��ʼ����һλ

	for (right, left; right > left; right--, left++)
		//���ͷβ�ֱ������жϣ�ͷ������++��β������--������ͷ������������β����������˵���ж����
	{
		if (a[right] != a[left])
		{
			return 0;
		}
	}
	return 1;
}


int maxArea(int* height, int heightSize) {
	int l = 0, r = heightSize - 1;
	int max = 0;
	while (l < r)
	{
		max = max > (height[l] > height[r] ? height[r] : height[l]) * (r - l) ? max : (height[l] > height[r] ? height[r] : height[l]) * (r - l);
		if (height[l] < height[r])
		{
			l++;
		}
		else if (height[l] > height[r])
		{
			r--;
		}
		else
		{
			l++;
			r--;
		}
	}
	return max;
}

const int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
const char* symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

char* intToRoman(int num) {
	char* roman = malloc(sizeof(char) * 16);
	roman[0] = '\0';
	for (int i = 0; i < 13; i++) {
		while (num >= values[i]) {
			num -= values[i];
			strcpy(roman + strlen(roman), symbols[i]);
		}
		if (num == 0) {
			break;
		}
	}
	return roman;
}


int is_space(char* str)
{
	if (*str == ' ')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int my_atoi(const char* arr)
{
	assert(arr);
	if (*arr == '\0')
	{
		return 0;
	}
	while (is_space(arr))
	{
		arr++;
	}
	int flag = 1;
	if (*arr == '+')
	{
		flag = 1;
		arr++;
	}
	else if (*arr == '-')
	{
		flag = -1;
		arr++;
	}

	long long sum = 0;
	while (isdigit(*arr))
	{
		sum = sum * 10 + (*arr - '0') * flag;
		if (sum > INT_MAX || sum < INT_MIN)
		{
			return 0;
		}
		arr++;
	}
	if (*arr == '\0')
	{
		status = VALID;
		return (int)sum;
	}
	return (int)sum;
}

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
	{
		return 0;
	}
	int quick = 1;
	int con = 1;
	while (quick < numsSize)
	{
		if (nums[quick - 1] != nums[quick])
		{
			nums[con] = nums[quick];
			con++;
		}
		quick++;
	}
	return con;
}

void test(int* a, int* b)
{
	for (int i = 0; i < 2; i++)
	{
		printf("%d\n", a[i]);
	}
}

int compare_int(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	assert(nums1 && nums2);
	int nums = nums1Size + nums2Size;
	int* nums0 = (int*)malloc(sizeof(int) * (nums));
	assert(nums0);
	for (int i = 0; i < nums1Size; i++)
	{
		nums0[i] = nums1[i];
	}
	for (int i = 0; i < nums2Size; i++)
	{
		nums0[i+ nums1Size] = nums2[i];
	}
	qsort(nums0, nums1Size + nums1Size,sizeof(nums0[0]), compare_int);
	if ((nums1Size + nums2Size) % 2 == 0)
	{
		return (nums0[nums1Size - 1] + nums0[nums1Size]) / 2.0;
	}
	int n = (nums1Size + nums2Size) / 2 +1;
	return nums0[n]/1.0;
}



double findMedianSortedArrays_success(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int length = nums1Size + nums2Size;
	int p = 0, q = 0, pre = -1, next = -1;
	for (int i = 0; i <= length / 2; i++) {
		pre = next;
		if (p < nums1Size && (q >= nums2Size || nums1[p] < nums2[q])) {
			next = nums1[p];
			p++;
		}
		else {
			next = nums2[q];
			q++;
		}
	}
	if (length % 2 == 0)
		return (pre + next) / 2.0;
	return next;

}

int addDigits(int num) {
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
		if (sum < 10 && num == 0)
		{
			break;
		}
		if (sum > 10 && num == 0)
		{
			num = sum;
			sum = 0;
		}
	}
	return sum;
}

int addDigits_process(int num) {
	return (num - 1) % 9 + 1;
}


int comp(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int threeSumClosest(int* nums, int numsSize, int target) {
	int n = numsSize;
	assert(nums);
	qsort(nums, numsSize, sizeof(nums[0]), comp);
	int best = nums[0] + nums[1] + nums[2];
	for (int i = 0; i < n - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int l = i + 1;
		int r = n - 1;
		while (l < r)
		{
			int sum = nums[i] + nums[l] + nums[r];
			if (abs(sum - target) < abs(best - target))
			{
				best = sum;
			}
			if (sum == target)
			{
				return sum;
			}
			if (sum < target)
			{
				l++;
				while (nums[l - 1] == nums[l] && l < r)
				{
					l++;
				}
			}
			else
			{
				r--;
				while (nums[r] == nums[r + 1] && l < r)
				{
					r--;
				}

			}
		}
	}
	return best;
}

char* convertToBase7(int num) {
	char* ret = (char*)malloc(sizeof(char) * 33);
	char tmp = '0';
	int flag = 1;
	if (num < 0)
	{
		flag = -1;
		num *= -1;
	}
	if (num == 0)
	{
		return "0";
	}
	int i = 0;
	while (num>0)
	{
		ret[i++] = num % 7 + '0';
		num /= 7;
	}
	if (flag == -1)
	{
		ret[i++] = '-';
	}
	ret[i] = '\0';
	int k = 0;
	while (k<i)
	{
		tmp = ret[--i];
		ret[i] = ret[k];
		ret[k++] = tmp;
	}

	return ret;
}

int decided(char* s, int l, int r)
{
	while (l >= 0 && r < strlen(s) && s[l] == s[r])
	{
		l--;
		r++;
	}
	return r - l - 1;
}


char* longestPalindrome(char* s) {
	int len = strlen(s);
	if (len == 0 || len == 1)
	{
		return s;
	}
	int max = 0;
	int start = 0;
	for (int i = 1; i < len; i++)
	{
		int len1 = decided(s, i - 1, i + 1);
		int len2 = decided(s, i - 1, i);
		if (max < (len1 > len2 ? len1 : len2))
		{
			max = (len1 > len2 ? len1 : len2);
			start = i - max / 2;
		}
	}
	*(s + start + max) = '\0';
	return s + start;
}

int bestRotation(int* nums, int numsSize) {
	int k = 0;
	int* arr = (int*)malloc(sizeof(int) * numsSize);
	int best = 0;
	int sum = 0;
	int key = 0;
	while (k < numsSize)
	{
		sum = 0;
		for (int i = 0; i < numsSize; i++)
		{
			arr[i] = i - k;
			if (arr[i] < 0)
			{
				arr[i] = numsSize + arr[i];
			}
			if (arr[i] >= nums[i])
			{
				sum++;
			}
		}
		//for (int j = 0; j < numsSize; j++)
		//{
		//	if (arr[j] >= nums[j])
		//	{
		//		sum++;
		//	}
		//}
		if (best < sum)
		{
			key = k;
			best = sum;
		}
		k++;
	}
	return key;
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int* ret = (int*)malloc(sizeof(int) * 2);
	ret[0] = -1;
	ret[1] = -1;
	int left = 0;
	int right = numsSize - 1;
	while (nums[left++] < target);
	while (nums[right--] > target);
	if (nums[left] == target)
	{
		ret[0] == left;
		while (nums[left] == target)
		{
			left++;
		}
		return ret;
	}
	if (nums[right] == target)
	{
		ret[1] = right;
		while (nums[left] == target)
		{
			right--;
		}
		return ret;
	}
	return ret;
}
