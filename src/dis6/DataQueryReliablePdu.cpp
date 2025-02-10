#include "DataQueryReliablePdu.h"

using namespace DIS;


DataQueryReliablePdu::DataQueryReliablePdu() : SimulationManagementWithReliabilityFamilyPdu(),
   requiredReliabilityService(0), 
   pad1(0), 
   pad2(0), 
   requestID(0), 
   timeInterval(0), 
   numberOfFixedDatumRecords(0), 
   numberOfVariableDatumRecords(0), 
   fixedDatumRecords(0), 
   variableDatumRecords(0)
{
    pduType = 58;
}

DataQueryReliablePdu::~DataQueryReliablePdu()
{
    fixedDatumRecords.clear();
    variableDatumRecords.clear();
}

void DataQueryReliablePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementWithReliabilityFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << requiredReliabilityService;
    dataStream << pad1;
    dataStream << pad2;
    dataStream << requestID;
    dataStream << timeInterval;
    dataStream << ( unsigned int )fixedDatumRecords.size();
    dataStream << ( unsigned int )variableDatumRecords.size();

     for(size_t idx = 0; idx < fixedDatumRecords.size(); idx++)
     {
        FixedDatum x = fixedDatumRecords[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < variableDatumRecords.size(); idx++)
     {
        VariableDatum x = variableDatumRecords[idx];
        x.marshal(dataStream);
     }

}

void DataQueryReliablePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementWithReliabilityFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> requiredReliabilityService;
    dataStream >> pad1;
    dataStream >> pad2;
    dataStream >> requestID;
    dataStream >> timeInterval;
    dataStream >> numberOfFixedDatumRecords;
    dataStream >> numberOfVariableDatumRecords;

     fixedDatumRecords.clear();
     for(size_t idx = 0; idx < numberOfFixedDatumRecords; idx++)
     {
        FixedDatum x;
        x.unmarshal(dataStream);
        fixedDatumRecords.push_back(x);
     }

     variableDatumRecords.clear();
     for(size_t idx = 0; idx < numberOfVariableDatumRecords; idx++)
     {
        VariableDatum x;
        x.unmarshal(dataStream);
        variableDatumRecords.push_back(x);
     }
}


bool DataQueryReliablePdu::operator ==(const DataQueryReliablePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementWithReliabilityFamilyPdu::operator==(rhs);

     if( ! (requiredReliabilityService == rhs.requiredReliabilityService) ) ivarsEqual = false;
     if( ! (pad1 == rhs.pad1) ) ivarsEqual = false;
     if( ! (pad2 == rhs.pad2) ) ivarsEqual = false;
     if( ! (requestID == rhs.requestID) ) ivarsEqual = false;
     if( ! (timeInterval == rhs.timeInterval) ) ivarsEqual = false;

     for(size_t idx = 0; idx < fixedDatumRecords.size(); idx++)
     {
        if( ! ( fixedDatumRecords[idx] == rhs.fixedDatumRecords[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < variableDatumRecords.size(); idx++)
     {
        if( ! ( variableDatumRecords[idx] == rhs.variableDatumRecords[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int DataQueryReliablePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 1;  // requiredReliabilityService
   marshalSize = marshalSize + 2;  // pad1
   marshalSize = marshalSize + 1;  // pad2
   marshalSize = marshalSize + 4;  // requestID
   marshalSize = marshalSize + 4;  // timeInterval
   marshalSize = marshalSize + 4;  // numberOfFixedDatumRecords
   marshalSize = marshalSize + 4;  // numberOfVariableDatumRecords

   for(int idx=0; idx < fixedDatumRecords.size(); idx++)
   {
        FixedDatum listElement = fixedDatumRecords[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < variableDatumRecords.size(); idx++)
   {
        VariableDatum listElement = variableDatumRecords[idx];
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
