#include "MinefieldResponseNackPdu.h"

using namespace DIS;


MinefieldResponseNackPdu::MinefieldResponseNackPdu() : MinefieldFamilyPdu(),
   minefieldID(), 
   requestingEntityID(), 
   requestID(0), 
   numberOfMissingPdus(0), 
   missingPduSequenceNumbers()
{
    pduType = 40;
}

MinefieldResponseNackPdu::~MinefieldResponseNackPdu()
{
}

void MinefieldResponseNackPdu::marshal(DataStream& dataStream) const
{
    MinefieldFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    minefieldID.marshal(dataStream);
    requestingEntityID.marshal(dataStream);
    dataStream << requestID;
    dataStream << numberOfMissingPdus;
    missingPduSequenceNumbers.marshal(dataStream);
}

void MinefieldResponseNackPdu::unmarshal(DataStream& dataStream)
{
    MinefieldFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    minefieldID.unmarshal(dataStream);
    requestingEntityID.unmarshal(dataStream);
    dataStream >> requestID;
    dataStream >> numberOfMissingPdus;
    missingPduSequenceNumbers.unmarshal(dataStream);
}


bool MinefieldResponseNackPdu::operator ==(const MinefieldResponseNackPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = MinefieldFamilyPdu::operator==(rhs);

     if( ! (minefieldID == rhs.minefieldID) ) ivarsEqual = false;
     if( ! (requestingEntityID == rhs.requestingEntityID) ) ivarsEqual = false;
     if( ! (requestID == rhs.requestID) ) ivarsEqual = false;
     if( ! (numberOfMissingPdus == rhs.numberOfMissingPdus) ) ivarsEqual = false;
     if( ! (missingPduSequenceNumbers == rhs.missingPduSequenceNumbers) ) ivarsEqual = false;

    return ivarsEqual;
 }

int MinefieldResponseNackPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = MinefieldFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + minefieldID.getMarshalledSize();  // minefieldID
   marshalSize = marshalSize + requestingEntityID.getMarshalledSize();  // requestingEntityID
   marshalSize = marshalSize + 1;  // requestID
   marshalSize = marshalSize + 1;  // numberOfMissingPdus
   marshalSize = marshalSize + missingPduSequenceNumbers.getMarshalledSize();  // missingPduSequenceNumbers
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
