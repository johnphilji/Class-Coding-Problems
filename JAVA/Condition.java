import java.util.Scanner;

public class Condition{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Percentage: ");
		float a = sc.nextFloat();
		if(a>=75){
			System.out.println("Distinction");
			}
		else if(a>=60){
			System.out.println("Merit");
			}
		else if(a>=40){
			System.out.println("Pass");
			}
		else{
			System.out.println("Fail");
			}
	}
}
