using System;
using System.Runtime.InteropServices;
using System.Text;

namespace munitscs
{
    public class Quantity
    {
        private IntPtr quantity;
        
        //C++ function imports
        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr CreateQuantity(int metric, double value, string unit);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern void DeleteQuantity(IntPtr q);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern string __toString(IntPtr q, StringBuilder sb);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern double __getValue(IntPtr q);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __add(IntPtr lft, IntPtr rgh);
    
        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __substract(IntPtr lft, IntPtr rgh);
        
        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __multiply(IntPtr lft, IntPtr rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __multiply_rgh_int(IntPtr lft, int rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __multiply_lft_int(int lft, IntPtr rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __multiply_lft_double(double lft, IntPtr rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __multiply_rgh_double(IntPtr lft, double rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __divide(IntPtr lft, IntPtr rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __divide_int(IntPtr lft, int rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __divide_double(IntPtr lft, double rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern bool __lt(IntPtr lft, IntPtr rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern bool __gt(IntPtr lft, IntPtr rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern bool __le(IntPtr lft, IntPtr rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern bool __ge(IntPtr lft, IntPtr rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern bool __eq(IntPtr lft, IntPtr rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern bool __ne(IntPtr lft, IntPtr rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __pow(IntPtr lft, int rgh);

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern IntPtr __ntrt(IntPtr lft, int rgh);

       
        public Quantity(int metric, double value, string unit)
        {
            this.quantity = CreateQuantity(metric, value, unit);
        }

        private Quantity(IntPtr q)
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
             __toString(this.quantity, buffer);
             return buffer.ToString();
         }

        public double GetValue()
        {
            return __getValue(this.quantity);
        }
         
        //add
        public static Quantity operator +(Quantity lft, Quantity rgh)
        {
            IntPtr temp = __add(lft.quantity, rgh.quantity);
            return new Quantity(temp);
        }
        // substract
        public static Quantity operator -(Quantity lft, Quantity rgh)
        {
            IntPtr temp = __substract(lft.quantity, rgh.quantity);
            return new Quantity(temp);
        }
        
        //multiply
        public static Quantity operator *(Quantity lft, Quantity rgh)
        {
            IntPtr temp = __multiply(lft.quantity, rgh.quantity);
            return new Quantity(temp);
        }
        public static Quantity operator *(Quantity lft, int rgh)
        {
            IntPtr temp = __multiply_rgh_int(lft.quantity, rgh);
            return new Quantity(temp);
        }
        public static Quantity operator *(int lft, Quantity rgh)
        {
            IntPtr temp = __multiply_lft_int(lft, rgh.quantity);
            return new Quantity(temp);
        }
        public static Quantity operator *(Quantity lft, double rgh)
        {
            IntPtr temp = __multiply_rgh_double(lft.quantity, rgh);
            return new Quantity(temp);
        }
        public static Quantity operator *(double lft, Quantity rgh)
        {
            IntPtr temp = __multiply_lft_double(lft, rgh.quantity);
            return new Quantity(temp);
        }
        
        //divide
        public static Quantity operator /(Quantity lft, Quantity rgh)
        {
            IntPtr temp = __divide(lft.quantity, rgh.quantity);
            return new Quantity(temp);
            
        }
        public static Quantity operator /(Quantity lft, int rgh)
        {
            IntPtr temp = __divide_int(lft.quantity, rgh);
            return new Quantity(temp);
        }
        public static Quantity operator /(Quantity lft, double rgh)
        {
            IntPtr temp = __divide_double(lft.quantity, rgh);
            return new Quantity(temp);
            
        }
        
        //comparison
        public static bool operator <(Quantity lft, Quantity rgh)
        {
            return __lt(lft.quantity, rgh.quantity);
        }
        public static bool operator >(Quantity lft, Quantity rgh)
        {
            return __gt(lft.quantity, rgh.quantity);
        }
        public static bool operator <=(Quantity lft, Quantity rgh)
        {
            return __le(lft.quantity, rgh.quantity);
        }
        public static bool operator >=(Quantity lft, Quantity rgh)
        {
            return __ge(lft.quantity, rgh.quantity);
        }
        public static bool operator ==(Quantity lft, Quantity rgh)
        {
            return __eq(lft.quantity, rgh.quantity);
        }
        public static bool operator !=(Quantity lft, Quantity rgh)
        {
            return __ne(lft.quantity, rgh.quantity);
        }
        
        //power
        public static Quantity Pow(Quantity lft, int rgh)
        {
            IntPtr temp = __pow(lft.quantity, rgh);
            return new Quantity(temp);
        }
        // nt roth
        public static Quantity Roth(Quantity lft, int rgh)
        {
            IntPtr temp = __ntrt(lft.quantity, rgh);
            return new Quantity(temp);
        }
        

    }

}

