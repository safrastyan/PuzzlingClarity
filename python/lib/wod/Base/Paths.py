import os

def path():
    return os.environ["PCPATH"]

def resource_path():
    return os.environ["PCPATH"] + "/resources"

