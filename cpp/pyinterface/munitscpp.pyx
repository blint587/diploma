from libcpp.string cimport string
from munitscpp cimport Quantity, metrics


cdef class PyQuantity:

    cdef :
        Quantity *_thisptr

    def __cinit__(self, metrics metric=_Last, double value=0, str unit="", PyQuantity other=None ):
        if other is None and metric!=_Last:
            self._thisptr = new Quantity(metric, value, bytes(unit, "utf-8"))
        elif other is not None:
            self._thisptr = new Quantity(other._thisptr[0])
        else:
            self._thisptr = NULL # initiating to nullptr

    def __dealloc__(self):
        if self._thisptr != NULL:
            del self._thisptr

    cdef int _check_alive(self) except -1:
        if self._thisptr == NULL:
            raise RuntimeError("Wrapped C++ object is deleted")
        else:
            return 0

    def __enter__(self):
        self._check_alive()
        return self

    def __exit__(self, exc_tp, exc_val, exc_tb):
        if self._thisptr != NULL:
            del self._thisptr
            self._thisptr = NULL # inform __dealloc__
        return False # propagate exceptions

    def __richcmp__(PyQuantity self, PyQuantity other, op):
        if op == 0:
            return self._thisptr[0] < other._thisptr[0]

    def __call__(PyQuantity self, str unit):
        return self._thisptr[0](bytes(unit, "utf-8"))

    def __add__(PyQuantity self, PyQuantity other):
        cdef PyQuantity nobj = PyQuantity()
        nobj._thisptr = new Quantity(self._thisptr[0] +  other._thisptr[0])
        return nobj

