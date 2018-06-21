import java.util.*;
 
public class Translation {
	public String stringTranslation(String A, int n, int len) {
		String result = "";
		result = reverseString(A, 0, len - 1);//��0��len-1֮�䷴ת
		result = reverseString(result, len, n - 1);//��len��n-1֮�䷴ת
		result = reverseString(result, 0, n - 1);//�����ַ�����ת
		return result;
	}
	//�ַ�����ת���� ��begin �� end֮����з�ת
	public String reverseString(String str, int begin, int end) {

		char[] chars = str.toCharArray();
		while (begin < end) {
			char temp = chars[begin];
			chars[begin] = chars[end];
			chars[end] = temp;
			end--;
			begin++;
		}
		return String.valueOf(chars);
	}
}