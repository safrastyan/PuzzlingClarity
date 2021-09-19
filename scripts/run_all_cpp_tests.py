import os
import subprocess

path = os.environ["PCPATH"] + "/build/tests"

total = 0
failed = 0
for root, subdirs, files in os.walk(path):
    list_file_path = os.path.join(root, 'my-directory-list.txt')
    
    for filename in files:
        total += 1
        file_path = os.path.join(root, filename)
        print("Running test " , filename)
        ret = subprocess.call([file_path], shell=True)
        if ret != 0:
            failed += 1
            print("Failed test ", file_path)



print("Failed ", failed, " out of ", total, "tests")



