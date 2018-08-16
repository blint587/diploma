using System;
using munitscs;


namespace munits_sandbox
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Quantity q1 = new Quantity(Metrics.Length, 15, "m");
            Console.WriteLine("Something");
            Console.WriteLine(q1.ToString());
        }
    }
}