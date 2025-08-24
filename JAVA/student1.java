import java.util.Scanner;

public class student1 {
    int roll_no;
    String name;

    student1(int roll_no, String name){
        this.roll_no = roll_no;
        this.name = name;
    }

    public void display(){
        System.out.println("Roll no :"+roll_no+" Name : "+name);
    }

    class Result extends student1{

        float m1, m2, m3;
        Result(int roll_no, String name, float m1, float m2, float m3){
            super(roll_no, name);
            this.m1 = m1;
            this.m2 = m2;
            this.m3 = m3;
        }

        public float calculate(){
            float percent = (m1+m2+m3)/300 *100;
            return percent;
        }

        public void display(){
            super.display();
            System.out.println("Marks: "+m1+", "+m2+", "+m3);
            System.out.println("Percentage: " +calculate()+ "%");
        }
    }

    
}






// import java.util.Scanner;

// public class Student1 {
//     int roll_no;
//     String name;

//     // Constructor to initialize roll number and name
//     Student1(int roll_no, String name) {
//         this.roll_no = roll_no;
//         this.name = name;
//     }

//     // Method to display student info
//     public void display() {
//         System.out.println("Roll no: " + roll_no + " Name: " + name);
//     }

//     // Inner class Result, extending Student1
//     class Result extends Student1 {
//         float m1, m2, m3;

//         // Constructor to initialize marks and call the superclass constructor
//         Result(int roll_no, String name, float m1, float m2, float m3) {
//             super(roll_no, name); // Call the superclass constructor
//             this.m1 = m1;
//             this.m2 = m2;
//             this.m3 = m3;
//         }

//         // Method to calculate percentage
//         public float calculate() {
//             float total = m1 + m2 + m3;
//             float percent = (total / 300) * 100; // Calculate percentage out of 100
//             return percent;
//         }

//         // Overriding the display method to show marks and percentage
//         @Override
//         public void display() {
//             super.display(); // Call the superclass display method to print student info
//             System.out.println("Marks: " + m1 + ", " + m2 + ", " + m3);
//             System.out.println("Percentage: " + calculate() + "%");
//         }
//     }

//     public static void main(String[] args) {
//         // Creating an instance of Student1
//         Scanner sc = new Scanner(System.in);

//         // Get student information
//         System.out.print("Enter Roll Number: ");
//         int roll_no = sc.nextInt();
//         sc.nextLine(); // Consume the newline
//         System.out.print("Enter Name: ");
//         String name = sc.nextLine();

//         // Create an instance of Result (inner class)
//         Student1 student = new Student1(roll_no, name);
//         Result result = student.new Result(roll_no, name, 85.5f, 90.0f, 78.0f);

//         // Display student and result info
//         result.display();

//         sc.close();
//     }
// }
