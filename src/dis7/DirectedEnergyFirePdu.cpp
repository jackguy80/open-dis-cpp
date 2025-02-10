#include "DirectedEnergyFirePdu.h"

using namespace DIS;


DirectedEnergyFirePdu::DirectedEnergyFirePdu() : WarfareFamilyPdu(),
   munitionType(), 
   shotStartTime(), 
   commulativeShotTime(0.0), 
   ApertureEmitterLocation(), 
   apertureDiameter(0.0), 
   wavelength(0.0), 
   peakIrradiance(0.0), 
   pulseRepetitionFrequency(0.0), 
   pulseWidth(0), 
   flags(0), 
   pulseShape(0), 
   padding1(0), 
   padding2(0), 
   padding3(0), 
   numberOfDERecords(0), 
   dERecords()
{
    pduType = 68;
}

DirectedEnergyFirePdu::~DirectedEnergyFirePdu()
{
}

void DirectedEnergyFirePdu::marshal(DataStream& dataStream) const
{
    WarfareFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    munitionType.marshal(dataStream);
    shotStartTime.marshal(dataStream);
    dataStream << commulativeShotTime;
    ApertureEmitterLocation.marshal(dataStream);
    dataStream << apertureDiameter;
    dataStream << wavelength;
    dataStream << peakIrradiance;
    dataStream << pulseRepetitionFrequency;
    dataStream << pulseWidth;
    dataStream << flags;
    dataStream << pulseShape;
    dataStream << padding1;
    dataStream << padding2;
    dataStream << padding3;
    dataStream << numberOfDERecords;
    dERecords.marshal(dataStream);
}

void DirectedEnergyFirePdu::unmarshal(DataStream& dataStream)
{
    WarfareFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    munitionType.unmarshal(dataStream);
    shotStartTime.unmarshal(dataStream);
    dataStream >> commulativeShotTime;
    ApertureEmitterLocation.unmarshal(dataStream);
    dataStream >> apertureDiameter;
    dataStream >> wavelength;
    dataStream >> peakIrradiance;
    dataStream >> pulseRepetitionFrequency;
    dataStream >> pulseWidth;
    dataStream >> flags;
    dataStream >> pulseShape;
    dataStream >> padding1;
    dataStream >> padding2;
    dataStream >> padding3;
    dataStream >> numberOfDERecords;
    dERecords.unmarshal(dataStream);
}


bool DirectedEnergyFirePdu::operator ==(const DirectedEnergyFirePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = WarfareFamilyPdu::operator==(rhs);

     if( ! (munitionType == rhs.munitionType) ) ivarsEqual = false;
     if( ! (shotStartTime == rhs.shotStartTime) ) ivarsEqual = false;
     if( ! (commulativeShotTime == rhs.commulativeShotTime) ) ivarsEqual = false;
     if( ! (ApertureEmitterLocation == rhs.ApertureEmitterLocation) ) ivarsEqual = false;
     if( ! (apertureDiameter == rhs.apertureDiameter) ) ivarsEqual = false;
     if( ! (wavelength == rhs.wavelength) ) ivarsEqual = false;
     if( ! (peakIrradiance == rhs.peakIrradiance) ) ivarsEqual = false;
     if( ! (pulseRepetitionFrequency == rhs.pulseRepetitionFrequency) ) ivarsEqual = false;
     if( ! (pulseWidth == rhs.pulseWidth) ) ivarsEqual = false;
     if( ! (flags == rhs.flags) ) ivarsEqual = false;
     if( ! (pulseShape == rhs.pulseShape) ) ivarsEqual = false;
     if( ! (padding1 == rhs.padding1) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;
     if( ! (padding3 == rhs.padding3) ) ivarsEqual = false;
     if( ! (numberOfDERecords == rhs.numberOfDERecords) ) ivarsEqual = false;
     if( ! (dERecords == rhs.dERecords) ) ivarsEqual = false;

    return ivarsEqual;
 }

int DirectedEnergyFirePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = WarfareFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + munitionType.getMarshalledSize();  // munitionType
   marshalSize = marshalSize + shotStartTime.getMarshalledSize();  // shotStartTime
   marshalSize = marshalSize + 4;  // commulativeShotTime
   marshalSize = marshalSize + ApertureEmitterLocation.getMarshalledSize();  // ApertureEmitterLocation
   marshalSize = marshalSize + 4;  // apertureDiameter
   marshalSize = marshalSize + 4;  // wavelength
   marshalSize = marshalSize + 4;  // peakIrradiance
   marshalSize = marshalSize + 4;  // pulseRepetitionFrequency
   marshalSize = marshalSize + 4;  // pulseWidth
   marshalSize = marshalSize + 4;  // flags
   marshalSize = marshalSize + 1;  // pulseShape
   marshalSize = marshalSize + 1;  // padding1
   marshalSize = marshalSize + 4;  // padding2
   marshalSize = marshalSize + 2;  // padding3
   marshalSize = marshalSize + 2;  // numberOfDERecords
   marshalSize = marshalSize + dERecords.getMarshalledSize();  // dERecords
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
