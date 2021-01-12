#include "BirdEyeManipulator.h"

BirdEyeManipulator::BirdEyeManipulator()
{
}

BirdEyeManipulator::~BirdEyeManipulator()
{
}

bool BirdEyeManipulator::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	return TerrainManipulator::handle(ea, aa);
}
