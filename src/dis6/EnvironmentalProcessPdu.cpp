#include "EnvironmentalProcessPdu.h"

using namespace DIS;


EnvironmentalProcessPdu::EnvironmentalProcessPdu() : SyntheticEnvironmentFamilyPdu(),
   environementalProcessID(), 
   environmentType(), 
   modelType(0), 
   environmentStatus(0), 
   numberOfEnvironmentRecords(0), 
   sequenceNumber(0), 
   environmentRecords(0)
{
    pduType = 41;
}

EnvironmentalProcessPdu::~EnvironmentalProcessPdu()
{
    environmentRecords.clear();
}

void EnvironmentalProcessPdu::marshal(DataStream& dataStream) const
{
    SyntheticEnvironmentFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    environementalProcessID.marshal(dataStream);
    environmentType.marshal(dataStream);
    dataStream << modelType;
    dataStream << environmentStatus;
    dataStream << ( unsigned char )environmentRecords.size();
    dataStream << sequenceNumber;

     for(size_t idx = 0; idx < environmentRecords.size(); idx++)
     {
        Environment x = environmentRecords[idx];
        x.marshal(dataStream);
     }

}

void EnvironmentalProcessPdu::unmarshal(DataStream& dataStream)
{
    SyntheticEnvironmentFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    environementalProcessID.unmarshal(dataStream);
    environmentType.unmarshal(dataStream);
    dataStream >> modelType;
    dataStream >> environmentStatus;
    dataStream >> numberOfEnvironmentRecords;
    dataStream >> sequenceNumber;

     environmentRecords.clear();
     for(size_t idx = 0; idx < numberOfEnvironmentRecords; idx++)
     {
        Environment x;
        x.unmarshal(dataStream);
        environmentRecords.push_back(x);
     }
}


bool EnvironmentalProcessPdu::operator ==(const EnvironmentalProcessPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SyntheticEnvironmentFamilyPdu::operator==(rhs);

     if( ! (environementalProcessID == rhs.environementalProcessID) ) ivarsEqual = false;
     if( ! (environmentType == rhs.environmentType) ) ivarsEqual = false;
     if( ! (modelType == rhs.modelType) ) ivarsEqual = false;
     if( ! (environmentStatus == rhs.environmentStatus) ) ivarsEqual = false;
     if( ! (sequenceNumber == rhs.sequenceNumber) ) ivarsEqual = false;

     for(size_t idx = 0; idx < environmentRecords.size(); idx++)
     {
        if( ! ( environmentRecords[idx] == rhs.environmentRecords[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int EnvironmentalProcessPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SyntheticEnvironmentFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + environementalProcessID.getMarshalledSize();  // environementalProcessID
   marshalSize = marshalSize + environmentType.getMarshalledSize();  // environmentType
   marshalSize = marshalSize + 1;  // modelType
   marshalSize = marshalSize + 1;  // environmentStatus
   marshalSize = marshalSize + 1;  // numberOfEnvironmentRecords
   marshalSize = marshalSize + 2;  // sequenceNumber

   for(int idx=0; idx < environmentRecords.size(); idx++)
   {
        Environment listElement = environmentRecords[idx];
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
