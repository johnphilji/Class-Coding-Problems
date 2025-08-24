import java.util.ArrayList;
import java.util.Scanner; 

class Donations {
    String category;
    String foodName;
    double quantity;

    Donations(String c, String fn, double q) {
        this.category = c;
        this.foodName = fn;
        this.quantity = q;
    }
}

public class Options {
    ArrayList<Donations> donationList = new ArrayList<>();
    Scanner sc = new Scanner(System.in);

    public void start() {
        int choice;
        do {
            System.out.println("<-- Food Donation System -->");
            System.out.println("1: Add donation");
            System.out.println("2: View Donation Summary");
            System.out.println("3: View Total Donations");
            System.out.println("4: Exit");
            System.out.print("Enter your choice: ");
            
            choice = sc.nextInt();
            sc.nextLine(); 

            switch (choice) {
                case 1:
                    addDonation();
                    break;
                case 2:
                    viewDonationSummary();
                    break;
                case 3:
                    viewTotalDonation();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid Choice");
            }
        } while (choice != 4);
    }

    // Add donation
    public void addDonation() {
        System.out.print("Enter category (e.g. Grains, Fruits, Vegetables): ");
        String c = sc.nextLine();
        System.out.print("Enter food name: ");
        String fn = sc.nextLine();
        System.out.print("Enter quantity: ");
        double q = sc.nextDouble();
        sc.nextLine();

        boolean flag = false;

        for (Donations d1 : donationList) {
            if (d1.category.equals(c) && d1.foodName.equals(fn)) {
                d1.quantity += q;
                flag = true;
                break;
            }
        }

        if (flag == false) {
            donationList.add(new Donations(c, fn, q));
        }

        System.out.println("Donation added successfully!\n");
    }

    // View Donation Summary
    public void viewDonationSummary() {
        System.out.println("\n--- Donation Summary ---");
        if (donationList.isEmpty()) {
            System.out.println("No donations yet.");
        } else {
            for (Donations d : donationList) {
                System.out.println("Category: " + d.category + " | Food: " + d.foodName + " | Quantity: " + d.quantity);
            }
        }
        System.out.println("\n");
    }

    // View Total Donation
    public void viewTotalDonation() {
        double total = 0;
        for (Donations d : donationList) {
            total += d.quantity;
        }
        System.out.println("Total Donations (all food items): " + total);
        System.out.println("\n");
    }

    // Main method
    public static void main(String[] args) {
        new Options().start();
    }
}
