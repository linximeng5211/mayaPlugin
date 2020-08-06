#include "createLight.h"

createLight::createLight() {};
createLight::~createLight() {};

//����һ���ƹ�
MStatus createLight::doIt(const MArgList& args)
{
	MStatus status;

	//���ʹ��redoIt���Ͳ��ܷ���MS::kSuccess����Ӧ�÷���
	return redoIt();

}

//�ظ�����һ���ƹ�
MStatus createLight::redoIt()
{
	MStatus status;
	pointNode = pointLight.create();

	return MS::kSuccess;
}

//��������ʹ��ɾ����һ��������ʵ��
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