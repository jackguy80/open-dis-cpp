#include "UAFundamentalParameter.h"

using namespace DIS;


UAFundamentalParameter::UAFundamentalParameter():
   activeEmissionParameterIndex(0), 
   scanPattern(0), 
   beamCenterAzimuthHorizontal(0.0), 
   azimuthalBeamwidthHorizontal(0.0), 
   beamCenterDepressionElevation(0.0), 
   beamwidthDownElevation(0.0)
{
}

UAFundamentalParameter::~UAFundamentalParameter()
{
}

void UAFundamentalParameter::marshal(DataStream& dataStream) const
{
    dataStream << activeEmissionParameterIndex;
    dataStream << scanPattern;
    dataStream << beamCenterAzimuthHorizontal;
    dataStream << azimuthalBeamwidthHorizontal;
    dataStream << beamCenterDepressionElevation;
    dataStream << beamwidthDownElevation;
}

void UAFundamentalParameter::unmarshal(DataStream& dataStream)
{
    dataStream >> activeEmissionParameterIndex;
    dataStream >> scanPattern;
    dataStream >> beamCenterAzimuthHorizontal;
    dataStream >> azimuthalBeamwidthHorizontal;
    dataStream >> beamCenterDepressionElevation;
    dataStream >> beamwidthDownElevation;
}


bool UAFundamentalParameter::operator ==(const UAFundamentalParameter& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (activeEmissionParameterIndex == rhs.activeEmissionParameterIndex) ) ivarsEqual = false;
     if( ! (scanPattern == rhs.scanPattern) ) ivarsEqual = false;
     if( ! (beamCenterAzimuthHorizontal == rhs.beamCenterAzimuthHorizontal) ) ivarsEqual = false;
     if( ! (azimuthalBeamwidthHorizontal == rhs.azimuthalBeamwidthHorizontal) ) ivarsEqual = false;
     if( ! (beamCenterDepressionElevation == rhs.beamCenterDepressionElevation) ) ivarsEqual = false;
     if( ! (beamwidthDownElevation == rhs.beamwidthDownElevation) ) ivarsEqual = false;

    return ivarsEqual;
 }

int UAFundamentalParameter::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // activeEmissionParameterIndex
   marshalSize = marshalSize + 2;  // scanPattern
   marshalSize = marshalSize + 4;  // beamCenterAzimuthHorizontal
   marshalSize = marshalSize + 4;  // azimuthalBeamwidthHorizontal
   marshalSize = marshalSize + 4;  // beamCenterDepressionElevation
   marshalSize = marshalSize + 4;  // beamwidthDownElevation
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
