import cmath
import math

class phasor:
    def __init__(self, *args): # args should be provided as (magnitude, phase) or (complex_num)
        if(len(args) == 1): # complex number input
            self.magnitude = abs(args[0])
            self.phase = math.degrees(cmath.phase(args[0]))
            self.real = args[0].real
            self.imag = args[0].imag
        else: # magnitude, phase input
            self.magnitude = args[0]
            self.phase = args[1]
            self.real = self.magnitude * cmath.cos(math.radians(self.phase))
            self.imag = self.magnitude * cmath.sin(math.radians(self.phase))

    def __str__(self):
        return f"{self.magnitude:.3f}\u2220 {self.phase:.3f}\u00b0"
    
    def __add__(self, other):
        real = self.real + other.real
        imag = self.imag + other.imag
        return phasor(complex(real, imag))

    def __sub__(self, other):
        real = self.real - other.real
        imag = self.imag - other.imag
        return phasor(complex(real, imag))

    # TODO: Handle negative magnitudes
    def __mul__(self, other):
        magnitude = self.magnitude * other.magnitude
        phase = (self.phase + other.phase) % 360
        return phasor(magnitude, phase)

    def __truediv__(self, other):
        magnitude = self.magnitude / other.magnitude
        phase = (self.phase - other.phase) % 360
        return phasor(magnitude, phase)

def get_magnitude(complex_num):
    return abs(complex_num)

def get_phase(complex_num):
    return cmath.phase(complex_num)
