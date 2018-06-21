import java.util.ArrayList;
import java.util.Stack;

public class TwoStacks {
	public ArrayList<Integer> twoStacksSort(int[] numbers) {
		Stack<Integer> stack = new Stack<>();// ԭʼ����ջ,��������ջ
		Stack<Integer> help = new Stack<>();// ����ջ

		for (int i = numbers.length - 1; i >= 0; i--) {// ��ʼ��ջ
			stack.push(numbers[i]);
		}

		while (!stack.empty()) {// ������ջ����ʱ һֱ����Ԫ��
			int top = stack.peek();
			stack.pop();

			if (help.isEmpty() || top >= help.peek()) {// ��ʱ����ջ��ջ��Ԫ��С������ջ��Ԫ��ʱ��ѹջ
				help.push(top);
				continue;
			}

			while (!help.empty() && help.peek() > top) {// ������ջ��Ԫ��һֱ��������ջ��Ԫ����һֱ��������ջԪ��
				stack.push(help.peek());
				help.pop();
			}

			help.push(top);
		}

		ArrayList<Integer> res = new ArrayList<>();
		while (!help.empty()) {
			res.add(help.peek());
			help.pop();
		}

		return res;
	}
}