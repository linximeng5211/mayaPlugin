#include "HelleMayaPlugin.h"

helloMayaPlugin::helloMayaPlugin()
{

}

helloMayaPlugin::~helloMayaPlugin()
{

}

MStatus helloMayaPlugin::doIt(const MArgList& args)
{
	//��������Ƿ�ִ�гɹ�
	MStatus status;
	MGlobal::displayInfo("HelloWord!");

	return MS::kSuccess;
}

void* helloMayaPlugin::creator()
{
	return new helloMayaPlugin();
}