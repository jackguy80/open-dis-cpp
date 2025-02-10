#include "MinefieldQueryPdu.h"

using namespace DIS;


MinefieldQueryPdu::MinefieldQueryPdu() : MinefieldFamilyPdu(),
   minefieldID(), 
   requestingEntityID(), 
   requestID(0), 
   numberOfPerimeterPoints(0), 
   pad2(0), 
   numberOfSensorTypes(0), 
   dataFilter(0), 
   requestedMineType(), 
   requestedPerimeterPoints(0), 
   sensorTypes(0)
{
    pduType = 38;
}

MinefieldQueryPdu::~MinefieldQueryPdu()
{
    requestedPerimeterPoints.clear();
    sensorTypes.clear();
}

void MinefieldQueryPdu::marshal(DataStream& dataStream) const
{
    MinefieldFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    minefieldID.marshal(dataStream);
    requestingEntityID.marshal(dataStream);
    dataStream << requestID;
    dataStream << ( unsigned char )requestedPerimeterPoints.size();
    dataStream << pad2;
    dataStream << ( unsigned char )sensorTypes.size();
    dataStream << dataFilter;
    requestedMineType.marshal(dataStream);

     for(size_t idx = 0; idx < requestedPerimeterPoints.size(); idx++)
     {
        Point x = requestedPerimeterPoints[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < sensorTypes.size(); idx++)
     {
        TwoByteChunk x = sensorTypes[idx];
        x.marshal(dataStream);
     }

}

void MinefieldQueryPdu::unmarshal(DataStream& dataStream)
{
    MinefieldFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    minefieldID.unmarshal(dataStream);
    requestingEntityID.unmarshal(dataStream);
    dataStream >> requestID;
    dataStream >> numberOfPerimeterPoints;
    dataStream >> pad2;
    dataStream >> numberOfSensorTypes;
    dataStream >> dataFilter;
    requestedMineType.unmarshal(dataStream);

     requestedPerimeterPoints.clear();
     for(size_t idx = 0; idx < numberOfPerimeterPoints; idx++)
     {
        Point x;
        x.unmarshal(dataStream);
        requestedPerimeterPoints.push_back(x);
     }

     sensorTypes.clear();
     for(size_t idx = 0; idx < numberOfSensorTypes; idx++)
     {
        TwoByteChunk x;
        x.unmarshal(dataStream);
        sensorTypes.push_back(x);
     }
}


bool MinefieldQueryPdu::operator ==(const MinefieldQueryPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = MinefieldFamilyPdu::operator==(rhs);

     if( ! (minefieldID == rhs.minefieldID) ) ivarsEqual = false;
     if( ! (requestingEntityID == rhs.requestingEntityID) ) ivarsEqual = false;
     if( ! (requestID == rhs.requestID) ) ivarsEqual = false;
     if( ! (pad2 == rhs.pad2) ) ivarsEqual = false;
     if( ! (dataFilter == rhs.dataFilter) ) ivarsEqual = false;
     if( ! (requestedMineType == rhs.requestedMineType) ) ivarsEqual = false;

     for(size_t idx = 0; idx < requestedPerimeterPoints.size(); idx++)
     {
        if( ! ( requestedPerimeterPoints[idx] == rhs.requestedPerimeterPoints[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < sensorTypes.size(); idx++)
     {
        if( ! ( sensorTypes[idx] == rhs.sensorTypes[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int MinefieldQueryPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = MinefieldFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + minefieldID.getMarshalledSize();  // minefieldID
   marshalSize = marshalSize + requestingEntityID.getMarshalledSize();  // requestingEntityID
   marshalSize = marshalSize + 1;  // requestID
   marshalSize = marshalSize + 1;  // numberOfPerimeterPoints
   marshalSize = marshalSize + 1;  // pad2
   marshalSize = marshalSize + 1;  // numberOfSensorTypes
   marshalSize = marshalSize + 4;  // dataFilter
   marshalSize = marshalSize + requestedMineType.getMarshalledSize();  // requestedMineType

   for(int idx=0; idx < requestedPerimeterPoints.size(); idx++)
   {
        Point listElement = requestedPerimeterPoints[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < sensorTypes.size(); idx++)
   {
        TwoByteChunk listElement = sensorTypes[idx];
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
