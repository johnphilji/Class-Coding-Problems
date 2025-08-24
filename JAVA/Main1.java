import java.util.Scanner;

public class Main1{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a Number: ");
		int a = sc.nextInt();
		sc.nextLine();
		System.out.print("Enter a Word: ");
		String name = sc.nextLine();
		System.out.println("Name is: "+name+" and Number is: " +a);
		
		}
	}
