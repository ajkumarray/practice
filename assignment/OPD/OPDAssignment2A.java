import java.util.*;

//program to find factorial of a given number using recursion

public class OPDAssignment2A {
    public static long factorial(long n)
    //recursive method to find factorial of given number
    {
        if(n == 0)
            return 1;
        else
            return(n*factorial(n-1));
    }
    public static void main(String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number: ");
        long n = scan.nextLong();
        System.out.println("Factorial of "+n+" is: "+factorial(n));
    }
}
