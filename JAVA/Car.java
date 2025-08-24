public class Car{
	String model;
	double price;
	int quantity;
	
	public Car(String model , double price , int quantity){
		this.model = model;
		this.price = price;
		this.quantity = quantity;
		}
		
	public void displayDetails() {
        System.out.println("Model: " + model);
        System.out.println("Price: ₹" + price);
        System.out.println("Quantity: " + quantity);
    	}
    	
    	public double calculateSales() {
        return price * quantity;
        }
    	
    	public static void main(String [] args){
    		Car car1 = new Car("Honda Accord", 250000, 10);
    		Car car2 = new Car("Honda City", 450000, 20);
    		Car car3 = new Car("Honda NSX", 950000, 10);
    		
    		System.out.println("Car 1 Details:");
        car1.displayDetails();
        System.out.println("Total Sales: ₹" + car1.calculateSales());
        System.out.println();

        System.out.println("Car 2 Details:");
        car2.displayDetails();
        System.out.println("Total Sales: ₹" + car2.calculateSales());
        System.out.println();

        System.out.println("Car 3 Details:");
        car3.displayDetails();
        System.out.println("Total Sales: ₹" + car3.calculateSales());
    		}
	 
	}
	
	
