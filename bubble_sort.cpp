/*********************************************************/
/*【程式名稱】: 8_b_sort.c                               */
/*【程式功能】: 氣泡浮昇排序法－按「鍵值不遞減」排序     */
/*       輸入 : 一組未經排序的整數鍵值                   */
/*       輸出 : 每一回合排序之結果                       */
/*【資料結構】: 陣列結構                                 */
/*********************************************************/
/*【變數名稱及用途】                                     */
/*        d[] : 儲存待排序的鍵值以及排序過程中每一回合之 */
/*              結果                                     */
/*     Size,n : 陣列 d 的大小(元素個數)                  */
/*********************************************************/

#include <stdio.h>
#define Size 8
#define MY_SIZE 8 


void print_org_data(const int d[], int n);
void print_array_data(const int d[], int n);
void swap(int *x, int *y);
void bubble_sort_ascending(int d[], int n);



/*------------------------------------------------*/
/*   列印排序前的鍵值資料(陣列 d 共有 n 個元素)   */
/*------------------------------------------------*/
void print_org_data(const int d[], int n)
{
	int i;

	//clrscr();
	printf("陣列元素   d[0] [1] [2] [3] [4] [5] [6] [7] \n");
	printf("----------------------------------------------\n");
	printf("<排序前> ==> ");
	for (i = 0; i < n; i++){
		printf("%2d  ", d[i]);
	}
	printf("\n----------------------------------------------\n");
}

/*---------------------------------------------*/
/*   印出陣列 d 的內容(陣列 d 共有 n 個元素)   */
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
/*   將 x,y 兩變數之值互換   */
/*---------------------------*/
void swap(int *x, int *y)
{
	int z = *x;

	*x = *y;
	*y = z;
}

/*-------------------------------*/
/*   氣泡浮昇排序法              */
/*     1.陣列 d 共有 n 個元素    */
/*     2.按「鍵值不遞減」排序    */
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
		printf(" 第%d回合 ==> ", i + 1);
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