#include "SeparationVP.h"

using namespace DIS;


SeparationVP::SeparationVP():
   recordType(2), 
   reasonForSeparation(0), 
   preEntityIndicator(0), 
   padding1(0), 
   parentEntityID(), 
   padding2(0), 
   stationLocation(0)
{
}

SeparationVP::~SeparationVP()
{
}

void SeparationVP::marshal(DataStream& dataStream) const
{
    dataStream << recordType;
    dataStream << reasonForSeparation;
    dataStream << preEntityIndicator;
    dataStream << padding1;
    parentEntityID.marshal(dataStream);
    dataStream << padding2;
    dataStream << stationLocation;
}

void SeparationVP::unmarshal(DataStream& dataStream)
{
    dataStream >> recordType;
    dataStream >> reasonForSeparation;
    dataStream >> preEntityIndicator;
    dataStream >> padding1;
    parentEntityID.unmarshal(dataStream);
    dataStream >> padding2;
    dataStream >> stationLocation;
}


bool SeparationVP::operator ==(const SeparationVP& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (recordType == rhs.recordType) ) ivarsEqual = false;
     if( ! (reasonForSeparation == rhs.reasonForSeparation) ) ivarsEqual = false;
     if( ! (preEntityIndicator == rhs.preEntityIndicator) ) ivarsEqual = false;
     if( ! (padding1 == rhs.padding1) ) ivarsEqual = false;
     if( ! (parentEntityID == rhs.parentEntityID) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;
     if( ! (stationLocation == rhs.stationLocation) ) ivarsEqual = false;

    return ivarsEqual;
 }

int SeparationVP::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // recordType
   marshalSize = marshalSize + 1;  // reasonForSeparation
   marshalSize = marshalSize + 1;  // preEntityIndicator
   marshalSize = marshalSize + 1;  // padding1
   marshalSize = marshalSize + parentEntityID.getMarshalledSize();  // parentEntityID
   marshalSize = marshalSize + 2;  // padding2
   marshalSize = marshalSize + 4;  // stationLocation
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
