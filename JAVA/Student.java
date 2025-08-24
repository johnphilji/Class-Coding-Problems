import java.util.Scanner;

public class Student {
    String name;
    int roll_no;

    public void show(){
        System.out.println("Roll no: "+roll_no);
        System.out.println("Name: "+name);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter no. of students");
        int n = sc.nextInt();
        Student []S = new Student[n];

        for(int i=0; i<n; i++){
            S[i] = new Student();

            System.out.println("Enter Roll No. for student "+(i+1)+":");
            S[i].roll_no = sc.nextInt();

            System.out.println("Enter Name for student "+(i+1)+":");
            sc.nextLine();
            S[i].name = sc.nextLine();

            
        }
        System.out.println("\n");
        for(int i=0; i<n; i++){
            S[i].show();
        }
    }
    
}
