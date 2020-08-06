#pragma once
#include <maya/MPxCommand.h>
#include <maya/MGlobal.h>
#include <maya/MFnPointLight.h>
#include <maya/MString.h>
#include <maya/MArgList.h>

class syntax :public MPxCommand
{
public:
	syntax();
	virtual ~syntax();

	virtual MStatus doIt(const MArgList& args);

	static void* creator();
};