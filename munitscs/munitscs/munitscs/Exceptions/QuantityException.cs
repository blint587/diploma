using System;

namespace munitscs.Exceptions
{
    public class QuantityException: Exception
    {
        public QuantityException(){}
        public QuantityException(string message): base(message){}
        public QuantityException(string message, Exception inner): base(message, inner){} 
    }
}