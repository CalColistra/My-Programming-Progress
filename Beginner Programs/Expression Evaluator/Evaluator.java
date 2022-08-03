import java.util.Stack;
import java.util.Scanner;

public class Evaluator {
	static Scanner input=new Scanner(System.in);
	
	public static String check() {
		String ans="An error has been found";
		System.out.println("Enter an expression");
		String exp = input.next();
		if(exp.length()<1)return "Expression not found";
		Stack<String> myStack = new Stack<>();
		
		for (int i = 0; i<exp.length();i++) {
			String cur = exp.substring(i,i+1);
			if(myStack.empty() && cur.equals(")")) return ans;
			if(cur.equals("(")) myStack.push(cur);
			else if(cur.equals(")")) myStack.pop();
		}
		
		if(myStack.empty())ans="No error has been found";
		return ans;
	}
	
	
}
