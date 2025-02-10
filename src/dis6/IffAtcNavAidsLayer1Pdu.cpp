#include "IffAtcNavAidsLayer1Pdu.h"

using namespace DIS;


IffAtcNavAidsLayer1Pdu::IffAtcNavAidsLayer1Pdu() : DistributedEmissionsFamilyPdu(),
   emittingEntityId(), 
   eventID(), 
   location(), 
   systemID(), 
   pad2(0), 
   fundamentalParameters()
{
    pduType = 28;
}

IffAtcNavAidsLayer1Pdu::~IffAtcNavAidsLayer1Pdu()
{
}

void IffAtcNavAidsLayer1Pdu::marshal(DataStream& dataStream) const
{
    DistributedEmissionsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    emittingEntityId.marshal(dataStream);
    eventID.marshal(dataStream);
    location.marshal(dataStream);
    systemID.marshal(dataStream);
    dataStream << pad2;
    fundamentalParameters.marshal(dataStream);
}

void IffAtcNavAidsLayer1Pdu::unmarshal(DataStream& dataStream)
{
    DistributedEmissionsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    emittingEntityId.unmarshal(dataStream);
    eventID.unmarshal(dataStream);
    location.unmarshal(dataStream);
    systemID.unmarshal(dataStream);
    dataStream >> pad2;
    fundamentalParameters.unmarshal(dataStream);
}


bool IffAtcNavAidsLayer1Pdu::operator ==(const IffAtcNavAidsLayer1Pdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = DistributedEmissionsFamilyPdu::operator==(rhs);

     if( ! (emittingEntityId == rhs.emittingEntityId) ) ivarsEqual = false;
     if( ! (eventID == rhs.eventID) ) ivarsEqual = false;
     if( ! (location == rhs.location) ) ivarsEqual = false;
     if( ! (systemID == rhs.systemID) ) ivarsEqual = false;
     if( ! (pad2 == rhs.pad2) ) ivarsEqual = false;
     if( ! (fundamentalParameters == rhs.fundamentalParameters) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IffAtcNavAidsLayer1Pdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = DistributedEmissionsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + emittingEntityId.getMarshalledSize();  // emittingEntityId
   marshalSize = marshalSize + eventID.getMarshalledSize();  // eventID
   marshalSize = marshalSize + location.getMarshalledSize();  // location
   marshalSize = marshalSize + systemID.getMarshalledSize();  // systemID
   marshalSize = marshalSize + 2;  // pad2
   marshalSize = marshalSize + fundamentalParameters.getMarshalledSize();  // fundamentalParameters
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
