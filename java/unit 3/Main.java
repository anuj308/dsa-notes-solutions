// You are using Java
class Calculator {
    public int add(int a,int b){
        return a+b;
    }
}

class AdvancedCalculator extends Calculator {
    public int subtract(int a,int b){
        return a - b;
    }
    public int multiply(int a,int b){
        return a*b;
    }
}



// You are using Java
class Person {
    String name;
    int age;
    double height;
    double weight;
    
    public Person(String name,int age,double height,double weight){
        this.name=name;
        this.age=age;
        this.height=height;
        this.weight=weight;
    }
    
    public double calculateBMI(){
        return weight /(height*height);
    }
    
    public void displayInfo(){
        
        System.out.println("Name: "+name);
        System.out.println("Age: "+age + " years");
        System.out.println("Height: "+String.format("%.2f", height) + " meters");
        System.out.println("Weight: "+String.format("%.2f",weight)+" kilograms");
        System.out.println("BMI: "+String.format("%.2f",calculateBMI()));
    }
}

class Athlete extends Person {
      int exercisesPerDay;
      double caloriesBurnedPerExercise;
      
      public Athlete(String name,int age,double height,double weight,int exercisesPerDay,double caloriesBurnedPerExercise){
          super(name,age,height,weight);
          this.exercisesPerDay = exercisesPerDay;
          this.caloriesBurnedPerExercise = caloriesBurnedPerExercise;
      }
      
      public double calculateTotalCaloriesBurned(){
          return exercisesPerDay*caloriesBurnedPerExercise;
      }
      
      @Override
      public void displayInfo(){
          super.displayInfo();
          System.out.println("Exercises per day: "+exercisesPerDay);
          System.out.println("Calories burned per exercise: "+String.format("%.2f",caloriesBurnedPerExercise) +" calories");
          System.out.println("Total Calories Burned: "+ String.format("%.2f",calculateTotalCaloriesBurned()) +" calories");
      }
}


// You are using Java
class Loan {
    protected double principal;
    protected double interestRate;
    protected int loanTerm;
    
    public Loan(double principal,double interestRate, int loanTerm){
        this.principal = principal;
        this.interestRate = interestRate;
        this.loanTerm = loanTerm;
    }
    
    public double calculateInterest(){
        return (principal*interestRate*loanTerm)/ 100;
    }
    
}

class CarLoan extends Loan {
    private double processingFee;
    
    public CarLoan(double principal,double interestRate,int loanTerm, double processingFee){
        super(principal,interestRate,loanTerm);
        this.processingFee =processingFee;
    }
    
    public double calculateTotalCost(){
        double interest = calculateInterest();
        return interest + processingFee;
    }
}


// You are using Java
class BusinessUtility {
    public double calculateMargin(double revenue, double cost){
        return ((revenue - cost)/revenue)*100;
    }
    
    
}

class SeasonalBusinessUtility extends BusinessUtility {
    //type your code here
    @Override
    public double calculateMargin(double revenue, double cost){
        double regularMargin = super.calculateMargin(revenue,cost);
        return regularMargin + 10;
    }
}

class ProfitabilityChecker {
   //type your code here
   public void checkProfitability(double regularMargin){
       if (regularMargin >= 10){
           System.out.println("Business is profitable.");
       } else{
           System.out.println("Business is not profitable.");
       }
   }
}

// You are using Java
class Student {
    //type your code here
    public double calculatePercentage(int totalMarks,int obtainedMarks){
        return ((double) obtainedMarks/ totalMarks)* 100;
    }
}

class ScholarshipStudent extends Student {
    //type your code here
    @Override
    public double calculatePercentage(int totalMarks, int obtainedMarks){
        double regularPercentage= super.calculatePercentage(totalMarks,obtainedMarks);
        return regularPercentage + 5;
    }
}

// You are using Java
class CustomClass {
    //type your code here
    private String input;
    
    public CustomClass(String input){
        this.input = input;
        
    }
    
    @Override
    public String toString(){
        StringBuilder result = new StringBuilder();
        
        for(int i=0;i<input.length();i++){
            char currentChar = input.charAt(i);
            if(!Character.isDigit(currentChar)){
                    result.append(currentChar);
            }
        }
        
        return result.toString();
    }
}


// You are using Java
class Person {
    //type your code here
    protected String name;
    
    public Person(String name){
        this.name = name;
    }
    
    public String getName(){
        return this.name;
    }
}

class FinanceStudent extends Person {
   
   //type your code here
   private double principal;
   private int rate;
   private int time;
   
   public FinanceStudent(String name, double principal, int rate,int time){
       super(name);
        this.principal =principal;
        this.rate = rate;
        this.time = time;
   }
   
   public double getPrincipal(){
       return this.principal;
   }
   
   public int getRate(){
       return this.rate;
   }
   
   public int getTime(){
       return this.time;
   }
   
   public double calculateSimpleInterest(){
       return (principal*rate*time)/100.0;
   }
   
}
// You are using Java
class PrefixClass {
    //type your code here
    private String fileName;
    private String categoryPrefix;
    
    public PrefixClass(String fileName, String categoryPrefix){
        this.fileName = fileName;
        this.categoryPrefix = categoryPrefix;
    }
    
    @Override
    public String toString(){
        return categoryPrefix + fileName;
    }
 }

 // You are using Java

class Vehicle {
    //type your code here
    protected int maxSpeed = 120;
    protected int customSpeed = 120;
    
    public Vehicle(){
        
    }
    
    public void displayMaxSpeed(){
        System.out.println("Maximum Speed from Base class (Vehicle): "+maxSpeed);
        
    }
}

class Car extends Vehicle {
      //type your code 
      public Car(int customSpeed){
          super();
          this.customSpeed = customSpeed;
      }
      
      public void display(){
          super.displayMaxSpeed();
          System.out.println("Maximum Speed from Subclass (Car): "+customSpeed);
      }
}

// You are using Java
class VowelCountMatching {
    //type your code here
    public int countVowels(String str){
        int count=0;
        for(int i=0; i < str.length();i++){
            char c = Character.toLowerCase(str.charAt(i));
            if( c== 'a' || c == 'e' || c == 'i' || c=='o' || c=='u'){
                count++;
            }
        }
        return count;
    }
    
    public boolean equals(VowelCountMatching other){
        return this.countVowels(this.firstString) == other.countVowels(other.firstString);
    }
    
    private String firstString;
    
    public VowelCountMatching(String str){
         this.firstString = str;
    }
 }


 // You are using Java
interface AgeCalculator {
    //type your code here
    int calculateAge(int birthYear);
}

class HumanAgeCalculator implements AgeCalculator {
   //type your code here
   public int calculateAge(int birthYear){
       int currentYear = 2024;
       return currentYear - birthYear;
       
   }
}

// You are using Java
interface StringProcessor {
    //type your code here
    default void countCharacterFrequency(String str){
       int[] freq = new int[256];
       
       for(char c : str.toCharArray()){
        freq[c]++;
       }
       
       if(freq[' ']>0){
           System.out.println("' ':" + freq[' ']);
       }
       
       for(char c = 'A';c<='Z';c++){
           if(freq[c]>0){
               
           System.out.println("'"+c+"': "+freq[c]);
           }
       }
       
       for(char c = 'a';c<='z';c++){
           if(freq[c]>0){
               
           System.out.println("'"+c+"': "+freq[c]);
           }
       }
    }
}

// You are using Java
abstract class Calculator {
    //type your code here
    public abstract int performOperation(int a);
    
    public abstract int performOperation(int a,int b,int c);
}

public class Operations extends Calculator {
    //type your code here
    @Override
    public int performOperation(int a){
        return a*a;
    }
    @Override
    public int performOperation(int a,int b,int c){
        return a*b*c;
    }
}
// error in runing file name issue



// You are using Java
interface Principal {
    //Type your code here
        double getPrincipal();
        
    }
    
    interface InterestRate {
    //Type your code here
        double getInterestRate();
    }
    
    class Loan implements Principal, InterestRate {
        //Type your code here
        private double principal;
        private double interestRate;
        
        public Loan(double principal,double interestRate){
            this.principal = principal;
            this.interestRate=interestRate;
        }
        @Override
        public double getPrincipal(){
            return this.principal;
        }
        
        @Override
        public double getInterestRate(){
            return this.interestRate;
        }
        
        public double calculateTotalInterest(int years){
            return (this.principal* this.interestRate*years)/100;
        }
    }
    

    // You are using Java
interface ShapeInput {
    //Type your code here
    void getInput();
 }
 
 interface ShapeCalculator {
       //Type your code here
     double calculateArea();
     double calculatePerimeter();
 }
 
 class Trapezoid implements ShapeInput, ShapeCalculator {
       //Type your code here
       private double base1, base2, height, side1, side2;
       
       @Override
       public void getInput(){
           Scanner sca = new Scanner(System.in);
           
           base1 = sca.nextDouble();
            base2 = sca.nextDouble();
             height = sca.nextDouble();
              side1 = sca.nextDouble();
               side2 = sca.nextDouble();
               
               sca.close();
       }
       
       @Override
       public double calculateArea(){
           return 0.5*(base1+base2)*height;
       }
       
       @Override
       public double calculatePerimeter(){
           return base1+base2+side1+side2;
       }}
 
 
//  allways close scanner it can give hidden errors


// You are using Java
abstract class FinancialCalculator {
    //type your code here
    public abstract double calculateCompoundInterest(double principal, double rate,int duration);
    public abstract double calculateFutureValue(double principal,double rate,int duration);
    public abstract double calculateMonthlyLoanPayment(double principal, double rate, int duration);
}
class InvestmentCalculator extends FinancialCalculator {
    //type your code here
    @Override
    public double calculateCompoundInterest(double principal, double rate,int duration){
        return principal * Math.pow(1+rate/100,duration) - principal;
    }
    
    @Override
     public double calculateFutureValue(double principal,double rate,int duration){
         return principal * Math.pow(1+rate/100,duration); 
     }
    public double calculateMonthlyLoanPayment(double principal, double rate, int duration){
        return 0;
    }
}
class LoanCalculator extends FinancialCalculator {
    //type your code here
   @Override
    public double calculateCompoundInterest(double principal, double rate,int duration){
        return 0;
    }
    
    @Override
     public double calculateFutureValue(double principal,double rate,int duration){
         return 0; 
     }
    public double calculateMonthlyLoanPayment(double principal, double rate, int duration){
        double monthlyRate = rate / 100 / 12;
        int totalMonths = duration*12;
       
        double result = (principal* monthlyRate* Math.pow(1 + monthlyRate,totalMonths))/(Math.pow(1 + monthlyRate, totalMonths) - 1);
        // return Math.round(result*100000000)/ 100000000.0;
        return result;
    }
}

// You are using Java
class EnvironmentalMetrics {
    //type your code here
    protected double electricityUsage;
    protected double transportationEmissions;
    
    public EnvironmentalMetrics(double electricityUsage, double transportationEmissions){
        this.electricityUsage=electricityUsage;
        this.transportationEmissions=transportationEmissions;
    }
  }
  
  class CarbonFootprintCalculator extends EnvironmentalMetrics {
    //type your code here
    private final double electricityEmissionFactor= 0.4;
    private final double transportationEmissionFactor  = 2.5;
    
    public CarbonFootprintCalculator(double electricityUsage,double transportationEmissions){
        super(electricityUsage, transportationEmissions);
        
    }
    
    public void estimateCarbonEmissions(){
        double electricityCarbon = electricityUsage* electricityEmissionFactor;
        double tcf = electricityCarbon + transportationEmissions;
        
        System.out.printf("Electricity: %.2f kgCO2\n",electricityCarbon);
        System.out.printf("Transportation: %.2f kgCO2\n",transportationEmissions);
        System.out.printf("Total: %.2f kgCO2\n",tcf);
        
        
    }
    
    public double getElectricityCarbon(){
        return electricityUsage*electricityEmissionFactor;
    }
     public double getTransportationEmissions(){
        return transportationEmissions;
    }
     public double getTotalCarbonFootprint(){
        return getElectricityCarbon() + transportationEmissions;
    }
  }
  

  // You are using Java
class CarUtility {
    //type your code here
    public double calculateRange(double fuel,double mileage){
        if(fuel*mileage<50){
            System.out.println("Low Range Warning!");
        }
        return fuel*mileage;
    }
}

class EcoCarUtility extends CarUtility {
   //type your code here
   @Override
   public double calculateRange(double fuel,double mileage){
        if(fuel*mileage<50){
            System.out.println("Low Range Warning!");
        }
       double range = fuel*mileage;
       if(range>=50){
           range+=20;
       }
       return range;
   }
   
}// You are using Java
abstract class Employee {
    //type your code here
    String name;
    double baseSalary;
    double bonus;
    
    public Employee(String name, double baseSalary,double bonus){
        this.name=name;
        this.baseSalary=baseSalary;
        this.bonus=bonus;
    }
    
    public abstract double calculateNetSalary();
}

class Engineer extends Employee {
    //type your code here
    public Engineer(String name,double baseSalary, double bonus){
        super(name,baseSalary,bonus);
        
    }
    @Override
    public double calculateNetSalary(){
        double grossSalary = baseSalary + bonus;
        double tax = grossSalary*0.10;
        double benefit = 100;
        return grossSalary - tax + benefit;
        
    }
}

class SoftwareEngineer extends Engineer {
    //type your code here
    public SoftwareEngineer(String name,double baseSalary, double bonus){
        super(name,baseSalary,bonus);
        
    }
     @Override
    public double calculateNetSalary(){
        double grossSalary = baseSalary + bonus;
        double tax = grossSalary*0.15;
        double benefit = 150;
        return grossSalary - tax + benefit;
    }
}

// You are using Java
class Pizza {
    //type your code here
    protected double basePrice;
    protected double toppingCost;
    
    public Pizza(double basePrice,double toppingCost){
        this.basePrice=basePrice;
        this.toppingCost=toppingCost;
    }
    public double calculatePrice(int noOfTopping){
        return basePrice + (toppingCost * noOfTopping);
    }
}

class DiscountedPizza extends Pizza {
   //type your code here
   public DiscountedPizza(double basePrice,double toppingCost){
       super(basePrice,toppingCost);
   }
   
   @Override
   public double calculatePrice(int noOfTopping){
       double regularPrice =super.calculatePrice(noOfTopping);
       if(noOfTopping>3){
           return regularPrice*0.9;
       }
       return regularPrice;
   }
}

// You are using Java
class Ticket {
    //type your code here
    public double calculatePrice(int distance){
        return distance*0.05;
    }
}

class SeniorCitizenTicket extends Ticket {
   //type your code here
   @Override
    public double calculatePrice(int distance){
        double regularPrice = super.calculatePrice(distance);
        return regularPrice*0.9;
    }
}


// You are using Java
class Person {
    //type your code here
    String name;
    public Person(String name){
        this.name=name;
    }
 }
 
 class FitnessEnthusiast extends Person {
   
    //type your code here
     int workoutDuration;
     double  calorieBurnRate;
     
     public FitnessEnthusiast(String name, int workoutDuration, double calorieBurnRate){
         super(name);
         this.workoutDuration=workoutDuration;
         this.calorieBurnRate=calorieBurnRate;
     }
     
     public double calculateCaloriesBurned(){
         return workoutDuration*calorieBurnRate;
     }
 }


 // You are using Java
class Utility {
    //type your code here
    public int findMax(int[] array){
        int max = Integer.MIN_VALUE;
        for(int v : array){
            if(v > max){
                max = v;
            }
        }
        return max;
    }
}

class ArrayUtils extends Utility {
   //type your code here
   private int[] array;
   
   public ArrayUtils(int[] array){
       this.array = array;
   }
   
   @Override
   public String toString(){
       StringBuilder sb = new StringBuilder();
       for(int i=0;i<array.length;i++){
           sb.append(array[i]);
           if(i < array.length - 1){
               sb.append(" ");
           }
       }
       return sb.toString();
   }
   
   @Override
   public boolean equals(Object obj){
       if (this == obj){
           return true;
       }
       if(obj == null || getClass() != obj.getClass()){
           return false;
       }
       
       ArrayUtils other = (ArrayUtils) obj;
       if(this.array.length != other.array.length){
           return false;
       }
       for(int  i=0;i < this.array.length;i++){
           if(this.array[i] != other.array[i]){
               return false;
           }
       }
       return true;
   }    
   
}


// You are using Java
class Shape {
    //Type your code here
    public String toString(){
        return "This is  a shape";
    }
    
    public boolean equals(Object obj){
        return this == obj;
    }
}

class Triangle extends Shape {
    //Type your code here
        private int s1,s2,s3;
        
        public Triangle(int s1,int s2,int s3){
            this.s1=s1;
            this.s2=s2;
            this.s3=s3;
        }
        public void checkTriangle(){
            if(isValidTriangle()){
                System.out.println("Triangle");
            }else{
                System.out.println("Not a Triangle");
            }
        }
        
        private boolean isValidTriangle(){
            return (s1 + s2 > s3) && ( s2+s3 >s1) && (s3+s1>s2);
        }
        
        @Override
        public String toString(){
            return "Triangle with sides: " + s1 + ", " +s2 +", "+ s3;
        }
}


// You are using Java
abstract class Account {
    //type your code here
    String acconutHolder;
    double principalAmount;
    
    public Account(String accountHolder, double principalAmount){
        this.acconutHolder = accountHolder;
        this.principalAmount=principalAmount;
    }
    
    abstract double calculateInterest();
}

class FixedDeposit extends Account {
   //type your code here
   int durationInYear;
   double rateOfInterest;
   
   public FixedDeposit(String accountHolder, double principalAmount, int durationInYear,double rateOfInterest){
       super(accountHolder,principalAmount);
       this.durationInYear=durationInYear;
       this.rateOfInterest=rateOfInterest;
   }
   @Override
   public double calculateInterest(){
       return (principalAmount* durationInYear * rateOfInterest) /100;
   }
}

class RecurringDeposit extends Account {
  //type your code here
  int monthlyDeposit;
  int durationInMonth;
  double rateOfInterest;
  
   public RecurringDeposit(String accountHolder, int principalAmount,int monthlyDeposit,int durationInMonth,double rateOfInterest){
       super(accountHolder, principalAmount);
       this.durationInMonth=durationInMonth;
       this.monthlyDeposit=monthlyDeposit;
       this.rateOfInterest=rateOfInterest;
   }
   
   @Override
   public double calculateInterest(){
       double maturityAmount = monthlyDeposit * durationInMonth;
       return (maturityAmount*durationInMonth*rateOfInterest )/(12*100);
       
   }
}

// You are using Java
class SuperClass{
    //type your code here
    int variableA;
    
    public SuperClass(int variableA){
        this.variableA=variableA;
    }
    
}
class SubClass extends SuperClass {
    //type your code here
    int variableB;
    
    public SubClass(){
        super(0);
        this.variableB = 2* super.variableA;
    }
    
    public void displayVariables(){
        Scanner sca = new Scanner(System.in);
        super.variableA = sca.nextInt();
        this.variableB = 2 * super.variableA;
        System.out.println("The value of SuperClass: "+ super.variableA);   
        System.out.println("The valueof SubClass: " + variableB);
    }
}

// You are using Java
class WordEntry {
    //type your code here
    private String word;
    
    public WordEntry(String word){
        this.word = word;
    }
    
    @Override
    public boolean equals(Object obj){
        if( this == obj){
            return true;
        }
        if(obj == null || getClass() != obj.getClass()){
            return false;
        }
        WordEntry other = (WordEntry) obj;
        
        String normalizedWorld1 = this.word.replaceAll("\\s","").toLowerCase();
        String normalizedWorld2 = other.word.replaceAll("\\s","").toLowerCase();
        
        return normalizedWorld1.equals(normalizedWorld2);
    }
}

// You are using Java
abstract class GameCharacter {
    //Type your code here
    public abstract void attack(int attribute);
    public abstract void defend(int attribute);
    
}

class Warrior extends GameCharacter {
    //Type your code here
    @Override
    public void attack(int attribute){
        int damage = attribute*3;
        System.out.println("Attack: Powerful sword slash for " + damage + " damage!");
        
    }
    @Override
    public void defend(int attribute){
        System.out.println("Defend: Raises shield, defence boosted by " + attribute + "!");
    }
    
}

class Wizard extends GameCharacter {
    //Type your code here
    @Override
    public void attack(int attribute){
        int damage=  attribute*2;
        System.out.println("Attack: Casts spell, deals " + damage + " magical damage!");
    }
    
    @Override
    public void defend(int attribute){
        System.out.println("Defend: Creates magical barrier, defence boosted by " + attribute + "!");
    }
    
}