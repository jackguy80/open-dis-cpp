#include "ElectronicEmissionSystemData.h"

using namespace DIS;


ElectronicEmissionSystemData::ElectronicEmissionSystemData():
   systemDataLength(0), 
   numberOfBeams(0), 
   emissionsPadding2(0), 
   emitterSystem(), 
   location(), 
   beamDataRecords(0)
{
}

ElectronicEmissionSystemData::~ElectronicEmissionSystemData()
{
    beamDataRecords.clear();
}

void ElectronicEmissionSystemData::marshal(DataStream& dataStream) const
{
    dataStream << systemDataLength;
    dataStream << ( unsigned char )beamDataRecords.size();
    dataStream << emissionsPadding2;
    emitterSystem.marshal(dataStream);
    location.marshal(dataStream);

     for(size_t idx = 0; idx < beamDataRecords.size(); idx++)
     {
        ElectronicEmissionBeamData x = beamDataRecords[idx];
        x.marshal(dataStream);
     }

}

void ElectronicEmissionSystemData::unmarshal(DataStream& dataStream)
{
    dataStream >> systemDataLength;
    dataStream >> numberOfBeams;
    dataStream >> emissionsPadding2;
    emitterSystem.unmarshal(dataStream);
    location.unmarshal(dataStream);

     beamDataRecords.clear();
     for(size_t idx = 0; idx < numberOfBeams; idx++)
     {
        ElectronicEmissionBeamData x;
        x.unmarshal(dataStream);
        beamDataRecords.push_back(x);
     }
}


bool ElectronicEmissionSystemData::operator ==(const ElectronicEmissionSystemData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (systemDataLength == rhs.systemDataLength) ) ivarsEqual = false;
     if( ! (emissionsPadding2 == rhs.emissionsPadding2) ) ivarsEqual = false;
     if( ! (emitterSystem == rhs.emitterSystem) ) ivarsEqual = false;
     if( ! (location == rhs.location) ) ivarsEqual = false;

     for(size_t idx = 0; idx < beamDataRecords.size(); idx++)
     {
        if( ! ( beamDataRecords[idx] == rhs.beamDataRecords[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ElectronicEmissionSystemData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // systemDataLength
   marshalSize = marshalSize + 1;  // numberOfBeams
   marshalSize = marshalSize + 2;  // emissionsPadding2
   marshalSize = marshalSize + emitterSystem.getMarshalledSize();  // emitterSystem
   marshalSize = marshalSize + location.getMarshalledSize();  // location

   for(int idx=0; idx < beamDataRecords.size(); idx++)
   {
        ElectronicEmissionBeamData listElement = beamDataRecords[idx];
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
