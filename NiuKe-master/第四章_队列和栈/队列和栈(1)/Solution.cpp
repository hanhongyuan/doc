class Solution {//������õĺ�JAVA��ʵ�ַ�����һ�㲻һ������Сֵջ�л���������ջ��һ�����Ԫ��
public:
    stack<int>stack_data;//����ջ
    stack<int>stack_min;//��Сֵջ
          
    void push(int value) {
        stack_data.push(value);
        if(stack_min.empty()||value<stack_min.top())//��ǰԪ��С����Сֵջ��Ԫ��ʱ���뵱ǰԪ�أ����������Сֵջ��Ԫ��(�����в�ͬ)
            {
            stack_min.push(value);
        }
        else stack_min.push(stack_min.top());
    }
    void pop() {
        if(!stack_data.empty()){//����Ԫ�أ���ͬ�ж�ֱ��һ�𵯳�(�����в�ͬ)
            stack_data.pop();
            stack_min.pop();
        }
    }
    int top() {
        return stack_data.top();
    }
    int min() {
    return stack_min.top();
    }
};