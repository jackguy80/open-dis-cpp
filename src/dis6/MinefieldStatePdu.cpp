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
   perimeterPoints(0), 
   mineType(0)
{
    pduType = 37;
}

MinefieldStatePdu::~MinefieldStatePdu()
{
    perimeterPoints.clear();
    mineType.clear();
}

void MinefieldStatePdu::marshal(DataStream& dataStream) const
{
    MinefieldFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    minefieldID.marshal(dataStream);
    dataStream << minefieldSequence;
    dataStream << forceID;
    dataStream << ( unsigned char )perimeterPoints.size();
    minefieldType.marshal(dataStream);
    dataStream << ( unsigned short )mineType.size();
    minefieldLocation.marshal(dataStream);
    minefieldOrientation.marshal(dataStream);
    dataStream << appearance;
    dataStream << protocolMode;

     for(size_t idx = 0; idx < perimeterPoints.size(); idx++)
     {
        Point x = perimeterPoints[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < mineType.size(); idx++)
     {
        EntityType x = mineType[idx];
        x.marshal(dataStream);
     }

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

     perimeterPoints.clear();
     for(size_t idx = 0; idx < numberOfPerimeterPoints; idx++)
     {
        Point x;
        x.unmarshal(dataStream);
        perimeterPoints.push_back(x);
     }

     mineType.clear();
     for(size_t idx = 0; idx < numberOfMineTypes; idx++)
     {
        EntityType x;
        x.unmarshal(dataStream);
        mineType.push_back(x);
     }
}


bool MinefieldStatePdu::operator ==(const MinefieldStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = MinefieldFamilyPdu::operator==(rhs);

     if( ! (minefieldID == rhs.minefieldID) ) ivarsEqual = false;
     if( ! (minefieldSequence == rhs.minefieldSequence) ) ivarsEqual = false;
     if( ! (forceID == rhs.forceID) ) ivarsEqual = false;
     if( ! (minefieldType == rhs.minefieldType) ) ivarsEqual = false;
     if( ! (minefieldLocation == rhs.minefieldLocation) ) ivarsEqual = false;
     if( ! (minefieldOrientation == rhs.minefieldOrientation) ) ivarsEqual = false;
     if( ! (appearance == rhs.appearance) ) ivarsEqual = false;
     if( ! (protocolMode == rhs.protocolMode) ) ivarsEqual = false;

     for(size_t idx = 0; idx < perimeterPoints.size(); idx++)
     {
        if( ! ( perimeterPoints[idx] == rhs.perimeterPoints[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < mineType.size(); idx++)
     {
        if( ! ( mineType[idx] == rhs.mineType[idx]) ) ivarsEqual = false;
     }


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

   for(int idx=0; idx < perimeterPoints.size(); idx++)
   {
        Point listElement = perimeterPoints[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < mineType.size(); idx++)
   {
        EntityType listElement = mineType[idx];
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
