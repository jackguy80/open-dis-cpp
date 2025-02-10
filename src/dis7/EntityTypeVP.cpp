#include "EntityTypeVP.h"

using namespace DIS;


EntityTypeVP::EntityTypeVP():
   recordType(3), 
   changeIndicator(0), 
   entityType(), 
   padding(0), 
   padding1(0)
{
}

EntityTypeVP::~EntityTypeVP()
{
}

void EntityTypeVP::marshal(DataStream& dataStream) const
{
    dataStream << recordType;
    dataStream << changeIndicator;
    entityType.marshal(dataStream);
    dataStream << padding;
    dataStream << padding1;
}

void EntityTypeVP::unmarshal(DataStream& dataStream)
{
    dataStream >> recordType;
    dataStream >> changeIndicator;
    entityType.unmarshal(dataStream);
    dataStream >> padding;
    dataStream >> padding1;
}


bool EntityTypeVP::operator ==(const EntityTypeVP& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (recordType == rhs.recordType) ) ivarsEqual = false;
     if( ! (changeIndicator == rhs.changeIndicator) ) ivarsEqual = false;
     if( ! (entityType == rhs.entityType) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;
     if( ! (padding1 == rhs.padding1) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EntityTypeVP::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // recordType
   marshalSize = marshalSize + 1;  // changeIndicator
   marshalSize = marshalSize + entityType.getMarshalledSize();  // entityType
   marshalSize = marshalSize + 2;  // padding
   marshalSize = marshalSize + 4;  // padding1
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
