#include "GridAxis.h"

using namespace DIS;


GridAxis::GridAxis():
   domainInitialXi(0.0), 
   domainFinalXi(0.0), 
   domainPointsXi(0), 
   interleafFactor(0), 
   axisType(0), 
   numberOfPointsOnXiAxis(0), 
   initialIndex(0)
{
}

GridAxis::~GridAxis()
{
}

void GridAxis::marshal(DataStream& dataStream) const
{
    dataStream << domainInitialXi;
    dataStream << domainFinalXi;
    dataStream << domainPointsXi;
    dataStream << interleafFactor;
    dataStream << axisType;
    dataStream << numberOfPointsOnXiAxis;
    dataStream << initialIndex;
}

void GridAxis::unmarshal(DataStream& dataStream)
{
    dataStream >> domainInitialXi;
    dataStream >> domainFinalXi;
    dataStream >> domainPointsXi;
    dataStream >> interleafFactor;
    dataStream >> axisType;
    dataStream >> numberOfPointsOnXiAxis;
    dataStream >> initialIndex;
}


bool GridAxis::operator ==(const GridAxis& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (domainInitialXi == rhs.domainInitialXi) ) ivarsEqual = false;
     if( ! (domainFinalXi == rhs.domainFinalXi) ) ivarsEqual = false;
     if( ! (domainPointsXi == rhs.domainPointsXi) ) ivarsEqual = false;
     if( ! (interleafFactor == rhs.interleafFactor) ) ivarsEqual = false;
     if( ! (axisType == rhs.axisType) ) ivarsEqual = false;
     if( ! (numberOfPointsOnXiAxis == rhs.numberOfPointsOnXiAxis) ) ivarsEqual = false;
     if( ! (initialIndex == rhs.initialIndex) ) ivarsEqual = false;

    return ivarsEqual;
 }

int GridAxis::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 8;  // domainInitialXi
   marshalSize = marshalSize + 8;  // domainFinalXi
   marshalSize = marshalSize + 2;  // domainPointsXi
   marshalSize = marshalSize + 1;  // interleafFactor
   marshalSize = marshalSize + 1;  // axisType
   marshalSize = marshalSize + 2;  // numberOfPointsOnXiAxis
   marshalSize = marshalSize + 2;  // initialIndex
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
