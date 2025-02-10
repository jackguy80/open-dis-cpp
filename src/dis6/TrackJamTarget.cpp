#include "TrackJamTarget.h"

using namespace DIS;


TrackJamTarget::TrackJamTarget():
   trackJam(), 
   emitterID(0), 
   beamID(0)
{
}

TrackJamTarget::~TrackJamTarget()
{
}

void TrackJamTarget::marshal(DataStream& dataStream) const
{
    trackJam.marshal(dataStream);
    dataStream << emitterID;
    dataStream << beamID;
}

void TrackJamTarget::unmarshal(DataStream& dataStream)
{
    trackJam.unmarshal(dataStream);
    dataStream >> emitterID;
    dataStream >> beamID;
}


bool TrackJamTarget::operator ==(const TrackJamTarget& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (trackJam == rhs.trackJam) ) ivarsEqual = false;
     if( ! (emitterID == rhs.emitterID) ) ivarsEqual = false;
     if( ! (beamID == rhs.beamID) ) ivarsEqual = false;

    return ivarsEqual;
 }

int TrackJamTarget::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + trackJam.getMarshalledSize();  // trackJam
   marshalSize = marshalSize + 1;  // emitterID
   marshalSize = marshalSize + 1;  // beamID
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
