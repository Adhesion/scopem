/*
 * WrapperGUI.cpp
 *
 * MultiGUI wrapper class to contain GL & normal editors.
 *
 * @author Andrew Ford
 */

#include "WrapperGUI.h"

WrapperGUI::WrapperGUI( AudioEffect* effect )
	: MultiGUIEditor( effect )
{

}

WrapperGUI::~WrapperGUI()
{

}

void WrapperGUI::setParameter( VstInt32 index, float value )
{
	gl->setParameter( index, value );
	control->setParameter( index, value );
}
