import java.util.*;

public class Replacement {
	public String replaceSpace(String iniString, int length) {
		int numOfblank = 0;// �ո�����

		for (int i = 0; i < length; i++) {// ����ո�����
			if (iniString.charAt(i) == ' ') {
				numOfblank++;
			}
		}

		int len = length + numOfblank * 2;// �µ��ַ�������
		char str[] = new char[len];// �����µĿռ�
		int k = len - 1;
		for (int i = length - 1; i >= 0; i--) {// ����ֵ
			if (iniString.charAt(i) == ' ') {
				str[k--] = '0';
				str[k--] = '2';
				str[k--] = '%';
			} else {
				str[k--] = iniString.charAt(i);
			}
		}

		return String.valueOf(str);
	}
}