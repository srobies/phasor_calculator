import unittest
import phasor

class testPhasorClass(unittest.TestCase):

    def test_add(self):
        # Purely real
        phasor1 = phasor.phasor(5)
        phasor2 = phasor.phasor(10)
        self.assertTrue(phasor1+phasor2 == phasor.phasor(15))

        # Purely imaginary
        phasor1 = phasor.phasor(5j)
        phasor2 = phasor.phasor(10j)
        self.assertTrue(phasor1+phasor2 == phasor.phasor(15j))
        
        # Complex
        phasor1 = phasor.phasor(1+1j)
        phasor2 = phasor.phasor(1-1j)
        self.assertTrue(phasor1+phasor2 == phasor.phasor(2))

        phasor1 = phasor.phasor(1+1j)
        phasor2 = phasor.phasor(-1+1j)
        self.assertTrue(phasor1+phasor2 == phasor.phasor(2j))
if __name__ == '__main__':
    unittest.main()
