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
    for(int k=0;k<t;k++){
        int n;
        cin >> n;
        printpartten2(n);
    }
    return 0;
}