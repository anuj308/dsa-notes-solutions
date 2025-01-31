// You are using Java
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt();
        int b =a;
        int evenNumber=0;
        while(b>0){
            int temp = b%10;
            if(temp%2==0){
                evenNumber++;
            }
            b = b /10;
        }
        
        if(evenNumber==0){
            System.out.println("There are no even digits in the number.");
        }else{
            if(a%evenNumber==0){
                System.out.println("It is a divisor of the original number.");
            }else{
                System.out.println("It is not a divisor of the original number.");
            }
        }

        // to find the sum of square of odd digits of a input number


        // Scanner scanner = new Scanner(System.in);
        
        // int a = scanner.nextInt();
        // int b = a;
        // int sum = 0;
        // while(b>0){
        //     int temp = b%10;
        //     if(temp%2!=0){
        //         sum+= temp*temp;
        //     }
        //     b = b / 10;
        // }
        // System.out.print(sum);
    }
}