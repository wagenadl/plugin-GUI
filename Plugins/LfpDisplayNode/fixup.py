#!/usr/bin/python3

files = '''EventDisplayInterface.h
	LfpBitmapPlotter.h
	LfpBitmapPlotterInfo.h
	LfpChannelColourScheme.h
	LfpChannelDisplay.h
	LfpChannelDisplayInfo.h
	LfpDefaultColorScheme.h
	LfpDisplay.h
	LfpDisplayOptions.h
	LfpGradientColourScheme.h
	LfpMonochromaticColourScheme.h
	LfpTimescale.h
	LfpViewport.h
	PerPixelBitmapPlotter.h
	ShowHideOptionsButton.h
	SupersampledBitmapPlotter.h'''.split('\n')

gpl = '''/*
    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2016 Open Ephys

    ------------------------------------------------------------------

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
'''


for fn in files:
    fn = fn.strip()
    with open(fn, 'r') as fh:
        txt = fh.read()
        
    with open(fn, 'w') as fh:
        fh.write(gpl)
        upfn = fn.upper().replace('.', '_')
        fh.write(f'''
#ifndef __{upfn}__
#define __{upfn}__

#include <VisualizerWindowHeaders.h>

namespace LfpViewer
{{
''')
        fh.write(txt)

        fh.write(f'''
}};
#endif
''')
        
