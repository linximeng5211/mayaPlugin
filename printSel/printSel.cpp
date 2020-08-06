#include "printSel.h"

printSel::printSel()
{

}
printSel::~printSel()
{

}

MStatus printSel::doIt(const MArgList& args)
{
	MStatus status;
	MSelectionList selList;
	MGlobal::getActiveSelectionList(selList);
	MDagPath path;
	for (int i = 0; i < selList.length(); i++)
	{
	selList.getDagPath(i, path);

	MGlobal::displayInfo(path.partialPathName());
	}
	return MS::kSuccess;
}

void* printSel::creator()
{
	return new printSel;
}