#include "IntercomSignalPdu.h"

using namespace DIS;


IntercomSignalPdu::IntercomSignalPdu() : RadioCommunicationsFamilyPdu(),
   entityID(), 
   communicationsDeviceID(0), 
   encodingScheme(0), 
   tdlType(0), 
   sampleRate(0), 
   dataLength(0), 
   samples(0), 
   data()
{
    pduType = 31;
}

IntercomSignalPdu::~IntercomSignalPdu()
{
}

void IntercomSignalPdu::marshal(DataStream& dataStream) const
{
    RadioCommunicationsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    entityID.marshal(dataStream);
    dataStream << communicationsDeviceID;
    dataStream << encodingScheme;
    dataStream << tdlType;
    dataStream << sampleRate;
    dataStream << dataLength;
    dataStream << samples;
    data.marshal(dataStream);
}

void IntercomSignalPdu::unmarshal(DataStream& dataStream)
{
    RadioCommunicationsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    entityID.unmarshal(dataStream);
    dataStream >> communicationsDeviceID;
    dataStream >> encodingScheme;
    dataStream >> tdlType;
    dataStream >> sampleRate;
    dataStream >> dataLength;
    dataStream >> samples;
    data.unmarshal(dataStream);
}


bool IntercomSignalPdu::operator ==(const IntercomSignalPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = RadioCommunicationsFamilyPdu::operator==(rhs);

     if( ! (entityID == rhs.entityID) ) ivarsEqual = false;
     if( ! (communicationsDeviceID == rhs.communicationsDeviceID) ) ivarsEqual = false;
     if( ! (encodingScheme == rhs.encodingScheme) ) ivarsEqual = false;
     if( ! (tdlType == rhs.tdlType) ) ivarsEqual = false;
     if( ! (sampleRate == rhs.sampleRate) ) ivarsEqual = false;
     if( ! (dataLength == rhs.dataLength) ) ivarsEqual = false;
     if( ! (samples == rhs.samples) ) ivarsEqual = false;
     if( ! (data == rhs.data) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IntercomSignalPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = RadioCommunicationsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + entityID.getMarshalledSize();  // entityID
   marshalSize = marshalSize + 2;  // communicationsDeviceID
   marshalSize = marshalSize + 2;  // encodingScheme
   marshalSize = marshalSize + 2;  // tdlType
   marshalSize = marshalSize + 4;  // sampleRate
   marshalSize = marshalSize + 2;  // dataLength
   marshalSize = marshalSize + 2;  // samples
   marshalSize = marshalSize + data.getMarshalledSize();  // data
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
