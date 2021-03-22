import java.util.*;
//nth term of fibonacci series using recursion

public class OPDAssignment2B {
    public static int fibonacci(int n)
    {
        if(n <= 1)
            return n;
        return fibonacci(n-1) + fibonacci(n-2);
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = scan.nextInt();
        System.out.println(n+"th term of Fibonacci series is: "+fibonacci(n));
    }
}
