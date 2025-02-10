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
   shaftRPMs(0), 
   apaData(0), 
   emitterSystems(0)
{
    pduType = 29;
}

UaPdu::~UaPdu()
{
    shaftRPMs.clear();
    apaData.clear();
    emitterSystems.clear();
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
    dataStream << ( unsigned char )shaftRPMs.size();
    dataStream << ( unsigned char )apaData.size();
    dataStream << ( unsigned char )emitterSystems.size();

     for(size_t idx = 0; idx < shaftRPMs.size(); idx++)
     {
        ShaftRPMs x = shaftRPMs[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < apaData.size(); idx++)
     {
        ApaData x = apaData[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < emitterSystems.size(); idx++)
     {
        AcousticEmitterSystemData x = emitterSystems[idx];
        x.marshal(dataStream);
     }

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

     shaftRPMs.clear();
     for(size_t idx = 0; idx < numberOfShafts; idx++)
     {
        ShaftRPMs x;
        x.unmarshal(dataStream);
        shaftRPMs.push_back(x);
     }

     apaData.clear();
     for(size_t idx = 0; idx < numberOfAPAs; idx++)
     {
        ApaData x;
        x.unmarshal(dataStream);
        apaData.push_back(x);
     }

     emitterSystems.clear();
     for(size_t idx = 0; idx < numberOfUAEmitterSystems; idx++)
     {
        AcousticEmitterSystemData x;
        x.unmarshal(dataStream);
        emitterSystems.push_back(x);
     }
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

     for(size_t idx = 0; idx < shaftRPMs.size(); idx++)
     {
        if( ! ( shaftRPMs[idx] == rhs.shaftRPMs[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < apaData.size(); idx++)
     {
        if( ! ( apaData[idx] == rhs.apaData[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < emitterSystems.size(); idx++)
     {
        if( ! ( emitterSystems[idx] == rhs.emitterSystems[idx]) ) ivarsEqual = false;
     }


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

   for(int idx=0; idx < shaftRPMs.size(); idx++)
   {
        ShaftRPMs listElement = shaftRPMs[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < apaData.size(); idx++)
   {
        ApaData listElement = apaData[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < emitterSystems.size(); idx++)
   {
        AcousticEmitterSystemData listElement = emitterSystems[idx];
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
