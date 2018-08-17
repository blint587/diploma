using System;
using System.Runtime.InteropServices;
using System.Text;
using munitscs.Exceptions;

namespace munitscs
{
    public class Quantity
    {
#if WIN64
        private const string DllName = "munits.x64.dll";
#elif WIN32
            private const string DllName = "munits.x86.dll";
        #else
            private const string DllName = "munits.dll";
        #endif
        private const CharSet Char = CharSet.Ansi;
        private IntPtr _quantity;

        //C++ function imports
        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr CreateQuantity(int metric, double value, string unit);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern void DeleteQuantity(IntPtr q);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __toString(IntPtr q, [MarshalAs(UnmanagedType.LPStr)] StringBuilder sb,
            ref uint bufferSize);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern double __getValue(IntPtr qm);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern string __getUnit(IntPtr q, [MarshalAs(UnmanagedType.LPStr)] StringBuilder sb,
            ref uint bufferSize);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __add(IntPtr lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __substract(IntPtr lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __multiply(IntPtr lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __multiply_rgh_int(IntPtr lft, int rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __multiply_lft_int(int lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __multiply_lft_double(double lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __multiply_rgh_double(IntPtr lft, double rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __divide(IntPtr lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __divide_int(IntPtr lft, int rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __divide_double(IntPtr lft, double rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern int __lt(IntPtr lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern int __gt(IntPtr lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern int __le(IntPtr lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern int __ge(IntPtr lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern int __eq(IntPtr lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern int __ne(IntPtr lft, IntPtr rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __pow(IntPtr lft, int rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern IntPtr __ntrt(IntPtr lft, int rgh);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern double __get(IntPtr lft, string u);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern double __double(IntPtr q);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, CharSet = Char)]
        private static extern int __getType(IntPtr q);


        public Quantity(Metrics metric, double value, string unit)
        {
            _quantity = CreateQuantity((int) metric, value, unit);
        }

        private Quantity(IntPtr q)
        {
            _quantity = q;
        }

        public Quantity(Quantity q) : this(q.GetUnitType(), q.GetValue(), q.GetUnit())
        {
        }

        // Freeing up quantity pointer
        ~Quantity()
        {
            DeleteQuantity(_quantity);
        }

        public override string ToString()
        {

            UInt32 bufferSize = 0;
            
            __toString(_quantity, null, ref bufferSize); // first call to determine buffer size 
            var sb = new StringBuilder((int) bufferSize); // creating buffer with the neceseary size
            __toString(_quantity, sb, ref bufferSize); // doing the actual copy 
            return sb.ToString();
        }

        public double GetValue()
        {
            return __getValue(_quantity);
        }

        public string GetUnit()
        {
            UInt32 bufferSize = 0;
            
            __getUnit(_quantity, null, ref bufferSize); // first call to determine buffer size 
            var sb = new StringBuilder((int) bufferSize); // creating buffer with the neceseary size
            __getUnit(_quantity, sb, ref bufferSize); // doing the actual copy 
            return sb.ToString();
        }


        //add
        public static Quantity operator +(Quantity lft, Quantity rgh)
        {
            IntPtr temp = __add(lft._quantity, rgh._quantity);
            return new Quantity(temp);
        }

        // substract
        public static Quantity operator -(Quantity lft, Quantity rgh)
        {
            IntPtr temp = __substract(lft._quantity, rgh._quantity);
            return new Quantity(temp);
        }

        //multiply
        public static Quantity operator *(Quantity lft, Quantity rgh)
        {
            IntPtr temp = __multiply(lft._quantity, rgh._quantity);
            return new Quantity(temp);
        }

        public static Quantity operator *(Quantity lft, int rgh)
        {
            IntPtr temp = __multiply_rgh_int(lft._quantity, rgh);
            return new Quantity(temp);
        }

        public static Quantity operator *(int lft, Quantity rgh)
        {
            IntPtr temp = __multiply_lft_int(lft, rgh._quantity);
            return new Quantity(temp);
        }

        public static Quantity operator *(Quantity lft, double rgh)
        {
            IntPtr temp = __multiply_rgh_double(lft._quantity, rgh);
            return new Quantity(temp);
        }

        public static Quantity operator *(double lft, Quantity rgh)
        {
            IntPtr temp = __multiply_lft_double(lft, rgh._quantity);
            return new Quantity(temp);
        }

        //divide
        public static Quantity operator /(Quantity lft, Quantity rgh)
        {
            IntPtr temp = __divide(lft._quantity, rgh._quantity);
            return new Quantity(temp);
        }

        public static Quantity operator /(Quantity lft, int rgh)
        {
            IntPtr temp = __divide_int(lft._quantity, rgh);
            return new Quantity(temp);
        }

        public static Quantity operator /(Quantity lft, double rgh)
        {
            IntPtr temp = __divide_double(lft._quantity, rgh);
            return new Quantity(temp);
        }

        //comparison
        public static bool operator <(Quantity lft, Quantity rgh)
        {
            try
            {
                return __lt(lft._quantity, rgh._quantity) == 1;
            }
            catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                    throw new CannotPerformComparison("Comparison cannot be done! Measurement Unit types do not match.",
                        ex);
                throw;
            }
        }

        public static bool operator >(Quantity lft, Quantity rgh)
        {
            try
            {
                return __gt(lft._quantity, rgh._quantity) == 1;
            }
            catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                    throw new CannotPerformComparison("Comparison cannot be done! Measurement Unit types do not match.",
                        ex);
                throw;
            }
        }

        public static bool operator <=(Quantity lft, Quantity rgh)
        {
            try
            {
                return __le(lft._quantity, rgh._quantity) == 1;
            }
            catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                    throw new CannotPerformComparison("Comparison cannot be done! Measurement Unit types do not match.",
                        ex);
                throw;
            }
        }

        public static bool operator >=(Quantity lft, Quantity rgh)
        {
            try
            {
                return __ge(lft._quantity, rgh._quantity) == 1;
            }
            catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                    throw new CannotPerformComparison("Comparison cannot be done! Measurement Unit types do not match.",
                        ex);
                throw;
            }
        }

        public static bool operator ==(Quantity lft, Quantity rgh)
        {
            if (!(ReferenceEquals(null, lft) || ReferenceEquals(null, rgh)))
                try
                {
                    return __eq(lft._quantity, rgh._quantity) == 1;
                }
                catch (SEHException ex)
                {
                    if (ex.ErrorCode == -2147467259) // logic_error
                        throw new CannotPerformComparison(
                            "Comparison cannot be done! Measurement Unit types do not match.",
                            ex);

                    throw;
                }

            //TODO: implement proper logic
            return false;
        }

        public static bool operator !=(Quantity lft, Quantity rgh)
        {
            if (!(ReferenceEquals(null, lft) || ReferenceEquals(null, rgh)))
                try
                {
                    return __ne(lft._quantity, rgh._quantity) == 1;
                }
                catch (SEHException ex)
                {
                    if (ex.ErrorCode == -2147467259) // logic_error
                        throw new CannotPerformComparison(
                            "Comparison cannot be done! Measurement Unit types do not match.", ex);

                    throw;
                }

            //TODO: implement proper logic
            return false;
        }

        //power
        public Quantity Pow(int rgh)
        {
            IntPtr temp = __pow(_quantity, rgh);
            return new Quantity(temp);
        }

        // nt roth
        public Quantity Root(int rgh)
        {
            try
            {
                IntPtr temp = __ntrt(_quantity, rgh);
                return new Quantity(temp);
            }
            catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                    throw new CannotPerformRootOperation($"Cannot perform {rgh}th root on {_quantity}!", ex);
                throw;
            }
        }

        public double Get(string u)
        {
            return __get(_quantity, u);
        }

        public static implicit operator double(Quantity q)
        {
            try
            {
                return __double(q._quantity);
            }
            catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                    throw new UnableToCastToDouble("Unit cannot be converted to double!!", ex);
                throw;
            }
        }

        public Metrics GetUnitType()
        {
            return (Metrics) __getType(_quantity);
        }

        public void SConvert(string newUnit)
        {
            double newValue = Get(newUnit);
            Metrics unitType =  GetUnitType(); 
            DeleteQuantity(_quantity); // disposing old quantity
            _quantity = CreateQuantity((int) unitType, newValue, newUnit);
        }

        public Quantity DeepCopy()
        {
            return new Quantity(this);
        }
    }
}