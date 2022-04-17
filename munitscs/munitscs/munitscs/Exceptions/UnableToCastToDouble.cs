using System;

namespace munitscs.Exceptions
{
    public class UnableToCastToDouble : QuantityException
    {
        public UnableToCastToDouble()
        {
        }

        public UnableToCastToDouble(string message) : base(message)
        {
        }

        public UnableToCastToDouble(string message, Exception inner) : base(message, inner)
        {
        }
    }
}