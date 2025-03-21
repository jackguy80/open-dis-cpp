#include "SeesPdu.h"

using namespace DIS;


SeesPdu::SeesPdu() : DistributedEmissionsFamilyPdu(),
   orginatingEntityID(), 
   infraredSignatureRepresentationIndex(0), 
   acousticSignatureRepresentationIndex(0), 
   radarCrossSectionSignatureRepresentationIndex(0), 
   numberOfPropulsionSystems(0), 
   numberOfVectoringNozzleSystems(0), 
   propulsionSystemData(0), 
   vectoringSystemData(0)
{
    pduType = 30;
}

SeesPdu::~SeesPdu()
{
    propulsionSystemData.clear();
    vectoringSystemData.clear();
}

void SeesPdu::marshal(DataStream& dataStream) const
{
    DistributedEmissionsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    orginatingEntityID.marshal(dataStream);
    dataStream << infraredSignatureRepresentationIndex;
    dataStream << acousticSignatureRepresentationIndex;
    dataStream << radarCrossSectionSignatureRepresentationIndex;
    dataStream << ( unsigned short )propulsionSystemData.size();
    dataStream << ( unsigned short )vectoringSystemData.size();

     for(size_t idx = 0; idx < propulsionSystemData.size(); idx++)
     {
        PropulsionSystemData x = propulsionSystemData[idx];
        x.marshal(dataStream);
     }


     for(size_t idx = 0; idx < vectoringSystemData.size(); idx++)
     {
        VectoringNozzleSystemData x = vectoringSystemData[idx];
        x.marshal(dataStream);
     }

}

void SeesPdu::unmarshal(DataStream& dataStream)
{
    DistributedEmissionsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    orginatingEntityID.unmarshal(dataStream);
    dataStream >> infraredSignatureRepresentationIndex;
    dataStream >> acousticSignatureRepresentationIndex;
    dataStream >> radarCrossSectionSignatureRepresentationIndex;
    dataStream >> numberOfPropulsionSystems;
    dataStream >> numberOfVectoringNozzleSystems;

     propulsionSystemData.clear();
     for(size_t idx = 0; idx < numberOfPropulsionSystems; idx++)
     {
        PropulsionSystemData x;
        x.unmarshal(dataStream);
        propulsionSystemData.push_back(x);
     }

     vectoringSystemData.clear();
     for(size_t idx = 0; idx < numberOfVectoringNozzleSystems; idx++)
     {
        VectoringNozzleSystemData x;
        x.unmarshal(dataStream);
        vectoringSystemData.push_back(x);
     }
}


bool SeesPdu::operator ==(const SeesPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = DistributedEmissionsFamilyPdu::operator==(rhs);

     if( ! (orginatingEntityID == rhs.orginatingEntityID) ) ivarsEqual = false;
     if( ! (infraredSignatureRepresentationIndex == rhs.infraredSignatureRepresentationIndex) ) ivarsEqual = false;
     if( ! (acousticSignatureRepresentationIndex == rhs.acousticSignatureRepresentationIndex) ) ivarsEqual = false;
     if( ! (radarCrossSectionSignatureRepresentationIndex == rhs.radarCrossSectionSignatureRepresentationIndex) ) ivarsEqual = false;

     for(size_t idx = 0; idx < propulsionSystemData.size(); idx++)
     {
        if( ! ( propulsionSystemData[idx] == rhs.propulsionSystemData[idx]) ) ivarsEqual = false;
     }


     for(size_t idx = 0; idx < vectoringSystemData.size(); idx++)
     {
        if( ! ( vectoringSystemData[idx] == rhs.vectoringSystemData[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int SeesPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = DistributedEmissionsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + orginatingEntityID.getMarshalledSize();  // orginatingEntityID
   marshalSize = marshalSize + 2;  // infraredSignatureRepresentationIndex
   marshalSize = marshalSize + 2;  // acousticSignatureRepresentationIndex
   marshalSize = marshalSize + 2;  // radarCrossSectionSignatureRepresentationIndex
   marshalSize = marshalSize + 2;  // numberOfPropulsionSystems
   marshalSize = marshalSize + 2;  // numberOfVectoringNozzleSystems

   for(int idx=0; idx < propulsionSystemData.size(); idx++)
   {
        PropulsionSystemData listElement = propulsionSystemData[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }


   for(int idx=0; idx < vectoringSystemData.size(); idx++)
   {
        VectoringNozzleSystemData listElement = vectoringSystemData[idx];
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
