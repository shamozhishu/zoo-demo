#ifndef __BIRD_EYE_MANIPULATOR_H__
#define __BIRD_EYE_MANIPULATOR_H__

#include <zooCmd_osg/OsgEarthSupport.h>

using namespace osgGA;

class BirdEyeManipulator : public TerrainManipulator
{
public:
	BirdEyeManipulator();
	~BirdEyeManipulator();
	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	void rotateTrackball(const float px0, const float py0, const float px1, const float py1, const float scale) {}
	void rotateWithFixedVertical(const float dx, const float dy) {}
	void rotateWithFixedVertical(const float dx, const float dy, const osg::Vec3f& up) {}
};

#endif // __BIRD_EYE_MANIPULATOR_H__
