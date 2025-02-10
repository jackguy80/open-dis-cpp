#include "LinearSegmentParameter.h"

using namespace DIS;


LinearSegmentParameter::LinearSegmentParameter():
   segmentNumber(0), 
   segmentAppearance(), 
   location(), 
   orientation(), 
   segmentLength(0), 
   segmentWidth(0), 
   segmentHeight(0), 
   segmentDepth(0), 
   pad1(0)
{
}

LinearSegmentParameter::~LinearSegmentParameter()
{
}

void LinearSegmentParameter::marshal(DataStream& dataStream) const
{
    dataStream << segmentNumber;
    segmentAppearance.marshal(dataStream);
    location.marshal(dataStream);
    orientation.marshal(dataStream);
    dataStream << segmentLength;
    dataStream << segmentWidth;
    dataStream << segmentHeight;
    dataStream << segmentDepth;
    dataStream << pad1;
}

void LinearSegmentParameter::unmarshal(DataStream& dataStream)
{
    dataStream >> segmentNumber;
    segmentAppearance.unmarshal(dataStream);
    location.unmarshal(dataStream);
    orientation.unmarshal(dataStream);
    dataStream >> segmentLength;
    dataStream >> segmentWidth;
    dataStream >> segmentHeight;
    dataStream >> segmentDepth;
    dataStream >> pad1;
}


bool LinearSegmentParameter::operator ==(const LinearSegmentParameter& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (segmentNumber == rhs.segmentNumber) ) ivarsEqual = false;
     if( ! (segmentAppearance == rhs.segmentAppearance) ) ivarsEqual = false;
     if( ! (location == rhs.location) ) ivarsEqual = false;
     if( ! (orientation == rhs.orientation) ) ivarsEqual = false;
     if( ! (segmentLength == rhs.segmentLength) ) ivarsEqual = false;
     if( ! (segmentWidth == rhs.segmentWidth) ) ivarsEqual = false;
     if( ! (segmentHeight == rhs.segmentHeight) ) ivarsEqual = false;
     if( ! (segmentDepth == rhs.segmentDepth) ) ivarsEqual = false;
     if( ! (pad1 == rhs.pad1) ) ivarsEqual = false;

    return ivarsEqual;
 }

int LinearSegmentParameter::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // segmentNumber
   marshalSize = marshalSize + segmentAppearance.getMarshalledSize();  // segmentAppearance
   marshalSize = marshalSize + location.getMarshalledSize();  // location
   marshalSize = marshalSize + orientation.getMarshalledSize();  // orientation
   marshalSize = marshalSize + 2;  // segmentLength
   marshalSize = marshalSize + 2;  // segmentWidth
   marshalSize = marshalSize + 2;  // segmentHeight
   marshalSize = marshalSize + 2;  // segmentDepth
   marshalSize = marshalSize + 4;  // pad1
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
