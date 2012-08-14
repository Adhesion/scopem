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

enum
{
	mode = 0,
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

private:
	char name[ kVstMaxEffectNameLen ];
	char vendor[ kVstMaxVendorStrLen ];
	VstInt32 version;

	float parameters[ numSParams ];

	int numChannels;

	WrapperGUI* gui;
};

#endif
