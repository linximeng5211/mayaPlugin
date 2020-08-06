#include "rivet.h"

MStatus rivet::doIt(const MArgList& args)
{
	MStatus status;
	red = 1.0;
	green = 1.0;
	blue = 1.0;

	unsigned int index;
	//检测是否有这个名字
	index = args.flagIndex("c", "color");
	if (args.kInvalidArgIndex != index)
	{
		args.get(index + 1, red);
		args.get(index + 2, green);
		args.get(index + 3, blue);
	}
	MSelectionList selList;
	MGlobal::getActiveSelectionList(selList);
	selList.getDagPath(0, targetPath);

	return redoIt();
}

MStatus rivet::redoIt()
{
	MStatus status;
	MFnMesh meshFn(targetPath);
	unsigned numVertex = meshFn.numVertices();
	for (unsigned i = 0; i < numVertex; i++)
	{
		MPoint pt;
		meshFn.getPoint(i, pt, MSpace::kWorld);
		MFnPointLight light;
		MObject lightNode = light.create();
		MColor kColor(red, green, blue);
		light.setColor(kColor);
		MObject transNode = light.parent(0);
		MFnTransform transFn(transNode);
		transFn.setTranslation(pt, MSpace::kObject);
		//放入数组为后面的撤销做准备
		nodeArray.append(transNode);
	}


	return MS::kSuccess;
}

MStatus rivet::undoIt()
{
	MStatus status;
	for (unsigned int i = 0; i < nodeArray.length(); i++)
	{
		MGlobal::deleteNode(nodeArray[i]);
	}

	return MS::kSuccess;
}