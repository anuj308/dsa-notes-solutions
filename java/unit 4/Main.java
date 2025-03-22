class Solution {
     //type your code here
    static class StringReversalUtils{
        public String reverseWithSpecialChars(String input){
            
            char[] inputArr = input.toCharArray();
            
            List<Character> charArr = new ArrayList<>();
            for(char c : inputArr){
                if(Character.isLetterOrDigit(c)){
                    charArr.add(c);
                }
            }
            Collections.reverse(charArr);
            
            int ind=0;
            for(int i=0;i<inputArr.length;i++){
                if(Character.isLetterOrDigit(inputArr[i])){
                    inputArr[i] = charArr.get(ind++);
                }
            }
            return new String(inputArr);
        }
    }
}


class Solution {
    // Write your code here

    public class GymMember {
        // Write your code here
        String name;
        int initialWeight;
        int currentWeight;
        public GymMember(String name,int initialWeight,int currentWeight){
            this.name = name;
            this.initialWeight =initialWeight;
            this.currentWeight=currentWeight;
        }
        public double getImprovementPercentage(){
            double ans = (double)(currentWeight - initialWeight) / initialWeight * 100;
            return ans;
        }
    }
    
}