/**
	SPICE BIG
	DataEntryShort.cpp
	Purpose: Class to provide a data entry for type short

	@author Lukas Mueller (ilt.hsr.ch)
	@version 1.1 2016_04_01
*/

#include "DataEntryShort.h"

namespace SPICE
{
	namespace BIG
	{
		namespace DataEntryTypes
		{
			DataEntryShort::DataEntryShort(std::string name) : DataEntry(name),
				_minValue(0),
				_maxValue(0),
				_minMaxSetted(false)
			{
				_value = "0";
			}
			DataEntryShort::DataEntryShort(std::string name, int16_t minValue, int16_t maxValue) : DataEntry(name),
				_minValue(minValue),
				_maxValue(maxValue),
				_minMaxSetted(true)
			{
				_value = "0";
			}
			DataEntryShort::DataEntryShort(std::string name, int16_t value) : DataEntry(name),
				_minValue(0),
				_maxValue(0),
				_minMaxSetted(false)
			{
				_value = std::to_string(value);
				_valueIsSet = true;
			}

			DataEntryShort::~DataEntryShort()
			{
			}

			bool DataEntryShort::setValue(int16_t value)
			{
				if(_minMaxSetted)
				{
					if(value < _minValue || value > _maxValue)
					{
						return false;
					}
				}
				_value = std::to_string(value);
				_valueIsSet = true;
				return true;
			}
			int16_t DataEntryShort::getValue()
			{
				return (int16_t)std::stoi(_value);
			}
			DataEntry::Types DataEntryShort::getDataEntryType()
			{
				return DataEntry::Types::Short;
			}
			std::string DataEntryShort::getDataEntryTypeAsString()
			{
				return "Short";
			}
			std::string DataEntryShort::getMinValue()
			{
				if(_minMaxSetted)
				{
					return std::to_string(_minValue);
				}
				return "";
			}
			std::string DataEntryShort::getMaxValue()
			{
				if(_minMaxSetted)
				{
					return std::to_string(_maxValue);
				}
				return "";
			}
			bool DataEntryShort::checkStringIsValidValue(std::string& valueString)
			{
				bool returnValue = true;
				try
				{
					int tempValueInt = std::stoi(valueString);
					int16_t tempValue = 0;
					if(tempValueInt < -32768 || tempValueInt > 32767)
					{
						returnValue = false;
					}
					else
					{
						tempValue = (int16_t)tempValueInt;
					}
					if(_minMaxSetted && returnValue)
					{
						if(tempValue < _minValue || tempValue > _maxValue)
						{
							returnValue = false;
						}
					}
					if(returnValue)
					{
						valueString = std::to_string(tempValue);
					}
				}
				catch (std::exception e)
				{
					returnValue = false;
				}
				return returnValue;
			}
		}
	}
}