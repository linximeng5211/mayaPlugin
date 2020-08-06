//保证头文件只被编译一次
#pragma once

#include <maya/MPxCommand.h>
#include <maya/MGlobal.h>
#include <maya/MFnDagNode.h>
#include <maya/MDagPath.h>
#include <maya/MPlugArray.h>
#include <maya/MPlug.h>
#include <maya/MObject.h>
#include <maya/MArgList.h>
#include <maya/MSelectionList.h>

class listConnect : MPxCommand
{
public:
	listConnect();
	virtual ~listConnect();
	virtual MStatus doIt(const MArgList& args);
	static void* creator();


};