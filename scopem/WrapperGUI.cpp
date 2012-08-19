/*
 * WrapperGUI.cpp
 *
 * MultiGUI wrapper class to contain GL & normal editors.
 *
 * @author Andrew Ford
 */

#include "WrapperGUI.h"
#include "scopem.h"

WrapperGUI::WrapperGUI( AudioEffect* effect )
	: MultiGUIEditor( effect )
{
	gl = new GLGUI( effect );
	control = new ControlGUI( effect );

	NiallsRect tempSize;
	ERect* subSize;

	gl->getRect( &subSize );
	tempSize.x = 0;
	tempSize.y = 0;
	tempSize.width = subSize->right - subSize->left;
	tempSize.height = subSize->bottom - subSize->top;
	addEditor( gl, tempSize );

	tempSize.y = subSize->bottom;
	control->getRect( &subSize );
	tempSize.x = 0;
	tempSize.width = subSize->right - subSize->left;
	tempSize.height = subSize->bottom - subSize->top;
	addEditor( control, tempSize );
}

WrapperGUI::~WrapperGUI()
{

}

void WrapperGUI::setParameter( long index, float value )
{
	// gl gui needs to know scaled values, gui controls in control need 0-1
	gl->setParameter( index,
		( ( scopem* )effect )->scaleParameter( index, value ) );
	control->setParameter( index, value );
}

void WrapperGUI::addToBuffer( float in )
{
	gl->addToBuffer( in );
}
