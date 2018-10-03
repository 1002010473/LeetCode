/*
 ���ʽ��ֵ����ת������׺���ʽ�Ĺ���֮�У�ʵ������

*/
#include<iostream>
#include "header.h"
#include<string>
#include<stack>
#include<queue>
using namespace std;
//��������������ȼ���ֵ
int precedence_value(char ch)
{
	int val = -100;
	switch (ch)
	{
	case '(': {    //���������ȼ����
		val = -1;
		break;
	}
	case '+':
	case '-': {
		val = 1;
		break;
	}
	case '*':
	case '/': {
		val = 2;
		break;
	}
	default: {
		val = -100;
		break;
	}
	}
	return val;
}
//�жϷ��ŵ����ȼ� a>b true 
bool higher_precedence(char a, char b)
{
	return precedence_value(a)>precedence_value(b);
}

int cal(int a,int b,char opr)
{
	int rst = 0;
	switch (opr)
	{
	case '+': {
		rst = a + b;
		break;
	}
	case '-': {
		rst = a - b;
		break;
	}
	case '*': {
		rst = a * b;
		break;
	}
	case '/': {
		rst = a / b;
		break;
	}
	}
	return  rst;
}
//��׺infixת���ɺ�׺postfix���ʽ ������������ Shunting-yard algorithm
queue<string> convert(string infix) {
	stack<char> opr_stack;
	queue<string> postfix;
	string unit = "";
	int i = 0;
	while (i < infix.size())
	{
		//�����λ����
		while (i < infix.size() && infix[i] >= '0' && infix[i] <= '9')
		{
			unit += infix[i];
			i++;
		}
		if (unit != "")
		{
			postfix.push(unit);
			unit = "";
		}
		if (i >= infix.size()) break;  //�����һ��λ���Ƿ�Խ��
									   //���������ţ�����������ջ��Ԫ�أ�ֱ��ջ��Ϊ ������
		if (infix[i] == ')')
		{

			while (true)
			{
				if (opr_stack.top() == '(')
				{
					opr_stack.pop();
					break;
				}
				string s(1, opr_stack.top());
				postfix.push(s);
				opr_stack.pop();
			}
		}
		else if (infix[i] == '(' || opr_stack.empty()) {
			//������ջΪ�յ�ǰ������Ϊ'('ʱ��������ֱ����ջ
			opr_stack.push(infix[i]);
		}
		else if (higher_precedence(infix[i], opr_stack.top())) {
			//ջ����Ϊ�յ�ǰ���¡���ǰ���������ȼ�����ջ��������
			opr_stack.push(infix[i]);
		}
		else
		{
			//��ǰ���������ȼ�С��ջ��������������ջ�� ��ǰ����������ջ(��Ϊ��֪�µ�ջ���͵�ǰ�����������ȼ���ϵ��continueһ�£������ж�һ��)
			string s(1, opr_stack.top());
			postfix.push(s);
			opr_stack.pop();
			continue; //������i++,������ͷִ�бȽ�һ�µ�ǰ����������ջ����Ԫ�����ȼ���ϵ
					  //opr_stack.push(infix[i]);  
		}
		i++;
	}

	while (!opr_stack.empty())
	{
		string s(1, opr_stack.top());
		postfix.push(s);
		opr_stack.pop();
	}
	return postfix;
}

//��׺infixת���ɺ�׺postfix���ʽ ������������ Shunting-yard algorithm
int calcaulate(string infix) {
	stack<int> value_stack;
	stack<char> opr_stack;
	string unit = "";
	unsigned int i = 0;
	int a, b;//������ʱ��ֵ���ڱ���ջ����ջ��
	while (i < infix.size())
	{
		//�����λ����
		while (i < infix.size() && infix[i] >= '0' && infix[i] <= '9')
		{
			unit += infix[i];
			i++;
		}
		if (unit != "")
		{
			value_stack.push(stoi(unit));
			cout << "��ջ��" << stoi(unit) << "ջ��" << value_stack.top()<<endl;
			unit = "";
		}
		if (i >= infix.size()) break;  //�����һ��λ���Ƿ�Խ��
									  						  
		if (infix[i] == ')')  //���������ţ�����������ջ��Ԫ�أ�ֱ��ջ��Ϊ ������
		{

			while (true)
			{
				if (opr_stack.top() == '(')
				{
					opr_stack.pop();
					break;
				}
				a = value_stack.top();
				value_stack.pop();
				b = value_stack.top();
				value_stack.pop();
				value_stack.push(cal(b, a, opr_stack.top()));  //ע���� ��ջ�� ��ǰ��ջ���ں�
				cout << "��ֵ��" << "ջ��" << value_stack.top() << endl;
				opr_stack.pop();
			}
		}
		else if (infix[i] == '(' || opr_stack.empty()) {
			//������ջΪ�յ�ǰ������Ϊ'('ʱ��������ֱ����ջ
			opr_stack.push(infix[i]);
		}
		else if (higher_precedence(infix[i], opr_stack.top())) {
			//ջ����Ϊ�յ�ǰ���¡���ǰ���������ȼ�����ջ��������
			opr_stack.push(infix[i]);
		}
		else
		{
			a = value_stack.top();
			value_stack.pop();
			b = value_stack.top();
			value_stack.pop();
			value_stack.push(cal(b, a, opr_stack.top()));
			cout << "��ֵ��" << "ջ��" << value_stack.top() << endl;
			opr_stack.pop();
			continue; 
		}
		i++;
	}

	while (!opr_stack.empty())
	{
		a = value_stack.top();
		value_stack.pop();
		b = value_stack.top();
		value_stack.pop();
		value_stack.push(cal(b, a, opr_stack.top()));
		cout << "��ֵ��" << "ջ��" << value_stack.top() << endl;
		opr_stack.pop();
	}
	return value_stack.top();
}

