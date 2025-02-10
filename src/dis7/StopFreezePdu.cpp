#include "StopFreezePdu.h"

using namespace DIS;


StopFreezePdu::StopFreezePdu() : SimulationManagementFamilyPdu(),
   realWorldTime(), 
   reason(0), 
   frozenBehavior(0), 
   padding1(0), 
   requestID(0)
{
    pduType = 14;
}

StopFreezePdu::~StopFreezePdu()
{
}

void StopFreezePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    realWorldTime.marshal(dataStream);
    dataStream << reason;
    dataStream << frozenBehavior;
    dataStream << padding1;
    dataStream << requestID;
}

void StopFreezePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    realWorldTime.unmarshal(dataStream);
    dataStream >> reason;
    dataStream >> frozenBehavior;
    dataStream >> padding1;
    dataStream >> requestID;
}


bool StopFreezePdu::operator ==(const StopFreezePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementFamilyPdu::operator==(rhs);

     if( ! (realWorldTime == rhs.realWorldTime) ) ivarsEqual = false;
     if( ! (reason == rhs.reason) ) ivarsEqual = false;
     if( ! (frozenBehavior == rhs.frozenBehavior) ) ivarsEqual = false;
     if( ! (padding1 == rhs.padding1) ) ivarsEqual = false;
     if( ! (requestID == rhs.requestID) ) ivarsEqual = false;

    return ivarsEqual;
 }

int StopFreezePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + realWorldTime.getMarshalledSize();  // realWorldTime
   marshalSize = marshalSize + 1;  // reason
   marshalSize = marshalSize + 1;  // frozenBehavior
   marshalSize = marshalSize + 2;  // padding1
   marshalSize = marshalSize + 4;  // requestID
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
