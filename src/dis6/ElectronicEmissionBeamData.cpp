#include "ElectronicEmissionBeamData.h"

using namespace DIS;


ElectronicEmissionBeamData::ElectronicEmissionBeamData():
   beamDataLength(0), 
   beamIDNumber(0), 
   beamParameterIndex(0), 
   fundamentalParameterData(), 
   beamFunction(0), 
   numberOfTrackJamTargets(0), 
   highDensityTrackJam(0), 
   pad4(0), 
   jammingModeSequence(0), 
   trackJamTargets(0)
{
}

ElectronicEmissionBeamData::~ElectronicEmissionBeamData()
{
    trackJamTargets.clear();
}

void ElectronicEmissionBeamData::marshal(DataStream& dataStream) const
{
    dataStream << beamDataLength;
    dataStream << beamIDNumber;
    dataStream << beamParameterIndex;
    fundamentalParameterData.marshal(dataStream);
    dataStream << beamFunction;
    dataStream << ( unsigned char )trackJamTargets.size();
    dataStream << highDensityTrackJam;
    dataStream << pad4;
    dataStream << jammingModeSequence;

     for(size_t idx = 0; idx < trackJamTargets.size(); idx++)
     {
        TrackJamTarget x = trackJamTargets[idx];
        x.marshal(dataStream);
     }

}

void ElectronicEmissionBeamData::unmarshal(DataStream& dataStream)
{
    dataStream >> beamDataLength;
    dataStream >> beamIDNumber;
    dataStream >> beamParameterIndex;
    fundamentalParameterData.unmarshal(dataStream);
    dataStream >> beamFunction;
    dataStream >> numberOfTrackJamTargets;
    dataStream >> highDensityTrackJam;
    dataStream >> pad4;
    dataStream >> jammingModeSequence;

     trackJamTargets.clear();
     for(size_t idx = 0; idx < numberOfTrackJamTargets; idx++)
     {
        TrackJamTarget x;
        x.unmarshal(dataStream);
        trackJamTargets.push_back(x);
     }
}


bool ElectronicEmissionBeamData::operator ==(const ElectronicEmissionBeamData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (beamDataLength == rhs.beamDataLength) ) ivarsEqual = false;
     if( ! (beamIDNumber == rhs.beamIDNumber) ) ivarsEqual = false;
     if( ! (beamParameterIndex == rhs.beamParameterIndex) ) ivarsEqual = false;
     if( ! (fundamentalParameterData == rhs.fundamentalParameterData) ) ivarsEqual = false;
     if( ! (beamFunction == rhs.beamFunction) ) ivarsEqual = false;
     if( ! (highDensityTrackJam == rhs.highDensityTrackJam) ) ivarsEqual = false;
     if( ! (pad4 == rhs.pad4) ) ivarsEqual = false;
     if( ! (jammingModeSequence == rhs.jammingModeSequence) ) ivarsEqual = false;

     for(size_t idx = 0; idx < trackJamTargets.size(); idx++)
     {
        if( ! ( trackJamTargets[idx] == rhs.trackJamTargets[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ElectronicEmissionBeamData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // beamDataLength
   marshalSize = marshalSize + 1;  // beamIDNumber
   marshalSize = marshalSize + 2;  // beamParameterIndex
   marshalSize = marshalSize + fundamentalParameterData.getMarshalledSize();  // fundamentalParameterData
   marshalSize = marshalSize + 1;  // beamFunction
   marshalSize = marshalSize + 1;  // numberOfTrackJamTargets
   marshalSize = marshalSize + 1;  // highDensityTrackJam
   marshalSize = marshalSize + 1;  // pad4
   marshalSize = marshalSize + 4;  // jammingModeSequence

   for(int idx=0; idx < trackJamTargets.size(); idx++)
   {
        TrackJamTarget listElement = trackJamTargets[idx];
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
