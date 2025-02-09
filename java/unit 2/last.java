// You are using Java
public static void main(String[] args) {
    Scanner sca = new Scanner(System.in);
    
    int n = sca.nextInt();
    
    int arr[]= new int[n];
    for(int i=0;i<n;i++){
        arr[i]= sca.nextInt();
    }
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum+=arr[j];
        }
        if(arr[i]>sum){
            System.out.println(arr[i]);
        }
        sum=0;
    }
    
}

// You are using Java
class ExpenseAnalyzer {
    public static int calculateMaxRemainingBudget(int[] expense){
        int ans=0;
        int maxLoss=0;
        for(int i=0;i<expense.length;i++){
                ans+=expense[i];
            if(expense[i]<maxLoss){
                maxLoss = expense[i];
            }
            
        }
        return ans-maxLoss;
    }
}

// You are using Java
class StringOps {
    public static String manipulate(String[] s){
         // System.out.println(s.length);
         if(s.length>2){
            return "Invalid input";
         }
         if(s.length==1){
             StringBuilder sb = new StringBuilder(s[0]);
             sb.reverse();
             return sb.toString();
        }else{
            return s[0] + s[1];
        }
       
    
    }
 }

 // You are using Java
class EncoderDecoder {
    public static String encode(String[] str){
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<str.length;i++){
            sb.append(str[i]);
            if(i!=str.length-1){
                sb.append("#");
                
            }
        }
        return sb.toString();
        
    }
    public static String[] decode(String str){
        String[] st = str.split("#");
        
        return st;
        
    }
}

// You are using Java
public static void main(String[] args) {
    Scanner sca = new Scanner(System.in);
    
    String ss = sca.nextLine();
    char[] ans = ss.toCharArray();
    System.out.print("[");
    for(int i=0;i<ans.length;i++){
        if(i==(ans.length-1)){
            System.out.print(ans[i]+"]");
        }else{
            System.out.print(ans[i]+", ");
            
        }
        
    }
}
