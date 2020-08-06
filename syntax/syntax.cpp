#include "syntax.h"

syntax::syntax() {}
syntax::~syntax() {}

MStatus syntax::doIt(const MArgList& args)
{
	MStatus status;

	MString name = "Light01";

	unsigned index;
	index = args.flagIndex("n", "name");
	//如果index 不是无效的
	if (MArgList::kInvalidArgIndex != index)
	{
		args.get(index + 1, name);
	}

	MFnPointLight light;

	light.create();
	light.setName(name);


	return MS::kSuccess;
}

void* syntax::creator()
{
	return new syntax;
}