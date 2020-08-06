#include <maya/MFnPlugin.h>
#include "listConnect.h"

MStatus initializePlugin( MObject obj )
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "lictConnect", "2018", "Any");
	plugin.registerCommand("listConnect", listConnect::creator);
	MGlobal::displayInfo("加载插件成功");

	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MStatus   status;
	MFnPlugin plugin( obj );
	plugin.deregisterCommand("listConnect");
	MGlobal::displayInfo("卸载插件成功");

	return status;
}
