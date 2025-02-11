#include <iostream>
using namespace std;
// ctrl shift b
void printpartten1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "*";
        }
        cout << endl;
    }
}
void printpartten2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout << "*";
        }
        cout << endl;
    }
}
void printpartten3(int n) {
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout << j << " ";
		}
		cout << endl;
	}
}
void printpartten4(int n) {
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout << i << " ";
		}
		cout << endl;
	}
}
void printpartten5(int n) {
	for(int i=n;i>0;i--){
		for(int j=i;j>0;j--){
			cout << "* ";
		}
		cout << endl;
	}
}
void printpartten6(int n) {
    for(int i=n;i>0;i--){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void printpartten7(int n) {
    // https://www.naukri.com/code360/problems/star-triangle_6573671?leftPanelTabValue=SUBMISSION
    int t=1;
    int r=n;
    for(int i=0;i<n;i++){

        for(int j=0;j<r-1;j++){
            cout << " ";
        }
        for(int k=0;k<t;k++){
            cout << "*";
        }
        for(int j=0;j<r-1;j++){
            cout << " ";
        }
        cout << endl;
        t+=2;
        r--;
    }
}
void printpartten8(int n) {
    int star = 2*n-1;
    int space = 0;
    for(int i=0;i<n;i++){

        for(int j=0;j<space;j++){
            cout << " ";
        }
        for(int t=0;t<star;t++){
            cout << "*";
        }
        for(int j=0;j<space;j++){
            cout << " ";
        }        
        space++;
        star-=2;
        cout << endl;
    }
}
void printpartten9(int n) {
    int space=n-1;
    int star= 1;
    for(int i=0;i<n;i++){
        
        for(int j=0;j<space;j++){
            cout << " ";
        }
        for(int t=0;t<star;t++){
            cout << "*";
        }
        for(int j=0;j<space;j++){
            cout << " ";
        }
        space--;
        star+=2;
        cout << endl;
    }
    space = 0;
    star = 2*n - 1;
    for(int i=0;i<n;i++){
        
        for(int j=0;j<space;j++){
            cout << " ";
        }
        for(int t=0;t<star;t++){
            cout << "*";
        }
        for(int j=0;j<space;j++){
            cout << " ";
        }
        space++;
        star-=2;
        cout << endl;
    }
}
void printpartten10(int n) {
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(j<=i){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
    for(int i=n-1;i>0;i--){
        for(int j=n;j>0;j--){
            if(j>n-i){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
}
void printpartten11(int n) {
    int b= 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){

            if(i%2==0 && j==0){
                b=1;
                // cout << "change to 1 " << endl;
            }else if(i%2!=0 && j==0){
                b=0;
                // cout << "change to 0 " << endl;
            }

            cout << b  << " ";
            if(b==0){
                b=1;
                // cout << b << endl;
            }else{
                b=0;
                // cout << b << endl;
            }
            // cout << b << "over a cycle" << endl;
        }
        cout << endl;
    }
}
void printpartten12(int n) {
    int t = 2*n;
    int space = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << j+1 << " ";
        }
        space = t-2*(i+1);
        for(int j=0;j<=t-2*(i+1);j++){
            cout << " ";
        }
        // cout << "t: " << t << " space : " << space << endl;
        
        for(int j=t-(i+1) - space - 1;j>=0;j--){
            cout << j+1 << " ";
        }
        // cout << "t: " << t << " space : " << space << endl;
        cout << endl;
    }
}
void printpartten13(int n) {
    int number = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << number << " ";
            number+=1;
        }
        cout << endl;
    }
}
void printpartten14(int n) {
    char alpha = 'A';
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            char newAlpha = alpha + j;
            cout << newAlpha << " ";
        }
        cout << endl;
    }
}
void printpartten15(int n) {   
    char alpha = 'A';
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            char newAlpha = alpha + j;
            cout << newAlpha << " ";
        }
        cout << endl;
    }
}
void printpartten16(int n) {
   char alpha = 'A';
    for(int i=0;i<n;i++){
        char newAlpha = alpha + i;
        for(int j=0;j<=i;j++){
            cout << newAlpha << " ";  
        }
        cout << endl;
    }
}
void printpartten17(int n) {
    int t = 2*n -1;
    int star = 1;
    char alpha = 'A';
    for(int i=0;i<n;i++){
        for(int j=0;j<(t-star)/2;j++){
            cout << "  ";
        }
        for(int j=0;j<=star/2;j++){
            char newAlpha = alpha + j;
            cout << newAlpha << " ";
        }
        for(int j=star/2;j>0;j--){
            char newAlpha = alpha + (j - 1);
            cout << newAlpha << " ";
        }
        for(int j=0;j<(t-star)/2;j++){
            cout << "  ";
        }
        star+=2;
        cout << endl;
    }
}
void printpartten18(int n) {
    char alpha = 'A';
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=n-1-i;j--){
            char newAlpha = alpha + j;
            cout << newAlpha << " ";
        }
        cout << endl;
    }
}
void printpartten19(int n) {
    int t = n*2;
    int star = n;
    int space = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<star;j++){
            cout << "* ";
        }
        for(int j=0;j<space;j++){
            cout << " ";
        }
        for(int j=0;j<star;j++){
            cout << "* ";
        }
        star-=1;
        space+=2;
        cout << endl;
    }
    star=1;
    space=n+1;
    for(int i=0;i<n;i++){
        for(int j=0;j<star;j++){
            cout << "* ";
        }
        for(int j=0;j<space;j++){
            cout << " ";
        }
        for(int j=0;j<star;j++){
            cout << "* ";
        }
        star+=1;
        space-=2;
        cout << endl;
    }
}
void printpartten20(int n) {
    int t = 2*n;
    int star =1;
    int space = n+1;
    for(int i=0;i<n;i++){
        for(int j=0;j<star;j++){
            cout << "* ";
        }
        for(int j=0;j<space;j++){
            cout << " ";
        }
        for(int j=0;j<star;j++){
            cout << "* ";
        }
        space-=2;
        star+=1;
        cout << endl;
    }
    space=2;
    star=n-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<star;j++){
            cout << "* ";
        }
        for(int j=0;j<space;j++){
            cout << " ";
        }
        for(int j=0;j<star;j++){
            cout << "* ";
        }
        space+=2;
        star-=1;
        cout << endl;
    }
}
void printpartten21(int n) {
    // Write your code here.
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || j==n-1 || i==n-1){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
}
void printpartten22(int n) {
    int num = n;
    for(int i=n;i>0;i--){
        for(int j=n;j>0;j--){
            if(i==n || j==n){
                cout << n;
            }else if(j>=num){
                cout << j;
            }else{
                cout << num;
            }
        }
        // num=n;
        for(int j=2;j<=n;j++){
            if(i==n || j==n){
                cout << n;
            }else if(j>=num){
                cout << j;
            }else{
                cout << num;
            }
        }

        num-=1;
        cout << endl;
    }
    num=2;
    for(int i=n;i>1;i--){
        for(int j=n;j>0;j--){
            if(i==1 || j==n){
                cout << n;
            }else if(j>=num){
                cout << j;
            }else{
                cout << num;
            }
        }
        for(int j=2;j<=n;j++){
            if(i==1 || j==n){
                cout << n;
            }else if(j>=num){
                cout << j;
            }else{
                cout << num;
            }
        }

        num+=1;
        cout << endl;
    }
}

int main(){
    // cout << "partten questions";
    // steps 
    // for the outer loops, count the no of lines
    // for the inner loop,focus on the columns, and connect them somehow to the rows
    // Print them "*" inside the innner for loop
    // observe symmetry [optional]
    // https://www.youtube.com/watch?v=tNm_NNSB3_w&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=5
    // ****https://www.naukri.com/code360/problems/star-triangle_6573671?leftPanelTabValue=SUBMISSION
    // ****
    // ****
    // ****
    int t;
    cin >> t;
    // for(int k=0;k<t;k++){
    //     int n;
    //     cin >> n;
        printpartten2(t);
    // }
    return 0;
}