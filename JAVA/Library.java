import java.util.*;

class LibraryItem {
    String title;
    String author;
    int year;

    LibraryItem(String t, String a, int y){
        this.title = t;
        this.author = a;
        this.year = y;
    }

    public String getTitle(){return title;}
    public String getAuthor(){return author;}
    public int getYear(){return year;}
  
    String getDetails(){
        return title + " by " + author + " (" + year + ")";
    }
}

//Sub classes
class Book extends LibraryItem{
    String origin;
    Book(String t, String a, int y, String O){
        super(t, a, y);
        this.origin = O;
    }

    @Override
    public String getDetails(){
        return "Origin is: "+origin+ super.getDetails();
    }
}

// Subclass for Magazines
class Magazine extends LibraryItem {
    private String brandAmbassador;

    public Magazine(String title, String publisher, int year, String brandAmbassador) {
        super(title, publisher, year);
        this.brandAmbassador = brandAmbassador;
    }

    @Override
    public String getDetails() {
        return "Magazine - " + super.getDetails() + ", Brand Ambassador: " + brandAmbassador;
    }
}

// Subclass for Journals
class Journal extends LibraryItem {
    private String indexing;

    public Journal(String title, String publisher, int year, String indexing) {
        super(title, publisher, year);
        this.indexing = indexing;
    }

    @Override
    public String getDetails() {
        return "Journal - " + super.getDetails() + ", Indexing: " + indexing;
    }
}


class Options{
    ArrayList<LibraryItem> items = new ArrayList<>();

    //Add Item
    void addItem(LibraryItem item){
        items.add(item);
        System.out.println(item.getTitle() + "Added to the Library");
    }

    void removeItem(LibraryItem toremove){
        items.remove(toremove);
        System.out.println();
    }

    //Search by title
    void searchByTitle(String t){
        for(int i=0; i<items.size(); i++){
            LibraryItem L2 = items.get(i);
            if(L2.getTitle().equalsIgnoreCase(t)){
                System.out.println("Found: " + L2.getDetails());
                return;
            }
        }
        System.out.println("No item found with title: " +t);
    }
}

//Main class
public class Library{
    public static void main(String[] args){
        Options library = new Options();

        //Create items
        Book b1 = new Book("Java Basics", "James Gosling", 1995,"Indian");

        //Add items
        library.addItem(b1);

    }
}