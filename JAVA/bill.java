import java.util.Scanner;

public class bill {

    static final int DISCOUNT_THRESHOLD = 200;
    static final double DISCOUNT_RATE = 0.10;
    static final double TAX_RATE = 0.05;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("How many items do you want to order?");
        int numchoice = scanner.nextInt();
        if(numchoice>=7){
            System.out.println("Invalid Input");
            
        }else{
            System.out.println(+numchoice);
        }

        double subtotal = 0; 

        for (int i = 1; i <= numchoice; i++) {
            System.out.println("\nWelcome to our Cafe\nMenu:");
            System.out.println("1. Cappuccino - Rs.210");
            System.out.println("2. Latte - Rs.150");
            System.out.println("3. Mocha - Rs.180");
            System.out.println("4. Espresso Shot - Rs.250");
            System.out.println("5. Americano - Rs.150");
            System.out.println("6. Macchiato - Rs.170");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            int price;
            switch (choice) {
                case 1: price = 210;
                 break;
                case 2: price = 150;
                 break;
                case 3: price = 180;
                 break;
                case 4: price = 250;
                 break;
                case 5: price = 150;
                 break;
                case 6: price = 170;
                 break;
                default:
                    System.out.println("Invalid input. Try again.");
                    i--; 
                    continue;
            }

            System.out.print("Enter quantity: ");
            int quantity = scanner.nextInt();

            subtotal += price * quantity;
        }

        System.out.println("\nSubtotal: Rs." + subtotal+"\n");

        double discountedTotal = applyDiscount(subtotal);
        double finalAmount = applyTax(discountedTotal);

        System.out.println("Final Amount to Pay: Rs." + finalAmount+"\n");
        scanner.close();
    }

    public static double applyDiscount(double subtotal) {
        if (subtotal >= DISCOUNT_THRESHOLD) {
            double discount = subtotal * DISCOUNT_RATE;
            double discountedTotal = subtotal - discount;
            System.out.println("Discount Applied: Rs." + discount+"\n");
            System.out.println("Price After Discount: Rs." + discountedTotal+"\n");
            return discountedTotal;
        } else {
            System.out.println("No discount applied.");
            return subtotal;
        }
    }

    public static double applyTax(double amountAfterDiscount) {
        double tax = amountAfterDiscount * TAX_RATE;
        double total = amountAfterDiscount + tax;
        System.out.println("Tax Applied: Rs." + tax+"\n");
        return total;
    }
}
