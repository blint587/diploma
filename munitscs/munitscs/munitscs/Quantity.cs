using System;
using System.Runtime.InteropServices;
using System.Text;
using munitscs.Exceptions;

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

//        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
//        private static extern string __toString(IntPtr q, string sb);

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

        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern double __get(IntPtr lft, string u);
    
        [DllImport("munits.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private static extern double __double(IntPtr q);
    
        
       
        public Quantity(Metrics metric, double value, string unit)
        {
            this.quantity = CreateQuantity((int) metric, value, unit);
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

//        public override string ToString()
//         {
//             string buffer = "";
//             __toString(this.quantity, buffer);
//             return buffer;
//         }

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
            try
            {
                return __lt(lft.quantity, rgh.quantity);
            }catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                {
                    throw new CannotPerformComparison("Comparison cannot be done! Measurement Unit types do not match.", ex);
                }
                throw;
            }
        }
        public static bool operator >(Quantity lft, Quantity rgh)
        {
            try
            {
                return __gt(lft.quantity, rgh.quantity);
            }catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                {
                    throw new CannotPerformComparison("Comparison cannot be done! Measurement Unit types do not match.", ex);
                }
                throw;
            }
        }
        public static bool operator <=(Quantity lft, Quantity rgh)
        {
            try
            {
                return __le(lft.quantity, rgh.quantity);
            }catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                {
                    throw new CannotPerformComparison("Comparison cannot be done! Measurement Unit types do not match.", ex);
                }
                throw;
            }
        }
        public static bool operator >=(Quantity lft, Quantity rgh)
        {
            try
            {
                return __ge(lft.quantity, rgh.quantity);
            }catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                {
                    throw new CannotPerformComparison("Comparison cannot be done! Measurement Unit types do not match.", ex);
                }
                throw;
            }
        }
        public static bool operator ==(Quantity lft, Quantity rgh)
        {    
            if (!(ReferenceEquals(null, lft) || ReferenceEquals(null, rgh))){
                try
                {
                    return __eq(lft.quantity, rgh.quantity);
                }
                catch (SEHException ex)
                {
                    if (ex.ErrorCode == -2147467259) // logic_error
                    {
                        throw new CannotPerformComparison("Comparison cannot be done! Measurement Unit types do not match.",
                            ex);
                    }

                    throw;
                }
            }
            //TODO: implement proper logic
            return false;
        }
        public static bool operator !=(Quantity lft, Quantity rgh)
        {
            if (!(ReferenceEquals(null, lft) || ReferenceEquals(null, rgh)))
            {
                try
                {
                    return __ne(lft.quantity, rgh.quantity);
                }
                catch (SEHException ex)
                {
                    if (ex.ErrorCode == -2147467259) // logic_error
                    {
                        throw new CannotPerformComparison("Comparison cannot be done! Measurement Unit types do not match.", ex);
                    }

                    throw;
                }
            }
            //TODO: implement proper logic
            return false;
        }
        
        //power
        public Quantity Pow(int rgh)
        {
            IntPtr temp = __pow(this.quantity, rgh);
            return new Quantity(temp);
        }
        // nt roth
        public Quantity Root(int rgh)
        {
            try
            {
                IntPtr temp = __ntrt(this.quantity, rgh);
                return new Quantity(temp);
            }
            catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                {
                    throw new CannotPerformRootOperation($"Cannot perform {rgh}th root on {quantity}!", ex);
                }
                throw;
            }
        }

        public double Get(string u)
        {
            return __get(this.quantity, u);
        }

        public static implicit operator double(Quantity q)
        {
            try
            {
                return __double(q.quantity);
            }
            catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                {
                    throw new CannotPerformRootOperation("Unit cannot be converted to double!!", ex);
                }
                throw;
            }
        }
    }
}

