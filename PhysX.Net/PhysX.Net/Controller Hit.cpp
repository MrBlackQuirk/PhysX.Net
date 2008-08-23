#include "StdAfx.h"

#include "Controller Hit.h"
#include "Scene.h"
#include "Base Shape.h"
#include "Actor.h"
#include "User Output Stream.h"
#include "Core.h"

using namespace StillDesign::PhysX;

ControllerShapeHit::ControllerShapeHit( NxControllerShapeHit shapeHit )
{
	_shapeHit = new NxControllerShapeHit( shapeHit );
	
	if( shapeHit.shape != NULL )
		_shape = ObjectCache::GetObject<StillDesign::PhysX::Shape^>( (intptr_t)shapeHit.shape );
	
	if( shapeHit.controller != NULL )
		_controller = ObjectCache::GetObject<StillDesign::PhysX::Controller^>( (intptr_t)shapeHit.controller );
}
ControllerShapeHit::~ControllerShapeHit()
{
	this->!ControllerShapeHit();
}
ControllerShapeHit::!ControllerShapeHit()
{
	SAFE_DELETE( _shapeHit );
	
	_controller = nullptr;
	_shape = nullptr;
}

StillDesign::PhysX::Controller^ ControllerShapeHit::Controller::get()
{
	return _controller;
}
Shape^ ControllerShapeHit::Shape::get()
{
	return _shape;
}

Vector3 ControllerShapeHit::WorldPosition::get()
{
	return Vector3( (float)_shapeHit->worldPos.x, (float)_shapeHit->worldPos.y, (float)_shapeHit->worldPos.z );
}

Vector3 ControllerShapeHit::WorldNormal::get()
{
	return Vector3( (float)_shapeHit->worldNormal.x, (float)_shapeHit->worldNormal.y, (float)_shapeHit->worldNormal.z );
}

unsigned int ControllerShapeHit::TriangleIndex::get()
{
	return _shapeHit->id;
}

Vector3 ControllerShapeHit::MotionDirection::get()
{
	return Math::NxVec3ToVector3( _shapeHit->dir );
}

float ControllerShapeHit::MotionLength::get()
{
	return _shapeHit->length;
}

NxControllerShapeHit* ControllerShapeHit::UnmanagedPointer::get()
{
	return _shapeHit;
}

//

ControllersHit::ControllersHit()
{
	
}
ControllersHit::ControllersHit( const NxControllersHit controllersHit )
{
	_controllersHit = new NxControllersHit( controllersHit );
}
ControllersHit::~ControllersHit()
{
	this->!ControllersHit();
}
ControllersHit::!ControllersHit()
{
	SAFE_DELETE( _controllersHit );
}