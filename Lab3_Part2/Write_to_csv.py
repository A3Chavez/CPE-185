#!/usr/bin/python

file = open("testfile.csv","w")

file.write("Name,Age,Units,\n")
file.write("John Smith,20,12,\n")
file.write("Jane Smith,23,15,\n")

file.close()
