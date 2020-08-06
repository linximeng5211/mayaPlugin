#pragma once
# include <maya/MPxCommand.h>
# include <maya/MGlobal.h>

class helloMayaPlugin : public MPxCommand {
	public:
		helloMayaPlugin();
		virtual ~helloMayaPlugin();
		virtual MStatus doIt(const MArgList& args);
		static void* creator();
};