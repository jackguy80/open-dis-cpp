#include "BeamAntennaPattern.h"

using namespace DIS;


BeamAntennaPattern::BeamAntennaPattern():
   beamDirection(), 
   azimuthBeamwidth(0), 
   elevationBeamwidth(0), 
   referenceSystem(0), 
   padding1(0), 
   padding2(0), 
   ez(0.0), 
   ex(0.0), 
   phase(0.0), 
   padding3(0)
{
}

BeamAntennaPattern::~BeamAntennaPattern()
{
}

void BeamAntennaPattern::marshal(DataStream& dataStream) const
{
    beamDirection.marshal(dataStream);
    dataStream << azimuthBeamwidth;
    dataStream << elevationBeamwidth;
    dataStream << referenceSystem;
    dataStream << padding1;
    dataStream << padding2;
    dataStream << ez;
    dataStream << ex;
    dataStream << phase;
    dataStream << padding3;
}

void BeamAntennaPattern::unmarshal(DataStream& dataStream)
{
    beamDirection.unmarshal(dataStream);
    dataStream >> azimuthBeamwidth;
    dataStream >> elevationBeamwidth;
    dataStream >> referenceSystem;
    dataStream >> padding1;
    dataStream >> padding2;
    dataStream >> ez;
    dataStream >> ex;
    dataStream >> phase;
    dataStream >> padding3;
}


bool BeamAntennaPattern::operator ==(const BeamAntennaPattern& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (beamDirection == rhs.beamDirection) ) ivarsEqual = false;
     if( ! (azimuthBeamwidth == rhs.azimuthBeamwidth) ) ivarsEqual = false;
     if( ! (elevationBeamwidth == rhs.elevationBeamwidth) ) ivarsEqual = false;
     if( ! (referenceSystem == rhs.referenceSystem) ) ivarsEqual = false;
     if( ! (padding1 == rhs.padding1) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;
     if( ! (ez == rhs.ez) ) ivarsEqual = false;
     if( ! (ex == rhs.ex) ) ivarsEqual = false;
     if( ! (phase == rhs.phase) ) ivarsEqual = false;
     if( ! (padding3 == rhs.padding3) ) ivarsEqual = false;

    return ivarsEqual;
 }

int BeamAntennaPattern::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + beamDirection.getMarshalledSize();  // beamDirection
   marshalSize = marshalSize + 4;  // azimuthBeamwidth
   marshalSize = marshalSize + 4;  // elevationBeamwidth
   marshalSize = marshalSize + 1;  // referenceSystem
   marshalSize = marshalSize + 1;  // padding1
   marshalSize = marshalSize + 2;  // padding2
   marshalSize = marshalSize + 4;  // ez
   marshalSize = marshalSize + 4;  // ex
   marshalSize = marshalSize + 4;  // phase
   marshalSize = marshalSize + 4;  // padding3
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
