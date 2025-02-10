#include "AttributePdu.h"

using namespace DIS;


AttributePdu::AttributePdu() : EntityInformationFamilyPdu(),
   originatingSimulationAddress(), 
   padding1(0), 
   padding2(0), 
   attributeRecordPduType(0), 
   attributeRecordProtocolVersion(0), 
   masterAttributeRecordType(0), 
   actionCode(0), 
   padding3(0), 
   numberAttributeRecordSet(0)
{
}

AttributePdu::~AttributePdu()
{
}

void AttributePdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    originatingSimulationAddress.marshal(dataStream);
    dataStream << padding1;
    dataStream << padding2;
    dataStream << attributeRecordPduType;
    dataStream << attributeRecordProtocolVersion;
    dataStream << masterAttributeRecordType;
    dataStream << actionCode;
    dataStream << padding3;
    dataStream << numberAttributeRecordSet;
}

void AttributePdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    originatingSimulationAddress.unmarshal(dataStream);
    dataStream >> padding1;
    dataStream >> padding2;
    dataStream >> attributeRecordPduType;
    dataStream >> attributeRecordProtocolVersion;
    dataStream >> masterAttributeRecordType;
    dataStream >> actionCode;
    dataStream >> padding3;
    dataStream >> numberAttributeRecordSet;
}


bool AttributePdu::operator ==(const AttributePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (originatingSimulationAddress == rhs.originatingSimulationAddress) ) ivarsEqual = false;
     if( ! (padding1 == rhs.padding1) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;
     if( ! (attributeRecordPduType == rhs.attributeRecordPduType) ) ivarsEqual = false;
     if( ! (attributeRecordProtocolVersion == rhs.attributeRecordProtocolVersion) ) ivarsEqual = false;
     if( ! (masterAttributeRecordType == rhs.masterAttributeRecordType) ) ivarsEqual = false;
     if( ! (actionCode == rhs.actionCode) ) ivarsEqual = false;
     if( ! (padding3 == rhs.padding3) ) ivarsEqual = false;
     if( ! (numberAttributeRecordSet == rhs.numberAttributeRecordSet) ) ivarsEqual = false;

    return ivarsEqual;
 }

int AttributePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + originatingSimulationAddress.getMarshalledSize();  // originatingSimulationAddress
   marshalSize = marshalSize + 4;  // padding1
   marshalSize = marshalSize + 2;  // padding2
   marshalSize = marshalSize + 1;  // attributeRecordPduType
   marshalSize = marshalSize + 1;  // attributeRecordProtocolVersion
   marshalSize = marshalSize + 4;  // masterAttributeRecordType
   marshalSize = marshalSize + 1;  // actionCode
   marshalSize = marshalSize + 1;  // padding3
   marshalSize = marshalSize + 2;  // numberAttributeRecordSet
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
