#include "MinefieldDataPdu.h"

using namespace DIS;


MinefieldDataPdu::MinefieldDataPdu() : MinefieldFamilyPdu(),
   minefieldID(), 
   requestingEntityID(), 
   minefieldSequenceNumbeer(0), 
   requestID(0), 
   pduSequenceNumber(0), 
   numberOfPdus(0), 
   numberOfMinesInThisPdu(0), 
   numberOfSensorTypes(0), 
   pad2(0), 
   dataFilter(0), 
   mineType(), 
   sensorTypes(0), 
   pad3(0), 
   mineLocation(0)
{
    pduType = 39;
}

MinefieldDataPdu::~MinefieldDataPdu()
{
    sensorTypes.clear();
    mineLocation.clear();
}

void MinefieldDataPdu::marshal(DataStream& dataStream) const
{
    MinefieldFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    minefieldID.marshal(dataStream);
    requestingEntityID.marshal(dataStream);
    dataStream << minefieldSequenceNumbeer;
    dataStream << requestID;
    dataStream << pduSequenceNumber;
    dataStream << numberOfPdus;
    dataStream << ( unsigned char )mineLocation.size();
    dataStream << ( unsigned char )sensorTypes.size();
    dataStream << pad2;
    dataStream << dataFilter;
    mineType.marshal(dataStream);

     for(size_t idx = 0; idx < sensorTypes.size(); idx++)
     {
        TwoByteChunk x = sensorTypes[idx];
        x.marshal(dataStream);
     }

    dataStream << pad3;

     for(size_t idx = 0; idx < mineLocation.size(); idx++)
     {
        Vector3Float x = mineLocation[idx];
        x.marshal(dataStream);
     }

}

void MinefieldDataPdu::unmarshal(DataStream& dataStream)
{
    MinefieldFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    minefieldID.unmarshal(dataStream);
    requestingEntityID.unmarshal(dataStream);
    dataStream >> minefieldSequenceNumbeer;
    dataStream >> requestID;
    dataStream >> pduSequenceNumber;
    dataStream >> numberOfPdus;
    dataStream >> numberOfMinesInThisPdu;
    dataStream >> numberOfSensorTypes;
    dataStream >> pad2;
    dataStream >> dataFilter;
    mineType.unmarshal(dataStream);

     sensorTypes.clear();
     for(size_t idx = 0; idx < numberOfSensorTypes; idx++)
     {
        TwoByteChunk x;
        x.unmarshal(dataStream);
        sensorTypes.push_back(x);
     }
    dataStream >> pad3;

     mineLocation.clear();
     for(size_t idx = 0; idx < numberOfMinesInThisPdu; idx++)
     {
        Vector3Float x;
        x.unmarshal(dataStream);
        mineLocation.push_back(x);
     }
}


bool MinefieldDataPdu::operator ==(const MinefieldDataPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = MinefieldFamilyPdu::operator==(rhs);

     if( ! (minefieldID == rhs.minefieldID) ) ivarsEqual = false;
     if( ! (requestingEntityID == rhs.requestingEntityID) ) ivarsEqual = false;
     if( ! (minefieldSequenceNumbeer == rhs.minefieldSequenceNumbeer) ) ivarsEqual = false;
     if( ! (requestID == rhs.requestID) ) ivarsEqual = false;
     if( ! (pduSequenceNumber == rhs.pduSequenceNumber) ) ivarsEqual = false;
     if( ! (numberOfPdus == rhs.numberOfPdus) ) ivarsEqual = false;
     if( ! (pad2 == rhs.pad2) ) ivarsEqual = false;
     if( ! (dataFilter == rhs.dataFilter) ) ivarsEqual = false;
     if( ! (mineType == rhs.mineType) ) ivarsEqual = false;

     for(size_t idx = 0; idx < sensorTypes.size(); idx++)
     {
        if( ! ( sensorTypes[idx] == rhs.sensorTypes[idx]) ) ivarsEqual = false;
     }

     if( ! (pad3 == rhs.pad3) ) ivarsEqual = false;

     for(size_t idx = 0; idx < mineLocation.size(); idx++)
     {
        if( ! ( mineLocation[idx] == rhs.mineLocation[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int MinefieldDataPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = MinefieldFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + minefieldID.getMarshalledSize();  // minefieldID
   marshalSize = marshalSize + requestingEntityID.getMarshalledSize();  // requestingEntityID
   marshalSize = marshalSize + 2;  // minefieldSequenceNumbeer
   marshalSize = marshalSize + 1;  // requestID
   marshalSize = marshalSize + 1;  // pduSequenceNumber
   marshalSize = marshalSize + 1;  // numberOfPdus
   marshalSize = marshalSize + 1;  // numberOfMinesInThisPdu
   marshalSize = marshalSize + 1;  // numberOfSensorTypes
   marshalSize = marshalSize + 1;  // pad2
   marshalSize = marshalSize + 4;  // dataFilter
   marshalSize = marshalSize + mineType.getMarshalledSize();  // mineType

   for(int idx=0; idx < sensorTypes.size(); idx++)
   {
        TwoByteChunk listElement = sensorTypes[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

   marshalSize = marshalSize + 1;  // pad3

   for(int idx=0; idx < mineLocation.size(); idx++)
   {
        Vector3Float listElement = mineLocation[idx];
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
