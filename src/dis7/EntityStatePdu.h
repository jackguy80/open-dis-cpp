#pragma once

#include "EntityID.h"
#include "EntityType.h"
#include "EntityType.h"
#include "Vector3Float.h"
#include "Vector3Double.h"
#include "EulerAngles.h"
#include "DeadReckoningParameters.h"
#include "EntityMarking.h"
#include "VariableParameter.h"
#include "EntityInformationFamilyPdu.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// Represents the postion and state of one entity in the world. Section 7.2.2. COMPLETE

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO EntityStatePdu : public EntityInformationFamilyPdu
{
  /** Unique ID for an entity that is tied to this state information */
  EntityID entityID;

  /** What force this entity is affiliated with, eg red, blue, neutral, etc */
  unsigned char forceId;

  /** How many variable parameters are in the variable length list. In earlier versions of DIS these were known as articulation parameters */
  unsigned char numberOfVariableParameters;

  /** Describes the type of entity in the world */
  EntityType entityType;

  EntityType alternativeEntityType;

  /** Describes the speed of the entity in the world */
  Vector3Float entityLinearVelocity;

  /** describes the location of the entity in the world */
  Vector3Double entityLocation;

  /** describes the orientation of the entity, in euler angles */
  EulerAngles entityOrientation;

  /** a series of bit flags that are used to help draw the entity, such as smoking, on fire, etc. */
  unsigned int entityAppearance;

  /** parameters used for dead reckoning */
  DeadReckoningParameters deadReckoningParameters;

  /** characters that can be used for debugging, or to draw unique strings on the side of entities in the world */
  EntityMarking marking;

  /** a series of bit flags */
  unsigned int capabilities;

  /** variable length list of variable parameters. In earlier DIS versions this was articulation parameters. */
  VariableParameter variableParameters;

    EntityStatePdu();
    virtual ~EntityStatePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const EntityStatePdu& rhs) const;
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
