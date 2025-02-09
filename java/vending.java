import java.util.Scanner;

public class vending {
    public static void showMenu(){
        System.out.println("Welcome: ");
        System.out.println("1. Tea");
        System.out.println("2. Coffee");
        System.out.println("3. Soup");
        System.out.println("Enter your choice: ");
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        showMenu();
        int a = scanner.nextInt();
        if(a==1){
            System.out.println("Tea is ordered");
        }else if(a==2){
            System.out.println("Coffee is ordered");
        }else if(a==3){
            System.out.println("Soup is ordered");
        }else{
            System.out.println("Invalid choice");
        }
    }
}

// 

// import java.util.Scanner;
public class VendingMachine{

    public static void showMenu(){
        System.out.println("Welcome");
        System.out.println("1. Tea");
        System.out.println("2. Coffee");
        System.out.println("3. Soup");
        System.out.println("------------");
    }

    public static void process(int choice){
        String message = "";

        if(choice == 1){
            message = "Order Received : Tea";
        }else if(choice == 2){
            message = "Order Received : Coffee";
        }else if(choice == 3){
            message = "Order Received : Soup";
        }else{
            message = "Invalid input";
        }

        System.out.println(message);
    }

    public static int takeInput(){
        Scanner scn = new Scanner(System.in);

        int input = scn.nextInt();

        return input;
    }

    public static void main(String args[]){
        showMenu();
        int choice = takeInput();
        process(choice);
    }
}
