#!/usr/bin/python3

import sys
from ctypes import *

def main():
    lib = cdll.LoadLibrary(sys.argv[1])
    entry = getattr(lib, "main")
    argv = [  ]
    i = 0
    for s in sys.argv:
        if i != 0:
            argv.append(s.encode("utf-8"))
        i += 1
    argvptr = (c_char_p * len(argv))(*argv)
    return entry(len(argv), argvptr)

sys.exit(main())
