import time
import sys, os

if len(sys.argv) < 2:
    print("Usage: code_workaround.py <file>")
    sys.exit()

input_file_path = sys.argv[1]
copy_file_path = sys.argv[1] + ".orig"

bug_detected = False

# check if bug trigger exists.  if yes, copy original file
with open(input_file_path, mode='r') as fin:
    line = fin.readline()
    while line != '':
        p = line.split('\t')
        if len(p) > 2 and p[1] == 'pop' and p[2][len(p[2])-4:len(p[2])-2] == 'pc':
            r = p[2][1:len(p[2]) - 1].split(",")
            if len(r) > 4:
                bug_detected = True
                print("****  BUG TRIGGER DETECTED - modifying code")
                fin.seek(0)
                fout = open(copy_file_path, mode='w')
                # fin.close()
                # fin = open(input_file_path, "r")
                line = fin.readline()
                while line != '':
                    fout.write(line)
                    line = fin.readline()
                fout.close()
                break
        line = fin.readline()

if bug_detected:
    with open(copy_file_path, mode='r') as fin:
        fout = open(input_file_path, mode='w')
        line = fin.readline()
        while line != '':
            p = line.split('\t')
            if len(p) > 2 and p[1] == 'pop' and p[2][len(p[2]) - 4:len(p[2]) - 2] == 'pc':
                r = p[2][1:len(p[2])-1].split(",")
                if len(r) > 4:
                    new_line_1 = "\tpop {"
                    for i in range(0, len(r)-3):
                        new_line_1 += "{}, ".format(r[i])
                    new_line_1 += "{}".format(r[len(r)-3]) + "}"
                    new_line_2 = "\tpop {"
                    new_line_2 += "{}, pc".format(r[len(r)-2]) + "}"
                    print("**** modified code for workaround\n")
                    fout.write("@ **** modified code for workaround\n")
                    fout.write("@ " + line)
                    fout.write(new_line_1 + '\n')
                    fout.write(new_line_2 + '\n')
                else:
                    fout.write(line)
            else:
                fout.write(line)
            line = fin.readline()


