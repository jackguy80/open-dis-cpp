#pragma once

#include "EntityID.h"
#include "EntityType.h"
#include "AggregateMarking.h"
#include "Vector3Float.h"
#include "Orientation.h"
#include "Vector3Double.h"
#include "Vector3Float.h"
#include "AggregateID.h"
#include "EntityID.h"
#include "EntityType.h"
#include "EntityType.h"
#include "VariableDatum.h"
#include <vector>
#include "EntityManagementFamilyPdu.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// Section 5.3.9.1 informationa bout aggregating entities anc communicating information about the aggregated entities.        requires manual intervention to fix the padding between entityID lists and silent aggregate sysem lists--this padding        is dependent on how many entityIDs there are, and needs to be on a 32 bit word boundary. UNFINISHED

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

#pragma warning(disable: 4251 ) // Disables warning for stl vector template DLL export in msvc

struct EXPORT_MACRO AggregateStatePdu : public EntityManagementFamilyPdu
{
  /** ID of aggregated entities */
  EntityID aggregateID;

  /** force ID */
  unsigned char forceID;

  /** state of aggregate */
  unsigned char aggregateState;

  /** entity type of the aggregated entities */
  EntityType aggregateType;

  /** formation of aggregated entities */
  unsigned int formation;

  /** marking for aggregate; first char is charset type, rest is char data */
  AggregateMarking aggregateMarking;

  /** dimensions of bounding box for the aggregated entities, origin at the center of mass */
  Vector3Float dimensions;

  /** orientation of the bounding box */
  Orientation orientation;

  /** center of mass of the aggregation */
  Vector3Double centerOfMass;

  /** velocity of aggregation */
  Vector3Float velocity;

  /** number of aggregates */
  unsigned short numberOfDisAggregates;

  /** number of entities */
  unsigned short numberOfDisEntities;

  /** number of silent aggregate types */
  unsigned short numberOfSilentAggregateTypes;

  /** number of silent entity types */
  unsigned short numberOfSilentEntityTypes;

  /** aggregates  list */
  std::vector<AggregateID> aggregateIDList;

  /** entity ID list */
  std::vector<EntityID> entityIDList;

  /** ^^^padding to put the start of the next list on a 32 bit boundary. This needs to be fixed */
  unsigned char pad2;

  /** silent entity types */
  std::vector<EntityType> silentAggregateSystemList;

  /** silent entity types */
  std::vector<EntityType> silentEntitySystemList;

  /** number of variable datum records */
  unsigned int numberOfVariableDatumRecords;

  /** variableDatums */
  std::vector<VariableDatum> variableDatumList;

    AggregateStatePdu();
    virtual ~AggregateStatePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const AggregateStatePdu& rhs) const;
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
