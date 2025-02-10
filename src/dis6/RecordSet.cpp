#include "RecordSet.h"

using namespace DIS;


RecordSet::RecordSet():
   recordID(0), 
   recordSetSerialNumber(0), 
   recordLength(0), 
   recordCount(0), 
   recordValues(0), 
   pad4(0)
{
}

RecordSet::~RecordSet()
{
}

void RecordSet::marshal(DataStream& dataStream) const
{
    dataStream << recordID;
    dataStream << recordSetSerialNumber;
    dataStream << recordLength;
    dataStream << recordCount;
    dataStream << recordValues;
    dataStream << pad4;
}

void RecordSet::unmarshal(DataStream& dataStream)
{
    dataStream >> recordID;
    dataStream >> recordSetSerialNumber;
    dataStream >> recordLength;
    dataStream >> recordCount;
    dataStream >> recordValues;
    dataStream >> pad4;
}


bool RecordSet::operator ==(const RecordSet& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (recordID == rhs.recordID) ) ivarsEqual = false;
     if( ! (recordSetSerialNumber == rhs.recordSetSerialNumber) ) ivarsEqual = false;
     if( ! (recordLength == rhs.recordLength) ) ivarsEqual = false;
     if( ! (recordCount == rhs.recordCount) ) ivarsEqual = false;
     if( ! (recordValues == rhs.recordValues) ) ivarsEqual = false;
     if( ! (pad4 == rhs.pad4) ) ivarsEqual = false;

    return ivarsEqual;
 }

int RecordSet::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // recordID
   marshalSize = marshalSize + 4;  // recordSetSerialNumber
   marshalSize = marshalSize + 2;  // recordLength
   marshalSize = marshalSize + 2;  // recordCount
   marshalSize = marshalSize + 2;  // recordValues
   marshalSize = marshalSize + 1;  // pad4
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
