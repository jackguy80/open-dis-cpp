#include "LinearSegmentParameter.h"

using namespace DIS;


LinearSegmentParameter::LinearSegmentParameter():
   segmentNumber(0), 
   segmentModification(0), 
   generalSegmentAppearance(0), 
   specificSegmentAppearance(0), 
   segmentLocation(), 
   segmentOrientation(), 
   segmentLength(0.0), 
   segmentWidth(0.0), 
   segmentHeight(0.0), 
   segmentDepth(0.0), 
   padding(0)
{
}

LinearSegmentParameter::~LinearSegmentParameter()
{
}

void LinearSegmentParameter::marshal(DataStream& dataStream) const
{
    dataStream << segmentNumber;
    dataStream << segmentModification;
    dataStream << generalSegmentAppearance;
    dataStream << specificSegmentAppearance;
    segmentLocation.marshal(dataStream);
    segmentOrientation.marshal(dataStream);
    dataStream << segmentLength;
    dataStream << segmentWidth;
    dataStream << segmentHeight;
    dataStream << segmentDepth;
    dataStream << padding;
}

void LinearSegmentParameter::unmarshal(DataStream& dataStream)
{
    dataStream >> segmentNumber;
    dataStream >> segmentModification;
    dataStream >> generalSegmentAppearance;
    dataStream >> specificSegmentAppearance;
    segmentLocation.unmarshal(dataStream);
    segmentOrientation.unmarshal(dataStream);
    dataStream >> segmentLength;
    dataStream >> segmentWidth;
    dataStream >> segmentHeight;
    dataStream >> segmentDepth;
    dataStream >> padding;
}


bool LinearSegmentParameter::operator ==(const LinearSegmentParameter& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (segmentNumber == rhs.segmentNumber) ) ivarsEqual = false;
     if( ! (segmentModification == rhs.segmentModification) ) ivarsEqual = false;
     if( ! (generalSegmentAppearance == rhs.generalSegmentAppearance) ) ivarsEqual = false;
     if( ! (specificSegmentAppearance == rhs.specificSegmentAppearance) ) ivarsEqual = false;
     if( ! (segmentLocation == rhs.segmentLocation) ) ivarsEqual = false;
     if( ! (segmentOrientation == rhs.segmentOrientation) ) ivarsEqual = false;
     if( ! (segmentLength == rhs.segmentLength) ) ivarsEqual = false;
     if( ! (segmentWidth == rhs.segmentWidth) ) ivarsEqual = false;
     if( ! (segmentHeight == rhs.segmentHeight) ) ivarsEqual = false;
     if( ! (segmentDepth == rhs.segmentDepth) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int LinearSegmentParameter::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // segmentNumber
   marshalSize = marshalSize + 1;  // segmentModification
   marshalSize = marshalSize + 2;  // generalSegmentAppearance
   marshalSize = marshalSize + 4;  // specificSegmentAppearance
   marshalSize = marshalSize + segmentLocation.getMarshalledSize();  // segmentLocation
   marshalSize = marshalSize + segmentOrientation.getMarshalledSize();  // segmentOrientation
   marshalSize = marshalSize + 4;  // segmentLength
   marshalSize = marshalSize + 4;  // segmentWidth
   marshalSize = marshalSize + 4;  // segmentHeight
   marshalSize = marshalSize + 4;  // segmentDepth
   marshalSize = marshalSize + 4;  // padding
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
