#include "IsGroupOfPdu.h"

using namespace DIS;


IsGroupOfPdu::IsGroupOfPdu() : EntityManagementFamilyPdu(),
   groupEntityID(), 
   groupedEntityCategory(0), 
   numberOfGroupedEntities(0), 
   pad2(0), 
   latitude(0.0), 
   longitude(0.0), 
   groupedEntityDescriptions(0)
{
    pduType = 34;
}

IsGroupOfPdu::~IsGroupOfPdu()
{
    groupedEntityDescriptions.clear();
}

void IsGroupOfPdu::marshal(DataStream& dataStream) const
{
    EntityManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    groupEntityID.marshal(dataStream);
    dataStream << groupedEntityCategory;
    dataStream << ( unsigned char )groupedEntityDescriptions.size();
    dataStream << pad2;
    dataStream << latitude;
    dataStream << longitude;

     for(size_t idx = 0; idx < groupedEntityDescriptions.size(); idx++)
     {
        VariableDatum x = groupedEntityDescriptions[idx];
        x.marshal(dataStream);
     }

}

void IsGroupOfPdu::unmarshal(DataStream& dataStream)
{
    EntityManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    groupEntityID.unmarshal(dataStream);
    dataStream >> groupedEntityCategory;
    dataStream >> numberOfGroupedEntities;
    dataStream >> pad2;
    dataStream >> latitude;
    dataStream >> longitude;

     groupedEntityDescriptions.clear();
     for(size_t idx = 0; idx < numberOfGroupedEntities; idx++)
     {
        VariableDatum x;
        x.unmarshal(dataStream);
        groupedEntityDescriptions.push_back(x);
     }
}


bool IsGroupOfPdu::operator ==(const IsGroupOfPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityManagementFamilyPdu::operator==(rhs);

     if( ! (groupEntityID == rhs.groupEntityID) ) ivarsEqual = false;
     if( ! (groupedEntityCategory == rhs.groupedEntityCategory) ) ivarsEqual = false;
     if( ! (pad2 == rhs.pad2) ) ivarsEqual = false;
     if( ! (latitude == rhs.latitude) ) ivarsEqual = false;
     if( ! (longitude == rhs.longitude) ) ivarsEqual = false;

     for(size_t idx = 0; idx < groupedEntityDescriptions.size(); idx++)
     {
        if( ! ( groupedEntityDescriptions[idx] == rhs.groupedEntityDescriptions[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int IsGroupOfPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + groupEntityID.getMarshalledSize();  // groupEntityID
   marshalSize = marshalSize + 1;  // groupedEntityCategory
   marshalSize = marshalSize + 1;  // numberOfGroupedEntities
   marshalSize = marshalSize + 4;  // pad2
   marshalSize = marshalSize + 8;  // latitude
   marshalSize = marshalSize + 8;  // longitude

   for(int idx=0; idx < groupedEntityDescriptions.size(); idx++)
   {
        VariableDatum listElement = groupedEntityDescriptions[idx];
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
