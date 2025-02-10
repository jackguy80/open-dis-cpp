#include "BlankingSector.h"

using namespace DIS;


BlankingSector::BlankingSector():
   recordType(3500), 
   recordLength(40), 
   padding(0), 
   emitterNumber(0), 
   beamNumber(0), 
   stateIndicator(0), 
   padding2(0), 
   leftAzimuth(0.0), 
   rightAzimuth(0.0), 
   lowerElevation(0.0), 
   upperElevation(0.0), 
   residualPower(0.0), 
   padding3(0), 
   padding4(0)
{
}

BlankingSector::~BlankingSector()
{
}

void BlankingSector::marshal(DataStream& dataStream) const
{
    dataStream << recordType;
    dataStream << recordLength;
    dataStream << padding;
    dataStream << emitterNumber;
    dataStream << beamNumber;
    dataStream << stateIndicator;
    dataStream << padding2;
    dataStream << leftAzimuth;
    dataStream << rightAzimuth;
    dataStream << lowerElevation;
    dataStream << upperElevation;
    dataStream << residualPower;
    dataStream << padding3;
    dataStream << padding4;
}

void BlankingSector::unmarshal(DataStream& dataStream)
{
    dataStream >> recordType;
    dataStream >> recordLength;
    dataStream >> padding;
    dataStream >> emitterNumber;
    dataStream >> beamNumber;
    dataStream >> stateIndicator;
    dataStream >> padding2;
    dataStream >> leftAzimuth;
    dataStream >> rightAzimuth;
    dataStream >> lowerElevation;
    dataStream >> upperElevation;
    dataStream >> residualPower;
    dataStream >> padding3;
    dataStream >> padding4;
}


bool BlankingSector::operator ==(const BlankingSector& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (recordType == rhs.recordType) ) ivarsEqual = false;
     if( ! (recordLength == rhs.recordLength) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;
     if( ! (emitterNumber == rhs.emitterNumber) ) ivarsEqual = false;
     if( ! (beamNumber == rhs.beamNumber) ) ivarsEqual = false;
     if( ! (stateIndicator == rhs.stateIndicator) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;
     if( ! (leftAzimuth == rhs.leftAzimuth) ) ivarsEqual = false;
     if( ! (rightAzimuth == rhs.rightAzimuth) ) ivarsEqual = false;
     if( ! (lowerElevation == rhs.lowerElevation) ) ivarsEqual = false;
     if( ! (upperElevation == rhs.upperElevation) ) ivarsEqual = false;
     if( ! (residualPower == rhs.residualPower) ) ivarsEqual = false;
     if( ! (padding3 == rhs.padding3) ) ivarsEqual = false;
     if( ! (padding4 == rhs.padding4) ) ivarsEqual = false;

    return ivarsEqual;
 }

int BlankingSector::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // recordType
   marshalSize = marshalSize + 2;  // recordLength
   marshalSize = marshalSize + 2;  // padding
   marshalSize = marshalSize + 1;  // emitterNumber
   marshalSize = marshalSize + 1;  // beamNumber
   marshalSize = marshalSize + 1;  // stateIndicator
   marshalSize = marshalSize + 1;  // padding2
   marshalSize = marshalSize + 4;  // leftAzimuth
   marshalSize = marshalSize + 4;  // rightAzimuth
   marshalSize = marshalSize + 4;  // lowerElevation
   marshalSize = marshalSize + 4;  // upperElevation
   marshalSize = marshalSize + 4;  // residualPower
   marshalSize = marshalSize + 4;  // padding3
   marshalSize = marshalSize + 4;  // padding4
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
