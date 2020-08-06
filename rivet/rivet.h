//ȷ��ͷ�ļ�ֻ����һ��
#pragma once
#include <maya/MPxCommand.h>
#include <maya/MSelectionList.h>
#include <maya/MGlobal.h>
#include <maya/MArgList.h>
#include <maya/MString.h>
#include <maya/MDagPath.h>
#include <maya/MFnMesh.h>
#include <maya/MObject.h>
#include <maya/MObjectArray.h>
#include <maya/MFnTransform.h>
#include <maya/MPoint.h>
#include <maya/MFnPointLight.h>
#include <maya/MVector.h>
#include <maya/MDoubleArray.h>
#include <maya/MColor.h>
#include <maya/MArgDatabase.h>

class rivet:public MPxCommand
{
public:
	rivet()
	{

	}
	virtual ~rivet()
	{

	}

	virtual MStatus doIt(const MArgList& args);
	virtual MStatus redoIt();
	virtual MStatus undoIt();
	/*isUndoable�ж��Ƿ�ɳ�����ִ����doIt
	�����ִ��isUndoable�����Ϊtrue��
	��һ��������¼�ڲ������У����㳷����
	Ĭ����false*/
	virtual bool isUndoable() const
	{
		return true;
	}
	static void* creator()
	{
		return new rivet;
	}

private:
	MDagPath targetPath;
	MObjectArray nodeArray;
	MArgList argList;
	double red;
	double green;
	double blue;

};


