//using parametric call for Base class only
class Base
{
    Base()
    {
        System.out.println("This is Base, over");
    }
    Base(int a)
    {
        System.out.println("This is Base, we have recieved value: "+a+", over.");
    }
}
class Derived extends Base{
    Derived()
    {
        super();
        System.out.println("This is Derived reporting, over.");
    }
    Derived(int a)
    {
        super(a);
        System.out.println("Base, this is Derived reporting, over.");
    }
    Derived(int a,int b)
    {
        super(a);
        System.out.println("Base we have recieved the value: "+b+", over.");
    }
}
public class OPDAssignment2C {
    public static void main(String[] args)
    {
        Derived objDerived = new Derived(5);
    }   
}
