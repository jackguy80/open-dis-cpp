#include "EntityStatePduProcessor.h"

#include <iostream>

using namespace Example;

void EntityStatePduProcessor::Process(const DIS::Pdu& packet)
{
   const DIS::EntityStatePdu& espdu = static_cast<const DIS::EntityStatePdu&>( packet );
   if( espdu.timestamp % 10 )
   {
      const DIS::Vector3Double& position = espdu.entityLocation;
      std::cout << "x:" << position.x
                << "\ty:" << position.y
                << "\tz:" << position.z
                << std::endl;
   }
}
