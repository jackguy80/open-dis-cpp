#include "IFFFundamentalParameterData.h"

using namespace DIS;


IFFFundamentalParameterData::IFFFundamentalParameterData():
   erp(0.0), 
   frequency(0.0), 
   pgrf(0.0), 
   pulseWidth(0.0), 
   burstLength(0), 
   applicableModes(0), 
   systemSpecificData(0)
{
}

IFFFundamentalParameterData::~IFFFundamentalParameterData()
{
}

void IFFFundamentalParameterData::marshal(DataStream& dataStream) const
{
    dataStream << erp;
    dataStream << frequency;
    dataStream << pgrf;
    dataStream << pulseWidth;
    dataStream << burstLength;
    dataStream << applicableModes;
    dataStream << systemSpecificData;
}

void IFFFundamentalParameterData::unmarshal(DataStream& dataStream)
{
    dataStream >> erp;
    dataStream >> frequency;
    dataStream >> pgrf;
    dataStream >> pulseWidth;
    dataStream >> burstLength;
    dataStream >> applicableModes;
    dataStream >> systemSpecificData;
}


bool IFFFundamentalParameterData::operator ==(const IFFFundamentalParameterData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (erp == rhs.erp) ) ivarsEqual = false;
     if( ! (frequency == rhs.frequency) ) ivarsEqual = false;
     if( ! (pgrf == rhs.pgrf) ) ivarsEqual = false;
     if( ! (pulseWidth == rhs.pulseWidth) ) ivarsEqual = false;
     if( ! (burstLength == rhs.burstLength) ) ivarsEqual = false;
     if( ! (applicableModes == rhs.applicableModes) ) ivarsEqual = false;
     if( ! (systemSpecificData == rhs.systemSpecificData) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IFFFundamentalParameterData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // erp
   marshalSize = marshalSize + 4;  // frequency
   marshalSize = marshalSize + 4;  // pgrf
   marshalSize = marshalSize + 4;  // pulseWidth
   marshalSize = marshalSize + 4;  // burstLength
   marshalSize = marshalSize + 1;  // applicableModes
   marshalSize = marshalSize + 1;  // systemSpecificData
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
