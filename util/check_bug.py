import time
import sys, os

if len(sys.argv) < 2:
    print("Usage: check_bug.py <file>")
    sys.exit()

file_path = sys.argv[1]

bug_detected = False

with open(file_path, mode='r') as f:
    x = f.readline()
    while x != '':
        p = x.split('\t')
        # if len(p) > 3 and p[2] == 'pop':
        if len(p) > 3 and (p[2] == 'pop' or p[2] == 'push'):
            regs = p[3].split(',')
            reg_count = len(regs)
            # print("{}  {} r={}".format(p[2], p[3], len(r)))
            # if reg_count > 3:
            # if reg_count > 3 and regs[reg_count-1][1:3] == 'pc':
            if reg_count > 3:
                print("**** BUG TRIGGER DETECTED **** ==> {} {} {}".format(p[0], p[2], p[3]))
                bug_detected = True
        x = f.readline()

if bug_detected:
    exit(-1)
else:
    exit(0)

