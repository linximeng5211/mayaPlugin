# include "HelleMayaPlugin.h"
# include <maya/MFnPlugin.h>

MStatus initializePlugin( MObject obj )
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "HelloMayaPlugin", "2018", "Any");
	plugin.registerCommand("helloMayaPlugin", helloMayaPlugin::creator);

	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MStatus   status;
	MFnPlugin plugin( obj );
	plugin.deregisterCommand("helloMayaPlugin");

	return status;
}
