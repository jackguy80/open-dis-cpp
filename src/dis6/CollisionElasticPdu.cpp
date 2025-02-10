#include "CollisionElasticPdu.h"

using namespace DIS;


CollisionElasticPdu::CollisionElasticPdu() : EntityInformationFamilyPdu(),
   issuingEntityID(), 
   collidingEntityID(), 
   collisionEventID(), 
   pad(0), 
   contactVelocity(), 
   mass(0.0), 
   location(), 
   collisionResultXX(0.0), 
   collisionResultXY(0.0), 
   collisionResultXZ(0.0), 
   collisionResultYY(0.0), 
   collisionResultYZ(0.0), 
   collisionResultZZ(0.0), 
   unitSurfaceNormal(), 
   coefficientOfRestitution(0.0)
{
    pduType = 66;
    protocolFamily = 1;
}

CollisionElasticPdu::~CollisionElasticPdu()
{
}

void CollisionElasticPdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    issuingEntityID.marshal(dataStream);
    collidingEntityID.marshal(dataStream);
    collisionEventID.marshal(dataStream);
    dataStream << pad;
    contactVelocity.marshal(dataStream);
    dataStream << mass;
    location.marshal(dataStream);
    dataStream << collisionResultXX;
    dataStream << collisionResultXY;
    dataStream << collisionResultXZ;
    dataStream << collisionResultYY;
    dataStream << collisionResultYZ;
    dataStream << collisionResultZZ;
    unitSurfaceNormal.marshal(dataStream);
    dataStream << coefficientOfRestitution;
}

void CollisionElasticPdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    issuingEntityID.unmarshal(dataStream);
    collidingEntityID.unmarshal(dataStream);
    collisionEventID.unmarshal(dataStream);
    dataStream >> pad;
    contactVelocity.unmarshal(dataStream);
    dataStream >> mass;
    location.unmarshal(dataStream);
    dataStream >> collisionResultXX;
    dataStream >> collisionResultXY;
    dataStream >> collisionResultXZ;
    dataStream >> collisionResultYY;
    dataStream >> collisionResultYZ;
    dataStream >> collisionResultZZ;
    unitSurfaceNormal.unmarshal(dataStream);
    dataStream >> coefficientOfRestitution;
}


bool CollisionElasticPdu::operator ==(const CollisionElasticPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (issuingEntityID == rhs.issuingEntityID) ) ivarsEqual = false;
     if( ! (collidingEntityID == rhs.collidingEntityID) ) ivarsEqual = false;
     if( ! (collisionEventID == rhs.collisionEventID) ) ivarsEqual = false;
     if( ! (pad == rhs.pad) ) ivarsEqual = false;
     if( ! (contactVelocity == rhs.contactVelocity) ) ivarsEqual = false;
     if( ! (mass == rhs.mass) ) ivarsEqual = false;
     if( ! (location == rhs.location) ) ivarsEqual = false;
     if( ! (collisionResultXX == rhs.collisionResultXX) ) ivarsEqual = false;
     if( ! (collisionResultXY == rhs.collisionResultXY) ) ivarsEqual = false;
     if( ! (collisionResultXZ == rhs.collisionResultXZ) ) ivarsEqual = false;
     if( ! (collisionResultYY == rhs.collisionResultYY) ) ivarsEqual = false;
     if( ! (collisionResultYZ == rhs.collisionResultYZ) ) ivarsEqual = false;
     if( ! (collisionResultZZ == rhs.collisionResultZZ) ) ivarsEqual = false;
     if( ! (unitSurfaceNormal == rhs.unitSurfaceNormal) ) ivarsEqual = false;
     if( ! (coefficientOfRestitution == rhs.coefficientOfRestitution) ) ivarsEqual = false;

    return ivarsEqual;
 }

int CollisionElasticPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + issuingEntityID.getMarshalledSize();  // issuingEntityID
   marshalSize = marshalSize + collidingEntityID.getMarshalledSize();  // collidingEntityID
   marshalSize = marshalSize + collisionEventID.getMarshalledSize();  // collisionEventID
   marshalSize = marshalSize + 2;  // pad
   marshalSize = marshalSize + contactVelocity.getMarshalledSize();  // contactVelocity
   marshalSize = marshalSize + 4;  // mass
   marshalSize = marshalSize + location.getMarshalledSize();  // location
   marshalSize = marshalSize + 4;  // collisionResultXX
   marshalSize = marshalSize + 4;  // collisionResultXY
   marshalSize = marshalSize + 4;  // collisionResultXZ
   marshalSize = marshalSize + 4;  // collisionResultYY
   marshalSize = marshalSize + 4;  // collisionResultYZ
   marshalSize = marshalSize + 4;  // collisionResultZZ
   marshalSize = marshalSize + unitSurfaceNormal.getMarshalledSize();  // unitSurfaceNormal
   marshalSize = marshalSize + 4;  // coefficientOfRestitution
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
