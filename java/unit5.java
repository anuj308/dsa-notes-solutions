import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values
        int readCount = scanner.nextInt();
        int skipCount = scanner.nextInt();
        scanner.nextLine(); // Consume the remaining newline
        String text = scanner.nextLine();
        
        // Process the first segment
        String firstSegment = text.substring(0, Math.min(readCount, text.length()));
        int firstSum = calculateAsciiSum(firstSegment);
        
        // Process the second segment after skipping
        int startIndex = readCount + skipCount;
        if (startIndex > text.length()) {
            startIndex = text.length();
        }
        String secondSegment = text.substring(startIndex, Math.min(startIndex + readCount, text.length()));
        int secondSum = calculateAsciiSum(secondSegment);
        
        // Print the results
        System.out.println(firstSegment);
        System.out.println(firstSum);
        System.out.println(secondSegment);
        System.out.println(secondSum);
        
        scanner.close();
    }
    
    private static int calculateAsciiSum(String str) {
        int sum = 0;
        for (char c : str.toCharArray()) {
            sum += (int) c;
        }
        return sum;
    }
}

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the book title from input
        String title = scanner.nextLine();
        
        // Print the title
        System.out.println(title);
        
        // Calculate and print the number of characters
        System.out.println(title.length());
        
        scanner.close();
    }
}
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values
        int skipCount = scanner.nextInt();
        int lineCount = scanner.nextInt();
        scanner.nextLine(); // Consume the remaining newline
        
        double totalSalary = 0.0;
        int processedCount = 0;
        
        // Process each employee record
        for (int i = 0; i < lineCount; i++) {
            String line = scanner.nextLine();
            if (i < skipCount) {
                continue; // Skip the specified number of records
            }
            
            String[] parts = line.split(" ");
            String name = parts[0];
            double salary = Double.parseDouble(parts[1]);
            
            // Print employee details
            System.out.printf("Name: %s, Salary: %.2f%n", name, salary);
            
            // Update totals
            totalSalary += salary;
            processedCount++;
        }
        
        // Calculate and print results
        if (processedCount > 0) {
            double averageSalary = totalSalary / processedCount;
            System.out.printf("%.2f%n", totalSalary);
            System.out.printf("%.2f%n", averageSalary);
        } else {
            System.out.println("0.00");
            System.out.println("0.00");
        }
        
        scanner.close();
    }
}
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();
        
        int half = s.length() / 2;
        
        // Split and reverse halves
        String firstHalf = new StringBuilder(s.substring(0, half)).reverse().toString();
        String secondHalf = new StringBuilder(s.substring(half)).reverse().toString();
        
        // Print space-separated result
        System.out.println(firstHalf + " " + secondHalf);
    }
}
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the remaining newline
        String s = scanner.nextLine();

        int[] freq = new int[26]; // To store frequency of each character (a-z)

        // Count frequency of each character
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            freq[c - 'a']++;
        }

        // Find the first character with frequency 1
        int result = -1;
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (freq[c - 'a'] == 1) {
                result = i;
                break;
            }
        }

        writer.println(result);
        writer.flush(); // imp

        scanner.close();
        writer.close();
    }
}

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        // Read input
        int n = scanner.nextInt();
        int[] prices = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = scanner.nextInt();
        }
        int target = scanner.nextInt();

        // Find the pair
        int firstIndex = -1, secondIndex = -1;
        outerloop:
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[i] + prices[j] == target) {
                    firstIndex = i + 1; // Convert to 1-based index
                    secondIndex = j + 1;
                    break outerloop;
                }
            }
        }

        // Output the result
        writer.println(firstIndex + " " + secondIndex);
        writer.flush();

        scanner.close();
        writer.close();
    }
}

import java.io.*;
import java.util.Scanner;

class Sample {
    public static void analyzeFile(String filePath, String input) {
        try {
            // Write to file
            FileOutputStream fos = new FileOutputStream(filePath);
            fos.write(input.getBytes());
            fos.close();
            System.out.println("Content has been written to " + filePath);

            // Read from file
            FileInputStream fis = new FileInputStream(filePath);
            byte[] data = new byte[fis.available()];
            fis.read(data);
            fis.close();
            String content = new String(data);

            System.out.println("Reading content from the file:");
            System.out.println("Original String: " + content);

            // Process string
            StringBuilder processed = new StringBuilder();
            int upperCount = 0;
            int lowerCount = 0;
            
            for (char c : content.toCharArray()) {
                if (Character.isUpperCase(c)) {
                    upperCount++;
                    processed.append(c);
                } else if (Character.isLowerCase(c)) {
                    lowerCount++;
                    processed.append(c);
                } else if (Character.isDigit(c)) {
                    processed.append(c);
                }
            }

            System.out.println("Processed String: " + processed.toString());
            System.out.println(upperCount);
            System.out.println(lowerCount);

        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String filePath = sc.nextLine();
        String input = sc.nextLine();
        Sample.analyzeFile(filePath, input);
        sc.close();
    }
}

import java.io.Serializable;

class Book implements Serializable {
    private int id;
    private String title;
    private String author;

    public Book(int id, String title, String author) {
        this.id = id;
        this.title = title;
        this.author = author;
    }

    // Required methods
    public boolean isPrime() {
        if (id <= 1) return false;
        for (int i = 2; i <= Math.sqrt(id); i++) {
            if (id % i == 0) return false;
        }
        return true;
    }

    public int sumOfDigits() {
        int sum = 0;
        int num = id;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    // Custom toString() to match expected output format
    @Override
    public String toString() {
        return "[BookId: " + id + "] \n" +
               "Title: " + title + "\n" +
               "Author: " + author + "\n" +
               "Prime Status: " + (isPrime() ? "Yes" : "No") + "\n" +
               "Sum of Digits of Book ID: " + sumOfDigits();
    }
}
import java.io.Serializable;

class HealthRecord implements Serializable {
    private final double weight;
    private final double currentBMI;
    private final double targetBMI;

    public HealthRecord(double weight, double currentBMI, double targetBMI) {
        this.weight = weight;
        this.currentBMI = currentBMI;
        this.targetBMI = targetBMI;
    }

    public double calculateWeightToReachTargetBmi() {
        double result = (targetBMI * weight) / currentBMI;
        return result;
    }
}
import java.util.Arrays;

class GenericReverser<T> {
    private T[] array;

    public GenericReverser(T[] array) {
        this.array = array;
    }

    // Method to display the array
    public void displayArray() {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    // Method to reverse the array
    public void reverseArray() {
        int left = 0;
        int right = array.length - 1;
        while (left < right) {
            T temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
}


import java.util.*;

class GenericUniqueFilter<T> {
    private T[] array;

    public GenericUniqueFilter(T[] array) {
        this.array = array;
    }

    // Displays the original array
    public void displayArray() {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    // Displays only unique elements in original order
    public void displayUniqueElements() {
        Set<T> seen = new LinkedHashSet<>();
        for (T element : array) {
            seen.add(element);
        }

        for (T element : seen) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
}

import java.util.Arrays;

class GenericSort<T extends Number & Comparable<T>> {

    // Default constructor (required due to main class calling new GenericSort<>())
    public GenericSort() {}

    // Method to display array (called with argument from main)
    public void displayArray(T[] array) {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    // Method to sort array (called with argument from main)
    public void sortArray(T[] array) {
        Arrays.sort(array);
    }
}

class Rectangle<T extends Number> {
    private T length;
    private T width;

    public Rectangle(T length, T width) {
        this.length = length;
        this.width = width;
    }

    // Method to calculate area using diamond operator for type inference
    public Double calculateArea() {
        return length.doubleValue() * width.doubleValue();
    }

    // Method to calculate perimeter
    public Double calculatePerimeter() {
        return 2 * (length.doubleValue() + width.doubleValue());
    }
}

class Box<T> {
    private T content;

    public Box(T content) {
        this.content = content;
    }

    // Static method to compare two boxes using wildcards
    public static boolean compareBoxes(Box<?> b1, Box<?> b2) {
        return b1.content.equals(b2.content);
    }
}
class ArrayRotator<T> {
    private T[] array;

    public ArrayRotator(T[] array) {
        this.array = array;
    }

    // Method to print array
    public void printArray() {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    // Helper method to reverse a portion of the array
    private void reverse(int start, int end) {
        while (start < end) {
            T temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }

    // Method to rotate array in-place using reversal algorithm
    public void rotateArray(int k) {
        int n = array.length;
        if (n == 0 || k == 0 || k % n == 0) return;

        k = k % n; // Normalize k

        // Step 1: Reverse last k elements
        reverse(n - k, n - 1);

        // Step 2: Reverse first n-k elements
        reverse(0, n - k - 1);

        // Step 3: Reverse entire array
        reverse(0, n - 1);
    }
}
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int n = sc.nextInt();
        sc.nextLine(); // consume newline
        String input = sc.nextLine();

        String[] words = input.trim().split(" ");
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < words.length; i += 2) {
            if (i + 1 < words.length) {
                sb.append(words[i + 1]).append(" ").append(words[i]);
            } else {
                sb.append(words[i]);
            }
            if (i + 2 < words.length) {
                sb.append(" ");
            }
        }

        pw.println(sb.toString());
        pw.flush(); // Always flush at end when using PrintWriter
    }
}

class reverseOddIndices<T> {
    private T[] array;

    // Constructor to initialize the array
    public reverseOddIndices(T[] array) {
        this.array = array;
    }

    // Method to process the array (reverse elements at odd indices - 1-based)
    public void processArray() {
        int length = array.length;
        int left = 0;
        int right = (length - 1) / 2;

        while (left < right) {
            int indexLeft = left * 2;
            int indexRight = right * 2;

            if (indexLeft >= length || indexRight >= length)
                break;

            T temp = array[indexLeft];
            array[indexLeft] = array[indexRight];
            array[indexRight] = temp;

            left++;
            right--;
        }
    }

    // Method to display the array
    public void displayArray() {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
}