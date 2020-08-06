#include "HelleMayaPlugin.h"

helloMayaPlugin::helloMayaPlugin()
{

}

helloMayaPlugin::~helloMayaPlugin()
{

}

MStatus helloMayaPlugin::doIt(const MArgList& args)
{
	//检测命令是否执行成功
	MStatus status;
	MGlobal::displayInfo("HelloWord!");

	return MS::kSuccess;
}

void* helloMayaPlugin::creator()
{
	return new helloMayaPlugin();
}