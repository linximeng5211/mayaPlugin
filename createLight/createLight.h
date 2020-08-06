#pragma once
#include <maya/MPxCommand.h>
#include <maya/MGlobal.h>
#include <maya/MFnPointLight.h>

class createLight : public MPxCommand
{
public:
	createLight();
	virtual ~createLight();

	virtual MStatus doIt(const MArgList& args);
	virtual MStatus redoIt();
	virtual MStatus undoIt();
	/*isUndoable判断是否可撤销，执行完doIt
	后会先执行isUndoable，如果为true则将
	上一步操作记录在操作器中，方便撤销，
	默认是false*/
	virtual bool isUndoable() const;
	static void* creator();
private:
	MFnPointLight pointLight;
	MObject pointNode;
};