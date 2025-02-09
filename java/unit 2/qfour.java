import java.util.Scanner;

// You are using Java
class SecondsToTime {
    int h,m,s;
    public SecondsToTime(int x){
        this.h=x/3600;
        this.m=(x/60)%60;
        this.s=x%60;
    }
    public void displayTime(){
        String hs = String.format("%02d",h);
         String ms = String.format("%02d",m);
          String ss = String.format("%02d",s);
        System.out.println(hs+":"+ms+":"+ss);
    }
 }

 public class qfour {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int totalSeconds = scanner.nextInt();
        scanner.close();

        SecondsToTime timeConverter = new SecondsToTime(totalSeconds);
        timeConverter.displayTime();
    }
}


// Arun is working on a project to convert seconds to a time format. He wants to create a program that accepts a time duration in seconds and converts it into hours, minutes, and seconds. 



// Help him write a logic under class SecondsToTime with a constructor that gets input in seconds and converts it into hh:mm:ss format.

// Input format :
// The input consists of a single integer, representing the time duration in seconds.

// Output format :
// The output prints the converted time in the format 'hh:mm:ss' where hh represents hours, mm represents minutes, and ss represents seconds.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ Time in Seconds ≤ 106

// Sample test cases :
// Input 1 :
// 3665
// Output 1 :
// 01:01:05
// Input 2 :
// 7200
// Output 2 :
// 02:00:00
// Input 3 :
// 60
// Output 3 :
// 00:01:00