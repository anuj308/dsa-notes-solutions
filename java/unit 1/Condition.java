import java.util.Scanner;

public class Condition{// You are using Java
public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    
    int a = scanner.nextInt();
    int b = scanner.nextInt();
    Boolean ans;
    
    if(a%4==0 || b%4==0){
        ans = true;
    }else{
        ans = false;
    }

    //  -------
    int a = scanner.nextInt();
    int b = scanner.nextInt();
    int c = scanner.nextInt();
    
    double ans = (a+b)*c/(a-b)+(c%a);
    
    System.out.printf("%.2f",ans);
    
    System.out.println(ans);
    // --------------
    int a = scanner.nextInt();
        int b = scanner.nextInt();
        int ans = (a > b ? a - b : a + b)*2;
        
        System.out.println("Result of (" + a +" > " + b +" ? " + a + " - " + b + " : " + a + " +"+ b +") * 2: "+ ans);

        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        
        double ans = (a+b)/2.0;
        System.out.printf("%.2f",ans);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        boolean ans;
        
        if(b == a*2){
            ans = true;
        }else{
            ans = false;    
        
        }
        
        System.out.println(ans);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        System.out.println(b+ " " +a);


        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        int e = scanner.nextInt();
        
        int largest;
        int smallest;
        if( a > b && a > c && a > d && a>e){
            largest =a;
        }else if( b > a && b > c && b > e && b > d){
            largest = b;
        }else if( c > a && c > b && c > d && c > e){
            largest = c;
        }else if( d > a && d> b && d>c && d>e){
            largest = d;
        }else{
            largest = e;
        }
        
        if( a < b && a < c && a < d && a<e){
            smallest =a;
        }else if( b < a && b < c && b < e && b < d){
            smallest = b;
        }else if( c < a && c < b && c < d && c < e){
            smallest = c;
        }else if( d < a && d< b && d<c && d<e){
            smallest = d;
        }else{
            smallest = e;
        }

        // -----------
        int a = scanner.nextInt();
        
        if( a >= 10 && a <=99 || a<=-10 && a>=-99){
            
        int ab = Math.abs(a);
        
        int sum = (ab/10) + (ab%10);
        
        System.out.println("Digit Sum: " + sum );
        if( sum <10){
            System.out.println("The sum of the digits is less than 10.");
        }else{
            System.out.println("The sum of the digits is not less than 10.");
        }
        }else{
            System.out.println("Not a valid two-digit number.");
        }

        // ------------
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        int e = scanner.nextInt();
        
        int avg = (a+b+c+d+e)/5;
        System.out.println("Average score: " + avg);
        
        if(avg>=50){
            System.out.println("The student has passed");
        }else{
            System.out.println("The student has failed");
        }

        // --------
        int a = scanner.nextInt();
        
        if(a%2==0 && a>100){
            System.out.println(a + " is even and greater than 100.");
        }else if(a%2==0 && a<100){
            System.out.println(a + " is even and not greater than 100.");
        }else if(a%2!=0 && a<100){
            System.out.println(a + " is odd and not greater than 100.");
        }else{
            System.out.println(a + " is odd and greater than 100.");
        }
        // ---------
        double a = scanner.nextDouble();
        int b = scanner.nextInt();
        
        if(b==1){
            double a1 = Math.round(a);
            System.out.println("Rounded to the nearest whole number: " + a1);
        }else if(b==2){
            String a2 = String.format("%.1f",a);
            System.out.println("Rounded to one decimal place: " + a2);
        }else if(b==3){
            String a3 = String.format("%.2f",a);
            System.out.println("Rounded to two decimal places: " + a3);
        }else{
            System.out.println("Invalid Choice.");
        }

        // ------
        int c =scanner.nextInt();
    double x1 = scanner.nextDouble();
    double y1 = scanner.nextDouble();
    double x2 = scanner.nextDouble();
    double y2 = scanner.nextDouble();
    
    if(c==1){
        double c1= (y2-y1)/(x2 - x1);
        System.out.println("Slope: " + c1);
    }else if(c==2){
        double c2= Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        String c22 = String.format("%.2f",c2);
        System.out.println("Distance: " + c22);
    }else if(c==3){
        double c3 =(x1+x2)/2;
        double c4 =(y1+y2)/2;
        System.out.println("Midpoint: (" +c3+","+c4+")");
    }else{
        System.out.println("Invalid choice. Please select a valid option.");
    }

    // -------------------
    String name = scanner.nextLine();
    String status = scanner.nextLine();
    int number =scanner.nextInt();
    
    System.out.println("Device Name: " + name);
    System.out.println("Status: " + status);
    System.out.println("Model Number: " + number);

    // -------
    int a = scanner.nextInt();
    int b = scanner.nextInt();
    int c = scanner.nextInt();
    int d = scanner.nextInt();
    
    int ans = ( a + b -c * d / a) % b;
    
    System.out.println("( a + b - c * d / a) % b = " + ans);

    // ----------
    int a = scanner.nextInt();
       int b = scanner.nextInt();
       
       int ans = (a)*45 + (a/b)*15;
       System.out.println(ans + " minutes");


    //    ------------


    int a = scanner.nextInt();
       int b = scanner.nextInt();
       
       int ans = (a)*45 + (a/b)*15;
       
       if(a%b==0){
           ans-=15;
       }
       System.out.println(ans + " minutes");
    // ----------
    int x1 = scanner.nextInt();
    int y1 = scanner.nextInt();
    int x2 = scanner.nextInt();
    int y2 = scanner.nextInt();
    
    double distance1 = Math.sqrt(x1*x1 + y1*y1);
    double distance2 = Math.sqrt(x2*x2 + y2*y2);
    
    double ans;
    if( distance1 < distance2){
        ans = distance1;
    }else{
        ans = distance2;
    }
    String shortDistance = String.format("%.1f",ans);
    
    System.out.println("Closer Distance: " + shortDistance);
    
    if(x1==x2){
        System.out.println("Orientation: Vertical");
    }else if(y1==y2){
        System.out.println("Orientation: Horizontal");
    }else{
        System.out.println("Orientation: Oblique");
    }

    // --------
    int monthRent = scanner.nextInt();
       int leaseTime = scanner.nextInt();
       
       int totalCost = monthRent*leaseTime;
       
       String paymentMethod;
      if(totalCost<=1000){
          paymentMethod = "Payment by cash or check is recommended.";
          
      }else if(totalCost>1000 && totalCost<5000){
          paymentMethod = "Payment by credit card is recommended.";
      }else{
          paymentMethod = "Payment by bank transfer is recommended.";
      }
        System.out.println("Total Cost: "+ totalCost);
       System.out.println("Payment Method Suggestion: "+paymentMethod);
} 
}