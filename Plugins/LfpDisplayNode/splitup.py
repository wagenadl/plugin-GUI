#!/usr/bin/python3

import re

c = re.compile(' - (.*?)( -?|$)')

with open('LfpDisplayCanvas.cpp', 'r') as fh:
    txt = fh.read()

hdr = ''
fh = None
for line in txt.split('\n'):
    print('*', line, '*')
    if 'pragma' in line:
        if fh is not None:
            fh.close()
            
        name = c.search(line).group(1)
        fh = open(name + '.cpp', 'w')
        fh.write(hdr)
        fh.write(f'#include "{name}.h"\n\n')
    else:
        if fh is None:
            hdr += line + '\n'
        else:
            fh.write(line + '\n')
            
            
