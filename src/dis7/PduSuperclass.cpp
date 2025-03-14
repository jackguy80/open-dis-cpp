#include "PduSuperclass.h"

using namespace DIS;


PduSuperclass::PduSuperclass():
   protocolVersion(7), 
   exerciseID(0), 
   pduType(0), 
   protocolFamily(0), 
   timestamp(0), 
   length(0)
{
}

PduSuperclass::~PduSuperclass()
{
}

void PduSuperclass::marshal(DataStream& dataStream) const
{
    dataStream << protocolVersion;
    dataStream << exerciseID;
    dataStream << pduType;
    dataStream << protocolFamily;
    dataStream << timestamp;
    dataStream << length;
}

void PduSuperclass::unmarshal(DataStream& dataStream)
{
    dataStream >> protocolVersion;
    dataStream >> exerciseID;
    dataStream >> pduType;
    dataStream >> protocolFamily;
    dataStream >> timestamp;
    dataStream >> length;
}


bool PduSuperclass::operator ==(const PduSuperclass& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (protocolVersion == rhs.protocolVersion) ) ivarsEqual = false;
     if( ! (exerciseID == rhs.exerciseID) ) ivarsEqual = false;
     if( ! (pduType == rhs.pduType) ) ivarsEqual = false;
     if( ! (protocolFamily == rhs.protocolFamily) ) ivarsEqual = false;
     if( ! (timestamp == rhs.timestamp) ) ivarsEqual = false;
     if( ! (length == rhs.length) ) ivarsEqual = false;

    return ivarsEqual;
 }

int PduSuperclass::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // protocolVersion
   marshalSize = marshalSize + 1;  // exerciseID
   marshalSize = marshalSize + 1;  // pduType
   marshalSize = marshalSize + 1;  // protocolFamily
   marshalSize = marshalSize + 4;  // timestamp
   marshalSize = marshalSize + 2;  // length
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
