package Java.Linear_DS;

/*Given an integer x, return true if x is a palindrome, and false otherwise. */
class Solution {
    public boolean isPalindrome(int x) {
        boolean is_p;
        if(x<0){
            is_p=false;
        }//Removing the negative numbers from the equation..
        else{
            int x2=x;//Preserving the main value
            int x1=0;//Reversel 
            while(true){
                if(x!=0){
                int digit=x%10;//eeking out the last digit
                x1=x1*10+digit; //Making space for the incoming digit
                x=x/10;//Removing the used digit
                }//
                else{
                    break;
                }
            }
            if(x1==x2){is_p=true;}
            else{is_p=false;}
        }
    return is_p;}
}
