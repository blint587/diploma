using System;
using munitscs;


namespace munits_sandbox
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Quantity q1 = new Quantity(Metrics.Length, 15, "m");
            Quantity q2 = new Quantity(Metrics.Length, 20000, "mm");

            Quantity q3 = q1 + q2;
            Quantity q4 = q1 * q2;
            Quantity q5 = q1 / q2;

            Console.WriteLine(q3.ToString());
            Console.WriteLine(q4.ToString());
            Console.WriteLine(q5.ToString());

        }
    }
}