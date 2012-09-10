/*
 * scopem.h
 *
 * GL-based scope & spectrum analysis VST.
 *
 * @author Andrew Ford
 */

#ifndef __SCOPEM_H
#define __SCOPEM_H

#include "audioeffectx.h"

class WrapperGUI;
class ControlGUI;

enum
{
	mode = 0,
	amplitude,
	frequency,
	numSParams
};

class scopem : public AudioEffectX
{
public:
	scopem( audioMasterCallback master );
	~scopem();

	void processReplacing( float** inputs, float** outputs, VstInt32 sampleFrames );
	
	void setParameter( VstInt32 index, float value );
	float getParameter( VstInt32 index );
	void getParameterLabel( VstInt32 index, char* text );
	void getParameterDisplay( VstInt32 index, char* text );
	void getParameterName( VstInt32 index, char* text );

	bool getEffectName( char* eName );
	bool getProductString( char* pString );
	bool getVendorString( char* vString );
	VstInt32 getVendorVersion();

	float scaleParameter( int param, float value );

private:
	char name[ kVstMaxEffectNameLen ];
	char vendor[ kVstMaxVendorStrLen ];
	VstInt32 version;

	float parameters[ numSParams ];

	float ampMin;
	float ampMax;
	float freqMin;
	float freqMax;

	int numChannels;

	WrapperGUI* gui;
};

#endif
