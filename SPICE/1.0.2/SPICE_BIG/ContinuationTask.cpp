/**
	SPICE BIG
	ContiunationTask.cpp
	Purpose: A continuation task which can be generated by a command and propsen to the PMS in case of an error

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.0 2015_10_21
*/

#include <sstream>

#include "ContinuationTask.h"

namespace SPICE
{
	namespace BIG
	{
		ContinuationTask::ContinuationTask(std::string name, std::string description, ContinuationTask::TaskTypes type) :
			_taskName(name),
			_taskDescription(description),
			_taskType(type)
		{
			//ctor
		}
		ContinuationTask::~ContinuationTask()
		{
			//dtor
		}

		std::string ContinuationTask::getName()
		{
			return _taskName;
		}

		std::string ContinuationTask::getDescription()
		{
			return _taskDescription;
		}

		ContinuationTask::TaskTypes ContinuationTask::getType()
		{
			return _taskType;
		}
	}
}
