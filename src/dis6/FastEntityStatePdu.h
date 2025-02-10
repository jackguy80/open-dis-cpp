#pragma once

#include "ArticulationParameter.h"
#include <vector>
#include "EntityInformationFamilyPdu.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// Section 5.3.3.1. Represents the postion and state of one entity in the world. This is identical in function to entity state pdu, but generates less garbage to collect in the Java world. COMPLETE

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

#pragma warning(disable: 4251 ) // Disables warning for stl vector template DLL export in msvc

struct EXPORT_MACRO FastEntityStatePdu : public EntityInformationFamilyPdu
{
  /** The site ID */
  unsigned short site;

  /** The application ID */
  unsigned short application;

  /** the entity ID */
  unsigned short entity;

  /** what force this entity is affiliated with, eg red, blue, neutral, etc */
  unsigned char forceId;

  /** How many articulation parameters are in the variable length list */
  char numberOfArticulationParameters;

  /** Kind of entity */
  unsigned char entityKind;

  /** Domain of entity (air, surface, subsurface, space, etc) */
  unsigned char domain;

  /** country to which the design of the entity is attributed */
  unsigned short country;

  /** category of entity */
  unsigned char category;

  /** subcategory of entity */
  unsigned char subcategory;

  /** specific info based on subcategory field. Name changed from specific because that is a reserved word in SQL. */
  unsigned char specif;

  unsigned char extra;

  /** Kind of entity */
  unsigned char altEntityKind;

  /** Domain of entity (air, surface, subsurface, space, etc) */
  unsigned char altDomain;

  /** country to which the design of the entity is attributed */
  unsigned short altCountry;

  /** category of entity */
  unsigned char altCategory;

  /** subcategory of entity */
  unsigned char altSubcategory;

  /** specific info based on subcategory field */
  unsigned char altSpecific;

  unsigned char altExtra;

  /** X velo */
  float xVelocity;

  /** y Value */
  float yVelocity;

  /** Z value */
  float zVelocity;

  /** X value */
  double xLocation;

  /** y Value */
  double yLocation;

  /** Z value */
  double zLocation;

  float psi;

  float theta;

  float phi;

  /** a series of bit flags that are used to help draw the entity, such as smoking, on fire, etc. */
  int entityAppearance;

  /** enumeration of what dead reckoning algorighm to use */
  unsigned char deadReckoningAlgorithm;

  /** other parameters to use in the dead reckoning algorithm */
  char otherParameters[15];

  /** X value */
  float xAcceleration;

  /** y Value */
  float yAcceleration;

  /** Z value */
  float zAcceleration;

  /** X value */
  float xAngularVelocity;

  /** y Value */
  float yAngularVelocity;

  /** Z value */
  float zAngularVelocity;

  /** characters that can be used for debugging, or to draw unique strings on the side of entities in the world */
  char marking[12];

  /** a series of bit flags */
  int capabilities;

  /** variable length list of articulation parameters */
  std::vector<ArticulationParameter> articulationParameters;

    FastEntityStatePdu();
    virtual ~FastEntityStatePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const FastEntityStatePdu& rhs) const;
};
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
