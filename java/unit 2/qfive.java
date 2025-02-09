// You are using Java
class PrimeFibonacciChecker {
    public PrimeFibonacciChecker(int start,int end,String s){
        // System.out.println(s);
        if(s.equals("prime")){
            int ans[] = new int[90];
            int p=0;
            for(int i=start;i<=end;i++){
                for(int j=2;j<i;j++){
                    if(j==i-1){
                            ans[p]=i;
                            p++;
                    }else if(i%j==0){
                        break;
                    }
                }
            }
            System.out.print("Prime numbers in the range "+start+" to "+end+": [");
            for(int i=0;i<p;i++){
                if(i==p-1){
                    System.out.print(ans[i] + "]");
                }else {
                    System.out.print(ans[i] + ", ");
                }
            }
        }else{
            int a = 0;
            int b= 1;
            int c= 0;
            int ans[] = new int[end];
            ans[0]=0;
            ans[1]=1;
            int r=2; //count
            while(c<=end){
                c=a+b;
                a=b;
                b=c;
                ans[r]=c;
                r++;
            }
            System.out.print("Fibonacci numbers in the range "+start+" to "+end+": [");
            for(int i=0;i<r;i++){
                if(ans[i]>=start || ans[i]<=end){
                    if(i==r-1){
                        System.out.print(ans[i] + "]");
                    }else{
                        System.out.print(ans[i] + ", ");
                    }
                }
            }
             
        }
    }
    public PrimeFibonacciChecker(int start,String s){
        if(s.equals("prime")){
            for(int j=2;j<start;j++){
                if(start%j!=0 && j==start-1){
                    System.out.print(start+" is a prime number.");
                }else if(j==start-1){
                    System.out.print(start+" is not a prime number.");
                }
            }          
        }else{
            int a = 0;
            int b= 1;
            int c= 0;
            int ans[] = new int[start];
            ans[0]=0;
            ans[1]=1;
            int r=2; //count
            while(c<=start){
                c=a+b;
                a=b;
                b=c;
                ans[r]=c;
                r++;
            }
            int found = 0;
            for(int f : ans){
                if(f==start){
                    System.out.print(start+" is a part of the Fibonacci series.");
                    found=1;
                }
            }
            if(found==0){
                System.out.print(start+" is not part of the Fibonacci series.");
                
            }
        }
    }
}
