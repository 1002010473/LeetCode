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
// ϣ������
void ShellSort(int data[MAX_LARGE]);
// �鲢����
void MergeSort(int data[MAX_LARGE]);
// ��������
void QuikSort(int data[MAX_LARGE]);
// ������
void HeapSort(int data[MAX_LARGE]);

// ��������
void Exchange(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Print(int data[MAX_LARGE], int n)
{
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void SelectSort(int data[MAX_LARGE], int n)
{
     // ����˼�룺�Ӻ��棨��������ѡ����С��Ԫ�طŵ�ǰ��(��������β��)
     // i ��¼�ź����λ�ã�j ��������ѡ����СԪ�ص�index
     int min_index;

     for(int i = 0; i < n; i++) {
        min_index = i;
        for(int j = i+1; j < n; j++) {
            if(data[j] < data[min_index]) {
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

    while(flag) {
        flag = false;
        for(i = 0; i < n - 1; i++) {
            if(data[i] > data[i+1]) {
                Exchange(data[i], data[i+1]);
                flag = true;
            }
        }
    }
}

void InsertSort(int data[MAX_LARGE], int n)
{
    // ����˼�룺�����Ϊ�����������Ҳ���������Ԫ�ز��뵽��ࣨ��Ƶ�λ�õ����κ��ƣ�
    // i �������߽� �� j ���������ƶ�������������Ԫ��
    int i, j;
    int temp;
    for(i = 0; i < n - 1; i++) {
        j = i;
        temp = data[i+1];
        while(j > 0 && data[j] > temp) {
            data[j+1] = data[j]; //����
            j--;
        }
        data[j+1] = temp;
    }
}

int main()
{
    int data[10] = {2, 8, 3, 7, 9, 0, 12, 33, 4, 1};
    // SelectSort(data, 10);
    // BubbleSort(data, 10);
    InsertSort(data, 10);
    Print(data, 10);
}
