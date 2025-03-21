#include "ActionRequestPdu.h"

using namespace DIS;


ActionRequestPdu::ActionRequestPdu() : SimulationManagementFamilyPdu(),
   requestID(0), 
   actionID(0), 
   numberOfFixedDatumRecords(0), 
   numberOfVariableDatumRecords(0), 
   fixedDatums(0), 
   variableDatums(0)
{
    pduType = 16;
}

ActionRequestPdu::~ActionRequestPdu()
{
    fixedDatums.clear();
    variableDatums.clear();
}

void ActionRequestPdu::marshal(DataStream& dataStream) const
{
    SimulationManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << requestID;
    dataStream << actionID;
    dataStream << ( unsigned int )fixedDatums.size();
    dataStream << ( unsigned int )variableDatums.size();

     for(size_t idx = 0; idx < fixedDatums.size(); idx++)
     {
        FixedDatum x = fixedDatums[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < variableDatums.size(); idx++)
     {
        VariableDatum x = variableDatums[idx];
        x.marshal(dataStream);
     }

}

void ActionRequestPdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> requestID;
    dataStream >> actionID;
    dataStream >> numberOfFixedDatumRecords;
    dataStream >> numberOfVariableDatumRecords;

     fixedDatums.clear();
     for(size_t idx = 0; idx < numberOfFixedDatumRecords; idx++)
     {
        FixedDatum x;
        x.unmarshal(dataStream);
        fixedDatums.push_back(x);
     }

     variableDatums.clear();
     for(size_t idx = 0; idx < numberOfVariableDatumRecords; idx++)
     {
        VariableDatum x;
        x.unmarshal(dataStream);
        variableDatums.push_back(x);
     }
}


bool ActionRequestPdu::operator ==(const ActionRequestPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementFamilyPdu::operator==(rhs);

     if( ! (requestID == rhs.requestID) ) ivarsEqual = false;
     if( ! (actionID == rhs.actionID) ) ivarsEqual = false;

     for(size_t idx = 0; idx < fixedDatums.size(); idx++)
     {
        if( ! ( fixedDatums[idx] == rhs.fixedDatums[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < variableDatums.size(); idx++)
     {
        if( ! ( variableDatums[idx] == rhs.variableDatums[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ActionRequestPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 4;  // requestID
   marshalSize = marshalSize + 4;  // actionID
   marshalSize = marshalSize + 4;  // numberOfFixedDatumRecords
   marshalSize = marshalSize + 4;  // numberOfVariableDatumRecords

   for(int idx=0; idx < fixedDatums.size(); idx++)
   {
        FixedDatum listElement = fixedDatums[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < variableDatums.size(); idx++)
   {
        VariableDatum listElement = variableDatums[idx];
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
