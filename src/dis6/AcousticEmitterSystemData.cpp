#include "AcousticEmitterSystemData.h"

using namespace DIS;


AcousticEmitterSystemData::AcousticEmitterSystemData():
   emitterSystemDataLength(0), 
   numberOfBeams(0), 
   pad2(0), 
   acousticEmitterSystem(), 
   emitterLocation(), 
   beamRecords(0)
{
}

AcousticEmitterSystemData::~AcousticEmitterSystemData()
{
    beamRecords.clear();
}

void AcousticEmitterSystemData::marshal(DataStream& dataStream) const
{
    dataStream << emitterSystemDataLength;
    dataStream << ( unsigned char )beamRecords.size();
    dataStream << pad2;
    acousticEmitterSystem.marshal(dataStream);
    emitterLocation.marshal(dataStream);

     for(size_t idx = 0; idx < beamRecords.size(); idx++)
     {
        AcousticBeamData x = beamRecords[idx];
        x.marshal(dataStream);
     }

}

void AcousticEmitterSystemData::unmarshal(DataStream& dataStream)
{
    dataStream >> emitterSystemDataLength;
    dataStream >> numberOfBeams;
    dataStream >> pad2;
    acousticEmitterSystem.unmarshal(dataStream);
    emitterLocation.unmarshal(dataStream);

     beamRecords.clear();
     for(size_t idx = 0; idx < numberOfBeams; idx++)
     {
        AcousticBeamData x;
        x.unmarshal(dataStream);
        beamRecords.push_back(x);
     }
}


bool AcousticEmitterSystemData::operator ==(const AcousticEmitterSystemData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (emitterSystemDataLength == rhs.emitterSystemDataLength) ) ivarsEqual = false;
     if( ! (pad2 == rhs.pad2) ) ivarsEqual = false;
     if( ! (acousticEmitterSystem == rhs.acousticEmitterSystem) ) ivarsEqual = false;
     if( ! (emitterLocation == rhs.emitterLocation) ) ivarsEqual = false;

     for(size_t idx = 0; idx < beamRecords.size(); idx++)
     {
        if( ! ( beamRecords[idx] == rhs.beamRecords[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int AcousticEmitterSystemData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // emitterSystemDataLength
   marshalSize = marshalSize + 1;  // numberOfBeams
   marshalSize = marshalSize + 2;  // pad2
   marshalSize = marshalSize + acousticEmitterSystem.getMarshalledSize();  // acousticEmitterSystem
   marshalSize = marshalSize + emitterLocation.getMarshalledSize();  // emitterLocation

   for(int idx=0; idx < beamRecords.size(); idx++)
   {
        AcousticBeamData listElement = beamRecords[idx];
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
