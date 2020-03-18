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
for fn in files:
    fn = fn.strip()
    with open(fn, 'r') as fh:
        txt = fh.read()
        
    
