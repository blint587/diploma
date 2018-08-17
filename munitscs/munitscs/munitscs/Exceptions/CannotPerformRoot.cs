using System;

namespace munitscs.Exceptions
{
    public class CannotPerformRootOperation : QuantityException
    {
        public CannotPerformRootOperation()
        {
        }

        public CannotPerformRootOperation(string message) : base(message)
        {
        }

        public CannotPerformRootOperation(string message, Exception inner) : base(message, inner)
        {
        }
    }
}