import cmath
import math

class phasor:
    def __init__(self, *args): # args should be provided as (magnitude, phase) or (complex_num)
        if(len(args) == 1): # complex number input
            self.magnitude = calc_mag(args[0])
            self.phase = calc_phase(args[0])
            self.real = args[0].real
            self.imag = args[0].imag
        elif(len(args) == 2): # magnitude, phase input
            self.magnitude = args[0]
            self.phase = args[1]
            self.real = self.magnitude * cmath.cos(math.radians(self.phase))
            self.imag = self.magnitude * cmath.sin(math.radians(self.phase))
        else:
            self.magnitude = 0
            self.phase = 0
            self.real = 0
            self.imag = 0

    def __str__(self):
        return f"{self.magnitude:.3f}\u2220 {self.phase:.3f}\u00b0"
    
    def __add__(self, other: 'phasor') -> 'phasor':
        real = self.real + other.real
        imag = self.imag + other.imag
        return phasor(complex(real,imag))

    def __sub__(self, other: 'phasor') -> 'phasor':
        real = self.real - other.real
        imag = self.imag - other.imag
        return phasor(complex(real,imag))

    # TODO: Handle negative magnitudes
    def __mul__(self, other: 'phasor') -> 'phasor':
        magnitude = self.magnitude * other.magnitude
        phase = (self.phase + other.phase) % 360
        return phasor(magnitude, phase)

    def __truediv__(self, other: 'phasor') -> 'phasor':
        magnitude = self.magnitude / other.magnitude
        phase = (self.phase - other.phase) % 360
        return phasor(magnitude, phase)

    def __eq__(self, other: 'phasor') -> bool:
        if(cmath.isclose(self.magnitude, other.magnitude) and
                cmath.isclose(self.phase, other.phase)):
            return True
        else:
            return False

    def clear(self):
        self.magnitude = 0
        self.phase = 0
        self.real = 0
        self.imag = 0

    def set_magnitude(self, new_magnitude: float) -> None:
        self.magnitude = new_magnitude

    def set_phase(self, new_phase: float) -> None:
        self.phase = new_phase

    def get_magnitude(self) -> float:
        return self.magnitude

    def get_phase(self) -> float:
        return self.phase

    def get_real(self) -> float:
        return self.real

    def get_imag(self) -> float:
        return self.imag

def calc_mag(complex_num: complex) -> float:
    return abs(complex_num)

def calc_phase(complex_num: complex) -> float:
    return math.degrees(cmath.phase(complex_num))

def calc_real(num: phasor) -> complex:
    mag = num.get_magnitude()
    phase = num.get_phase()
    return mag*cmath.cos(phase)

def calc_imag(num: phasor) -> complex:
    mag = num.get_magnitude()
    phase = num.get_phase()
    return mag*cmath.sin(phase)
