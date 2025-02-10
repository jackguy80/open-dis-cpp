#include "AngleDeception.h"

using namespace DIS;


AngleDeception::AngleDeception():
   recordType(3501), 
   recordLength(48), 
   padding(0), 
   emitterNumber(0), 
   beamNumber(0), 
   stateIndicator(0), 
   padding2(0), 
   azimuthOffset(0.0), 
   azimuthWidth(0.0), 
   azimuthPullRate(0.0), 
   azimuthPullAcceleration(0.0), 
   elevationOffset(0.0), 
   elevationWidth(0.0), 
   elevationPullRate(0.0), 
   elevationPullAcceleration(0.0), 
   padding3(0)
{
}

AngleDeception::~AngleDeception()
{
}

void AngleDeception::marshal(DataStream& dataStream) const
{
    dataStream << recordType;
    dataStream << recordLength;
    dataStream << padding;
    dataStream << emitterNumber;
    dataStream << beamNumber;
    dataStream << stateIndicator;
    dataStream << padding2;
    dataStream << azimuthOffset;
    dataStream << azimuthWidth;
    dataStream << azimuthPullRate;
    dataStream << azimuthPullAcceleration;
    dataStream << elevationOffset;
    dataStream << elevationWidth;
    dataStream << elevationPullRate;
    dataStream << elevationPullAcceleration;
    dataStream << padding3;
}

void AngleDeception::unmarshal(DataStream& dataStream)
{
    dataStream >> recordType;
    dataStream >> recordLength;
    dataStream >> padding;
    dataStream >> emitterNumber;
    dataStream >> beamNumber;
    dataStream >> stateIndicator;
    dataStream >> padding2;
    dataStream >> azimuthOffset;
    dataStream >> azimuthWidth;
    dataStream >> azimuthPullRate;
    dataStream >> azimuthPullAcceleration;
    dataStream >> elevationOffset;
    dataStream >> elevationWidth;
    dataStream >> elevationPullRate;
    dataStream >> elevationPullAcceleration;
    dataStream >> padding3;
}


bool AngleDeception::operator ==(const AngleDeception& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (recordType == rhs.recordType) ) ivarsEqual = false;
     if( ! (recordLength == rhs.recordLength) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;
     if( ! (emitterNumber == rhs.emitterNumber) ) ivarsEqual = false;
     if( ! (beamNumber == rhs.beamNumber) ) ivarsEqual = false;
     if( ! (stateIndicator == rhs.stateIndicator) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;
     if( ! (azimuthOffset == rhs.azimuthOffset) ) ivarsEqual = false;
     if( ! (azimuthWidth == rhs.azimuthWidth) ) ivarsEqual = false;
     if( ! (azimuthPullRate == rhs.azimuthPullRate) ) ivarsEqual = false;
     if( ! (azimuthPullAcceleration == rhs.azimuthPullAcceleration) ) ivarsEqual = false;
     if( ! (elevationOffset == rhs.elevationOffset) ) ivarsEqual = false;
     if( ! (elevationWidth == rhs.elevationWidth) ) ivarsEqual = false;
     if( ! (elevationPullRate == rhs.elevationPullRate) ) ivarsEqual = false;
     if( ! (elevationPullAcceleration == rhs.elevationPullAcceleration) ) ivarsEqual = false;
     if( ! (padding3 == rhs.padding3) ) ivarsEqual = false;

    return ivarsEqual;
 }

int AngleDeception::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // recordType
   marshalSize = marshalSize + 2;  // recordLength
   marshalSize = marshalSize + 2;  // padding
   marshalSize = marshalSize + 1;  // emitterNumber
   marshalSize = marshalSize + 1;  // beamNumber
   marshalSize = marshalSize + 1;  // stateIndicator
   marshalSize = marshalSize + 1;  // padding2
   marshalSize = marshalSize + 4;  // azimuthOffset
   marshalSize = marshalSize + 4;  // azimuthWidth
   marshalSize = marshalSize + 4;  // azimuthPullRate
   marshalSize = marshalSize + 4;  // azimuthPullAcceleration
   marshalSize = marshalSize + 4;  // elevationOffset
   marshalSize = marshalSize + 4;  // elevationWidth
   marshalSize = marshalSize + 4;  // elevationPullRate
   marshalSize = marshalSize + 4;  // elevationPullAcceleration
   marshalSize = marshalSize + 4;  // padding3
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
