#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        	stack<int> s;// ԭʼ����ջ,��������ջ
		stack<int> help;// ����ջ
		
		for(int i=numbers.size()-1;i>=0;i--){// ��ʼ��ջ
			s.push(numbers[i]);
		}

		while(!s.empty()){// ������ջ����ʱ һֱ����Ԫ��
			int top=s.top();
			s.pop();

			if(help.empty()||top>=help.top()){// ��ʱ����ջ��ջ��Ԫ��С������ջ��Ԫ��ʱ��ѹջ
				help.push(top);
				continue;
			}

			while(!help.empty()&&top<help.top()){// ������ջ��Ԫ��һֱ��������ջ��Ԫ����һֱ��������ջԪ��
				s.push(help.top());
				help.pop();
			}

			help.push(top);
		}

		vector<int> res;
		while(!help.empty()){
			res.push_back(help.top());
			help.pop();
		}

		return res;
    }
};
