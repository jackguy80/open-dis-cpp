#include "ArticulatedParts.h"

using namespace DIS;


ArticulatedParts::ArticulatedParts():
   recordType(0), 
   changeIndicator(0), 
   partAttachedTo(0), 
   parameterType(0), 
   parameterValue(0)
{
}

ArticulatedParts::~ArticulatedParts()
{
}

void ArticulatedParts::marshal(DataStream& dataStream) const
{
    dataStream << recordType;
    dataStream << changeIndicator;
    dataStream << partAttachedTo;
    dataStream << parameterType;
    dataStream << parameterValue;
}

void ArticulatedParts::unmarshal(DataStream& dataStream)
{
    dataStream >> recordType;
    dataStream >> changeIndicator;
    dataStream >> partAttachedTo;
    dataStream >> parameterType;
    dataStream >> parameterValue;
}


bool ArticulatedParts::operator ==(const ArticulatedParts& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (recordType == rhs.recordType) ) ivarsEqual = false;
     if( ! (changeIndicator == rhs.changeIndicator) ) ivarsEqual = false;
     if( ! (partAttachedTo == rhs.partAttachedTo) ) ivarsEqual = false;
     if( ! (parameterType == rhs.parameterType) ) ivarsEqual = false;
     if( ! (parameterValue == rhs.parameterValue) ) ivarsEqual = false;

    return ivarsEqual;
 }

int ArticulatedParts::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // recordType
   marshalSize = marshalSize + 1;  // changeIndicator
   marshalSize = marshalSize + 2;  // partAttachedTo
   marshalSize = marshalSize + 4;  // parameterType
   marshalSize = marshalSize + 8;  // parameterValue
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
