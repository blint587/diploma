from libcpp.string cimport string
from munitscpp cimport Quantity, metrics
from cython.operator cimport dereference as deref

cdef class PyQuantity:

    cdef :
        Quantity *_thisptr

    def __cinit__(self, metrics metric=_Last, double value=0., str unit="", PyQuantity other=None ):
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
        if 0 == op:
            return deref(self._thisptr) < deref(other._thisptr)
        elif 1 == op:
            return deref(self._thisptr) <= deref(other._thisptr)
        elif 2 == op:
            return deref(self._thisptr) == deref(other._thisptr)
        elif 3 == op:
            return deref(self._thisptr) != deref(other._thisptr)
        elif 4 == op:
            return deref(self._thisptr) > deref(other._thisptr)
        elif 5 == op:
            return deref(self._thisptr) >= deref(other._thisptr)

    def __call__(PyQuantity self, str unit):
        return self._thisptr[0](bytes(unit, "utf-8"))

    def __add__(PyQuantity self, PyQuantity other):
        cdef PyQuantity nobj = PyQuantity()
        nobj._thisptr = new Quantity(deref(self._thisptr) +  deref(other._thisptr))
        return nobj

    def __mul__(PyQuantity self, PyQuantity other):
        cdef PyQuantity nobj = PyQuantity()
        nobj._thisptr = new Quantity(deref(self._thisptr) *  deref(other._thisptr))
        return nobj

    def __sub__(PyQuantity self, PyQuantity other):
        cdef PyQuantity nobj = PyQuantity()
        nobj._thisptr = new Quantity(deref(self._thisptr) -  deref(other._thisptr))
        return nobj


    def __truediv__(PyQuantity self, PyQuantity other):
        cdef PyQuantity nobj = PyQuantity()
        nobj._thisptr = new Quantity(deref(self._thisptr) / deref(other._thisptr) )
        return nobj

    __div__ = __truediv__

    def __pow__(PyQuantity self, int exp, modulo=None):
        cdef PyQuantity nobj = PyQuantity()
        nobj._thisptr = new Quantity(pow(deref(self._thisptr), exp))
        return nobj

    def __str__(PyQuantity self):
        return self._thisptr.toString().decode("utf-8")

    @property
    def matrix_index(PyQuantity self):
        return self._thisptr.getMatrixIndex()

NPOS = _Last