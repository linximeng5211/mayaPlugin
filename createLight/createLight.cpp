#include "createLight.h"

createLight::createLight() {};
createLight::~createLight() {};

//创建一个灯光
MStatus createLight::doIt(const MArgList& args)
{
	MStatus status;

	//如果使用redoIt，就不能返回MS::kSuccess，而应该返回
	return redoIt();

}

//重复创建一个灯光
MStatus createLight::redoIt()
{
	MStatus status;
	pointNode = pointLight.create();

	return MS::kSuccess;
}

//撤销可以使用删除上一步操作来实现
MStatus createLight::undoIt()
{
	MStatus status;
	MGlobal::removeFromModel(pointNode);

	return MS::kSuccess;
}

bool createLight::isUndoable() const
{
	return true;
}

void* createLight::creator()
{
	return new createLight();
}