public class Main {

    public static void whileDemo(int n) {
        int i =1;
        while(i<=n){
            System.out.println(i);
            i++;
        }
        System.out.println("----");
        i=1;
        do{
            System.out.println(i);
            i++;
        }while(i<=n);
        System.out.println("----");
        for(int j=1;j<=n;j++){
            System.out.println(j);
        }
    }
    public static void main(String[] args) {
        whileDemo(5);
        System.out.println("anuj");

        
    }   
}