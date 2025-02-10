#include "ArealObjectStatePdu.h"

using namespace DIS;


ArealObjectStatePdu::ArealObjectStatePdu() : SyntheticEnvironmentFamilyPdu(),
   objectID(), 
   referencedObjectID(), 
   updateNumber(0), 
   forceID(0), 
   modifications(0), 
   objectType(), 
   objectAppearance(), 
   numberOfPoints(0), 
   requesterID(), 
   receivingID(), 
   objectLocation(0)
{
    pduType = 45;
}

ArealObjectStatePdu::~ArealObjectStatePdu()
{
    objectLocation.clear();
}

void ArealObjectStatePdu::marshal(DataStream& dataStream) const
{
    SyntheticEnvironmentFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    objectID.marshal(dataStream);
    referencedObjectID.marshal(dataStream);
    dataStream << updateNumber;
    dataStream << forceID;
    dataStream << modifications;
    objectType.marshal(dataStream);
    objectAppearance.marshal(dataStream);
    dataStream << ( unsigned short )objectLocation.size();
    requesterID.marshal(dataStream);
    receivingID.marshal(dataStream);

     for(size_t idx = 0; idx < objectLocation.size(); idx++)
     {
        Vector3Double x = objectLocation[idx];
        x.marshal(dataStream);
     }

}

void ArealObjectStatePdu::unmarshal(DataStream& dataStream)
{
    SyntheticEnvironmentFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    objectID.unmarshal(dataStream);
    referencedObjectID.unmarshal(dataStream);
    dataStream >> updateNumber;
    dataStream >> forceID;
    dataStream >> modifications;
    objectType.unmarshal(dataStream);
    objectAppearance.unmarshal(dataStream);
    dataStream >> numberOfPoints;
    requesterID.unmarshal(dataStream);
    receivingID.unmarshal(dataStream);

     objectLocation.clear();
     for(size_t idx = 0; idx < numberOfPoints; idx++)
     {
        Vector3Double x;
        x.unmarshal(dataStream);
        objectLocation.push_back(x);
     }
}


bool ArealObjectStatePdu::operator ==(const ArealObjectStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SyntheticEnvironmentFamilyPdu::operator==(rhs);

     if( ! (objectID == rhs.objectID) ) ivarsEqual = false;
     if( ! (referencedObjectID == rhs.referencedObjectID) ) ivarsEqual = false;
     if( ! (updateNumber == rhs.updateNumber) ) ivarsEqual = false;
     if( ! (forceID == rhs.forceID) ) ivarsEqual = false;
     if( ! (modifications == rhs.modifications) ) ivarsEqual = false;
     if( ! (objectType == rhs.objectType) ) ivarsEqual = false;
     if( ! (objectAppearance == rhs.objectAppearance) ) ivarsEqual = false;
     if( ! (requesterID == rhs.requesterID) ) ivarsEqual = false;
     if( ! (receivingID == rhs.receivingID) ) ivarsEqual = false;

     for(size_t idx = 0; idx < objectLocation.size(); idx++)
     {
        if( ! ( objectLocation[idx] == rhs.objectLocation[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ArealObjectStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SyntheticEnvironmentFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + objectID.getMarshalledSize();  // objectID
   marshalSize = marshalSize + referencedObjectID.getMarshalledSize();  // referencedObjectID
   marshalSize = marshalSize + 2;  // updateNumber
   marshalSize = marshalSize + 1;  // forceID
   marshalSize = marshalSize + 1;  // modifications
   marshalSize = marshalSize + objectType.getMarshalledSize();  // objectType
   marshalSize = marshalSize + objectAppearance.getMarshalledSize();  // objectAppearance
   marshalSize = marshalSize + 2;  // numberOfPoints
   marshalSize = marshalSize + requesterID.getMarshalledSize();  // requesterID
   marshalSize = marshalSize + receivingID.getMarshalledSize();  // receivingID

   for(int idx=0; idx < objectLocation.size(); idx++)
   {
        Vector3Double listElement = objectLocation[idx];
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
