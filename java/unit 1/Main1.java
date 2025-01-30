// You are using Java
import java.util.Scanner;

public class Main1{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        
        String modelName = scanner.next();
        int training = scanner.nextInt();
        int batch = scanner.nextInt();
        double learning = scanner.nextDouble();
        boolean trainingSuccessfull = scanner.nextBoolean();
        
        double rounded = Math.floor(learning * 100)/100;
        String lr = String.format("%.2f",rounded);
        
        System.out.println("Model Name: " + modelName);
        System.out.println("Training Epochs: "+ training);
        System.out.println("Batch Size: " + batch);
        System.out.println("Learning Rate: " + lr);
        System.out.println("Training Successful: " + trainingSuccessfull);

        // Scanner scanner = new Scanner(System.in);
        
        // String name = scanner.next();
        // String date = scanner.next();
        
        System.out.println("Hi "+ name + ",");
        System.out.println("Just a reminder: Your next renewal is on "+ date + ".");
        System.out.println("Don't forget to renew!");
        // Scanner scanner = new Scanner(System.in);
        
        int ep = scanner.nextInt();
        double hr = scanner.nextDouble();
        
        // string
        System.out.println("Episode "+ ep + " is "+ hr + " hours long!");
    }
    
}

// Single File Programming Question
// Problem Statement



// Ram is a data scientist who is preparing a report on AI model training for their team's daily meeting. He wants to create a program that reads the model's name, training epochs, batch size, learning rate, and whether the training was successful and then displays a formatted summary for the meeting.



// Can you assist Ram in this?

// Input format :
// The input consists of:

// Model Name (String)
// Training Epochs (int)
// Batch Size (int)
// Learning Rate (float)
// Training Success Status (boolean)
// Output format :
// The first line of output prints the model name.

// The second line prints the number of training epochs.

// The third line prints the batch size.

// The fourth line prints the learning rate, rounded off to two decimal places.

// The fifth line prints the training success status.



// Refer to the sample output for the exact text and format.

// Code constraints :
// The model name is a non-empty string.

// 1 ≤ epoch, batch size ≤ 500

// 0.0 ≤ learning rate ≤ 10.0

// Sample test cases :
// Input 1 :
// GPT-4
// 100
// 64
// 2.56
// true
// Output 1 :
// Model Name: GPT-4
// Training Epochs: 100
// Batch Size: 64
// Learning Rate: 2.56
// Training Successful: true
// Input 2 :
// BERT
// 50
// 32
// 7.015
// false
// Output 2 :
// Model Name: BERT
// Training Epochs: 50
// Batch Size: 32
// Learning Rate: 7.01
// Training Successful: false
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.