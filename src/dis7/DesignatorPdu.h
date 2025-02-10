#pragma once

#include "EntityID.h"
#include "EntityID.h"
#include "Vector3Float.h"
#include "Vector3Double.h"
#include "Vector3Float.h"
#include "DistributedEmissionsFamilyPdu.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// Section 5.3.7.2. Handles designating operations. COMPLETE

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO DesignatorPdu : public DistributedEmissionsFamilyPdu
{
  /** ID of the entity designating */
  EntityID designatingEntityID;

  /** This field shall specify a unique emitter database number assigned to  differentiate between otherwise similar or identical emitter beams within an emitter system. */
  unsigned short codeName;

  /** ID of the entity being designated */
  EntityID designatedEntityID;

  /** This field shall identify the designator code being used by the designating entity  */
  unsigned short designatorCode;

  /** This field shall identify the designator output power in watts */
  float designatorPower;

  /** This field shall identify the designator wavelength in units of microns */
  float designatorWavelength;

  /** designtor spot wrt the designated entity */
  Vector3Float designatorSpotWrtDesignated;

  /** designtor spot wrt the designated entity */
  Vector3Double designatorSpotLocation;

  /** Dead reckoning algorithm */
  char deadReckoningAlgorithm;

  /** padding */
  unsigned short padding1;

  /** padding */
  char padding2;

  /** linear accelleration of entity */
  Vector3Float entityLinearAcceleration;

    DesignatorPdu();
    virtual ~DesignatorPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const DesignatorPdu& rhs) const;
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
