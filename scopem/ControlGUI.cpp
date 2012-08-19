/*
 * ControlGUI.cpp
 *
 * VST GUI editor with the main controls.
 *
 * @author Andrew Ford
 */

#include "ControlGUI.h"
#include "scopem.h"

#include <stdio.h>

ControlGUI::ControlGUI( AudioEffect* effect )
	: AEffGUIEditor( effect )
{
	rect.left = 0;
	rect.right = 512;
	rect.top = 0;
	rect.bottom = 128;

	frame = NULL;
}

ControlGUI::~ControlGUI()
{

}

bool ControlGUI::open( void* ptr )
{
	AEffGUIEditor::open( ptr );

	CRect frameSize( rect.left, rect.top, rect.right, rect.bottom );
	CFrame* tempFrame = new CFrame( frameSize, ptr, this );

	background = new CBitmap( backgroundID );
	sliderBackground = new CBitmap( sliderBackgroundID );
	sliderHandle = new CBitmap( sliderHandleID );

	tempFrame->setBackground( background );

	printf( "sliderback: %i, %i\n", sliderBackground->getWidth(), sliderBackground->getHeight() );
	printf( "sliderhandle: %i, %i\n", sliderHandle->getWidth(), sliderHandle->getHeight() );

	CRect size( 171, 14, 171 + sliderBackground->getWidth(), 14 + sliderBackground->getHeight() );
	CPoint point( 2, 0 );
	//size.offset( point.x, point.y );
	amplitudeControl = new CVerticalSlider( size, this, amplitude, size.top + 1,
		size.top + sliderBackground->getHeight() - sliderHandle->getHeight() - 1,
		sliderHandle, sliderBackground, point, kBottom );
	amplitudeControl->setValue( effect->getParameter( amplitude ) );
	amplitudeControl->setTransparency( false );
	tempFrame->addView( amplitudeControl );

	size( 300, 14, 300 + sliderBackground->getWidth(), 14 + sliderBackground->getHeight() );
	point( 2, 0 );
	frequencyControl = new CVerticalSlider( size, this, frequency, size.top + 1,
		size.top + sliderBackground->getHeight() - sliderHandle->getHeight() - 1,
		sliderHandle, sliderBackground, point, kBottom );
	frequencyControl->setValue( effect->getParameter( frequency ) );
	frequencyControl->setTransparency( false );
	tempFrame->addView( frequencyControl );

	frame = tempFrame;

	return true;
}

void ControlGUI::close()
{
	if ( frame != NULL )
	{
		delete frame;
		frame = NULL;
	}

	background->forget();
	sliderBackground->forget();
	sliderHandle->forget();
}

void ControlGUI::setParameter( VstInt32 index, float value )
{
	// TODO fix this, make into loop (check tags)
	// vector of controls? or map?
	if ( index == amplitude )
	{
		printf( "set parameter amplitude to %f\n", value );
		amplitudeControl->setValue( effect->getParameter( index ) );
	}
	else if ( index == frequency )
	{
		frequencyControl->setValue( effect->getParameter( index ) );
	}
}

void ControlGUI::valueChanged( CDrawContext* context, CControl* control )
{
	printf( "value change amplitude to %f\n", control->getValue() );
	effect->setParameterAutomated( control->getTag(), control->getValue() );
}
