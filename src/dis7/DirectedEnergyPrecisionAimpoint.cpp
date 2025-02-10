#include "DirectedEnergyPrecisionAimpoint.h"

using namespace DIS;


DirectedEnergyPrecisionAimpoint::DirectedEnergyPrecisionAimpoint():
   recordType(4000), 
   recordLength(88), 
   padding(0), 
   targetSpotLocation(), 
   targetSpotEntityLocation(), 
   targetSpotVelocity(), 
   targetSpotAcceleration(), 
   targetEntityID(), 
   targetComponentID(0), 
   beamSpotType(0), 
   beamSpotCrossSectionSemiMajorAxis(0), 
   beamSpotCrossSectionSemiMinorAxis(0), 
   beamSpotCrossSectionOrientationAngle(0), 
   peakIrradiance(0), 
   padding2(0)
{
}

DirectedEnergyPrecisionAimpoint::~DirectedEnergyPrecisionAimpoint()
{
}

void DirectedEnergyPrecisionAimpoint::marshal(DataStream& dataStream) const
{
    dataStream << recordType;
    dataStream << recordLength;
    dataStream << padding;
    targetSpotLocation.marshal(dataStream);
    targetSpotEntityLocation.marshal(dataStream);
    targetSpotVelocity.marshal(dataStream);
    targetSpotAcceleration.marshal(dataStream);
    targetEntityID.marshal(dataStream);
    dataStream << targetComponentID;
    dataStream << beamSpotType;
    dataStream << beamSpotCrossSectionSemiMajorAxis;
    dataStream << beamSpotCrossSectionSemiMinorAxis;
    dataStream << beamSpotCrossSectionOrientationAngle;
    dataStream << peakIrradiance;
    dataStream << padding2;
}

void DirectedEnergyPrecisionAimpoint::unmarshal(DataStream& dataStream)
{
    dataStream >> recordType;
    dataStream >> recordLength;
    dataStream >> padding;
    targetSpotLocation.unmarshal(dataStream);
    targetSpotEntityLocation.unmarshal(dataStream);
    targetSpotVelocity.unmarshal(dataStream);
    targetSpotAcceleration.unmarshal(dataStream);
    targetEntityID.unmarshal(dataStream);
    dataStream >> targetComponentID;
    dataStream >> beamSpotType;
    dataStream >> beamSpotCrossSectionSemiMajorAxis;
    dataStream >> beamSpotCrossSectionSemiMinorAxis;
    dataStream >> beamSpotCrossSectionOrientationAngle;
    dataStream >> peakIrradiance;
    dataStream >> padding2;
}


bool DirectedEnergyPrecisionAimpoint::operator ==(const DirectedEnergyPrecisionAimpoint& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (recordType == rhs.recordType) ) ivarsEqual = false;
     if( ! (recordLength == rhs.recordLength) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;
     if( ! (targetSpotLocation == rhs.targetSpotLocation) ) ivarsEqual = false;
     if( ! (targetSpotEntityLocation == rhs.targetSpotEntityLocation) ) ivarsEqual = false;
     if( ! (targetSpotVelocity == rhs.targetSpotVelocity) ) ivarsEqual = false;
     if( ! (targetSpotAcceleration == rhs.targetSpotAcceleration) ) ivarsEqual = false;
     if( ! (targetEntityID == rhs.targetEntityID) ) ivarsEqual = false;
     if( ! (targetComponentID == rhs.targetComponentID) ) ivarsEqual = false;
     if( ! (beamSpotType == rhs.beamSpotType) ) ivarsEqual = false;
     if( ! (beamSpotCrossSectionSemiMajorAxis == rhs.beamSpotCrossSectionSemiMajorAxis) ) ivarsEqual = false;
     if( ! (beamSpotCrossSectionSemiMinorAxis == rhs.beamSpotCrossSectionSemiMinorAxis) ) ivarsEqual = false;
     if( ! (beamSpotCrossSectionOrientationAngle == rhs.beamSpotCrossSectionOrientationAngle) ) ivarsEqual = false;
     if( ! (peakIrradiance == rhs.peakIrradiance) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;

    return ivarsEqual;
 }

int DirectedEnergyPrecisionAimpoint::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // recordType
   marshalSize = marshalSize + 2;  // recordLength
   marshalSize = marshalSize + 2;  // padding
   marshalSize = marshalSize + targetSpotLocation.getMarshalledSize();  // targetSpotLocation
   marshalSize = marshalSize + targetSpotEntityLocation.getMarshalledSize();  // targetSpotEntityLocation
   marshalSize = marshalSize + targetSpotVelocity.getMarshalledSize();  // targetSpotVelocity
   marshalSize = marshalSize + targetSpotAcceleration.getMarshalledSize();  // targetSpotAcceleration
   marshalSize = marshalSize + targetEntityID.getMarshalledSize();  // targetEntityID
   marshalSize = marshalSize + 1;  // targetComponentID
   marshalSize = marshalSize + 1;  // beamSpotType
   marshalSize = marshalSize + 4;  // beamSpotCrossSectionSemiMajorAxis
   marshalSize = marshalSize + 4;  // beamSpotCrossSectionSemiMinorAxis
   marshalSize = marshalSize + 4;  // beamSpotCrossSectionOrientationAngle
   marshalSize = marshalSize + 4;  // peakIrradiance
   marshalSize = marshalSize + 4;  // padding2
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
