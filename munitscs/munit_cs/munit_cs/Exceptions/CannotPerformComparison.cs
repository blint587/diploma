using System;

namespace munitscs.Exceptions
{
    public class CannotPerformComparison : QuantityException
    {
        public CannotPerformComparison()
        {
        }

        public CannotPerformComparison(string message) : base(message)
        {
        }

        public CannotPerformComparison(string message, Exception inner) : base(message, inner)
        {
        }
    }
}