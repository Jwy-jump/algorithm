/*********************************************************/
/*�i�{���W�١j: 8_h_sort.c                               */
/*�i�{���\��j: ��n�ƧǪk�Ы��u��Ȥ����W�v�Ƨ�         */
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

static void print_org_data(const int d[], int n);
static void print_array_data(const int d[], int low, int high);
static void swap(int *x, int *y);
void move_up(int d[], int n);
void move_down(int d[], int n);
int output_and_delete_root(int d[], int *n);
void heap_sort_descending(int d[], int low, int high);


/*------------------------------------------------*/
/*   �C�L�Ƨǫe����ȸ��(�}�C d �@�� n �Ӥ���)   */
/*------------------------------------------------*/
static void print_org_data(const int d[], int n)
{
	int i;

	//  clrscr( );
	printf("�}�C����   d[0] [1] [2] [3] [4] [5] [6] [7] \n");
	printf("----------------------------------------------\n");
	printf("<�Ƨǫe> ==> ");
	for (i = 0; i < n; i++){
		printf("%2d  ", d[i]);
	}
	printf("\n----------------------------------------------\n");
}

/*---------------------------------------------*/
/*   �L�X�}�C d �����e(�q d[low] �� d[high])   */
/*---------------------------------------------*/
static void print_array_data(const int d[], int low, int high)
{
	int i;

	for (i = low; i <= high; i++){
		printf("%2d  ", d[i]);
	}
	printf("\n");
}

/*---------------------------*/
/*   �N x,y ���ܼƤ��Ȥ���   */
/*---------------------------*/
static void swap(int *x, int *y)
{
	int z = *x;

	*x = *y;
	*y = z;
}

/*--------------------------------------------------*/
/*   �q d[n] �`�I����ڰl�ܡA�N�G����վ㬰��n��   */
/*--------------------------------------------------*/
void move_up(int d[], int n)
{
	int temp;

	temp = d[n];
	while (n / 2 > 0 && temp > d[n / 2]){
		d[n] = d[n / 2];
		n /= 2;
	}
	d[n] = temp;
}

/*------------------------------------------*/
/*   �q��� d[1] �}�l�N�G����վ㬰��n��   */
/*------------------------------------------*/
void move_down(int d[], int n)
{
	int i, left;
	int temp;

	temp = d[1];
	i = 1;
	while (i <= n / 2){
		left = 2 * i;
		if (left < n && d[left] < d[left + 1])
			left++;
		if (temp < d[left]){
			d[i] = d[left];
			i = left;
		}
		else break;
	}
	d[i] = temp;
}

/*------------------------------------------------------------*/
/* ��X��ڤ��ȡA�N�̫�@�Ӹ`�I����ȷh���ڡA�A�վ㬰��n�� */
/*------------------------------------------------------------*/
int output_and_delete_root(int d[], int *n)
{
	int root;

	root = d[1];
	swap(&d[1], &d[*n]);
	*n = *n - 1;
	move_down(d, *n);
	return root;
}

/*-------------------------------*/
/*   ��n�ƧǪk                  */
/*     1.�}�C d �@�� n �Ӥ���    */
/*     2.���u��Ȥ����W�v�Ƨ�    */
/*-------------------------------*/
void heap_sort_descending(int d[], int low, int high)
{
	int i, j, n, y[Size + 1], step;

	step = 0;
	/*---------------------------------------------------*/
	/*   �سy����G������x�s�b�}�C y[] ����             */
	/*   (����K�_�� y[0] �O�d���ΡA�H y[1] ����ڦ�m   */
	/*---------------------------------------------------*/
	n = 0;
	for (j = low; j <= high; j++){
		y[++n] = d[j];
		move_up(y, n);
	}
	/*--------------*/
	/*   ��n�Ƨ�   */
	/*--------------*/
	for (i = high; i >= low; i--){
		d[i] = output_and_delete_root(y, &n);
		printf(" ��%d�^�X ==> ", ++step);
		print_array_data(d, low, high);
		printf(" ==> ��X %d\n", d[i]);
	}
}

void heap_main_test(void)
{
	int d[Size] = { 83, 66, 55, 21, 88, 18, 88, 99 };

	print_org_data(d, Size); /* �C�L�Ƨǫe����ȸ�� */

	/* �N�}�C d �̪� d[0] �� d[Size-1] ����ȫ��u��Ȥ�����v�Ƨ� */
	heap_sort_descending(d, 0, Size - 1);
    return;
}


static void my_swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}


static void my_move_up(int *h, int index)
{
	int p_i;
	p_i = index / 2;
	while (p_i > 0 && h[index] > h[p_i])
	{
		my_swap(&h[index], &h[p_i]);
		index = p_i;
		p_i = index / 2;
	}

}

static void my_move_down(int *heap, int index, int high)
{
	int L_child;
	int R_child;
	int is_swapped;
	int largest;

	L_child = index * 2;
	R_child = index * 2 + 1;
	largest = index;
	is_swapped = 0;
	do
	{
		is_swapped = 0;
		index = largest;
		L_child = index * 2;
		R_child = index * 2 + 1;

		if (heap[index] < heap[L_child] && L_child < high)
		{
			largest = L_child;
		}
		if (heap[largest] < heap[R_child] && R_child < high)
		{
			largest = R_child;
		}
		if (largest != index)
		{
			swap(&heap[index], &heap[largest]);
			is_swapped = 1;
		}
	} while (is_swapped);
}

static void my_delete_heapify(int *heap, int low, int high)
{
	my_swap(&heap[low], &heap[high]);
	my_move_down(heap, low, high - 1);

}
void my_heap_sort_descending(int d[], int low, int high)
{
	int i = 0;
	//build MAX HEAP
	int heap[9];
	int size;

	size = high - low + 1;
	for (i = 0; i < size; i++){
		heap[i + 1] = d[i];
		my_move_up(heap, i + 1);
	}
	printf("Max heap data \n");
	print_array_data(heap, 1, 8);
	//delete and repeat
	for (i = 0; i < size; i++){
		printf(" ��%d�^�X ==> ", i);
		print_array_data(heap, 1, 8);
		my_delete_heapify(heap, 1, size - i);

	}
	printf("sorted heap data \n");
	print_array_data(heap, 1, 8);
}


void my_heap_main_test(void)
{
	int d[Size] = { 83, 66, 55, 21, 88, 18, 88, 99 };

	print_org_data(d, Size); /* �C�L�Ƨǫe����ȸ�� */

	/* �N�}�C d �̪� d[0] �� d[Size-1] ����ȫ��u��Ȥ�����v�Ƨ� */
	my_heap_sort_descending(d, 0, Size - 1);
}
