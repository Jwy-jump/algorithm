/*********************************************************/
/*�i�{���W�١j: 8_b_sort.c                               */
/*�i�{���\��j: ��w�B�@�ƧǪk�Ы��u��Ȥ�����v�Ƨ�     */
/*       ��J : �@�ե��g�ƧǪ�������                   */
/*       ��X : �C�@�^�X�ƧǤ����G                       */
/*�i��Ƶ��c�j: �}�C���c                                 */
/*********************************************************/
/*�i�ܼƦW�٤Υγ~�j                                     */
/*        d[] : �x�s�ݱƧǪ���ȥH�αƧǹL�{���C�@�^�X�� */
/*              ���G                                     */
/*     Size,n : �}�C d ���j�p(�����Ӽ�)                  */
/*********************************************************/

#include <stdio.h>
#define Size 8
#define MY_SIZE 8 


void print_org_data(const int d[], int n);
void print_array_data(const int d[], int n);
void swap(int *x, int *y);
void bubble_sort_ascending(int d[], int n);



/*------------------------------------------------*/
/*   �C�L�Ƨǫe����ȸ��(�}�C d �@�� n �Ӥ���)   */
/*------------------------------------------------*/
void print_org_data(const int d[], int n)
{
	int i;

	//clrscr();
	printf("�}�C����   d[0] [1] [2] [3] [4] [5] [6] [7] \n");
	printf("----------------------------------------------\n");
	printf("<�Ƨǫe> ==> ");
	for (i = 0; i < n; i++){
		printf("%2d  ", d[i]);
	}
	printf("\n----------------------------------------------\n");
}

/*---------------------------------------------*/
/*   �L�X�}�C d �����e(�}�C d �@�� n �Ӥ���)   */
/*---------------------------------------------*/
void print_array_data(const int d[], int n)
{
	int i;

	for (i = 0; i < n; i++){
		printf("%2d  ", d[i]);
	}
	printf("\n");
}

/*---------------------------*/
/*   �N x,y ���ܼƤ��Ȥ���   */
/*---------------------------*/
void swap(int *x, int *y)
{
	int z = *x;

	*x = *y;
	*y = z;
}

/*-------------------------------*/
/*   ��w�B�@�ƧǪk              */
/*     1.�}�C d �@�� n �Ӥ���    */
/*     2.���u��Ȥ�����v�Ƨ�    */
/*-------------------------------*/
void bubble_sort_ascending(int d[], int n)
{
	int i, j;
	char isswap = 'Y';

	for (i = 0; i < n - 1 && isswap == 'Y'; i++){
		isswap = 'N';
		for (j = 0; j < n - 1; j++){
			if (d[j] > d[j + 1]){
				swap(&d[j], &d[j + 1]);
				isswap = 'Y';
			}
		}
		printf(" ��%d�^�X ==> ", i + 1);
		print_array_data(d, n);
	}
}




void b_main_test(void)
{
	int d[Size] = { 83, 66, 55, 21, 88, 18, 88, 99 };
	print_org_data(d, Size);
	return;
}


void my_swap(int *a, int *b){
	int z = *b;
	*b = *a;
	*a = z;
}

void my_bubble_sort(int *d, int n)
{
	int i = 0;
	int j = 0;
	int swap = 0;

	printf("original array: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", d[i]);
	}
	printf("\n");

	for (i = 0; i < (n - 1); i++)
	{
		swap = 0;
		for (j = 0; j < (n - 1); j++){
			if (d[j] > d[j + 1]){
				my_swap(&d[j], &d[j + 1]);
				swap = 1;
			}
		}
		if (swap == 0)
			break;
	}

	printf("sorted array: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", d[i]);
	}
	printf("\n");
}



void b_my_test(void)
{
	int data[] = { 9, 89, 6, 7, 3, 3, 6, 4 };
	my_bubble_sort(data, MY_SIZE);
	return;
}