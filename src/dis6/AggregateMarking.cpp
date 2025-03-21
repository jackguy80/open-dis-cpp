#include "AggregateMarking.h"

using namespace DIS;


AggregateMarking::AggregateMarking():
   characterSet(0)
{
     // Initialize fixed length array
     for(int lengthcharacters= 0; lengthcharacters < 31; lengthcharacters++)
     {
         characters[lengthcharacters] = 0;
     }

}

AggregateMarking::~AggregateMarking()
{
}

void AggregateMarking::marshal(DataStream& dataStream) const
{
    dataStream << characterSet;

     for(size_t idx = 0; idx < 31; idx++)
     {
        dataStream << characters[idx];
     }

}

void AggregateMarking::unmarshal(DataStream& dataStream)
{
    dataStream >> characterSet;

     for(size_t idx = 0; idx < 31; idx++)
     {
        dataStream >> characters[idx];
     }

}


bool AggregateMarking::operator ==(const AggregateMarking& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (characterSet == rhs.characterSet) ) ivarsEqual = false;

     for(int idx = 0; idx < 31; idx++)
     {
          if(!(characters[idx] == rhs.characters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int AggregateMarking::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // characterSet
   marshalSize = marshalSize + 31 * 1;  // characters
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
