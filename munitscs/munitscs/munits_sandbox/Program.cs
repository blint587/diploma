using System;
using munitscs;


namespace munits_sandbox
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Quantity q1 = new Quantity(Metrics.Length, 15, "m"); // initiat a object
            Console.WriteLine($"q1 is {q1}");
            Quantity q2 = new Quantity(Metrics.Length, 15000, "mm"); // initiat a object
            Console.WriteLine($"q2 is {q2}");
            
            //add
            Quantity q3 = q1 + q2;
            Console.WriteLine($"q1 + q2 = {q3}");
            
            //multiply
            Quantity q4 = q1 * q2;
            Console.WriteLine($"q1 * q2 = {q4}");
            
            //power function
            //For power function us 'Pow' method! 
            Quantity q5 = q1.Pow(3);
            Console.WriteLine($"q1 on 3rd power is {q5}");
            
            //root
            //For root function us 'Root' method!
            Quantity q6 = q5.Root(3);
            Console.WriteLine($"{q5} on 3rd root is {q6}");
           
            //compare
            //To compare units us the comparison operator '<,>,<=,>=,==,!='
            // At the moment don't compare to null, use 'ReferenceEquals' instead
            Console.WriteLine($"q1 < q2 -> {q1 < q2}");
            
            //self convert
            //Use 'SConver' to performin self convert!
            q1.SConvert("mm");
            Console.WriteLine($"q1 in 'mm' is {q1}");
            
            //get measurement unit type
            //Use 'GetUnitType' to get the unit type.
            Console.WriteLine($"The unit type of q1 is {q1.GetUnitType()}");
            
            //get unit of quantity
            //To get the unit use the  'GetUnit' method 
            Console.WriteLine($"The unit of q1: {q1.GetUnit()}");
            
            // get value in a spcific unit
            //To get the value in a specific unit use 'Get(<string>unit)' method
            Console.WriteLine($"q1 in km is {q1.Get("km")}");
            
            
            //IT IS A REFERNECE TYPE
            //Warning it is a reference type so if you perform SConvert it will be reflected on all references
            Quantity q7 = new Quantity(Metrics.Mass, 1, "kg");
            Quantity q8 = q7;
            
            q7.SConvert("g");
            Console.WriteLine($"q7 {q7} -> q8 {q8}");
            
            //For proper copy use the copy constructor or the DeepCopy method
            Quantity q9 = new Quantity(q7);
            q9.SConvert("mg");
            Quantity q10 = q7.DeepCopy();
            q7.SConvert("t");
            
            Console.WriteLine($"q7: {q7}");
            Console.WriteLine($"q9: {q9}");
            Console.WriteLine($"q10: {q10}");
            
        }
    }
}