import java.util.Scanner;

public class Letter{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter your favourite Word: ");
		char letter = sc.next().charAt(0);
		System.out.println("Favourite letter: "+letter);
		
		}
	}
