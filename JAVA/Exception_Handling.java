public class Exception_Handling {
    public static void main(String args[]){
        int a=10;
        int b=0;
        try{
            int c=a/b;
            int arr[] = {10,20,30};
            System.out.println("Array at index 3 is:"+arr[3]);
            System.out.println("Value of a/b is: "+c);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Error Found"+e);
        }
        catch(ArithmeticException e){
            System.out.println("Error Found "+e);
        }
        finally{
            System.out.println("Execution Completed");
        }
        System.out.println("Program End");
    }
}
