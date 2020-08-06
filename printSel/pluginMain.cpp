#include <maya/MFnPlugin.h>
#include "printSel.h"

MStatus initializePlugin( MObject obj )
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "printSel", "2018", "Any");
	plugin.registerCommand("printSel", printSel::creator);

	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MStatus   status;
	MFnPlugin plugin( obj );
	plugin.deregisterCommand("printSel");

	return status;
}
