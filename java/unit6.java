import java.util.ArrayList;
import java.util.Scanner;

public class AverageCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read number of elements
        int n = scanner.nextInt();

        // Read the list of double values
        ArrayList<Double> marks = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            marks.add(scanner.nextDouble());
        }

        // Calculate sum
        double sum = 0;
        for (Double mark : marks) {
            sum += mark;
        }

        // Calculate average
        double average = sum / n;

        // Print result formatted to two decimal places
        System.out.printf("Average of the list: %.2f%n", average);
    }
}

import java.util.ArrayList;
import java.util.Scanner;

public class InventoryManager {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> inventory = new ArrayList<>();

        // Read the full line of input and split into tokens
        String[] inputTokens = scanner.nextLine().split(" ");
        int i = 0;

        while (i < inputTokens.length) {
            String choiceStr = inputTokens[i];
            int choice = Integer.parseInt(choiceStr);

            switch (choice) {
                case 1:
                    if (i + 1 >= inputTokens.length) {
                        // Invalid input, but per note, assuming valid test cases
                        break;
                    }
                    String addProduct = inputTokens[++i];
                    inventory.add(addProduct);
                    System.out.println(addProduct + " has been added to the list.");
                    break;

                case 2:
                    if (i + 1 >= inputTokens.length) {
                        // Invalid input, but per note, assuming valid test cases
                        break;
                    }
                    String removeProduct = inputTokens[++i];
                    if (inventory.contains(removeProduct)) {
                        inventory.remove(removeProduct);
                        System.out.println(removeProduct + " has been removed from the list.");
                    } else {
                        System.out.println(removeProduct + " not found in the list.");
                    }
                    break;

                case 3:
                    System.out.println("Items in the list:");
                    if (inventory.isEmpty()) {
                        System.out.println("The list is empty.");
                    } else {
                        for (String item : inventory) {
                            System.out.println(item);
                        }
                    }
                    break;

                case 4:
                    if (i + 1 >= inputTokens.length) {
                        // Invalid input, but per note, assuming valid test cases
                        break;
                    }
                    String searchProduct = inputTokens[++i];
                    if (inventory.contains(searchProduct)) {
                        System.out.println(searchProduct + " is found in the list.");
                    } else {
                        System.out.println(searchProduct + " not found in the list.");
                    }
                    break;
            }
            i++;
        }

        scanner.close();
    }
}

import java.util.ArrayList;
import java.util.Scanner;

public class RemoveTransactionDuplicates {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        ArrayList<Integer> uniqueTransactions = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int amount = scanner.nextInt();
            if (!uniqueTransactions.contains(amount)) {
                uniqueTransactions.add(amount);
            }
        }

        for (int amount : uniqueTransactions) {
            System.out.println(amount);
        }

        scanner.close();
    }
}

import java.util.ArrayList;
import java.util.Scanner;

public class StudentRegistration {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read number of students
        int n = scanner.nextInt();

        // Read student names
        ArrayList<String> studentList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            studentList.add(name);
        }

        // Read index to retrieve
        int index = scanner.nextInt();

        // Retrieve and display result
        if (index >= 0 && index < studentList.size()) {
            System.out.println("Element at index " + index + ": " + studentList.get(index));
        } else {
            System.out.println("Invalid index");
        }

        scanner.close();
    }
}
import java.util.*;

class Student implements Comparable<Student> {
    int rollNo;
    String name;
    int attendance;

    public Student(int rollNo, String name) {
        this.rollNo = rollNo;
        this.name = name;
        this.attendance = 0;
    }

    @Override
    public int compareTo(Student other) {
        return Integer.compare(this.rollNo, other.rollNo);
    }
}

public class AttendanceTracker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        TreeSet<Student> studentSet = new TreeSet<>();

        for (int i = 0; i < n; i++) {
            String operation = scanner.next();

            switch (operation) {
                case "A":
                    int rollAdd = scanner.nextInt();
                    String name = scanner.next();
                    Student newStudent = new Student(rollAdd, name);
                    studentSet.add(newStudent); // TreeSet will ignore duplicates
                    break;

                case "M":
                    int rollMark = scanner.nextInt();
                    for (Student s : studentSet) {
                        if (s.rollNo == rollMark) {
                            s.attendance++;
                            break;
                        }
                    }
                    break;

                case "D":
                    for (Student s : studentSet) {
                        System.out.println(s.rollNo + " " + s.name + " " + s.attendance);
                    }
                    break;
            }
        }

        scanner.close();
    }
}

import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

public class EmployeeDataProcess {

    // Method to take input and populate the map
    public void input(Scanner sc, Map<String, Integer> map) {
        while (true) {
            String name = sc.nextLine().trim();

            if (name.equalsIgnoreCase("done")) {
                break;
            }

            int salary = sc.nextInt();
            sc.nextLine(); // Consume newline character

            map.put(name, salary);
        }
    }

    // Method to calculate and print average earnings using Map
    public void avgEar(Map<String, Integer> map) {
        double total = 0;
        for (int salary : map.values()) {
            total += salary;
        }

        double average = 0;
        if (!map.isEmpty()) {
            average = total / map.size();
        }

        System.out.printf("%.2f%n", average);
    }

    // Main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<String, Integer> employeeMap = new HashMap<>();

        EmployeeDataProcess processor = new EmployeeDataProcess();

        // Call input method to read data
        processor.input(scanner, employeeMap);

        // Call average earning method
        processor.avgEar(employeeMap);

        scanner.close();
    }
}
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Scanner;
class DequeProcessor {
    // You are using Java
    Deque<Integer> dpp = new ArrayDeque<>();

    public void addElement(int e) {
        dpp.add(e);
    }

    public void removeElementsAtOddIndices() {
        Deque<Integer> temp = new ArrayDeque<>();

        int ind = 0;
        while (!dpp.isEmpty()) {
            Integer v = dpp.pollFirst();
            if (ind % 2 == 0) {
                temp.add(v);
            }
            ind++;
        }

        for (Integer i : temp) {
            dpp.add(i);
        }
    }

    public Deque<Integer> getDeque() {
        return dpp;
    }
}

    // Main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Deque<Integer> jerseyDeque = new ArrayDeque<>();

        Processor processor = new Processor();

        // Add elements
        processor.addElement(scanner);

        // Remove elements at odd indices directly
        processor.removeElementAtOddIndices();

        // Print modified deque
        System.out.println(jerseyDeque);

        scanner.close();
    }
}

import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Scanner;

public class ReverseWords {
    public static String reverseWordsOrder(String sentence) {
        String[] words = sentence.split(" ");
        Deque<String> deque = new ArrayDeque<>();
        for (String word : words) {
            String reversedWord = new StringBuilder(word).reverse().toString();
            deque.addFirst(reversedWord);
        }
        StringBuilder reversed = new StringBuilder();
        while (!deque.isEmpty()) {
            reversed.append(deque.removeFirst());
            if (!deque.isEmpty()) {
                reversed.append(" ");
            }
        }import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Scanner;

public class ReverseWords {
    public static String reverseWordsOrder(String sentence) {
        String[] words = sentence.split(" ");
        Deque<String> deque = new ArrayDeque<>();
        for (String word : words) {
            // String reversedWord = new StringBuilder(word).reverse().toString();
            deque.addFirst(word);
        }
        StringBuilder reversed = new StringBuilder();
        while (!deque.isEmpty()) {
            reversed.append(deque.removeFirst());
            if (!deque.isEmpty()) {
                reversed.append(" ");
            }
        }
        return reversed.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        System.out.println(reverseWordsOrder(S));
    }
}
        return reversed.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        System.out.println(reverseWordsOrder(S));
    }
}

import java.util.*;
import java.io.*;

public class ValueProcessor {
    public static HashMap<String, Double> readValue(Scanner scanner) {
        HashMap<String, Double> fruitMap = new HashMap<>();
        while (true) {
            String input = scanner.nextLine();
            if (input.equals("done")) {
                break;
            }
            String[] parts = input.split(":");
            if (parts.length != 2) {
                System.out.println("Invalid format");
                continue;
            }
            String fruitName = parts[0];
            String quantityStr = parts[1];
            try {
                double quantity = Double.parseDouble(quantityStr);
                fruitMap.put(fruitName, quantity);
            } catch (NumberFormatException e) {
                System.out.println("Invalid input");
            }
        }
        return fruitMap;
    }

    public static double calculateSum(Map<String, Double> fruitMap) {
        double sum = 0.0;
        for (double quantity : fruitMap.values()) {
            sum += quantity;
        }
        return Math.round(sum * 100.0) / 100.0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<String, Double> fruitMap = readValue(scanner);
        double total = calculateSum(fruitMap);
        System.out.printf("%.2f", total);
    }
}


import java.util.*;
import java.io.*;

public class ScoreTracker {
    private HashMap<String, Integer> playerScores = new HashMap<>();

    public void processInput(String input) {
        if (input.equals("done")) {
            return;
        }
        String[] parts = input.split(":");
        if (parts.length != 2) {
            System.out.println("Invalid format");
            return;
        }
        String playerName = parts[0];
        String scoreStr = parts[1];
        try {
            int score = Integer.parseInt(scoreStr);
            playerScores.put(playerName, score);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input");
        }
    }

    public String findTopPlayer() {
        if (playerScores.isEmpty()) {
            return "";
        }
        String topPlayer = "";
        int maxScore = Integer.MIN_VALUE;
        for (Map.Entry<String, Integer> entry : playerScores.entrySet()) {
            if (entry.getValue() > maxScore) {
                maxScore = entry.getValue();
                topPlayer = entry.getKey();
            }
        }
        return topPlayer;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ScoreTracker tracker = new ScoreTracker();
        while (true) {
            String input = scanner.nextLine();
            if (input.equals("done")) {
                break;
            }
            tracker.processInput(input);
        }
        String topPlayer = tracker.findTopPlayer();
        System.out.println(topPlayer);
    }
}

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost/ri_db";
        String username = "test";
        String password = "test123";
        
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection connection = DriverManager.getConnection(url, username, password);
            System.out.println("Database connection established!");
            System.out.println(connection.toString());
            connection.close();
        } catch (ClassNotFoundException e) {
            System.out.println("MySQL JDBC Driver not found!");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Connection failed!");
            e.printStackTrace();
        }
    }
}

import java.sql.*;

public class ProductFetcher {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost/ri_db";
        String username = "test";
        String password = "test123";
        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;
        
        try {
            int productId = Integer.parseInt(args[0]);
            
            // Establish connection (not using try-with-resources)
            conn = DriverManager.getConnection(url, username, password);
            
            // Prepare statement
            String sql = "SELECT name, price, quantity FROM products WHERE productId = ?";
            pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, productId);
            
            // Execute query
            rs = pstmt.executeQuery();
            
            if (rs.next()) {
                String name = rs.getString("name");
                double price = rs.getDouble("price");
                int quantity = rs.getInt("quantity");
                
                System.out.println("Product Name: " + name);
                System.out.println("Price: " + price);
                System.out.println("Quantity: " + quantity);
            } else {
                System.out.println("No product found with ID " + productId);
            }
            

// Establish connection
conn = DriverManager.getConnection(url, username, password);
System.out.println("Connection established successfully!");

// Prepare and execute query
String sql = "SELECT studentId, name, age, grade FROM students WHERE studentId = ?";
pstmt = conn.prepareStatement(sql);
pstmt.setInt(1, studentId);
rs = pstmt.executeQuery();

if (rs.next()) {
    System.out.println("Student Details:");
    System.out.println("ID: " + rs.getInt("studentId"));
    System.out.println("Name: " + rs.getString("name"));
    System.out.println("Age: " + rs.getInt("age"));
    System.out.println("Grade: " + rs.getString("grade"));
} else {
    System.out.println("No student found with ID " + studentId);
}