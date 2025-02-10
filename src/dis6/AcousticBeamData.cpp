#include "AcousticBeamData.h"

using namespace DIS;


AcousticBeamData::AcousticBeamData():
   beamDataLength(0), 
   beamIDNumber(0), 
   pad2(0), 
   fundamentalDataParameters()
{
}

AcousticBeamData::~AcousticBeamData()
{
}

void AcousticBeamData::marshal(DataStream& dataStream) const
{
    dataStream << beamDataLength;
    dataStream << beamIDNumber;
    dataStream << pad2;
    fundamentalDataParameters.marshal(dataStream);
}

void AcousticBeamData::unmarshal(DataStream& dataStream)
{
    dataStream >> beamDataLength;
    dataStream >> beamIDNumber;
    dataStream >> pad2;
    fundamentalDataParameters.unmarshal(dataStream);
}


bool AcousticBeamData::operator ==(const AcousticBeamData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (beamDataLength == rhs.beamDataLength) ) ivarsEqual = false;
     if( ! (beamIDNumber == rhs.beamIDNumber) ) ivarsEqual = false;
     if( ! (pad2 == rhs.pad2) ) ivarsEqual = false;
     if( ! (fundamentalDataParameters == rhs.fundamentalDataParameters) ) ivarsEqual = false;

    return ivarsEqual;
 }

int AcousticBeamData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // beamDataLength
   marshalSize = marshalSize + 1;  // beamIDNumber
   marshalSize = marshalSize + 2;  // pad2
   marshalSize = marshalSize + fundamentalDataParameters.getMarshalledSize();  // fundamentalDataParameters
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
