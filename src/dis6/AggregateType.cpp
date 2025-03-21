#include "AggregateType.h"

using namespace DIS;


AggregateType::AggregateType():
   aggregateKind(0), 
   domain(0), 
   country(0), 
   category(0), 
   subcategory(0), 
   specificInfo(0), 
   extra(0)
{
}

AggregateType::~AggregateType()
{
}

void AggregateType::marshal(DataStream& dataStream) const
{
    dataStream << aggregateKind;
    dataStream << domain;
    dataStream << country;
    dataStream << category;
    dataStream << subcategory;
    dataStream << specificInfo;
    dataStream << extra;
}

void AggregateType::unmarshal(DataStream& dataStream)
{
    dataStream >> aggregateKind;
    dataStream >> domain;
    dataStream >> country;
    dataStream >> category;
    dataStream >> subcategory;
    dataStream >> specificInfo;
    dataStream >> extra;
}


bool AggregateType::operator ==(const AggregateType& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (aggregateKind == rhs.aggregateKind) ) ivarsEqual = false;
     if( ! (domain == rhs.domain) ) ivarsEqual = false;
     if( ! (country == rhs.country) ) ivarsEqual = false;
     if( ! (category == rhs.category) ) ivarsEqual = false;
     if( ! (subcategory == rhs.subcategory) ) ivarsEqual = false;
     if( ! (specificInfo == rhs.specificInfo) ) ivarsEqual = false;
     if( ! (extra == rhs.extra) ) ivarsEqual = false;

    return ivarsEqual;
 }

int AggregateType::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // aggregateKind
   marshalSize = marshalSize + 1;  // domain
   marshalSize = marshalSize + 2;  // country
   marshalSize = marshalSize + 1;  // category
   marshalSize = marshalSize + 1;  // subcategory
   marshalSize = marshalSize + 1;  // specificInfo
   marshalSize = marshalSize + 1;  // extra
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
