#include "DetonationPdu.h"

using namespace DIS;


DetonationPdu::DetonationPdu() : WarfareFamilyPdu(),
   munitionID(), 
   eventID(), 
   velocity(), 
   locationInWorldCoordinates(), 
   burstDescriptor(), 
   locationInEntityCoordinates(), 
   detonationResult(0), 
   numberOfArticulationParameters(0), 
   pad(0), 
   articulationParameters(0)
{
    pduType = 3;
}

DetonationPdu::~DetonationPdu()
{
    articulationParameters.clear();
}

void DetonationPdu::marshal(DataStream& dataStream) const
{
    WarfareFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    munitionID.marshal(dataStream);
    eventID.marshal(dataStream);
    velocity.marshal(dataStream);
    locationInWorldCoordinates.marshal(dataStream);
    burstDescriptor.marshal(dataStream);
    locationInEntityCoordinates.marshal(dataStream);
    dataStream << detonationResult;
    dataStream << ( unsigned char )articulationParameters.size();
    dataStream << pad;

     for(size_t idx = 0; idx < articulationParameters.size(); idx++)
     {
        ArticulationParameter x = articulationParameters[idx];
        x.marshal(dataStream);
     }

}

void DetonationPdu::unmarshal(DataStream& dataStream)
{
    WarfareFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    munitionID.unmarshal(dataStream);
    eventID.unmarshal(dataStream);
    velocity.unmarshal(dataStream);
    locationInWorldCoordinates.unmarshal(dataStream);
    burstDescriptor.unmarshal(dataStream);
    locationInEntityCoordinates.unmarshal(dataStream);
    dataStream >> detonationResult;
    dataStream >> numberOfArticulationParameters;
    dataStream >> pad;

     articulationParameters.clear();
     for(size_t idx = 0; idx < numberOfArticulationParameters; idx++)
     {
        ArticulationParameter x;
        x.unmarshal(dataStream);
        articulationParameters.push_back(x);
     }
}


bool DetonationPdu::operator ==(const DetonationPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = WarfareFamilyPdu::operator==(rhs);

     if( ! (munitionID == rhs.munitionID) ) ivarsEqual = false;
     if( ! (eventID == rhs.eventID) ) ivarsEqual = false;
     if( ! (velocity == rhs.velocity) ) ivarsEqual = false;
     if( ! (locationInWorldCoordinates == rhs.locationInWorldCoordinates) ) ivarsEqual = false;
     if( ! (burstDescriptor == rhs.burstDescriptor) ) ivarsEqual = false;
     if( ! (locationInEntityCoordinates == rhs.locationInEntityCoordinates) ) ivarsEqual = false;
     if( ! (detonationResult == rhs.detonationResult) ) ivarsEqual = false;
     if( ! (pad == rhs.pad) ) ivarsEqual = false;

     for(size_t idx = 0; idx < articulationParameters.size(); idx++)
     {
        if( ! ( articulationParameters[idx] == rhs.articulationParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int DetonationPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = WarfareFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + munitionID.getMarshalledSize();  // munitionID
   marshalSize = marshalSize + eventID.getMarshalledSize();  // eventID
   marshalSize = marshalSize + velocity.getMarshalledSize();  // velocity
   marshalSize = marshalSize + locationInWorldCoordinates.getMarshalledSize();  // locationInWorldCoordinates
   marshalSize = marshalSize + burstDescriptor.getMarshalledSize();  // burstDescriptor
   marshalSize = marshalSize + locationInEntityCoordinates.getMarshalledSize();  // locationInEntityCoordinates
   marshalSize = marshalSize + 1;  // detonationResult
   marshalSize = marshalSize + 1;  // numberOfArticulationParameters
   marshalSize = marshalSize + 2;  // pad

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
