import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        
        StringBuilder result = new StringBuilder();
        int size = a.length();
        for(int i = 0; i< size; ++i)
        {
            char ch = a.charAt(i);
            if(Character.isUpperCase(ch))
            {
                result.append(Character.toLowerCase(ch));
            }
            else
            {
                result.append(Character.toUpperCase(ch));
            }
        }
        
        System.out.println(result.toString());
    }
    
}