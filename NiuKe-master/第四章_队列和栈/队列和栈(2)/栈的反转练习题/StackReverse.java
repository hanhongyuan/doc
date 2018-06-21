import java.util.Stack;

public class StackReverse {

	public Stack<Integer> stack = new Stack<>();

	public int[] reverseStack(int[] A, int n) {// ��Ϊ����ʹ���������ջ�����Ա��������ջ��ʱ����Ҫ��ĩβѹջ
		for (int i = n - 1; i >= 0; i--) {
			stack.push(A[i]);
		}

		reverse(stack);// ����

		for (int i = 0; i < n; i++) {// ��Ԫ�ط��ظ�����
			A[i] = stack.peek();
			stack.pop();
		}

		return A;
	}

	public int get(Stack<Integer> s) {// �ݹ麯��������ɾ��ջ��Ԫ�ز�����ջ��Ԫ��
		int result = s.pop();
		if (s.isEmpty()) {
			return result;
		} else {
			int last = get(s);
			s.push(result);
			return last;
		}
	}

	public void reverse(Stack<Integer> s) {// ������
		if (s.empty()) {
			return;
		}
		int last = get(s);// ÿ�εݹ��ȡ��ǰջ�е�ջ��Ԫ�أ�Ȼ�����ʱ����ѹ��ջ�о���ɵ���Ĳ����ˡ�
		reverse(s);
		s.push(last);
	}
}