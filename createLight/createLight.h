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
	/*isUndoable�ж��Ƿ�ɳ�����ִ����doIt
	�����ִ��isUndoable�����Ϊtrue��
	��һ��������¼�ڲ������У����㳷����
	Ĭ����false*/
	virtual bool isUndoable() const;
	static void* creator();
private:
	MFnPointLight pointLight;
	MObject pointNode;
};