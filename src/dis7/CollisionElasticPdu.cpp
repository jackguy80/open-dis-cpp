#include "CollisionElasticPdu.h"

using namespace DIS;


CollisionElasticPdu::CollisionElasticPdu() : EntityInformationFamilyPdu(),
   issuingEntityID(), 
   collidingEntityID(), 
   collisionEventID(), 
   pad(0), 
   contactVelocity(), 
   mass(0.0), 
   locationOfImpact(), 
   collisionIntermediateResultXX(0.0), 
   collisionIntermediateResultXY(0.0), 
   collisionIntermediateResultXZ(0.0), 
   collisionIntermediateResultYY(0.0), 
   collisionIntermediateResultYZ(0.0), 
   collisionIntermediateResultZZ(0.0), 
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
    locationOfImpact.marshal(dataStream);
    dataStream << collisionIntermediateResultXX;
    dataStream << collisionIntermediateResultXY;
    dataStream << collisionIntermediateResultXZ;
    dataStream << collisionIntermediateResultYY;
    dataStream << collisionIntermediateResultYZ;
    dataStream << collisionIntermediateResultZZ;
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
    locationOfImpact.unmarshal(dataStream);
    dataStream >> collisionIntermediateResultXX;
    dataStream >> collisionIntermediateResultXY;
    dataStream >> collisionIntermediateResultXZ;
    dataStream >> collisionIntermediateResultYY;
    dataStream >> collisionIntermediateResultYZ;
    dataStream >> collisionIntermediateResultZZ;
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
     if( ! (locationOfImpact == rhs.locationOfImpact) ) ivarsEqual = false;
     if( ! (collisionIntermediateResultXX == rhs.collisionIntermediateResultXX) ) ivarsEqual = false;
     if( ! (collisionIntermediateResultXY == rhs.collisionIntermediateResultXY) ) ivarsEqual = false;
     if( ! (collisionIntermediateResultXZ == rhs.collisionIntermediateResultXZ) ) ivarsEqual = false;
     if( ! (collisionIntermediateResultYY == rhs.collisionIntermediateResultYY) ) ivarsEqual = false;
     if( ! (collisionIntermediateResultYZ == rhs.collisionIntermediateResultYZ) ) ivarsEqual = false;
     if( ! (collisionIntermediateResultZZ == rhs.collisionIntermediateResultZZ) ) ivarsEqual = false;
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
   marshalSize = marshalSize + locationOfImpact.getMarshalledSize();  // locationOfImpact
   marshalSize = marshalSize + 4;  // collisionIntermediateResultXX
   marshalSize = marshalSize + 4;  // collisionIntermediateResultXY
   marshalSize = marshalSize + 4;  // collisionIntermediateResultXZ
   marshalSize = marshalSize + 4;  // collisionIntermediateResultYY
   marshalSize = marshalSize + 4;  // collisionIntermediateResultYZ
   marshalSize = marshalSize + 4;  // collisionIntermediateResultZZ
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
