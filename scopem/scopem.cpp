/*
 * scopem.h
 *
 * GL-based scope & spectrum analysis VST.
 *
 * @author Andrew Ford
 */

#include "scopem.h"
#include "WrapperGUI.h"
#include "ControlGUI.h"

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

	for( int i = 0; i < numSParams; i++ )
	{
		parameters[ i ] = 0.0f;
	}

	numChannels = 2;
	setNumInputs( numChannels );
	setNumOutputs( numChannels );

	canProcessReplacing( true );

	setUniqueID( 'scpm' );

	gui = new WrapperGUI( this );
	setEditor( gui );
}

scopem::~scopem()
{

}

void scopem::processReplacing( float** inputs, float** outputs, VstInt32 sampleFrames )
{
	for( int i = 0; i < sampleFrames; i++ )
	{
		gui->addToBuffer( ( inputs[0][i] + inputs[1][i] ) / 2.0f );
	}
}

void scopem::setParameter( VstInt32 index, float value )
{
	parameters[ index ] = value;

	if ( editor )
	{
		( ( MultiGUIEditor* )editor )->setParameter( index, value );
	}
}

float scopem::getParameter( VstInt32 index )
{
	return parameters[ index ];
}

void scopem::getParameterLabel( VstInt32 index, char* text )
{
	strcpy( text, " " );
}

void scopem::getParameterDisplay( VstInt32 index, char* text )
{
	float2string( parameters[ index ], text, kVstMaxParamStrLen );
}

void scopem::getParameterName( VstInt32 index, char* text )
{
	switch( index )
	{
	mode:
		strcpy( text, "Mode" );
		break;
	amplitude:
		strcpy( text, "Amplitude" );
		break;
	frequency:
		strcpy( text, "Frequency" );
		break;
	default:
		strcpy( text, "" );
	}
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

float scopem::scaleParameter( int param, float value )
{
	float out = value;
	switch( param )
	{
	case amplitude:
		out = linearScale( out, 0.5f, 2.0f );
		break;
	case frequency:
		out = linearScale( out, 20.0f, 5000.0f );
		break;
	}
	return out;
}

float scopem::linearScale( float in, float min, float max )
{
	float ret;
	if ( min == 0.0f && max == 0.0f )
	{
		ret = 0.0f;
	}
	else if ( min > max )
	{
		ret = min - ( in * ( min - max ) );
	}
	else
	{
		ret = min + ( in * ( max - min ) );
	}
	return ret;
}

float scopem::linearDescale( float in, float min, float max )
{
	float ret;
	if ( min == 0.0f && max == 0.0f )
	{
		ret = 0.0f;
	}
	else if ( min > max )
	{
		ret = ( min - in ) / ( min - max );
	}
	else
	{
		ret = ( in - min ) / ( max - min );
	}
	return ret;
}
