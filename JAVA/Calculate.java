// 2. Function with parameter, but no return type
// public class Calculate{
//     public static void add(int c, int d){
//         int sum = c+d;
//         System.out.println("The sum is: " +sum);
//     }
//     public static void main(String[] args) {
//         int a,b;
//         a=10;
//         b=20;
//         add(a,b);
//     }
// }


// 3. Function with parameter and return type
// public class Calculate{
//     public static int add(int c, int d){
//         int sum = c+d;
//         return sum;
//     }
//     public static void main(String[] args) {
//         int a,b;
//         a=10;
//         b=20;
//         int S = add(a,b);
//     }
// }


// 4. Function with no parameters, but having a return type.
// public class Calculate{
//     public static int add(){
//         int a=10,b=20;
//         return a+b;
//     }

//     public static void main(String[] args) {
//         int s = add();
//         System.out.println("The sum is: "+s);
//     }
// }



// Method Overloading - class having a method with same name but different parameters.
public class Calculate{
    public static int add(int a, int b){
        int sum = a+b;
        return sum;
    }

    public static int add(int a, int b, int c){
        int sum = a+b+c;
        return sum;
    }

    public static float add(float a, float b){
        float sum = a+b;
        return sum;
    }

    public static void main(String args[]){
        float S = add(10,20);
        System.out.println("The sum is: " + S);
           
    }
}