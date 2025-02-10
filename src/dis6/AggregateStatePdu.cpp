#include "AggregateStatePdu.h"

using namespace DIS;


AggregateStatePdu::AggregateStatePdu() : EntityManagementFamilyPdu(),
   aggregateID(), 
   forceID(0), 
   aggregateState(0), 
   aggregateType(), 
   formation(0), 
   aggregateMarking(), 
   dimensions(), 
   orientation(), 
   centerOfMass(), 
   velocity(), 
   numberOfDisAggregates(0), 
   numberOfDisEntities(0), 
   numberOfSilentAggregateTypes(0), 
   numberOfSilentEntityTypes(0), 
   aggregateIDList(0), 
   entityIDList(0), 
   pad2(0), 
   silentAggregateSystemList(0), 
   silentEntitySystemList(0), 
   numberOfVariableDatumRecords(0), 
   variableDatumList(0)
{
    pduType = 33;
}

AggregateStatePdu::~AggregateStatePdu()
{
    aggregateIDList.clear();
    entityIDList.clear();
    silentAggregateSystemList.clear();
    silentEntitySystemList.clear();
    variableDatumList.clear();
}

void AggregateStatePdu::marshal(DataStream& dataStream) const
{
    EntityManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    aggregateID.marshal(dataStream);
    dataStream << forceID;
    dataStream << aggregateState;
    aggregateType.marshal(dataStream);
    dataStream << formation;
    aggregateMarking.marshal(dataStream);
    dimensions.marshal(dataStream);
    orientation.marshal(dataStream);
    centerOfMass.marshal(dataStream);
    velocity.marshal(dataStream);
    dataStream << ( unsigned short )aggregateIDList.size();
    dataStream << ( unsigned short )entityIDList.size();
    dataStream << ( unsigned short )silentAggregateSystemList.size();
    dataStream << ( unsigned short )silentEntitySystemList.size();

     for(size_t idx = 0; idx < aggregateIDList.size(); idx++)
     {
        AggregateID x = aggregateIDList[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < entityIDList.size(); idx++)
     {
        EntityID x = entityIDList[idx];
        x.marshal(dataStream);
     }

    dataStream << pad2;

     for(size_t idx = 0; idx < silentAggregateSystemList.size(); idx++)
     {
        EntityType x = silentAggregateSystemList[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < silentEntitySystemList.size(); idx++)
     {
        EntityType x = silentEntitySystemList[idx];
        x.marshal(dataStream);
     }

    dataStream << ( unsigned int )variableDatumList.size();

     for(size_t idx = 0; idx < variableDatumList.size(); idx++)
     {
        VariableDatum x = variableDatumList[idx];
        x.marshal(dataStream);
     }

}

void AggregateStatePdu::unmarshal(DataStream& dataStream)
{
    EntityManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    aggregateID.unmarshal(dataStream);
    dataStream >> forceID;
    dataStream >> aggregateState;
    aggregateType.unmarshal(dataStream);
    dataStream >> formation;
    aggregateMarking.unmarshal(dataStream);
    dimensions.unmarshal(dataStream);
    orientation.unmarshal(dataStream);
    centerOfMass.unmarshal(dataStream);
    velocity.unmarshal(dataStream);
    dataStream >> numberOfDisAggregates;
    dataStream >> numberOfDisEntities;
    dataStream >> numberOfSilentAggregateTypes;
    dataStream >> numberOfSilentEntityTypes;

     aggregateIDList.clear();
     for(size_t idx = 0; idx < numberOfDisAggregates; idx++)
     {
        AggregateID x;
        x.unmarshal(dataStream);
        aggregateIDList.push_back(x);
     }

     entityIDList.clear();
     for(size_t idx = 0; idx < numberOfDisEntities; idx++)
     {
        EntityID x;
        x.unmarshal(dataStream);
        entityIDList.push_back(x);
     }
    dataStream >> pad2;

     silentAggregateSystemList.clear();
     for(size_t idx = 0; idx < numberOfSilentAggregateTypes; idx++)
     {
        EntityType x;
        x.unmarshal(dataStream);
        silentAggregateSystemList.push_back(x);
     }

     silentEntitySystemList.clear();
     for(size_t idx = 0; idx < numberOfSilentEntityTypes; idx++)
     {
        EntityType x;
        x.unmarshal(dataStream);
        silentEntitySystemList.push_back(x);
     }
    dataStream >> numberOfVariableDatumRecords;

     variableDatumList.clear();
     for(size_t idx = 0; idx < numberOfVariableDatumRecords; idx++)
     {
        VariableDatum x;
        x.unmarshal(dataStream);
        variableDatumList.push_back(x);
     }
}


bool AggregateStatePdu::operator ==(const AggregateStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityManagementFamilyPdu::operator==(rhs);

     if( ! (aggregateID == rhs.aggregateID) ) ivarsEqual = false;
     if( ! (forceID == rhs.forceID) ) ivarsEqual = false;
     if( ! (aggregateState == rhs.aggregateState) ) ivarsEqual = false;
     if( ! (aggregateType == rhs.aggregateType) ) ivarsEqual = false;
     if( ! (formation == rhs.formation) ) ivarsEqual = false;
     if( ! (aggregateMarking == rhs.aggregateMarking) ) ivarsEqual = false;
     if( ! (dimensions == rhs.dimensions) ) ivarsEqual = false;
     if( ! (orientation == rhs.orientation) ) ivarsEqual = false;
     if( ! (centerOfMass == rhs.centerOfMass) ) ivarsEqual = false;
     if( ! (velocity == rhs.velocity) ) ivarsEqual = false;

     for(size_t idx = 0; idx < aggregateIDList.size(); idx++)
     {
        if( ! ( aggregateIDList[idx] == rhs.aggregateIDList[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < entityIDList.size(); idx++)
     {
        if( ! ( entityIDList[idx] == rhs.entityIDList[idx]) ) ivarsEqual = false;
     }

     if( ! (pad2 == rhs.pad2) ) ivarsEqual = false;

     for(size_t idx = 0; idx < silentAggregateSystemList.size(); idx++)
     {
        if( ! ( silentAggregateSystemList[idx] == rhs.silentAggregateSystemList[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < silentEntitySystemList.size(); idx++)
     {
        if( ! ( silentEntitySystemList[idx] == rhs.silentEntitySystemList[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < variableDatumList.size(); idx++)
     {
        if( ! ( variableDatumList[idx] == rhs.variableDatumList[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int AggregateStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + aggregateID.getMarshalledSize();  // aggregateID
   marshalSize = marshalSize + 1;  // forceID
   marshalSize = marshalSize + 1;  // aggregateState
   marshalSize = marshalSize + aggregateType.getMarshalledSize();  // aggregateType
   marshalSize = marshalSize + 4;  // formation
   marshalSize = marshalSize + aggregateMarking.getMarshalledSize();  // aggregateMarking
   marshalSize = marshalSize + dimensions.getMarshalledSize();  // dimensions
   marshalSize = marshalSize + orientation.getMarshalledSize();  // orientation
   marshalSize = marshalSize + centerOfMass.getMarshalledSize();  // centerOfMass
   marshalSize = marshalSize + velocity.getMarshalledSize();  // velocity
   marshalSize = marshalSize + 2;  // numberOfDisAggregates
   marshalSize = marshalSize + 2;  // numberOfDisEntities
   marshalSize = marshalSize + 2;  // numberOfSilentAggregateTypes
   marshalSize = marshalSize + 2;  // numberOfSilentEntityTypes

   for(int idx=0; idx < aggregateIDList.size(); idx++)
   {
        AggregateID listElement = aggregateIDList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < entityIDList.size(); idx++)
   {
        EntityID listElement = entityIDList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

   marshalSize = marshalSize + 1;  // pad2

   for(int idx=0; idx < silentAggregateSystemList.size(); idx++)
   {
        EntityType listElement = silentAggregateSystemList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < silentEntitySystemList.size(); idx++)
   {
        EntityType listElement = silentEntitySystemList[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

   marshalSize = marshalSize + 4;  // numberOfVariableDatumRecords

   for(int idx=0; idx < variableDatumList.size(); idx++)
   {
        VariableDatum listElement = variableDatumList[idx];
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
