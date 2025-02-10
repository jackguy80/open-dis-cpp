#include "GriddedDataPdu.h"

using namespace DIS;


GriddedDataPdu::GriddedDataPdu() : SyntheticEnvironmentFamilyPdu(),
   environmentalSimulationApplicationID(), 
   fieldNumber(0), 
   pduNumber(0), 
   pduTotal(0), 
   coordinateSystem(0), 
   numberOfGridAxes(0), 
   constantGrid(0), 
   environmentType(), 
   orientation(), 
   sampleTime(0), 
   totalValues(0), 
   vectorDimension(0), 
   padding1(0), 
   padding2(0), 
   gridDataList(0)
{
    pduType = 42;
}

GriddedDataPdu::~GriddedDataPdu()
{
    gridDataList.clear();
}

void GriddedDataPdu::marshal(DataStream& dataStream) const
{
    SyntheticEnvironmentFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    environmentalSimulationApplicationID.marshal(dataStream);
    dataStream << fieldNumber;
    dataStream << pduNumber;
    dataStream << pduTotal;
    dataStream << coordinateSystem;
    dataStream << ( unsigned char )gridDataList.size();
    dataStream << constantGrid;
    environmentType.marshal(dataStream);
    orientation.marshal(dataStream);
    dataStream << sampleTime;
    dataStream << totalValues;
    dataStream << vectorDimension;
    dataStream << padding1;
    dataStream << padding2;

     for(size_t idx = 0; idx < gridDataList.size(); idx++)
     {
        GridAxisRecord x = gridDataList[idx];
        x.marshal(dataStream);
     }

}

void GriddedDataPdu::unmarshal(DataStream& dataStream)
{
    SyntheticEnvironmentFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    environmentalSimulationApplicationID.unmarshal(dataStream);
    dataStream >> fieldNumber;
    dataStream >> pduNumber;
    dataStream >> pduTotal;
    dataStream >> coordinateSystem;
    dataStream >> numberOfGridAxes;
    dataStream >> constantGrid;
    environmentType.unmarshal(dataStream);
    orientation.unmarshal(dataStream);
    dataStream >> sampleTime;
    dataStream >> totalValues;
    dataStream >> vectorDimension;
    dataStream >> padding1;
    dataStream >> padding2;

     gridDataList.clear();
     for(size_t idx = 0; idx < numberOfGridAxes; idx++)
     {
        GridAxisRecord x;
        x.unmarshal(dataStream);
        gridDataList.push_back(x);
     }
}


bool GriddedDataPdu::operator ==(const GriddedDataPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SyntheticEnvironmentFamilyPdu::operator==(rhs);

     if( ! (environmentalSimulationApplicationID == rhs.environmentalSimulationApplicationID) ) ivarsEqual = false;
     if( ! (fieldNumber == rhs.fieldNumber) ) ivarsEqual = false;
     if( ! (pduNumber == rhs.pduNumber) ) ivarsEqual = false;
     if( ! (pduTotal == rhs.pduTotal) ) ivarsEqual = false;
     if( ! (coordinateSystem == rhs.coordinateSystem) ) ivarsEqual = false;
     if( ! (constantGrid == rhs.constantGrid) ) ivarsEqual = false;
     if( ! (environmentType == rhs.environmentType) ) ivarsEqual = false;
     if( ! (orientation == rhs.orientation) ) ivarsEqual = false;
     if( ! (sampleTime == rhs.sampleTime) ) ivarsEqual = false;
     if( ! (totalValues == rhs.totalValues) ) ivarsEqual = false;
     if( ! (vectorDimension == rhs.vectorDimension) ) ivarsEqual = false;
     if( ! (padding1 == rhs.padding1) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;

     for(size_t idx = 0; idx < gridDataList.size(); idx++)
     {
        if( ! ( gridDataList[idx] == rhs.gridDataList[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int GriddedDataPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SyntheticEnvironmentFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + environmentalSimulationApplicationID.getMarshalledSize();  // environmentalSimulationApplicationID
   marshalSize = marshalSize + 2;  // fieldNumber
   marshalSize = marshalSize + 2;  // pduNumber
   marshalSize = marshalSize + 2;  // pduTotal
   marshalSize = marshalSize + 2;  // coordinateSystem
   marshalSize = marshalSize + 1;  // numberOfGridAxes
   marshalSize = marshalSize + 1;  // constantGrid
   marshalSize = marshalSize + environmentType.getMarshalledSize();  // environmentType
   marshalSize = marshalSize + orientation.getMarshalledSize();  // orientation
   marshalSize = marshalSize + 8;  // sampleTime
   marshalSize = marshalSize + 4;  // totalValues
   marshalSize = marshalSize + 1;  // vectorDimension
   marshalSize = marshalSize + 2;  // padding1
   marshalSize = marshalSize + 1;  // padding2

   for(int idx=0; idx < gridDataList.size(); idx++)
   {
        GridAxisRecord listElement = gridDataList[idx];
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
