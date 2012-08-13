/*
 * scopem.h
 *
 * GL-based scope & spectrum analysis VST.
 *
 * @author Andrew Ford
 */

#include "scopem.h"

AudioEffect* createEffectInstance( audioMasterCallback master )
{
	return new scopem( master );
}

scopem::scopem( audioMasterCallback master )
	: AudioEffectX( master, 1, numSParams )
{
	strcpy( name, "scopem" );
	strcpy( vendor, "Adhesion" );

	version = 100;

	numChannels = 2;
	setNumInputs( numChannels );
	setNumInputs( numChannels );

	canProcessReplacing( true );

	setUniqueID( 'scpm' );
}

scopem::~scopem()
{

}

void scopem::processReplacing( float** inputs, float** outputs, VstInt32 sampleFrames )
{

}

void scopem::setParameter( VstInt32 index, float value )
{
	parameters[ index ] = value;
}

float scopem::getParameter( VstInt32 index )
{
	return parameters[ index ];
}

void scopem::getParameterLabel( VstInt32 index, char* text )
{

}

void scopem::getParameterDisplay( VstInt32 index, char* text )
{

}

void scopem::getParameterName( VstInt32 index, char* text )
{

}

bool scopem::getEffectName( char* eName )
{
	strcpy( eName, name );
	return true;
}

bool scopem::getProductString( char* pString )
{
	strcpy( pString, name );
	return true;
}

bool scopem::getVendorString( char* vString )
{
	strcpy( vString, vendor );
	return true;
}

VstInt32 scopem::getVendorVersion()
{
	return version;
}
