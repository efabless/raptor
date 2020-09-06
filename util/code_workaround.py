import time
import sys, os

if len(sys.argv) < 2:
    print("Usage: code_workaround.py <file>")
    sys.exit()

input_file_path = sys.argv[1]
copy_file_path = sys.argv[1] + ".orig"

first_pass = True

while first_pass:
    first_pass = False
    bug_detected = False
    # check if bug trigger exists.  if yes, copy original file
    with open(input_file_path, mode='r') as fin:
        line = fin.readline()
        while line != '':
            p = line.split('\t')
            # if len(p) > 2 and p[1] == 'pop' and p[2][len(p[2])-4:len(p[2])-2] == 'pc':
            if len(p) > 2 and (p[1] == 'pop' or p[1] == 'push'):
                r = p[2][1:len(p[2]) - 1].split(",")
                if len(r) > 3:
                    bug_detected = True
                    if first_pass:
                        print("****  BUG TRIGGER DETECTED - modifying code")
                    else:
                        print("****  BUG TRIGGER DETECTED - second pass check")
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
                r = ""
                # if len(p) > 2 and p[1] == 'pop' and p[2][len(p[2]) - 4:len(p[2]) - 2] == 'pc':
                if len(p) > 2 and p[1] == 'pop':
                    x = p[2].find("}")
                    r = p[2][1:x]
                    r = r.split(",")
                    if len(r) > 3:
                        # new_line_1 = "\tpop {"
                        new_line_1 = "\t"+p[1]+" {"
                        for i in range(0, len(r)-3):
                            new_line_1 += "{}, ".format(r[i])
                        new_line_1 += "{}".format(r[len(r)-3]) + "}"
                        new_line_2 = "\t"+p[1]+" {"
                        new_line_2 += "{}, {}".format(r[len(r)-2], r[len(r)-1]) + " }"
                        print("**** modified code for workaround\n")
                        fout.write("@ **** modified code for workaround\n")
                        fout.write("@ " + line)
                        fout.write(new_line_1 + '\n')
                        fout.write("\tnop\n")
                        # print(new_line_1 + '\n')
                        fout.write(new_line_2 + '\n')
                        # print(new_line_2 + '\n')
                    else:
                        fout.write(line)
                elif len(p) > 2 and p[1] == 'push':
                    x = p[2].find("}")
                    r = p[2][1:x]
                    r = r.split(",")
                    if len(r) > 3:
                        # new_line_1 = "\tpop {"
                        new_line_1 = "\t" + p[1] + " {"
                        for i in range(0, len(r) - 3):
                            new_line_1 += "{}, ".format(r[i])
                        new_line_1 += "{}".format(r[len(r) - 3]) + "}"
                        new_line_2 = "\t" + p[1] + " {"
                        new_line_2 += "{}, {}".format(r[len(r) - 2], r[len(r) - 1]) + " }"
                        print("**** modified code for workaround\n")
                        fout.write("@ **** modified code for workaround\n")
                        fout.write("@ " + line)
                        fout.write(new_line_2 + '\n')
                        fout.write("\tnop\n")
                        # print(new_line_1 + '\n')
                        fout.write(new_line_1 + '\n')
                        # print(new_line_2 + '\n')
                    else:
                        fout.write(line)
                else:
                    fout.write(line)
                line = fin.readline()
