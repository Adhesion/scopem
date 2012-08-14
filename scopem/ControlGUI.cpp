/*
 * ControlGUI.cpp
 *
 * VST GUI editor with the main controls.
 *
 * @author Andrew Ford
 */

#include "ControlGUI.h"

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
	frame = new CFrame( frameSize, ptr, this );

	return true;
}

void ControlGUI::close()
{
	if ( frame != NULL )
	{
		delete frame;
		frame = NULL;
	}
}

void ControlGUI::setParameter( VstInt32 index, float value )
{

}

void ControlGUI::valueChanged( CDrawContext* context, CControl* control )
{
	// TODO figure out parameter # from control
	// map of params to controls?
	effect->setParameterAutomated( 0, control->getValue() );
}
