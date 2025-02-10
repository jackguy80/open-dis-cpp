#include "RepairCompletePdu.h"

using namespace DIS;


RepairCompletePdu::RepairCompletePdu() : LogisticsFamilyPdu(),
   receivingEntityID(), 
   repairingEntityID(), 
   repair(0), 
   padding2(0)
{
    pduType = 9;
}

RepairCompletePdu::~RepairCompletePdu()
{
}

void RepairCompletePdu::marshal(DataStream& dataStream) const
{
    LogisticsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    receivingEntityID.marshal(dataStream);
    repairingEntityID.marshal(dataStream);
    dataStream << repair;
    dataStream << padding2;
}

void RepairCompletePdu::unmarshal(DataStream& dataStream)
{
    LogisticsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    receivingEntityID.unmarshal(dataStream);
    repairingEntityID.unmarshal(dataStream);
    dataStream >> repair;
    dataStream >> padding2;
}


bool RepairCompletePdu::operator ==(const RepairCompletePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = LogisticsFamilyPdu::operator==(rhs);

     if( ! (receivingEntityID == rhs.receivingEntityID) ) ivarsEqual = false;
     if( ! (repairingEntityID == rhs.repairingEntityID) ) ivarsEqual = false;
     if( ! (repair == rhs.repair) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;

    return ivarsEqual;
 }

int RepairCompletePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = LogisticsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + receivingEntityID.getMarshalledSize();  // receivingEntityID
   marshalSize = marshalSize + repairingEntityID.getMarshalledSize();  // repairingEntityID
   marshalSize = marshalSize + 2;  // repair
   marshalSize = marshalSize + 2;  // padding2
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
