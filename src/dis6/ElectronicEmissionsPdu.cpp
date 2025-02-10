#include "ElectronicEmissionsPdu.h"

using namespace DIS;


ElectronicEmissionsPdu::ElectronicEmissionsPdu() : DistributedEmissionsFamilyPdu(),
   emittingEntityID(), 
   eventID(), 
   stateUpdateIndicator(0), 
   numberOfSystems(0), 
   paddingForEmissionsPdu(0), 
   systems(0)
{
    pduType = 23;
    paddingForEmissionsPdu = 0;
}

ElectronicEmissionsPdu::~ElectronicEmissionsPdu()
{
    systems.clear();
}

void ElectronicEmissionsPdu::marshal(DataStream& dataStream) const
{
    DistributedEmissionsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    emittingEntityID.marshal(dataStream);
    eventID.marshal(dataStream);
    dataStream << stateUpdateIndicator;
    dataStream << ( unsigned char )systems.size();
    dataStream << paddingForEmissionsPdu;

     for(size_t idx = 0; idx < systems.size(); idx++)
     {
        ElectronicEmissionSystemData x = systems[idx];
        x.marshal(dataStream);
     }

}

void ElectronicEmissionsPdu::unmarshal(DataStream& dataStream)
{
    DistributedEmissionsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    emittingEntityID.unmarshal(dataStream);
    eventID.unmarshal(dataStream);
    dataStream >> stateUpdateIndicator;
    dataStream >> numberOfSystems;
    dataStream >> paddingForEmissionsPdu;

     systems.clear();
     for(size_t idx = 0; idx < numberOfSystems; idx++)
     {
        ElectronicEmissionSystemData x;
        x.unmarshal(dataStream);
        systems.push_back(x);
     }
}


bool ElectronicEmissionsPdu::operator ==(const ElectronicEmissionsPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = DistributedEmissionsFamilyPdu::operator==(rhs);

     if( ! (emittingEntityID == rhs.emittingEntityID) ) ivarsEqual = false;
     if( ! (eventID == rhs.eventID) ) ivarsEqual = false;
     if( ! (stateUpdateIndicator == rhs.stateUpdateIndicator) ) ivarsEqual = false;
     if( ! (paddingForEmissionsPdu == rhs.paddingForEmissionsPdu) ) ivarsEqual = false;

     for(size_t idx = 0; idx < systems.size(); idx++)
     {
        if( ! ( systems[idx] == rhs.systems[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ElectronicEmissionsPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = DistributedEmissionsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + emittingEntityID.getMarshalledSize();  // emittingEntityID
   marshalSize = marshalSize + eventID.getMarshalledSize();  // eventID
   marshalSize = marshalSize + 1;  // stateUpdateIndicator
   marshalSize = marshalSize + 1;  // numberOfSystems
   marshalSize = marshalSize + 2;  // paddingForEmissionsPdu

   for(int idx=0; idx < systems.size(); idx++)
   {
        ElectronicEmissionSystemData listElement = systems[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

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
