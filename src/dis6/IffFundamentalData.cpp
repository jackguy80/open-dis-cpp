#include "IffFundamentalData.h"

using namespace DIS;


IffFundamentalData::IffFundamentalData():
   systemStatus(0), 
   alternateParameter4(0), 
   informationLayers(0), 
   modifier(0), 
   parameter1(0), 
   parameter2(0), 
   parameter3(0), 
   parameter4(0), 
   parameter5(0), 
   parameter6(0)
{
}

IffFundamentalData::~IffFundamentalData()
{
}

void IffFundamentalData::marshal(DataStream& dataStream) const
{
    dataStream << systemStatus;
    dataStream << alternateParameter4;
    dataStream << informationLayers;
    dataStream << modifier;
    dataStream << parameter1;
    dataStream << parameter2;
    dataStream << parameter3;
    dataStream << parameter4;
    dataStream << parameter5;
    dataStream << parameter6;
}

void IffFundamentalData::unmarshal(DataStream& dataStream)
{
    dataStream >> systemStatus;
    dataStream >> alternateParameter4;
    dataStream >> informationLayers;
    dataStream >> modifier;
    dataStream >> parameter1;
    dataStream >> parameter2;
    dataStream >> parameter3;
    dataStream >> parameter4;
    dataStream >> parameter5;
    dataStream >> parameter6;
}


bool IffFundamentalData::operator ==(const IffFundamentalData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (systemStatus == rhs.systemStatus) ) ivarsEqual = false;
     if( ! (alternateParameter4 == rhs.alternateParameter4) ) ivarsEqual = false;
     if( ! (informationLayers == rhs.informationLayers) ) ivarsEqual = false;
     if( ! (modifier == rhs.modifier) ) ivarsEqual = false;
     if( ! (parameter1 == rhs.parameter1) ) ivarsEqual = false;
     if( ! (parameter2 == rhs.parameter2) ) ivarsEqual = false;
     if( ! (parameter3 == rhs.parameter3) ) ivarsEqual = false;
     if( ! (parameter4 == rhs.parameter4) ) ivarsEqual = false;
     if( ! (parameter5 == rhs.parameter5) ) ivarsEqual = false;
     if( ! (parameter6 == rhs.parameter6) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IffFundamentalData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // systemStatus
   marshalSize = marshalSize + 1;  // alternateParameter4
   marshalSize = marshalSize + 1;  // informationLayers
   marshalSize = marshalSize + 1;  // modifier
   marshalSize = marshalSize + 2;  // parameter1
   marshalSize = marshalSize + 2;  // parameter2
   marshalSize = marshalSize + 2;  // parameter3
   marshalSize = marshalSize + 2;  // parameter4
   marshalSize = marshalSize + 2;  // parameter5
   marshalSize = marshalSize + 2;  // parameter6
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
