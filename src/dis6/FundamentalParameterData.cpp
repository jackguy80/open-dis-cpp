#include "FundamentalParameterData.h"

using namespace DIS;


FundamentalParameterData::FundamentalParameterData():
   frequency(0.0), 
   frequencyRange(0.0), 
   effectiveRadiatedPower(0.0), 
   pulseRepetitionFrequency(0.0), 
   pulseWidth(0.0), 
   beamAzimuthCenter(0.0), 
   beamAzimuthSweep(0.0), 
   beamElevationCenter(0.0), 
   beamElevationSweep(0.0), 
   beamSweepSync(0.0)
{
}

FundamentalParameterData::~FundamentalParameterData()
{
}

void FundamentalParameterData::marshal(DataStream& dataStream) const
{
    dataStream << frequency;
    dataStream << frequencyRange;
    dataStream << effectiveRadiatedPower;
    dataStream << pulseRepetitionFrequency;
    dataStream << pulseWidth;
    dataStream << beamAzimuthCenter;
    dataStream << beamAzimuthSweep;
    dataStream << beamElevationCenter;
    dataStream << beamElevationSweep;
    dataStream << beamSweepSync;
}

void FundamentalParameterData::unmarshal(DataStream& dataStream)
{
    dataStream >> frequency;
    dataStream >> frequencyRange;
    dataStream >> effectiveRadiatedPower;
    dataStream >> pulseRepetitionFrequency;
    dataStream >> pulseWidth;
    dataStream >> beamAzimuthCenter;
    dataStream >> beamAzimuthSweep;
    dataStream >> beamElevationCenter;
    dataStream >> beamElevationSweep;
    dataStream >> beamSweepSync;
}


bool FundamentalParameterData::operator ==(const FundamentalParameterData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (frequency == rhs.frequency) ) ivarsEqual = false;
     if( ! (frequencyRange == rhs.frequencyRange) ) ivarsEqual = false;
     if( ! (effectiveRadiatedPower == rhs.effectiveRadiatedPower) ) ivarsEqual = false;
     if( ! (pulseRepetitionFrequency == rhs.pulseRepetitionFrequency) ) ivarsEqual = false;
     if( ! (pulseWidth == rhs.pulseWidth) ) ivarsEqual = false;
     if( ! (beamAzimuthCenter == rhs.beamAzimuthCenter) ) ivarsEqual = false;
     if( ! (beamAzimuthSweep == rhs.beamAzimuthSweep) ) ivarsEqual = false;
     if( ! (beamElevationCenter == rhs.beamElevationCenter) ) ivarsEqual = false;
     if( ! (beamElevationSweep == rhs.beamElevationSweep) ) ivarsEqual = false;
     if( ! (beamSweepSync == rhs.beamSweepSync) ) ivarsEqual = false;

    return ivarsEqual;
 }

int FundamentalParameterData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // frequency
   marshalSize = marshalSize + 4;  // frequencyRange
   marshalSize = marshalSize + 4;  // effectiveRadiatedPower
   marshalSize = marshalSize + 4;  // pulseRepetitionFrequency
   marshalSize = marshalSize + 4;  // pulseWidth
   marshalSize = marshalSize + 4;  // beamAzimuthCenter
   marshalSize = marshalSize + 4;  // beamAzimuthSweep
   marshalSize = marshalSize + 4;  // beamElevationCenter
   marshalSize = marshalSize + 4;  // beamElevationSweep
   marshalSize = marshalSize + 4;  // beamSweepSync
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
