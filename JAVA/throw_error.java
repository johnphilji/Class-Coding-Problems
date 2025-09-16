import java.util.Scanner;

public class throw_error {
    static void checkAge(int age){
        if(age < 18){
            throw new ArithmeticException("Access Denied - You must be atleast 18 years old.");
        }else{
            System.out.println("Access granted - You are old enough!");
        }
    }
    public static void main(String args[]){
        Scanner s1 = new Scanner(System.in);
        System.out.println("Enter Age to check: ");
        int age = s1.nextInt();
        checkAge(age);
    }
}
