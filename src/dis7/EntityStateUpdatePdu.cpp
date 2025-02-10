#include "EntityStateUpdatePdu.h"

using namespace DIS;


EntityStateUpdatePdu::EntityStateUpdatePdu() : EntityInformationFamilyPdu(),
   entityID(), 
   padding1(0), 
   numberOfVariableParameters(0), 
   entityLinearVelocity(), 
   entityLocation(), 
   entityOrientation(), 
   entityAppearance(0), 
   variableParameters()
{
    pduType = 67;
    protocolFamily = 1;
}

EntityStateUpdatePdu::~EntityStateUpdatePdu()
{
}

void EntityStateUpdatePdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    entityID.marshal(dataStream);
    dataStream << padding1;
    dataStream << numberOfVariableParameters;
    entityLinearVelocity.marshal(dataStream);
    entityLocation.marshal(dataStream);
    entityOrientation.marshal(dataStream);
    dataStream << entityAppearance;
    variableParameters.marshal(dataStream);
}

void EntityStateUpdatePdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    entityID.unmarshal(dataStream);
    dataStream >> padding1;
    dataStream >> numberOfVariableParameters;
    entityLinearVelocity.unmarshal(dataStream);
    entityLocation.unmarshal(dataStream);
    entityOrientation.unmarshal(dataStream);
    dataStream >> entityAppearance;
    variableParameters.unmarshal(dataStream);
}


bool EntityStateUpdatePdu::operator ==(const EntityStateUpdatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (entityID == rhs.entityID) ) ivarsEqual = false;
     if( ! (padding1 == rhs.padding1) ) ivarsEqual = false;
     if( ! (numberOfVariableParameters == rhs.numberOfVariableParameters) ) ivarsEqual = false;
     if( ! (entityLinearVelocity == rhs.entityLinearVelocity) ) ivarsEqual = false;
     if( ! (entityLocation == rhs.entityLocation) ) ivarsEqual = false;
     if( ! (entityOrientation == rhs.entityOrientation) ) ivarsEqual = false;
     if( ! (entityAppearance == rhs.entityAppearance) ) ivarsEqual = false;
     if( ! (variableParameters == rhs.variableParameters) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EntityStateUpdatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + entityID.getMarshalledSize();  // entityID
   marshalSize = marshalSize + 1;  // padding1
   marshalSize = marshalSize + 1;  // numberOfVariableParameters
   marshalSize = marshalSize + entityLinearVelocity.getMarshalledSize();  // entityLinearVelocity
   marshalSize = marshalSize + entityLocation.getMarshalledSize();  // entityLocation
   marshalSize = marshalSize + entityOrientation.getMarshalledSize();  // entityOrientation
   marshalSize = marshalSize + 4;  // entityAppearance
   marshalSize = marshalSize + variableParameters.getMarshalledSize();  // variableParameters
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
