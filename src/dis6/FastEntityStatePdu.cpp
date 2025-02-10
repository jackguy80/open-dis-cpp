#include "FastEntityStatePdu.h"

using namespace DIS;


FastEntityStatePdu::FastEntityStatePdu() : EntityInformationFamilyPdu(),
   site(0), 
   application(0), 
   entity(0), 
   forceId(0), 
   numberOfArticulationParameters(0), 
   entityKind(0), 
   domain(0), 
   country(0), 
   category(0), 
   subcategory(0), 
   specif(0), 
   extra(0), 
   altEntityKind(0), 
   altDomain(0), 
   altCountry(0), 
   altCategory(0), 
   altSubcategory(0), 
   altSpecific(0), 
   altExtra(0), 
   xVelocity(0.0), 
   yVelocity(0.0), 
   zVelocity(0.0), 
   xLocation(0.0), 
   yLocation(0.0), 
   zLocation(0.0), 
   psi(0.0), 
   theta(0.0), 
   phi(0.0), 
   entityAppearance(0), 
   deadReckoningAlgorithm(0), 
   xAcceleration(0.0), 
   yAcceleration(0.0), 
   zAcceleration(0.0), 
   xAngularVelocity(0.0), 
   yAngularVelocity(0.0), 
   zAngularVelocity(0.0), 
   capabilities(0), 
   articulationParameters(0)
{
    pduType = 1;
     // Initialize fixed length array
     for(int lengthotherParameters= 0; lengthotherParameters < 15; lengthotherParameters++)
     {
         otherParameters[lengthotherParameters] = 0;
     }

     // Initialize fixed length array
     for(int lengthmarking= 0; lengthmarking < 12; lengthmarking++)
     {
         marking[lengthmarking] = 0;
     }

}

FastEntityStatePdu::~FastEntityStatePdu()
{
    articulationParameters.clear();
}

void FastEntityStatePdu::marshal(DataStream& dataStream) const
{
    EntityInformationFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << site;
    dataStream << application;
    dataStream << entity;
    dataStream << forceId;
    dataStream << ( char )articulationParameters.size();
    dataStream << entityKind;
    dataStream << domain;
    dataStream << country;
    dataStream << category;
    dataStream << subcategory;
    dataStream << specif;
    dataStream << extra;
    dataStream << altEntityKind;
    dataStream << altDomain;
    dataStream << altCountry;
    dataStream << altCategory;
    dataStream << altSubcategory;
    dataStream << altSpecific;
    dataStream << altExtra;
    dataStream << xVelocity;
    dataStream << yVelocity;
    dataStream << zVelocity;
    dataStream << xLocation;
    dataStream << yLocation;
    dataStream << zLocation;
    dataStream << psi;
    dataStream << theta;
    dataStream << phi;
    dataStream << entityAppearance;
    dataStream << deadReckoningAlgorithm;

     for(size_t idx = 0; idx < 15; idx++)
     {
        dataStream << otherParameters[idx];
     }

    dataStream << xAcceleration;
    dataStream << yAcceleration;
    dataStream << zAcceleration;
    dataStream << xAngularVelocity;
    dataStream << yAngularVelocity;
    dataStream << zAngularVelocity;

     for(size_t idx = 0; idx < 12; idx++)
     {
        dataStream << marking[idx];
     }

    dataStream << capabilities;

     for(size_t idx = 0; idx < articulationParameters.size(); idx++)
     {
        ArticulationParameter x = articulationParameters[idx];
        x.marshal(dataStream);
     }

}

void FastEntityStatePdu::unmarshal(DataStream& dataStream)
{
    EntityInformationFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> site;
    dataStream >> application;
    dataStream >> entity;
    dataStream >> forceId;
    dataStream >> numberOfArticulationParameters;
    dataStream >> entityKind;
    dataStream >> domain;
    dataStream >> country;
    dataStream >> category;
    dataStream >> subcategory;
    dataStream >> specif;
    dataStream >> extra;
    dataStream >> altEntityKind;
    dataStream >> altDomain;
    dataStream >> altCountry;
    dataStream >> altCategory;
    dataStream >> altSubcategory;
    dataStream >> altSpecific;
    dataStream >> altExtra;
    dataStream >> xVelocity;
    dataStream >> yVelocity;
    dataStream >> zVelocity;
    dataStream >> xLocation;
    dataStream >> yLocation;
    dataStream >> zLocation;
    dataStream >> psi;
    dataStream >> theta;
    dataStream >> phi;
    dataStream >> entityAppearance;
    dataStream >> deadReckoningAlgorithm;

     for(size_t idx = 0; idx < 15; idx++)
     {
        dataStream >> otherParameters[idx];
     }

    dataStream >> xAcceleration;
    dataStream >> yAcceleration;
    dataStream >> zAcceleration;
    dataStream >> xAngularVelocity;
    dataStream >> yAngularVelocity;
    dataStream >> zAngularVelocity;

     for(size_t idx = 0; idx < 12; idx++)
     {
        dataStream >> marking[idx];
     }

    dataStream >> capabilities;

     articulationParameters.clear();
     for(size_t idx = 0; idx < numberOfArticulationParameters; idx++)
     {
        ArticulationParameter x;
        x.unmarshal(dataStream);
        articulationParameters.push_back(x);
     }
}


bool FastEntityStatePdu::operator ==(const FastEntityStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityInformationFamilyPdu::operator==(rhs);

     if( ! (site == rhs.site) ) ivarsEqual = false;
     if( ! (application == rhs.application) ) ivarsEqual = false;
     if( ! (entity == rhs.entity) ) ivarsEqual = false;
     if( ! (forceId == rhs.forceId) ) ivarsEqual = false;
     if( ! (entityKind == rhs.entityKind) ) ivarsEqual = false;
     if( ! (domain == rhs.domain) ) ivarsEqual = false;
     if( ! (country == rhs.country) ) ivarsEqual = false;
     if( ! (category == rhs.category) ) ivarsEqual = false;
     if( ! (subcategory == rhs.subcategory) ) ivarsEqual = false;
     if( ! (specif == rhs.specif) ) ivarsEqual = false;
     if( ! (extra == rhs.extra) ) ivarsEqual = false;
     if( ! (altEntityKind == rhs.altEntityKind) ) ivarsEqual = false;
     if( ! (altDomain == rhs.altDomain) ) ivarsEqual = false;
     if( ! (altCountry == rhs.altCountry) ) ivarsEqual = false;
     if( ! (altCategory == rhs.altCategory) ) ivarsEqual = false;
     if( ! (altSubcategory == rhs.altSubcategory) ) ivarsEqual = false;
     if( ! (altSpecific == rhs.altSpecific) ) ivarsEqual = false;
     if( ! (altExtra == rhs.altExtra) ) ivarsEqual = false;
     if( ! (xVelocity == rhs.xVelocity) ) ivarsEqual = false;
     if( ! (yVelocity == rhs.yVelocity) ) ivarsEqual = false;
     if( ! (zVelocity == rhs.zVelocity) ) ivarsEqual = false;
     if( ! (xLocation == rhs.xLocation) ) ivarsEqual = false;
     if( ! (yLocation == rhs.yLocation) ) ivarsEqual = false;
     if( ! (zLocation == rhs.zLocation) ) ivarsEqual = false;
     if( ! (psi == rhs.psi) ) ivarsEqual = false;
     if( ! (theta == rhs.theta) ) ivarsEqual = false;
     if( ! (phi == rhs.phi) ) ivarsEqual = false;
     if( ! (entityAppearance == rhs.entityAppearance) ) ivarsEqual = false;
     if( ! (deadReckoningAlgorithm == rhs.deadReckoningAlgorithm) ) ivarsEqual = false;

     for(int idx = 0; idx < 15; idx++)
     {
          if(!(otherParameters[idx] == rhs.otherParameters[idx]) ) ivarsEqual = false;
     }

     if( ! (xAcceleration == rhs.xAcceleration) ) ivarsEqual = false;
     if( ! (yAcceleration == rhs.yAcceleration) ) ivarsEqual = false;
     if( ! (zAcceleration == rhs.zAcceleration) ) ivarsEqual = false;
     if( ! (xAngularVelocity == rhs.xAngularVelocity) ) ivarsEqual = false;
     if( ! (yAngularVelocity == rhs.yAngularVelocity) ) ivarsEqual = false;
     if( ! (zAngularVelocity == rhs.zAngularVelocity) ) ivarsEqual = false;

     for(int idx = 0; idx < 12; idx++)
     {
          if(!(marking[idx] == rhs.marking[idx]) ) ivarsEqual = false;
     }

     if( ! (capabilities == rhs.capabilities) ) ivarsEqual = false;

     for(size_t idx = 0; idx < articulationParameters.size(); idx++)
     {
        if( ! ( articulationParameters[idx] == rhs.articulationParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int FastEntityStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityInformationFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 2;  // site
   marshalSize = marshalSize + 2;  // application
   marshalSize = marshalSize + 2;  // entity
   marshalSize = marshalSize + 1;  // forceId
   marshalSize = marshalSize + 1;  // numberOfArticulationParameters
   marshalSize = marshalSize + 1;  // entityKind
   marshalSize = marshalSize + 1;  // domain
   marshalSize = marshalSize + 2;  // country
   marshalSize = marshalSize + 1;  // category
   marshalSize = marshalSize + 1;  // subcategory
   marshalSize = marshalSize + 1;  // specif
   marshalSize = marshalSize + 1;  // extra
   marshalSize = marshalSize + 1;  // altEntityKind
   marshalSize = marshalSize + 1;  // altDomain
   marshalSize = marshalSize + 2;  // altCountry
   marshalSize = marshalSize + 1;  // altCategory
   marshalSize = marshalSize + 1;  // altSubcategory
   marshalSize = marshalSize + 1;  // altSpecific
   marshalSize = marshalSize + 1;  // altExtra
   marshalSize = marshalSize + 4;  // xVelocity
   marshalSize = marshalSize + 4;  // yVelocity
   marshalSize = marshalSize + 4;  // zVelocity
   marshalSize = marshalSize + 8;  // xLocation
   marshalSize = marshalSize + 8;  // yLocation
   marshalSize = marshalSize + 8;  // zLocation
   marshalSize = marshalSize + 4;  // psi
   marshalSize = marshalSize + 4;  // theta
   marshalSize = marshalSize + 4;  // phi
   marshalSize = marshalSize + 4;  // entityAppearance
   marshalSize = marshalSize + 1;  // deadReckoningAlgorithm
   marshalSize = marshalSize + 15 * 1;  // otherParameters
   marshalSize = marshalSize + 4;  // xAcceleration
   marshalSize = marshalSize + 4;  // yAcceleration
   marshalSize = marshalSize + 4;  // zAcceleration
   marshalSize = marshalSize + 4;  // xAngularVelocity
   marshalSize = marshalSize + 4;  // yAngularVelocity
   marshalSize = marshalSize + 4;  // zAngularVelocity
   marshalSize = marshalSize + 12 * 1;  // marking
   marshalSize = marshalSize + 4;  // capabilities

   for(int idx=0; idx < articulationParameters.size(); idx++)
   {
        ArticulationParameter listElement = articulationParameters[idx];
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
