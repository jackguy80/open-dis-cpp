#include "CommentPdu.h"

using namespace DIS;


CommentPdu::CommentPdu() : SimulationManagementFamilyPdu(),
   numberOfFixedDatumRecords(0), 
   numberOfVariableDatumRecords(0), 
   fixedDatums(), 
   variableDatums()
{
    pduType = 22;
}

CommentPdu::~CommentPdu()
{
}

void CommentPdu::marshal(DataStream& dataStream) const
{
    SimulationManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << numberOfFixedDatumRecords;
    dataStream << numberOfVariableDatumRecords;
    fixedDatums.marshal(dataStream);
    variableDatums.marshal(dataStream);
}

void CommentPdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> numberOfFixedDatumRecords;
    dataStream >> numberOfVariableDatumRecords;
    fixedDatums.unmarshal(dataStream);
    variableDatums.unmarshal(dataStream);
}


bool CommentPdu::operator ==(const CommentPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementFamilyPdu::operator==(rhs);

     if( ! (numberOfFixedDatumRecords == rhs.numberOfFixedDatumRecords) ) ivarsEqual = false;
     if( ! (numberOfVariableDatumRecords == rhs.numberOfVariableDatumRecords) ) ivarsEqual = false;
     if( ! (fixedDatums == rhs.fixedDatums) ) ivarsEqual = false;
     if( ! (variableDatums == rhs.variableDatums) ) ivarsEqual = false;

    return ivarsEqual;
 }

int CommentPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 4;  // numberOfFixedDatumRecords
   marshalSize = marshalSize + 4;  // numberOfVariableDatumRecords
   marshalSize = marshalSize + fixedDatums.getMarshalledSize();  // fixedDatums
   marshalSize = marshalSize + variableDatums.getMarshalledSize();  // variableDatums
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
