using System;
using System.Runtime.InteropServices;
using System.Text;
using munitscs.Exceptions;

namespace munitscs
{
    public class Quantity
    {

        private const string LibName = "munits";
    

        private const CharSet Char = CharSet.Unicode;
        private const CallingConvention CallConv = CallingConvention.StdCall;
        
        private IntPtr _quantity;
        
        
        //C++ function imports
        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr CreateQuantity(int metric, double value, byte[] unit);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern void DeleteQuantity(IntPtr q);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern void __toString(IntPtr q, byte[] sb,
            ref uint bufferSize);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern double __getValue(IntPtr qm);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern void __getUnit(IntPtr q, byte[] sb,
            ref uint bufferSize);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __add(IntPtr lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __substract(IntPtr lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __multiply(IntPtr lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __multiply_rgh_int(IntPtr lft, int rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __multiply_lft_int(int lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __multiply_lft_double(double lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __multiply_rgh_double(IntPtr lft, double rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __divide(IntPtr lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __divide_int(IntPtr lft, int rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __divide_double(IntPtr lft, double rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern int __lt(IntPtr lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern int __gt(IntPtr lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern int __le(IntPtr lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern int __ge(IntPtr lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern int __eq(IntPtr lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern int __ne(IntPtr lft, IntPtr rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __power(IntPtr lft, int rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern IntPtr __ntrt(IntPtr lft, int rgh);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern double __get(IntPtr lft, byte[] u);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern double __double(IntPtr q);

        [DllImport(LibName, CallingConvention = CallConv, CharSet = Char)]
        private static extern int __getType(IntPtr q);


        public Quantity(Metrics metric, double value, string unit)
        {
//            string _unit =  
            try
            {
                byte[] nunit = Encoding.UTF8.GetBytes(unit);
                _quantity = CreateQuantity((int) metric, value, nunit);
            }
            catch (SEHException ex)
            {
                Console.WriteLine(ex.ToString());
                throw;
            }
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
            var sb = new byte[(int)bufferSize]; // creating buffer with the neceseary size
            __toString(_quantity, sb, ref bufferSize); // doing the actual copy 
            return Encoding.UTF8.GetString(sb).Replace("\0", string.Empty);
        }

        public double GetValue()
        {
            return __getValue(_quantity);
        }

        public string GetUnit()
        {
            UInt32 bufferSize = 0;
            
            __getUnit(_quantity, null, ref bufferSize); // first call to determine buffer size 
            var sb = new byte[(int) bufferSize]; // creating buffer with the neceseary size
            __getUnit(_quantity, sb, ref bufferSize); // doing the actual copy 
            return Encoding.UTF8.GetString(sb).Replace("\0", string.Empty);
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
        public static Quantity Pow(Quantity q, int rgh)
        {
            IntPtr temp = __power(q._quantity, rgh);
            return new Quantity(temp);
        }

        // nt roth
        public static Quantity Root(Quantity q, int rgh)
        {
            try
            {
                IntPtr temp = __ntrt(q._quantity, rgh);
                return new Quantity(temp);
            }
            catch (SEHException ex)
            {
                if (ex.ErrorCode == -2147467259) // logic_error
                    throw new CannotPerformRootOperation($"Cannot perform {rgh}th root on {q._quantity}!", ex);
                throw;
            }
        }

        public double Get(string u)
        {
            byte[] nunit = Encoding.UTF8.GetBytes(u);
            return __get(_quantity, nunit);
        }

        public static explicit operator double(Quantity q)
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

        public static implicit operator string(Quantity q)
        {
            return q.ToString();
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
            byte[] nunit = Encoding.UTF8.GetBytes(newUnit);
            
            _quantity = CreateQuantity((int) unitType, newValue, nunit);
        }

        public Quantity Convert(string newUnit)
        {
            double newValue = Get(newUnit);
            Metrics unitType =  GetUnitType();
            
            return new Quantity(unitType, newValue, newUnit);
            
        }

        public Quantity DeepCopy()
        {
            return new Quantity(this);
        }
    }
}