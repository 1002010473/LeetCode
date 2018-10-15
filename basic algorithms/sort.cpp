/**
 * ���������㷨��ʵ��
 *
 * ѡ������ð�����򡢲�������
 * ϣ�����򡢹鲢���򡢿������򡢶�����
 *
 * ��С�������� n > 1
 */

#include<iostream>
using namespace std;

const int MAX_LARGE = 100;

// ѡ������
void SelectSort(int data[MAX_LARGE], int n);
// ð������
void BubbleSort(int data[MAX_LARGE], int n);
// ��������
void InsertSort(int data[MAX_LARGE], int n);
// ϣ�����򣨻��ڲ�������
void ShellSort(int data[MAX_LARGE], int n);
// �鲢����
void MergeSort(int data[MAX_LARGE], int low, int high);
// ��������
void QuikSort(int data[MAX_LARGE], int low, int high);
// ������
void HeapSort(int data[MAX_LARGE], int n);

// ��������
void Exchange(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Print(int data[MAX_LARGE], int n)
{
	for (int i = 0; i < n; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

void SelectSort(int data[MAX_LARGE], int n)
{
	// ����˼�룺�Ӻ��棨��������ѡ����С��Ԫ�طŵ�ǰ��(��������β��)
	// i ��¼�ź����λ�ã�j ��������ѡ����СԪ�ص�index
	int min_index;

	for (int i = 0; i < n; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (data[j] < data[min_index]) {
				min_index = j;
			}
		}
		Exchange(data[i], data[min_index]);
	}
}

void BubbleSort(int data[MAX_LARGE], int n)
{
	// һ����һ��Ľ�������Ԫ�أ�ֱ������
	int flag = true; // �Ƿ񽻻���Ԫ�أ��Ƿ�ð�ݣ�
	int i;

	while (flag) {
		flag = false;
		for (i = 0; i < n - 1; i++) {
			if (data[i] > data[i + 1]) {
				Exchange(data[i], data[i + 1]);
				flag = true;
			}
		}
	}
}

void InsertSort(int data[MAX_LARGE], int n)
{
	// ����˼�룺�����Ϊ�����������Ҳ���������Ԫ�ز��뵽��ࣨ��Ƶ�λ�õ����κ��ƣ�
	// i �������߽� �� j ���������ƶ����Ӻ���ǰ���ҵ����ʵ�λ�ã�������������Ԫ��
	// ����һ��ʵ�ַ��������ǴӺ���ǰ��������Ľ���
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		j = i;
		temp = data[i + 1];
		while (j >= 0 && data[j] > temp) {          // ע��˴�j��ȡֵ
			data[j + 1] = data[j]; //����
			j--;
		}
		data[j + 1] = temp;
	}

}

void ShellSort(int data[MAX_LARGE], int n)
{
	// ����˼�룺�Բ����ڵ�Ԫ�أ��м��h�����в�������Ȼ�����̼����1
	// ������̼�����У��������У�ϣ�������ֽ���С�����������򣩣���ר�ŵ��о�������Ҫ�Լ���ƣ�ѡ��ĳЩ���õļ���
	int h = 1;
	int temp;
	int i, j;

	// ����h�ĳ�ʼֵ
	while (h < n / 3) h = h * 3 + 1;  // �������� 1, 4, 13, 40, 121, 364 .....

	while (h >= 1) {
		// �����������ÿ���ƶ�1����Ϊ�ƶ�h
		for (i = 0; i < n - h; i++) {
			j = i;
			temp = data[i + h];
			while (j >= 0 && data[j] > temp) {
				data[j + h] = data[j];
				j -= h;
			}
			data[j + h] = temp;
		}
		h /= 3;
	}
}
// ԭ�ع鲢��low�����½磬high�����Ͻ�
void Merge(int data[MAX_LARGE], int low, int mid, int high)
{
	// ԭ�ع鲢������һ�����飬����ǰ��벿�֣�������С���󣩣��鲢��һ����������
	int i = low, j = mid + 1;  // j ������mid+1����Ϊ mid�п��ܺ�low���
	int *aux = new int[high + 1];  // ��������

	for (int k = low; k <= high; k++)
		aux[k] = data[k];

	// ���鲢�Ľ���ŵ�ԭ������
	for (int k = low; k <= high; k++) {
		if (i > mid) // ǰ�벿�ֹ鲢���
			data[k] = aux[j++];
		else if (j > high) // ��벿�ֹ鲢���
			data[k] = aux[i++];
		else if (aux[i] < aux[j]) // ע���ǱȽϸ������飬���ɱȽ�ԭ���飨��Ϊԭ�����Ѿ��仯�ˣ�
			data[k] = aux[i++];
		else
			data[k] = aux[j++];
	}
}

void MergeSort(int data[MAX_LARGE], int low, int high)
{
	// ���϶��£�����˼�룩
	if (low >= high) return;
	int mid = (low + high) / 2;

	// ���Σ�һ��Ҫ��ע����η֣����ڱ߽�Ҫ�࿼���������
	// MergeSort(data, low, mid-1); // ��mid==0
	// MergeSort(data, mid, high); // ��������»ᵼ�� MergeSort(data, 0, 1)һֱ����

	MergeSort(data, low, mid);
	MergeSort(data, mid + 1, high);
	Merge(data, low, mid, high);
}

// ԭ���з�(���ڱ߽���ж��Ǹ��ѵ�)
int Partition(int data[MAX_LARGE], int low, int high)
{
	// high > low 
	int i = low, j = high;
	while (true) {
		while (data[++i] < data[low]) {// �ҵ�������Ԫ��data[low] ���Ԫ��data[i]
			if (i == high) break;  // ����Խ��
		}
		while (data[j] > data[low]) { // �ҵ�������Ԫ��data[low] С��Ԫ��data[j]
			j--; // ������while�� data[j--] ����Ϊ������ʹdata[j] ������data[low]��Ȼ���Լ�
			if (j == low) break;  // ����Խ��
		}
		if (i >= j) break;  // ��������
		Exchange(data[i], data[j]);
	}
	Exchange(data[low], data[j]);
	return j;
}

void QuikSort(int data[MAX_LARGE], int low, int high)
{
	cout << "low: " << low << " high: " << high << endl;
	if (low >= high) return;
	// �з�
	int pivot = Partition(data, low, high);
	cout << " pivot:" << pivot << endl;
	// �������� ǰ����j--;
	QuikSort(data, low, pivot - 1);
	// �������� �󲿷�
	QuikSort(data, pivot + 1, high);
}
// �����зֿ��������д����ظ�Ԫ��ʱ���㷨Ч�ʺܸߣ�
void QuikSort3Way(int data[MAX_LARGE], int low, int high)
{
	if (low >= high) return;
	// data[low...lt-1] < pivot  data[lt...i-1] == pivot   data[i...gt] δȷ���� data[gt...high] > pivot
	int lt = low;
	int gt = high;
	int i = low + 1;
	int pivot = data[low];
	// if a[i] < pivot a[lt] <-> a[i] lt++ i++
	// if a[i] > pivot a[gt] <-> a[i] gt--
	// if a[i] == pivot i++
	while (i <= gt) {
		if (data[i] < pivot)
			Exchange(data[lt++], data[i++]);
		else if (data[i] > pivot)
			Exchange(data[i], data[gt--]);
		else
			i++;
	}
	QuikSort3Way(data, low, lt - 1);
	QuikSort3Way(data, gt + 1, high);
}

int main()
{
	int data[30] = { 121, 18, 3, 7, 9, 11, 612, 133, 4, 1, 6, 8, 13, 7, 39, 0, 162, 33, 4, 5, 2, 8, 55, 63, 49, 0, 12, 33, 4, 14 };
	// SelectSort(data, 30);
	// BubbleSort(data, 30);
	// InsertSort(data, 30);
	// ShellSort(data, 30);
	// Print(data, 30);
	// int merge_data[] = {110, 37};
	int data2[] = { 5, 6, 4 };
	QuikSort3Way(data, 0, 30 - 1);
	Print(data, 30);
}

