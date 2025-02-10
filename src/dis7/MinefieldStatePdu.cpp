#include "MinefieldStatePdu.h"

using namespace DIS;


MinefieldStatePdu::MinefieldStatePdu() : MinefieldFamilyPdu(),
   minefieldID(), 
   minefieldSequence(0), 
   forceID(0), 
   numberOfPerimeterPoints(0), 
   minefieldType(), 
   numberOfMineTypes(0), 
   minefieldLocation(), 
   minefieldOrientation(), 
   appearance(0), 
   protocolMode(0), 
   perimeterPoints(), 
   mineType()
{
    pduType = 37;
}

MinefieldStatePdu::~MinefieldStatePdu()
{
}

void MinefieldStatePdu::marshal(DataStream& dataStream) const
{
    MinefieldFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    minefieldID.marshal(dataStream);
    dataStream << minefieldSequence;
    dataStream << forceID;
    dataStream << numberOfPerimeterPoints;
    minefieldType.marshal(dataStream);
    dataStream << numberOfMineTypes;
    minefieldLocation.marshal(dataStream);
    minefieldOrientation.marshal(dataStream);
    dataStream << appearance;
    dataStream << protocolMode;
    perimeterPoints.marshal(dataStream);
    mineType.marshal(dataStream);
}

void MinefieldStatePdu::unmarshal(DataStream& dataStream)
{
    MinefieldFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    minefieldID.unmarshal(dataStream);
    dataStream >> minefieldSequence;
    dataStream >> forceID;
    dataStream >> numberOfPerimeterPoints;
    minefieldType.unmarshal(dataStream);
    dataStream >> numberOfMineTypes;
    minefieldLocation.unmarshal(dataStream);
    minefieldOrientation.unmarshal(dataStream);
    dataStream >> appearance;
    dataStream >> protocolMode;
    perimeterPoints.unmarshal(dataStream);
    mineType.unmarshal(dataStream);
}


bool MinefieldStatePdu::operator ==(const MinefieldStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = MinefieldFamilyPdu::operator==(rhs);

     if( ! (minefieldID == rhs.minefieldID) ) ivarsEqual = false;
     if( ! (minefieldSequence == rhs.minefieldSequence) ) ivarsEqual = false;
     if( ! (forceID == rhs.forceID) ) ivarsEqual = false;
     if( ! (numberOfPerimeterPoints == rhs.numberOfPerimeterPoints) ) ivarsEqual = false;
     if( ! (minefieldType == rhs.minefieldType) ) ivarsEqual = false;
     if( ! (numberOfMineTypes == rhs.numberOfMineTypes) ) ivarsEqual = false;
     if( ! (minefieldLocation == rhs.minefieldLocation) ) ivarsEqual = false;
     if( ! (minefieldOrientation == rhs.minefieldOrientation) ) ivarsEqual = false;
     if( ! (appearance == rhs.appearance) ) ivarsEqual = false;
     if( ! (protocolMode == rhs.protocolMode) ) ivarsEqual = false;
     if( ! (perimeterPoints == rhs.perimeterPoints) ) ivarsEqual = false;
     if( ! (mineType == rhs.mineType) ) ivarsEqual = false;

    return ivarsEqual;
 }

int MinefieldStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = MinefieldFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + minefieldID.getMarshalledSize();  // minefieldID
   marshalSize = marshalSize + 2;  // minefieldSequence
   marshalSize = marshalSize + 1;  // forceID
   marshalSize = marshalSize + 1;  // numberOfPerimeterPoints
   marshalSize = marshalSize + minefieldType.getMarshalledSize();  // minefieldType
   marshalSize = marshalSize + 2;  // numberOfMineTypes
   marshalSize = marshalSize + minefieldLocation.getMarshalledSize();  // minefieldLocation
   marshalSize = marshalSize + minefieldOrientation.getMarshalledSize();  // minefieldOrientation
   marshalSize = marshalSize + 2;  // appearance
   marshalSize = marshalSize + 2;  // protocolMode
   marshalSize = marshalSize + perimeterPoints.getMarshalledSize();  // perimeterPoints
   marshalSize = marshalSize + mineType.getMarshalledSize();  // mineType
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
