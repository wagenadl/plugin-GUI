#plugin build file
cmake_minimum_required(VERSION 3.5.0)

#include common rules
include(../PluginRules.cmake)

#add sources, not including OpenEphysLib.cpp
add_sources(${PLUGIN_NAME}
	LfpDisplayNode.cpp
	LfpDisplayNode.h
	LfpDisplayEditor.cpp
	LfpDisplayEditor.h
	LfpDisplayCanvas.cpp
	LfpDisplayCanvas.h
        EventDisplayInterface.h
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
	SupersampledBitmapPlotter.h        
	)
	
#optional: create IDE groups
#plugin_create_filters()
