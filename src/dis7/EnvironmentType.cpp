#include "EnvironmentType.h"

using namespace DIS;


EnvironmentType::EnvironmentType():
   entityKind(0), 
   domain(0), 
   entityClass(0), 
   category(0), 
   subcategory(0), 
   specific(0), 
   extra(0)
{
}

EnvironmentType::~EnvironmentType()
{
}

void EnvironmentType::marshal(DataStream& dataStream) const
{
    dataStream << entityKind;
    dataStream << domain;
    dataStream << entityClass;
    dataStream << category;
    dataStream << subcategory;
    dataStream << specific;
    dataStream << extra;
}

void EnvironmentType::unmarshal(DataStream& dataStream)
{
    dataStream >> entityKind;
    dataStream >> domain;
    dataStream >> entityClass;
    dataStream >> category;
    dataStream >> subcategory;
    dataStream >> specific;
    dataStream >> extra;
}


bool EnvironmentType::operator ==(const EnvironmentType& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (entityKind == rhs.entityKind) ) ivarsEqual = false;
     if( ! (domain == rhs.domain) ) ivarsEqual = false;
     if( ! (entityClass == rhs.entityClass) ) ivarsEqual = false;
     if( ! (category == rhs.category) ) ivarsEqual = false;
     if( ! (subcategory == rhs.subcategory) ) ivarsEqual = false;
     if( ! (specific == rhs.specific) ) ivarsEqual = false;
     if( ! (extra == rhs.extra) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EnvironmentType::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // entityKind
   marshalSize = marshalSize + 1;  // domain
   marshalSize = marshalSize + 2;  // entityClass
   marshalSize = marshalSize + 1;  // category
   marshalSize = marshalSize + 1;  // subcategory
   marshalSize = marshalSize + 1;  // specific
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
