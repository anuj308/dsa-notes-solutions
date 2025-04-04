class Solution {
     //type your code here
    static class StringReversalUtils{
        public String reverseWithSpecialChars(String input){
            
            char[] inputArr = input.toCharArray();
            
            List<Character> charArr = new ArrayList<>();
            for(char c : inputArr){
                if(Character.isLetterOrDigit(c)){
                    charArr.add(c);
                }
            }
            Collections.reverse(charArr);
            
            int ind=0;
            for(int i=0;i<inputArr.length;i++){
                if(Character.isLetterOrDigit(inputArr[i])){
                    inputArr[i] = charArr.get(ind++);
                }
            }
            return new String(inputArr);
        }
    }
}


class Solution {
    // Write your code here

    public class GymMember {
        // Write your code here
        String name;
        int initialWeight;
        int currentWeight;
        public GymMember(String name,int initialWeight,int currentWeight){
            this.name = name;
            this.initialWeight =initialWeight;
            this.currentWeight=currentWeight;
        }
        public double getImprovementPercentage(){
            double ans = (double)(currentWeight - initialWeight) / initialWeight * 100;
            return ans;
        }
    }
    
}
import java.util.Scanner;

// Functional interface for number filtering
interface NumberFilter {
    boolean test(int n);
}

// Class to calculate sum of even numbers using the filter
class EvenSumCalculator {
    public int calculateEvenSum(int[] numbers, NumberFilter filter) {
        int sum = 0;
        for (int num : numbers) {
            if (filter.test(num)) {
                sum += num;
            }
        }
        return sum;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter numbers separated by spaces:");
        String inputLine = scanner.nextLine();
        String[] tokens = inputLine.split(" ");
        int[] numbers = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            numbers[i] = Integer.parseInt(tokens[i]);
        }

        EvenSumCalculator calculator = new EvenSumCalculator();
        int sum = calculator.calculateEvenSum(numbers, (n) -> n % 2 == 0);
        System.out.println("Sum of even numbers: " + sum);
        scanner.close();
    }
}
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.Period;

public class DateUtil {
    public static String calculateDuration(String startDateStr, String endDateStr) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate startDate = LocalDate.parse(startDateStr, formatter);
        LocalDate endDate = LocalDate.parse(endDateStr, formatter);
        
        Period period = Period.between(startDate, endDate);
        return period.getMonths() + " months and " + period.getDays() + " days";
    }
}
import java.util.Scanner;

public class DateFormatConverter {
    public String convertDateFormat(String inputDate) {
        String[] parts = inputDate.split("/");
        String day = parts[0];
        String month = parts[1];
        String year = parts[2];
        
        // Ensure day and month are two digits
        if (day.length() == 1) {
            day = "0" + day;
        }
        if (month.length() == 1) {
            month = "0" + month;
        }
        
        return year + "-" + month + "-" + day;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputDate = scanner.nextLine();
        DateFormatConverter converter = new DateFormatConverter();
        String outputDate = converter.convertDateFormat(inputDate);
        System.out.println(outputDate);
        scanner.close();
    }
}
// You are using Java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Type your code here
        Scanner sca = new Scanner(System.in);
        int n = sca.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = sca.nextInt();
        }
        int i = sca.nextInt();
        try {
            System.out.println("Element at index " + i + ": " + arr[i]);
        } catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Index out of bound");
        }
    }
}
// You are using Java
class Product {
    String name;
    double p;
    int q;
    
    public Product(String name, double p, int q) {
        this.name = name;
        this.p = p;
        this.q = q;
    }
    
    public static void isValidProduct(String name, double p, int q) {
        try {
            // Validate product name length
            if (name.length() > 25) {
                throw new IllegalArgumentException("Product name should be 25 characters or less");
            }
            
            // Validate price
            if (p <= 0) {
                throw new IllegalArgumentException("Price should be a positive value");
            }
            
            // Validate quantity
            if (q < 0) {
                throw new IllegalArgumentException("Quantity should be a non-negative integer");
            }
            
            // If all validations pass
            System.out.println("Product details are valid");
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}
// You are using Java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);
        
        try {
            // Read number of days
            if (!sca.hasNextInt()) {
                throw new NumberFormatException("Error: Please enter valid integer sales amounts");
            }
            int n = sca.nextInt();
            
            // Validate number of days (1-30)
            if (n < 1 || n > 30) {
                throw new IllegalArgumentException("Error: Number of days sales must be between 1 and 30");
            }
            
            int[] sal = new int[n];
            
            // Read sales amounts
            for (int i = 0; i < n; i++) {
                if (!sca.hasNextInt()) {
                    throw new NumberFormatException("Error: Please enter valid integer sales amounts");
                }
                sal[i] = sca.nextInt();
            }
            
            // Read index and new amount
            if (!sca.hasNextInt()) {
                throw new NumberFormatException("Error: Please enter valid integer sales amounts");
            }
            int ind = sca.nextInt();
            
            if (!sca.hasNextInt()) {
                throw new NumberFormatException("Error: Please enter valid integer sales amounts");
            }
            int ant = sca.nextInt();
            
            // Validate index
            if (ind < 0 || ind >= n) {
                throw new ArrayIndexOutOfBoundsException("Error: Invalid Index. Please provide a valid day number");
            }
            
            // Update and print results
            System.out.println("Original sales at day " + ind + ": " + sal[ind]);
            sal[ind] = ant;
            System.out.println("Updated sales at day " + ind + ": " + sal[ind]);
            
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println(e.getMessage());
        }
    }
}
import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String num1Input = null;
        String num2Input = null;
        String op = null;
        
        try {
            // Read inputs
            num1Input = sc.next();
            num2Input = sc.next();
            sc.nextLine(); // consume the newline
            op = sc.nextLine().trim();
            
            // Parse numbers
            double n1 = Double.parseDouble(num1Input);
            double n2 = Double.parseDouble(num2Input);
            
            if (n2 == 0 && op.equals("/")) {
                throw new ArithmeticException("Arithmetic exception: Cannot divide by zero");
            }
            
            double result = performOperation(n1, n2, op);
            System.out.printf("Result: %.1f", result);
            
        } catch (NumberFormatException e) {
            // Determine which number was invalid
            String invalidNum = e.getMessage().contains(num1Input) ? num1Input : num2Input;
            System.out.println("Invalid number format: " + invalidNum);
        } catch (StringIndexOutOfBoundsException e) {
            System.out.println("Invalid operation input: " + op);
        } catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        } catch (Exception e) {
            System.out.println("Invalid input");
        }
    }
    
    public static double performOperation(double n1, double n2, String op) {
        switch (op) {
            case "+":
                return n1 + n2;
            case "-":
                return n1 - n2;
            case "*":
                return n1 * n2;
            case "/":
                return n1 / n2;
            default:
                throw new StringIndexOutOfBoundsException("Invalid operation: " + op);
        }
    }
}
class InvalidUsernameException extends Exception {
    public InvalidUsernameException(String message) {
        super(message);
    }
}

public class UsernameValidator {
    public static void validateUsername(String username) throws InvalidUsernameException {
        if (username.length() < 5) {
            throw new InvalidUsernameException("Username must be at least 5 characters long");
        }
        if (username.contains(" ")) {
            throw new InvalidUsernameException("Username cannot contain spaces");
        }
    }

    public static void main(String[] args) {
        try {
            validateUsername("test");      // Too short
            validateUsername("good name");  // Contains space
            validateUsername("validName");  // Valid
        } catch (InvalidUsernameException e) {
            System.out.println("Invalid username: " + e.getMessage());
        }
    }
}
import java.time.LocalDate;
import java.time.format.DateTimeParseException;

public class DayChecker {
    public static String getDayType(String dateStr) {
        try {
            String[] parts = dateStr.split(" ");
            if (parts.length != 3) {
                return "Invalid date format. Use 'DD MM YYYY'.";
            }

            int day = Integer.parseInt(parts[0]);
            int month = Integer.parseInt(parts[1]);
            int year = Integer.parseInt(parts[2]);

            LocalDate date = LocalDate.of(year, month, day);
            String dayOfWeek = date.getDayOfWeek().toString();

            if (dayOfWeek.equals("SATURDAY") || dayOfWeek.equals("SUNDAY")) {
                return "Weekend";
            } else {
                return "Weekday";
            }
        } catch (DateTimeParseException e) {
            return "Invalid date. Check day, month, and year.";
        } catch (NumberFormatException e) {
            return "Invalid number format in date.";
        }
    }

    public static void main(String[] args) {
        String date = "8 3 2024"; // Example: 8th March 2024 (Friday → Weekday)
        System.out.println(getDayType(date)); // Output: "Weekday"

        date = "9 3 2024"; // 9th March 2024 (Saturday → Weekend)
        System.out.println(getDayType(date)); // Output: "Weekend"
    }
}
class NumberProcessorLogic {
    // Static nested class to avoid the error
    static class NegativeNumberException extends Exception {
        public NegativeNumberException(String message) {
            super(message);
        }
    }

    public static int processInput(int n) throws NegativeNumberException {
        if (n < 0) {
            String errorMess = n + " is negative";
            throw new NegativeNumberException(errorMess);
        }
        return n * 2;
    }
}
