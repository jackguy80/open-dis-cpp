#include "FirePdu.h"

using namespace DIS;


FirePdu::FirePdu() : WarfareFamilyPdu(),
   munitionID(), 
   eventID(), 
   fireMissionIndex(0), 
   locationInWorldCoordinates(), 
   burstDescriptor(), 
   velocity(), 
   rangeToTarget(0.0)
{
    pduType = 2;
}

FirePdu::~FirePdu()
{
}

void FirePdu::marshal(DataStream& dataStream) const
{
    WarfareFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    munitionID.marshal(dataStream);
    eventID.marshal(dataStream);
    dataStream << fireMissionIndex;
    locationInWorldCoordinates.marshal(dataStream);
    burstDescriptor.marshal(dataStream);
    velocity.marshal(dataStream);
    dataStream << rangeToTarget;
}

void FirePdu::unmarshal(DataStream& dataStream)
{
    WarfareFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    munitionID.unmarshal(dataStream);
    eventID.unmarshal(dataStream);
    dataStream >> fireMissionIndex;
    locationInWorldCoordinates.unmarshal(dataStream);
    burstDescriptor.unmarshal(dataStream);
    velocity.unmarshal(dataStream);
    dataStream >> rangeToTarget;
}


bool FirePdu::operator ==(const FirePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = WarfareFamilyPdu::operator==(rhs);

     if( ! (munitionID == rhs.munitionID) ) ivarsEqual = false;
     if( ! (eventID == rhs.eventID) ) ivarsEqual = false;
     if( ! (fireMissionIndex == rhs.fireMissionIndex) ) ivarsEqual = false;
     if( ! (locationInWorldCoordinates == rhs.locationInWorldCoordinates) ) ivarsEqual = false;
     if( ! (burstDescriptor == rhs.burstDescriptor) ) ivarsEqual = false;
     if( ! (velocity == rhs.velocity) ) ivarsEqual = false;
     if( ! (rangeToTarget == rhs.rangeToTarget) ) ivarsEqual = false;

    return ivarsEqual;
 }

int FirePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = WarfareFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + munitionID.getMarshalledSize();  // munitionID
   marshalSize = marshalSize + eventID.getMarshalledSize();  // eventID
   marshalSize = marshalSize + 4;  // fireMissionIndex
   marshalSize = marshalSize + locationInWorldCoordinates.getMarshalledSize();  // locationInWorldCoordinates
   marshalSize = marshalSize + burstDescriptor.getMarshalledSize();  // burstDescriptor
   marshalSize = marshalSize + velocity.getMarshalledSize();  // velocity
   marshalSize = marshalSize + 4;  // rangeToTarget
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
