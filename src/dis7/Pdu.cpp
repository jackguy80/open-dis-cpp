#include "Pdu.h"

using namespace DIS;


Pdu::Pdu() : PduSuperclass(),
   pduStatus(0), 
   padding(0)
{
}

Pdu::~Pdu()
{
}

void Pdu::marshal(DataStream& dataStream) const
{
    PduSuperclass::marshal(dataStream); // Marshal information in superclass first
    dataStream << pduStatus;
    dataStream << padding;
}

void Pdu::unmarshal(DataStream& dataStream)
{
    PduSuperclass::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> pduStatus;
    dataStream >> padding;
}


bool Pdu::operator ==(const Pdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = PduSuperclass::operator==(rhs);

     if( ! (pduStatus == rhs.pduStatus) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int Pdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = PduSuperclass::getMarshalledSize();
   marshalSize = marshalSize + 1;  // pduStatus
   marshalSize = marshalSize + 1;  // padding
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
