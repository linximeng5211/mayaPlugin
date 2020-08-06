#include <maya/MFnPlugin.h>
#include "listConnect.h"

MStatus initializePlugin( MObject obj )
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "lictConnect", "2018", "Any");
	plugin.registerCommand("listConnect", listConnect::creator);
	MGlobal::displayInfo("���ز���ɹ�");

	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MStatus   status;
	MFnPlugin plugin( obj );
	plugin.deregisterCommand("listConnect");
	MGlobal::displayInfo("ж�ز���ɹ�");

	return status;
}
