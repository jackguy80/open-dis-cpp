#include "CollisionPdu.h"

using namespace DIS;


CollisionPdu::CollisionPdu() : EntityInformationFamilyPdu(),
   issuingEntityID(), 
   collidingEntityID(), 
   eventID(), 
   collisionType(0), 
   pad(0), 
   velocity(), 
   mass(0.0), 
   location()
{
    pduType = 4;
    protocolFamily = 1;
}

CollisionPdu::~CollisionPdu()
{
}

void CollisionPdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    issuingEntityID.marshal(dataStream);
    collidingEntityID.marshal(dataStream);
    eventID.marshal(dataStream);
    dataStream << collisionType;
    dataStream << pad;
    velocity.marshal(dataStream);
    dataStream << mass;
    location.marshal(dataStream);
}

void CollisionPdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    issuingEntityID.unmarshal(dataStream);
    collidingEntityID.unmarshal(dataStream);
    eventID.unmarshal(dataStream);
    dataStream >> collisionType;
    dataStream >> pad;
    velocity.unmarshal(dataStream);
    dataStream >> mass;
    location.unmarshal(dataStream);
}


bool CollisionPdu::operator ==(const CollisionPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (issuingEntityID == rhs.issuingEntityID) ) ivarsEqual = false;
     if( ! (collidingEntityID == rhs.collidingEntityID) ) ivarsEqual = false;
     if( ! (eventID == rhs.eventID) ) ivarsEqual = false;
     if( ! (collisionType == rhs.collisionType) ) ivarsEqual = false;
     if( ! (pad == rhs.pad) ) ivarsEqual = false;
     if( ! (velocity == rhs.velocity) ) ivarsEqual = false;
     if( ! (mass == rhs.mass) ) ivarsEqual = false;
     if( ! (location == rhs.location) ) ivarsEqual = false;

    return ivarsEqual;
 }

int CollisionPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + issuingEntityID.getMarshalledSize();  // issuingEntityID
   marshalSize = marshalSize + collidingEntityID.getMarshalledSize();  // collidingEntityID
   marshalSize = marshalSize + eventID.getMarshalledSize();  // eventID
   marshalSize = marshalSize + 1;  // collisionType
   marshalSize = marshalSize + 1;  // pad
   marshalSize = marshalSize + velocity.getMarshalledSize();  // velocity
   marshalSize = marshalSize + 4;  // mass
   marshalSize = marshalSize + location.getMarshalledSize();  // location
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
