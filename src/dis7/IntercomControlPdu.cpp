#include "IntercomControlPdu.h"

using namespace DIS;


IntercomControlPdu::IntercomControlPdu() : RadioCommunicationsFamilyPdu(),
   controlType(0), 
   communicationsChannelType(0), 
   sourceEntityID(), 
   sourceCommunicationsDeviceID(0), 
   sourceLineID(0), 
   transmitPriority(0), 
   transmitLineState(0), 
   command(0), 
   masterEntityID(), 
   masterCommunicationsDeviceID(0), 
   intercomParametersLength(0), 
   intercomParameters()
{
    pduType = 32;
}

IntercomControlPdu::~IntercomControlPdu()
{
}

void IntercomControlPdu::marshal(DataStream& dataStream) const
{
    RadioCommunicationsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << controlType;
    dataStream << communicationsChannelType;
    sourceEntityID.marshal(dataStream);
    dataStream << sourceCommunicationsDeviceID;
    dataStream << sourceLineID;
    dataStream << transmitPriority;
    dataStream << transmitLineState;
    dataStream << command;
    masterEntityID.marshal(dataStream);
    dataStream << masterCommunicationsDeviceID;
    dataStream << intercomParametersLength;
    intercomParameters.marshal(dataStream);
}

void IntercomControlPdu::unmarshal(DataStream& dataStream)
{
    RadioCommunicationsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> controlType;
    dataStream >> communicationsChannelType;
    sourceEntityID.unmarshal(dataStream);
    dataStream >> sourceCommunicationsDeviceID;
    dataStream >> sourceLineID;
    dataStream >> transmitPriority;
    dataStream >> transmitLineState;
    dataStream >> command;
    masterEntityID.unmarshal(dataStream);
    dataStream >> masterCommunicationsDeviceID;
    dataStream >> intercomParametersLength;
    intercomParameters.unmarshal(dataStream);
}


bool IntercomControlPdu::operator ==(const IntercomControlPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = RadioCommunicationsFamilyPdu::operator==(rhs);

     if( ! (controlType == rhs.controlType) ) ivarsEqual = false;
     if( ! (communicationsChannelType == rhs.communicationsChannelType) ) ivarsEqual = false;
     if( ! (sourceEntityID == rhs.sourceEntityID) ) ivarsEqual = false;
     if( ! (sourceCommunicationsDeviceID == rhs.sourceCommunicationsDeviceID) ) ivarsEqual = false;
     if( ! (sourceLineID == rhs.sourceLineID) ) ivarsEqual = false;
     if( ! (transmitPriority == rhs.transmitPriority) ) ivarsEqual = false;
     if( ! (transmitLineState == rhs.transmitLineState) ) ivarsEqual = false;
     if( ! (command == rhs.command) ) ivarsEqual = false;
     if( ! (masterEntityID == rhs.masterEntityID) ) ivarsEqual = false;
     if( ! (masterCommunicationsDeviceID == rhs.masterCommunicationsDeviceID) ) ivarsEqual = false;
     if( ! (intercomParametersLength == rhs.intercomParametersLength) ) ivarsEqual = false;
     if( ! (intercomParameters == rhs.intercomParameters) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IntercomControlPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = RadioCommunicationsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 1;  // controlType
   marshalSize = marshalSize + 1;  // communicationsChannelType
   marshalSize = marshalSize + sourceEntityID.getMarshalledSize();  // sourceEntityID
   marshalSize = marshalSize + 1;  // sourceCommunicationsDeviceID
   marshalSize = marshalSize + 1;  // sourceLineID
   marshalSize = marshalSize + 1;  // transmitPriority
   marshalSize = marshalSize + 1;  // transmitLineState
   marshalSize = marshalSize + 1;  // command
   marshalSize = marshalSize + masterEntityID.getMarshalledSize();  // masterEntityID
   marshalSize = marshalSize + 2;  // masterCommunicationsDeviceID
   marshalSize = marshalSize + 4;  // intercomParametersLength
   marshalSize = marshalSize + intercomParameters.getMarshalledSize();  // intercomParameters
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
