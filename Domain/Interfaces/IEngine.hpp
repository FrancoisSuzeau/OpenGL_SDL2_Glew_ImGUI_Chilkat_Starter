/******************************************************************************************************************************************/
// File : IEngine.hpp
// Purpose : the interface engine 
/******************************************************************************************************************************************/
#ifndef IENGINE_H
#define IENGINE_H

namespace Engines {


	class IEngine
	{
	public:
		virtual ~IEngine() {}
		virtual void Construct() = 0;
	};
}
#endif