using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace munitscs
{
    public class Quantity
    {
        private IntPtr quantity;

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr CreateQuantity(int metric, double value, string unit);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern void DeleteQuantity(IntPtr q);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern string toCSString(IntPtr q, StringBuilder sb);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern double GetValueForCS(IntPtr q);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr AddForCS(IntPtr lft, IntPtr rgh);


        public Quantity(int metric, double value, string unit)
        {
            this.quantity = CreateQuantity(metric, value, unit);
        }

        protected Quantity(IntPtr q)
        {
            this.quantity = q;
        }

        // Freeing up quantity pointer
        ~Quantity()
        {
            DeleteQuantity(this.quantity);
        }

        public override string ToString()
         {
             StringBuilder buffer = new StringBuilder(512);
             toCSString(this.quantity, buffer);
             return buffer.ToString();
         }

        public double GetValue()
        {
            return GetValueForCS(this.quantity);
        }

        public static Quantity operator +(Quantity lft, Quantity rgh)
        {
            IntPtr temp = AddForCS(lft.quantity, rgh.quantity);
            return new Quantity(temp);
        }

    }

}

