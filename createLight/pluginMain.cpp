#include <maya/MFnPlugin.h>
#include "createLight.h"

MStatus initializePlugin( MObject obj )
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "creatLight", "2018", "Any");
	plugin.registerCommand("creatLight", createLight::creator);
	MGlobal::displayInfo("成功加载创建灯光插件");

	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MStatus   status;
	MFnPlugin plugin( obj );
	plugin.deregisterCommand("creatLight");
	MGlobal::displayInfo("成功卸载创建灯光插件");

	return status;
}
