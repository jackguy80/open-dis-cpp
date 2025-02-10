#include "CommentReliablePdu.h"

using namespace DIS;


CommentReliablePdu::CommentReliablePdu() : SimulationManagementWithReliabilityFamilyPdu(),
   numberOfFixedDatumRecords(0), 
   numberOfVariableDatumRecords(0), 
   fixedDatumRecords(), 
   variableDatumRecords()
{
    pduType = 62;
}

CommentReliablePdu::~CommentReliablePdu()
{
}

void CommentReliablePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementWithReliabilityFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << numberOfFixedDatumRecords;
    dataStream << numberOfVariableDatumRecords;
    fixedDatumRecords.marshal(dataStream);
    variableDatumRecords.marshal(dataStream);
}

void CommentReliablePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementWithReliabilityFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> numberOfFixedDatumRecords;
    dataStream >> numberOfVariableDatumRecords;
    fixedDatumRecords.unmarshal(dataStream);
    variableDatumRecords.unmarshal(dataStream);
}


bool CommentReliablePdu::operator ==(const CommentReliablePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementWithReliabilityFamilyPdu::operator==(rhs);

     if( ! (numberOfFixedDatumRecords == rhs.numberOfFixedDatumRecords) ) ivarsEqual = false;
     if( ! (numberOfVariableDatumRecords == rhs.numberOfVariableDatumRecords) ) ivarsEqual = false;
     if( ! (fixedDatumRecords == rhs.fixedDatumRecords) ) ivarsEqual = false;
     if( ! (variableDatumRecords == rhs.variableDatumRecords) ) ivarsEqual = false;

    return ivarsEqual;
 }

int CommentReliablePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 4;  // numberOfFixedDatumRecords
   marshalSize = marshalSize + 4;  // numberOfVariableDatumRecords
   marshalSize = marshalSize + fixedDatumRecords.getMarshalledSize();  // fixedDatumRecords
   marshalSize = marshalSize + variableDatumRecords.getMarshalledSize();  // variableDatumRecords
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
