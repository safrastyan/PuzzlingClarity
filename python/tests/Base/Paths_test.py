import unittest

from wod.Base import Paths, Names 

import os

class TestPathMethods(unittest.TestCase):

    def test_path(self):
        self.assertTrue(len(Paths.path()) > 0)

    def test_resource_path(self):
        self.assertTrue(len(Paths.resource_path()) > 0)
        self.assertTrue(len(Paths.resource_path()) > len(Paths.path()))
    
    

if __name__ == '__main__':
    unittest.main()
