#include "TransmitterPdu.h"

using namespace DIS;


TransmitterPdu::TransmitterPdu() : RadioCommunicationsFamilyPdu(),
   radioReferenceID(), 
   radioNumber(0), 
   radioEntityType(), 
   transmitState(0), 
   inputSource(0), 
   variableTransmitterParameterCount(0), 
   antennaLocation(), 
   relativeAntennaLocation(), 
   antennaPatternType(0), 
   antennaPatternCount(0), 
   frequency(0), 
   transmitFrequencyBandwidth(0.0), 
   power(0.0), 
   modulationType(), 
   cryptoSystem(0), 
   cryptoKeyId(0), 
   modulationParameterCount(0), 
   padding2(0), 
   padding3(0), 
   modulationParametersList(), 
   antennaPatternList()
{
    pduType = 25;
}

TransmitterPdu::~TransmitterPdu()
{
}

void TransmitterPdu::marshal(DataStream& dataStream) const
{
    RadioCommunicationsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    radioReferenceID.marshal(dataStream);
    dataStream << radioNumber;
    radioEntityType.marshal(dataStream);
    dataStream << transmitState;
    dataStream << inputSource;
    dataStream << variableTransmitterParameterCount;
    antennaLocation.marshal(dataStream);
    relativeAntennaLocation.marshal(dataStream);
    dataStream << antennaPatternType;
    dataStream << antennaPatternCount;
    dataStream << frequency;
    dataStream << transmitFrequencyBandwidth;
    dataStream << power;
    modulationType.marshal(dataStream);
    dataStream << cryptoSystem;
    dataStream << cryptoKeyId;
    dataStream << modulationParameterCount;
    dataStream << padding2;
    dataStream << padding3;
    modulationParametersList.marshal(dataStream);
    antennaPatternList.marshal(dataStream);
}

void TransmitterPdu::unmarshal(DataStream& dataStream)
{
    RadioCommunicationsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    radioReferenceID.unmarshal(dataStream);
    dataStream >> radioNumber;
    radioEntityType.unmarshal(dataStream);
    dataStream >> transmitState;
    dataStream >> inputSource;
    dataStream >> variableTransmitterParameterCount;
    antennaLocation.unmarshal(dataStream);
    relativeAntennaLocation.unmarshal(dataStream);
    dataStream >> antennaPatternType;
    dataStream >> antennaPatternCount;
    dataStream >> frequency;
    dataStream >> transmitFrequencyBandwidth;
    dataStream >> power;
    modulationType.unmarshal(dataStream);
    dataStream >> cryptoSystem;
    dataStream >> cryptoKeyId;
    dataStream >> modulationParameterCount;
    dataStream >> padding2;
    dataStream >> padding3;
    modulationParametersList.unmarshal(dataStream);
    antennaPatternList.unmarshal(dataStream);
}


bool TransmitterPdu::operator ==(const TransmitterPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = RadioCommunicationsFamilyPdu::operator==(rhs);

     if( ! (radioReferenceID == rhs.radioReferenceID) ) ivarsEqual = false;
     if( ! (radioNumber == rhs.radioNumber) ) ivarsEqual = false;
     if( ! (radioEntityType == rhs.radioEntityType) ) ivarsEqual = false;
     if( ! (transmitState == rhs.transmitState) ) ivarsEqual = false;
     if( ! (inputSource == rhs.inputSource) ) ivarsEqual = false;
     if( ! (variableTransmitterParameterCount == rhs.variableTransmitterParameterCount) ) ivarsEqual = false;
     if( ! (antennaLocation == rhs.antennaLocation) ) ivarsEqual = false;
     if( ! (relativeAntennaLocation == rhs.relativeAntennaLocation) ) ivarsEqual = false;
     if( ! (antennaPatternType == rhs.antennaPatternType) ) ivarsEqual = false;
     if( ! (antennaPatternCount == rhs.antennaPatternCount) ) ivarsEqual = false;
     if( ! (frequency == rhs.frequency) ) ivarsEqual = false;
     if( ! (transmitFrequencyBandwidth == rhs.transmitFrequencyBandwidth) ) ivarsEqual = false;
     if( ! (power == rhs.power) ) ivarsEqual = false;
     if( ! (modulationType == rhs.modulationType) ) ivarsEqual = false;
     if( ! (cryptoSystem == rhs.cryptoSystem) ) ivarsEqual = false;
     if( ! (cryptoKeyId == rhs.cryptoKeyId) ) ivarsEqual = false;
     if( ! (modulationParameterCount == rhs.modulationParameterCount) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;
     if( ! (padding3 == rhs.padding3) ) ivarsEqual = false;
     if( ! (modulationParametersList == rhs.modulationParametersList) ) ivarsEqual = false;
     if( ! (antennaPatternList == rhs.antennaPatternList) ) ivarsEqual = false;

    return ivarsEqual;
 }

int TransmitterPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = RadioCommunicationsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + radioReferenceID.getMarshalledSize();  // radioReferenceID
   marshalSize = marshalSize + 2;  // radioNumber
   marshalSize = marshalSize + radioEntityType.getMarshalledSize();  // radioEntityType
   marshalSize = marshalSize + 1;  // transmitState
   marshalSize = marshalSize + 1;  // inputSource
   marshalSize = marshalSize + 2;  // variableTransmitterParameterCount
   marshalSize = marshalSize + antennaLocation.getMarshalledSize();  // antennaLocation
   marshalSize = marshalSize + relativeAntennaLocation.getMarshalledSize();  // relativeAntennaLocation
   marshalSize = marshalSize + 2;  // antennaPatternType
   marshalSize = marshalSize + 2;  // antennaPatternCount
   marshalSize = marshalSize + 8;  // frequency
   marshalSize = marshalSize + 4;  // transmitFrequencyBandwidth
   marshalSize = marshalSize + 4;  // power
   marshalSize = marshalSize + modulationType.getMarshalledSize();  // modulationType
   marshalSize = marshalSize + 2;  // cryptoSystem
   marshalSize = marshalSize + 2;  // cryptoKeyId
   marshalSize = marshalSize + 1;  // modulationParameterCount
   marshalSize = marshalSize + 2;  // padding2
   marshalSize = marshalSize + 1;  // padding3
   marshalSize = marshalSize + modulationParametersList.getMarshalledSize();  // modulationParametersList
   marshalSize = marshalSize + antennaPatternList.getMarshalledSize();  // antennaPatternList
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
