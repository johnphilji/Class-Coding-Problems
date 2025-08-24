public class Employee {
    int id;
    float salary;

    public Employee(int id, float salary) {
        this.id = id;
        this.salary = salary;
    }

    public void show(){
        System.out.println("id= "+id);
        System.out.println("salary= "+salary);
    }

    public static void main(String[] args) {
        Employee E1 = new Employee(1203, 12000);
        Employee E2 = new Employee(3265, 16500);
        System.out.println("ID: "+E1.id);
        System.out.println("ID: "+E2.id);
    }
}
