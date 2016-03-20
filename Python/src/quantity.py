class Quantity():
    # 1. length
    # 2. mass
    # 3. time
    # 4. electric_current
    # 5. temperature
    # 6. amount_of_substance
    # 7. luminous_intensity
    dim_vector = (0, 0, 0, 0, 0, 0, 0)
    unit_vector = ["", "", "", "", "", "", ""]

    def __init__(self, value, unit):
        self.__value = value
        self.__unit = unit

    def __truediv__(self, other):
        if isinstance(other, Quantity):
            dim_vector = (
                self.dim_vector[0] - other.dim_vector[0],
                self.dim_vector[1] - other.dim_vector[1],
                self.dim_vector[2] - other.dim_vector[2],
                self.dim_vector[3] - other.dim_vector[3],
                self.dim_vector[4] - other.dim_vector[4],
                self.dim_vector[5] - other.dim_vector[5],
                self.dim_vector[6] - other.dim_vector[6],
            )
            unit_vector = [
                self.unit_vector[0] + other.unit_vector[0] if self.unit_vector[0] != other.unit_vector[0] else
                self.unit_vector[0],
                self.unit_vector[1] + other.unit_vector[1] if self.unit_vector[1] != other.unit_vector[1] else
                self.unit_vector[1],
                self.unit_vector[2] + other.unit_vector[2] if self.unit_vector[2] != other.unit_vector[2] else
                self.unit_vector[2],
                self.unit_vector[3] + other.unit_vector[3] if self.unit_vector[3] != other.unit_vector[3] else
                self.unit_vector[3],
                self.unit_vector[4] + other.unit_vector[4] if self.unit_vector[4] != other.unit_vector[4] else
                self.unit_vector[4],
                self.unit_vector[5] + other.unit_vector[5] if self.unit_vector[5] != other.unit_vector[5] else
                self.unit_vector[5],
                self.unit_vector[6] + other.unit_vector[6] if self.unit_vector[6] != other.unit_vector[6] else
                self.unit_vector[6],
            ]
            new = Quantity(self.value / other.value, "")
            new.dim_vector = dim_vector
            new.unit_vector = unit_vector
            return new
        else:
            raise TypeError

    def __str__(self):
        return "{0} {1}".format(self.value, self.unit)

    def __mul__(self, other):
        if isinstance(other, Quantity):
            dim_vector = (
                self.dim_vector[0] + other.dim_vector[0],
                self.dim_vector[1] + other.dim_vector[1],
                self.dim_vector[2] + other.dim_vector[2],
                self.dim_vector[3] + other.dim_vector[3],
                self.dim_vector[4] + other.dim_vector[4],
                self.dim_vector[5] + other.dim_vector[5],
                self.dim_vector[6] + other.dim_vector[6],
            )
            unit_vector = [
                self.unit_vector[0] + other.unit_vector[0] if self.unit_vector[0] != other.unit_vector[0] else
                self.unit_vector[0],
                self.unit_vector[1] + other.unit_vector[1] if self.unit_vector[1] != other.unit_vector[1] else
                self.unit_vector[1],
                self.unit_vector[2] + other.unit_vector[2] if self.unit_vector[2] != other.unit_vector[2] else
                self.unit_vector[2],
                self.unit_vector[3] + other.unit_vector[3] if self.unit_vector[3] != other.unit_vector[3] else
                self.unit_vector[3],
                self.unit_vector[4] + other.unit_vector[4] if self.unit_vector[4] != other.unit_vector[4] else
                self.unit_vector[4],
                self.unit_vector[5] + other.unit_vector[5] if self.unit_vector[5] != other.unit_vector[5] else
                self.unit_vector[5],
                self.unit_vector[6] + other.unit_vector[6] if self.unit_vector[6] != other.unit_vector[6] else
                self.unit_vector[6],
            ]
            new = Quantity(self.value * other.value, "")
            new.dim_vector = dim_vector
            new.unit_vector = unit_vector
            return new
        else:
            raise TypeError

    @property
    def value(self):
        return self.__value

    @value.setter
    def value(self, x):
        self.__value = x

    @property
    def unit(self):
        return "_".join(filter(lambda x: x, ["{}{}".format(unit, self.dim_vector[index] if self.dim_vector[index] != 1 else "")
                        if unit else "" for index, unit in enumerate(self.unit_vector)]))


class Length(Quantity):
    dim_vector = (1, 0, 0, 0, 0, 0, 0)
    unit_vector = ["m", "", "", "", "", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class Mass(Quantity):
    dim_vector = (0, 1, 0, 0, 0, 0, 0)
    unit_vector = ["", "kg", "", "", "", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class Time(Quantity):
    dim_vector = (0, 0, 1, 0, 0, 0, 0)
    unit_vector = ["", "", "s", "", "", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class ElectricCurrency(Quantity):
    dim_vector = (0, 0, 0, 1, 0, 0, 0)
    unit_vector = ["", "", "", "A", "", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class Temperature(Quantity):
    dim_vector = (0, 0, 0, 0, 1, 0, 0)
    unit_vector = ["", "", "", "", "K", "", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class AmountOfSubstance(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 1, 0)
    unit_vector = ["", "", "", "", "", "mol", ""]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


class LuminousIntensity(Quantity):
    dim_vector = (0, 0, 0, 0, 0, 0, 1)
    unit_vector = ["", "", "", "", "", "", "cd"]

    def __init__(self, value, unit):
        Quantity.__init__(self, value, unit)


# class Velocity(Quantity):
#     dim_vector = (1, 0, -1, 0, 0, 0, 0)
#     unit_vector = ["", "", "", "", "", "", ""]
#
#     def __init__(self, value, unit):
#         Quantity.__init__(self, value, unit)
#
#
# class Area(Quantity):
#     dim_vector = (2, 0, 0, 0, 0, 0, 0)
#
#     def __init__(self, value, unit):
#         Quantity.__init__(self, value, unit)
#
#
# class Volume(Quantity):
#     dim_vector = (3, 0, 0, 0, 0, 0, 0)
#
#     def __init__(self, value, unit):
#         Quantity.__init__(self, value, unit)
#
#


if __name__ == "__main__":
    distance = Length(15.0, "m")
    time = Time(10.0, "s")

    # velocity = distance / time
    # print(velocity)

    print(distance * distance * distance / time)
