// You are using Java
class GeometryCalculator {
    double vol;
    public double calculateVolume(double s){
        this.vol = s*s*s;
        return vol;
    }
    public double calculateVolume(double b,double h){
        this.vol = (b*h)/3.0;
        return vol;
    }
}


// You are using Java
class VelocityCalculator {
    
    public static int calculateVelocity(int d,int t){
        int velocity=d/t;
        return velocity;
    }
    public static double calculateVelocity(double d,double t){
        double vel=d/t;
        return vel;
    }
    
}


// You are using Java
class IntArrayCalculator {
    public void displayArrayOperations(){
        Scanner sca = new Scanner(System.in);
        int n = sca.nextInt();
        int arr[]= new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sca.nextInt();
        }
        int sum=0;
        int max =-99999999;
        for(int i=0;i<n;i++){
            if(arr[i]>max){
                max = arr[i];
            }
            sum+=arr[i];
        }
        double avg=sum/(n+0.0);
        String avgs = String.format("%.2f",avg);
        System.out.println("Sum: " + sum);
        System.out.println("Average: " + avgs);
        System.out.println("Maximum Value: " + max);
        
    }
}


// You are using Java
public static void main(String[] args) {
    Scanner sca = new Scanner(System.in);
    
    String s1 = sca.nextLine();
    // int n = 
    System.out.println(s1.length());
    
}


// You are using Java
public static void main(String[] args) {
    Scanner sca = new Scanner(System.in);
    
    String s = sca.nextLine();
    String t = sca.next();
    String r = sca.next();
    
    s = s.replace(t,r);
    System.out.println(s);
}

// You are using Java
class StringManipulation {
    public static String insertSubstring(String orignal,String insert,int position){
        StringBuilder sb = new StringBuilder(orignal);
        
        sb.insert(position,insert);
        
        return sb.toString();
    }
}