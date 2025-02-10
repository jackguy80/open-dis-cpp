#include "UaPdu.h"

using namespace DIS;


UaPdu::UaPdu() : DistributedEmissionsFamilyPdu(),
   emittingEntityID(), 
   eventID(), 
   stateChangeIndicator(0), 
   pad(0), 
   passiveParameterIndex(0), 
   propulsionPlantConfiguration(0), 
   numberOfShafts(0), 
   numberOfAPAs(0), 
   numberOfUAEmitterSystems(0), 
   shaftRPMs(), 
   apaData(), 
   emitterSystems()
{
    pduType = 29;
}

UaPdu::~UaPdu()
{
}

void UaPdu::marshal(DataStream& dataStream) const
{
    DistributedEmissionsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    emittingEntityID.marshal(dataStream);
    eventID.marshal(dataStream);
    dataStream << stateChangeIndicator;
    dataStream << pad;
    dataStream << passiveParameterIndex;
    dataStream << propulsionPlantConfiguration;
    dataStream << numberOfShafts;
    dataStream << numberOfAPAs;
    dataStream << numberOfUAEmitterSystems;
    shaftRPMs.marshal(dataStream);
    apaData.marshal(dataStream);
    emitterSystems.marshal(dataStream);
}

void UaPdu::unmarshal(DataStream& dataStream)
{
    DistributedEmissionsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    emittingEntityID.unmarshal(dataStream);
    eventID.unmarshal(dataStream);
    dataStream >> stateChangeIndicator;
    dataStream >> pad;
    dataStream >> passiveParameterIndex;
    dataStream >> propulsionPlantConfiguration;
    dataStream >> numberOfShafts;
    dataStream >> numberOfAPAs;
    dataStream >> numberOfUAEmitterSystems;
    shaftRPMs.unmarshal(dataStream);
    apaData.unmarshal(dataStream);
    emitterSystems.unmarshal(dataStream);
}


bool UaPdu::operator ==(const UaPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = DistributedEmissionsFamilyPdu::operator==(rhs);

     if( ! (emittingEntityID == rhs.emittingEntityID) ) ivarsEqual = false;
     if( ! (eventID == rhs.eventID) ) ivarsEqual = false;
     if( ! (stateChangeIndicator == rhs.stateChangeIndicator) ) ivarsEqual = false;
     if( ! (pad == rhs.pad) ) ivarsEqual = false;
     if( ! (passiveParameterIndex == rhs.passiveParameterIndex) ) ivarsEqual = false;
     if( ! (propulsionPlantConfiguration == rhs.propulsionPlantConfiguration) ) ivarsEqual = false;
     if( ! (numberOfShafts == rhs.numberOfShafts) ) ivarsEqual = false;
     if( ! (numberOfAPAs == rhs.numberOfAPAs) ) ivarsEqual = false;
     if( ! (numberOfUAEmitterSystems == rhs.numberOfUAEmitterSystems) ) ivarsEqual = false;
     if( ! (shaftRPMs == rhs.shaftRPMs) ) ivarsEqual = false;
     if( ! (apaData == rhs.apaData) ) ivarsEqual = false;
     if( ! (emitterSystems == rhs.emitterSystems) ) ivarsEqual = false;

    return ivarsEqual;
 }

int UaPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = DistributedEmissionsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + emittingEntityID.getMarshalledSize();  // emittingEntityID
   marshalSize = marshalSize + eventID.getMarshalledSize();  // eventID
   marshalSize = marshalSize + 1;  // stateChangeIndicator
   marshalSize = marshalSize + 1;  // pad
   marshalSize = marshalSize + 2;  // passiveParameterIndex
   marshalSize = marshalSize + 1;  // propulsionPlantConfiguration
   marshalSize = marshalSize + 1;  // numberOfShafts
   marshalSize = marshalSize + 1;  // numberOfAPAs
   marshalSize = marshalSize + 1;  // numberOfUAEmitterSystems
   marshalSize = marshalSize + shaftRPMs.getMarshalledSize();  // shaftRPMs
   marshalSize = marshalSize + apaData.getMarshalledSize();  // apaData
   marshalSize = marshalSize + emitterSystems.getMarshalledSize();  // emitterSystems
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
