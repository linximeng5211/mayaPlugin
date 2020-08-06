#include <maya/MFnPlugin.h>
#include "createLight.h"

MStatus initializePlugin( MObject obj )
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "creatLight", "2018", "Any");
	plugin.registerCommand("creatLight", createLight::creator);
	MGlobal::displayInfo("�ɹ����ش����ƹ���");

	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MStatus   status;
	MFnPlugin plugin( obj );
	plugin.deregisterCommand("creatLight");
	MGlobal::displayInfo("�ɹ�ж�ش����ƹ���");

	return status;
}
