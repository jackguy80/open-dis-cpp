#include "FalseTargetsAttribute.h"

using namespace DIS;


FalseTargetsAttribute::FalseTargetsAttribute():
   recordType(3502), 
   recordLength(40), 
   padding(0), 
   emitterNumber(0), 
   beamNumber(0), 
   stateIndicator(0), 
   padding2(0), 
   falseTargetCount(0), 
   walkSpeed(0.0), 
   walkAcceleration(0.0), 
   maximumWalkDistance(0.0), 
   keepTime(0.0), 
   echoSpacing(0.0)
{
}

FalseTargetsAttribute::~FalseTargetsAttribute()
{
}

void FalseTargetsAttribute::marshal(DataStream& dataStream) const
{
    dataStream << recordType;
    dataStream << recordLength;
    dataStream << padding;
    dataStream << emitterNumber;
    dataStream << beamNumber;
    dataStream << stateIndicator;
    dataStream << padding2;
    dataStream << falseTargetCount;
    dataStream << walkSpeed;
    dataStream << walkAcceleration;
    dataStream << maximumWalkDistance;
    dataStream << keepTime;
    dataStream << echoSpacing;
}

void FalseTargetsAttribute::unmarshal(DataStream& dataStream)
{
    dataStream >> recordType;
    dataStream >> recordLength;
    dataStream >> padding;
    dataStream >> emitterNumber;
    dataStream >> beamNumber;
    dataStream >> stateIndicator;
    dataStream >> padding2;
    dataStream >> falseTargetCount;
    dataStream >> walkSpeed;
    dataStream >> walkAcceleration;
    dataStream >> maximumWalkDistance;
    dataStream >> keepTime;
    dataStream >> echoSpacing;
}


bool FalseTargetsAttribute::operator ==(const FalseTargetsAttribute& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (recordType == rhs.recordType) ) ivarsEqual = false;
     if( ! (recordLength == rhs.recordLength) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;
     if( ! (emitterNumber == rhs.emitterNumber) ) ivarsEqual = false;
     if( ! (beamNumber == rhs.beamNumber) ) ivarsEqual = false;
     if( ! (stateIndicator == rhs.stateIndicator) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;
     if( ! (falseTargetCount == rhs.falseTargetCount) ) ivarsEqual = false;
     if( ! (walkSpeed == rhs.walkSpeed) ) ivarsEqual = false;
     if( ! (walkAcceleration == rhs.walkAcceleration) ) ivarsEqual = false;
     if( ! (maximumWalkDistance == rhs.maximumWalkDistance) ) ivarsEqual = false;
     if( ! (keepTime == rhs.keepTime) ) ivarsEqual = false;
     if( ! (echoSpacing == rhs.echoSpacing) ) ivarsEqual = false;

    return ivarsEqual;
 }

int FalseTargetsAttribute::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // recordType
   marshalSize = marshalSize + 2;  // recordLength
   marshalSize = marshalSize + 2;  // padding
   marshalSize = marshalSize + 1;  // emitterNumber
   marshalSize = marshalSize + 1;  // beamNumber
   marshalSize = marshalSize + 1;  // stateIndicator
   marshalSize = marshalSize + 1;  // padding2
   marshalSize = marshalSize + 2;  // falseTargetCount
   marshalSize = marshalSize + 4;  // walkSpeed
   marshalSize = marshalSize + 4;  // walkAcceleration
   marshalSize = marshalSize + 4;  // maximumWalkDistance
   marshalSize = marshalSize + 4;  // keepTime
   marshalSize = marshalSize + 4;  // echoSpacing
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
