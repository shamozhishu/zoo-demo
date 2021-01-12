#ifndef __FLIGHT_CTRL_CMD_H__
#define __FLIGHT_CTRL_CMD_H__

#include <zooCmd/Cmd.h>
#include <zooCmd_osg/OsgEarthSupport.h>

class FlightCtrlCmd : public zooCmd::Cmd
{
	ZOO_REFLEX_DECLARE(FlightCtrlCmd)
public:
	FlightCtrlCmd();
	~FlightCtrlCmd();
	bool init();
	void help(zooCmd::CmdUsage* usage);
	void parse(Signal& subcmd, zooCmd::CmdParser& cmdarg, zoo::UserData& returnValue);

private:
	osg::AnimationPath* createAnimationPath(const osg::Vec3& center, float radius, double looptime);

private:
	zoo::Spawner* _selectScene;
};

#endif // __FLIGHT_CTRL_CMD_H__
