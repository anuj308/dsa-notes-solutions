// You are using Java
import java.util.Scanner;

public class qone{
    enum Day  {MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY};
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        
        String day = scanner.nextLine().toUpperCase();
        
        for(int i=0;i<7;i++){
            
            if(Day.values()[i].name().equals(day)){
                
                if(i == 6){
                    System.out.println(Day.values()[0]);
                }else{
                    
                    System.out.println(Day.values()[i+1]);
                }
                return;
            }
            
        }
                System.out.println("Invalid Input");
        
    }
}

// Danny is developing a scheduling application that needs to determine the next meeting day based on the current day. 



// The application allows users to input the current day, and it then determines and displays the next day for scheduling meetings. Write the program that uses the enum concept to implement this feature. 

// Input format :
// The input consists of a single string representing the day of the week.

// Output format :
// If the input is a valid day of the week, print the name of the next day in upper case.

// If the input is not a valid day of the week, print "Invalid Input".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The input is case-insensitive.

// enum name: Day

// Sample test cases :
// Input 1 :
// MONDAY
// Output 1 :
// TUESDAY
// Input 2 :
// FriDay
// Output 2 :
// SATURDAY
// Input 3 :
// Fridays
// Output 3 :
// Invalid Input