import os
import sys

dirlist = ['arcout','arcreco','images','outimj','subjectX','videos','yououtimj','restored','build']

for dir in dirlist:
    if not os.path.exists(dir):
        os.makedirs(dir)
        print(f"created {dir}")

os.system("cd build && cmake ..")