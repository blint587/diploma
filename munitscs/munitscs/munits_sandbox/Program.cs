using System;
using munitscs;


namespace munits_sandbox
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Quantity q1 = new Quantity(Metrics.Length, 15, "m");
            Console.WriteLine(q1.ToString());
            q1.SConvert("mm");
            Console.WriteLine(q1.ToString());
            Console.WriteLine(q1.GetUnitType());
        }
    }
}