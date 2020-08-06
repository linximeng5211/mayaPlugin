#include "listConnect.h"

listConnect::listConnect()
{

}

listConnect::~listConnect()
{

}

MStatus listConnect::doIt(const MArgList& args)
{
	MStatus status;
	MObject node;
	MDagPath path;
	MPlug plug;
	MPlugArray plugArray;

	MSelectionList selList;

	if (args.length() == 1)
	{
		selList.add(args.asString(0));
	}
	else
	{
		MGlobal::getActiveSelectionList(selList);
	}

	selList.getDagPath(0, path);
	node = path.node();
	MFnDagNode nodeFn(node);
	nodeFn.getConnections(plugArray);
	for (unsigned int i = 0; i < plugArray.length(); i++)
	{
		plug = plugArray[i];
		MGlobal::displayInfo(plug.name());
	}


	return MS::kSuccess;
}

void* listConnect::creator()
{
	return new listConnect;
}