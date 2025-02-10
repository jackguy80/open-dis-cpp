#include "DetonationPdu.h"

using namespace DIS;


DetonationPdu::DetonationPdu() : WarfareFamilyPdu(),
   explodingEntityID(), 
   eventID(), 
   velocity(), 
   locationInWorldCoordinates(), 
   descriptor(), 
   locationOfEntityCoordinates(), 
   detonationResult(0), 
   numberOfVariableParameters(0), 
   pad(0), 
   variableParameters()
{
    pduType = 3;
}

DetonationPdu::~DetonationPdu()
{
}

void DetonationPdu::marshal(DataStream& dataStream) const
{
    WarfareFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    explodingEntityID.marshal(dataStream);
    eventID.marshal(dataStream);
    velocity.marshal(dataStream);
    locationInWorldCoordinates.marshal(dataStream);
    descriptor.marshal(dataStream);
    locationOfEntityCoordinates.marshal(dataStream);
    dataStream << detonationResult;
    dataStream << numberOfVariableParameters;
    dataStream << pad;
    variableParameters.marshal(dataStream);
}

void DetonationPdu::unmarshal(DataStream& dataStream)
{
    WarfareFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    explodingEntityID.unmarshal(dataStream);
    eventID.unmarshal(dataStream);
    velocity.unmarshal(dataStream);
    locationInWorldCoordinates.unmarshal(dataStream);
    descriptor.unmarshal(dataStream);
    locationOfEntityCoordinates.unmarshal(dataStream);
    dataStream >> detonationResult;
    dataStream >> numberOfVariableParameters;
    dataStream >> pad;
    variableParameters.unmarshal(dataStream);
}


bool DetonationPdu::operator ==(const DetonationPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = WarfareFamilyPdu::operator==(rhs);

     if( ! (explodingEntityID == rhs.explodingEntityID) ) ivarsEqual = false;
     if( ! (eventID == rhs.eventID) ) ivarsEqual = false;
     if( ! (velocity == rhs.velocity) ) ivarsEqual = false;
     if( ! (locationInWorldCoordinates == rhs.locationInWorldCoordinates) ) ivarsEqual = false;
     if( ! (descriptor == rhs.descriptor) ) ivarsEqual = false;
     if( ! (locationOfEntityCoordinates == rhs.locationOfEntityCoordinates) ) ivarsEqual = false;
     if( ! (detonationResult == rhs.detonationResult) ) ivarsEqual = false;
     if( ! (numberOfVariableParameters == rhs.numberOfVariableParameters) ) ivarsEqual = false;
     if( ! (pad == rhs.pad) ) ivarsEqual = false;
     if( ! (variableParameters == rhs.variableParameters) ) ivarsEqual = false;

    return ivarsEqual;
 }

int DetonationPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = WarfareFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + explodingEntityID.getMarshalledSize();  // explodingEntityID
   marshalSize = marshalSize + eventID.getMarshalledSize();  // eventID
   marshalSize = marshalSize + velocity.getMarshalledSize();  // velocity
   marshalSize = marshalSize + locationInWorldCoordinates.getMarshalledSize();  // locationInWorldCoordinates
   marshalSize = marshalSize + descriptor.getMarshalledSize();  // descriptor
   marshalSize = marshalSize + locationOfEntityCoordinates.getMarshalledSize();  // locationOfEntityCoordinates
   marshalSize = marshalSize + 1;  // detonationResult
   marshalSize = marshalSize + 1;  // numberOfVariableParameters
   marshalSize = marshalSize + 2;  // pad
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
