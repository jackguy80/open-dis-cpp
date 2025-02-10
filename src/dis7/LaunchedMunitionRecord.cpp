#include "LaunchedMunitionRecord.h"

using namespace DIS;


LaunchedMunitionRecord::LaunchedMunitionRecord():
   fireEventID(), 
   padding(0), 
   firingEntityID(), 
   padding2(0), 
   targetEntityID(), 
   padding3(0), 
   targetLocation()
{
}

LaunchedMunitionRecord::~LaunchedMunitionRecord()
{
}

void LaunchedMunitionRecord::marshal(DataStream& dataStream) const
{
    fireEventID.marshal(dataStream);
    dataStream << padding;
    firingEntityID.marshal(dataStream);
    dataStream << padding2;
    targetEntityID.marshal(dataStream);
    dataStream << padding3;
    targetLocation.marshal(dataStream);
}

void LaunchedMunitionRecord::unmarshal(DataStream& dataStream)
{
    fireEventID.unmarshal(dataStream);
    dataStream >> padding;
    firingEntityID.unmarshal(dataStream);
    dataStream >> padding2;
    targetEntityID.unmarshal(dataStream);
    dataStream >> padding3;
    targetLocation.unmarshal(dataStream);
}


bool LaunchedMunitionRecord::operator ==(const LaunchedMunitionRecord& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (fireEventID == rhs.fireEventID) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;
     if( ! (firingEntityID == rhs.firingEntityID) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;
     if( ! (targetEntityID == rhs.targetEntityID) ) ivarsEqual = false;
     if( ! (padding3 == rhs.padding3) ) ivarsEqual = false;
     if( ! (targetLocation == rhs.targetLocation) ) ivarsEqual = false;

    return ivarsEqual;
 }

int LaunchedMunitionRecord::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + fireEventID.getMarshalledSize();  // fireEventID
   marshalSize = marshalSize + 2;  // padding
   marshalSize = marshalSize + firingEntityID.getMarshalledSize();  // firingEntityID
   marshalSize = marshalSize + 2;  // padding2
   marshalSize = marshalSize + targetEntityID.getMarshalledSize();  // targetEntityID
   marshalSize = marshalSize + 2;  // padding3
   marshalSize = marshalSize + targetLocation.getMarshalledSize();  // targetLocation
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
