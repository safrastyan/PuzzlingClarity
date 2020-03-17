import unittest

from wod.Base import Names  

import os

class TestPathMethods(unittest.TestCase):

    def test_basic(self):
        self.assertTrue(Names.Project.projectName == "PuzzlingClarity")
        

if __name__ == '__main__':
    unittest.main()
