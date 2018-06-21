import java.util.Stack;

public class Solution {

	Stack<Integer> stack_data = new Stack<>();// ������ݵ�ջ
	Stack<Integer> stack_min = new Stack<>();// �����Сֵ��ջ

	public void push(int node) {
		stack_data.push(node);
		if (stack_min.isEmpty() || node < stack_min.peek()) {// ��Ҫ�����Ԫ��С����Сֵջ��Ԫ��ʱ��ִ�в������ջΪ��
			stack_min.push(node);
		}
	}

	public void pop() {
		if (!stack_data.empty()) {// ��ջ��Ϊ��ʱ
			int node = stack_data.peek();
			if (node <= stack_min.peek()) {// ��������Ԫ��С�ڵ�����Сֵջ��Ԫ��ʱ��������Сֵջ��Ԫ�ء�
				stack_min.pop();
			}
			stack_data.pop();
		}
	}

	public int top() {
		return stack_data.peek();
	}

	public int min() {
		return stack_min.peek();
	}
}