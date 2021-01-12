#include "FlightCtrlCmd.h"
#include <zoo/Utils.h>
#include <zoo/Component.h>
#include <zooCmd/CmdManager.h>
#include <zooCmd_osg/OsgEarthContext.h>
#include <zooCmd_osg/OsgComponentImpls.h>
#include "BirdEyeManipulator.h"

using namespace zoo;
using namespace zooCmd;

ZOO_REGISTER(FlightCtrlCmd)
ZOO_REFLEX_IMPLEMENT(FlightCtrlCmd);

FlightCtrlCmd::FlightCtrlCmd()
{
	_selectScene = Spawner::find(1);
}

FlightCtrlCmd::~FlightCtrlCmd()
{
}

bool FlightCtrlCmd::init()
{
	if (!_selectScene)
		return false;

	BirdEyeManipulator* pManipu = new BirdEyeManipulator;
	_selectScene->getComponentImpl<CameraImpl>()->_manipulatorMgr->addMatrixManipulator(0, "BirdEye", pManipu);
	_selectScene->getComponentImpl<CameraImpl>()->_manipulatorMgr->selectMatrixManipulator(0);
	pManipu->setHomePosition(osg::Vec3d(83091, 194301, 10000), osg::Vec3d(83091, 194301, 0), osg::Vec3d(0, 1, 0));
	pManipu->setTransformation(osg::Vec3d(83091, 194301, 10000), osg::Vec3d(83091, 194301, 0), osg::Vec3d(0, 1, 0));
	return true;
}

void FlightCtrlCmd::help(CmdUsage* usage)
{
	usage->setDescription("flight control command: 飞控程序视景相关的命令插件");
	usage->addCommandProcedureCall("cam(float x, float y)", "");
}

void FlightCtrlCmd::parse(Signal& subcmd, CmdParser& cmdarg, UserData& returnValue)
{
	do
	{
		float x, y;
		if (cmdarg.read("cam", x, y))
		{
			SignalTrigger::connect(subcmd, [this, x, y]
			{
				
			});
			break;
		}
	} while (0);
}

osg::AnimationPath* FlightCtrlCmd::createAnimationPath(const osg::Vec3& center, float radius, double looptime)
{
	// set up the animation path
	osg::AnimationPath* animationPath = new osg::AnimationPath;
	animationPath->setLoopMode(osg::AnimationPath::LOOP);

	int numSamples = 40;
	float yaw = 0.0f;
	float yaw_delta = 2.0f*osg::PI / ((float)numSamples - 1.0f);
	float roll = osg::inDegrees(30.0f);

	double time = 0.0f;
	double time_delta = looptime / (double)numSamples;
	for (int i = 0; i < numSamples; ++i)
	{
		osg::Vec3 position(center + osg::Vec3(sinf(yaw)*radius, cosf(yaw)*radius, 0.0f));
		osg::Quat rotation(osg::Quat(roll, osg::Vec3(0.0, 1.0, 0.0))*osg::Quat(-(yaw + osg::inDegrees(90.0f)), osg::Vec3(0.0, 0.0, 1.0)));

		animationPath->insert(time, osg::AnimationPath::ControlPoint(position, rotation));

		yaw += yaw_delta;
		time += time_delta;

	}
	return animationPath;
}
