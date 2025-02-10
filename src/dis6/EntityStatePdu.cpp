#include "EntityStatePdu.h"

using namespace DIS;


EntityStatePdu::EntityStatePdu() : EntityInformationFamilyPdu(),
   entityID(), 
   forceId(0), 
   numberOfArticulationParameters(0), 
   entityType(), 
   alternativeEntityType(), 
   entityLinearVelocity(), 
   entityLocation(), 
   entityOrientation(), 
   entityAppearance(0), 
   deadReckoningParameters(), 
   marking(), 
   capabilities(0), 
   articulationParameters(0)
{
    pduType = 1;
}

EntityStatePdu::~EntityStatePdu()
{
    articulationParameters.clear();
}

void EntityStatePdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    entityID.marshal(dataStream);
    dataStream << forceId;
    dataStream << ( char )articulationParameters.size();
    entityType.marshal(dataStream);
    alternativeEntityType.marshal(dataStream);
    entityLinearVelocity.marshal(dataStream);
    entityLocation.marshal(dataStream);
    entityOrientation.marshal(dataStream);
    dataStream << entityAppearance;
    deadReckoningParameters.marshal(dataStream);
    marking.marshal(dataStream);
    dataStream << capabilities;

     for(size_t idx = 0; idx < articulationParameters.size(); idx++)
     {
        ArticulationParameter x = articulationParameters[idx];
        x.marshal(dataStream);
     }

}

void EntityStatePdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    entityID.unmarshal(dataStream);
    dataStream >> forceId;
    dataStream >> numberOfArticulationParameters;
    entityType.unmarshal(dataStream);
    alternativeEntityType.unmarshal(dataStream);
    entityLinearVelocity.unmarshal(dataStream);
    entityLocation.unmarshal(dataStream);
    entityOrientation.unmarshal(dataStream);
    dataStream >> entityAppearance;
    deadReckoningParameters.unmarshal(dataStream);
    marking.unmarshal(dataStream);
    dataStream >> capabilities;

     articulationParameters.clear();
     for(size_t idx = 0; idx < numberOfArticulationParameters; idx++)
     {
        ArticulationParameter x;
        x.unmarshal(dataStream);
        articulationParameters.push_back(x);
     }
}


bool EntityStatePdu::operator ==(const EntityStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (entityID == rhs.entityID) ) ivarsEqual = false;
     if( ! (forceId == rhs.forceId) ) ivarsEqual = false;
     if( ! (entityType == rhs.entityType) ) ivarsEqual = false;
     if( ! (alternativeEntityType == rhs.alternativeEntityType) ) ivarsEqual = false;
     if( ! (entityLinearVelocity == rhs.entityLinearVelocity) ) ivarsEqual = false;
     if( ! (entityLocation == rhs.entityLocation) ) ivarsEqual = false;
     if( ! (entityOrientation == rhs.entityOrientation) ) ivarsEqual = false;
     if( ! (entityAppearance == rhs.entityAppearance) ) ivarsEqual = false;
     if( ! (deadReckoningParameters == rhs.deadReckoningParameters) ) ivarsEqual = false;
     if( ! (marking == rhs.marking) ) ivarsEqual = false;
     if( ! (capabilities == rhs.capabilities) ) ivarsEqual = false;

     for(size_t idx = 0; idx < articulationParameters.size(); idx++)
     {
        if( ! ( articulationParameters[idx] == rhs.articulationParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int EntityStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + entityID.getMarshalledSize();  // entityID
   marshalSize = marshalSize + 1;  // forceId
   marshalSize = marshalSize + 1;  // numberOfArticulationParameters
   marshalSize = marshalSize + entityType.getMarshalledSize();  // entityType
   marshalSize = marshalSize + alternativeEntityType.getMarshalledSize();  // alternativeEntityType
   marshalSize = marshalSize + entityLinearVelocity.getMarshalledSize();  // entityLinearVelocity
   marshalSize = marshalSize + entityLocation.getMarshalledSize();  // entityLocation
   marshalSize = marshalSize + entityOrientation.getMarshalledSize();  // entityOrientation
   marshalSize = marshalSize + 4;  // entityAppearance
   marshalSize = marshalSize + deadReckoningParameters.getMarshalledSize();  // deadReckoningParameters
   marshalSize = marshalSize + marking.getMarshalledSize();  // marking
   marshalSize = marshalSize + 4;  // capabilities

   for(int idx=0; idx < articulationParameters.size(); idx++)
   {
        ArticulationParameter listElement = articulationParameters[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

    return marshalSize;
}

// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
// 
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
