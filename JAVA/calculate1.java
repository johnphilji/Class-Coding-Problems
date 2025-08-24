
public class calculate1 {
    public static double area(double a){
        return a*a;
    }

    public static double area(double b, double h){
        
        return 0.5*b*h;
    }
    
    public static double area(int r){
        return 3.14 * r * r;
    }
    
    public static void main(String args[]){
        
        double sq = area(19.22);
        double tri = area(19.22, 10.22);
        double cir = area(19);
        
        System.out.println(sq);
        System.out.println(tri);
        System.out.println(cir);
    }

    
}