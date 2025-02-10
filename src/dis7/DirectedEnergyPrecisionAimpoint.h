#pragma once

#include "Vector3Double.h"
#include "Vector3Float.h"
#include "Vector3Float.h"
#include "Vector3Float.h"
#include "EntityID.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// DE Precision Aimpoint Record. Section 6.2.20.3

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO DirectedEnergyPrecisionAimpoint
{
  /** Type of Record */
  unsigned int recordType;

  /** Length of Record */
  unsigned short recordLength;

  /** Padding */
  unsigned short padding;

  /** Position of Target Spot in World Coordinates. */
  Vector3Double targetSpotLocation;

  /** Position (meters) of Target Spot relative to Entity Position. */
  Vector3Float targetSpotEntityLocation;

  /** Velocity (meters/sec) of Target Spot. */
  Vector3Float targetSpotVelocity;

  /** Acceleration (meters/sec/sec) of Target Spot. */
  Vector3Float targetSpotAcceleration;

  /** Unique ID of the target entity. */
  EntityID targetEntityID;

  /** Target Component ID ENUM, same as in DamageDescriptionRecord. */
  unsigned char targetComponentID;

  /** Spot Shape ENUM. */
  unsigned char beamSpotType;

  /** Beam Spot Cross Section Semi-Major Axis. */
  float beamSpotCrossSectionSemiMajorAxis;

  /** Beam Spot Cross Section Semi-Major Axis. */
  float beamSpotCrossSectionSemiMinorAxis;

  /** Beam Spot Cross Section Orientation Angle. */
  float beamSpotCrossSectionOrientationAngle;

  /** Peak irradiance */
  float peakIrradiance;

  /** padding */
  unsigned int padding2;

    DirectedEnergyPrecisionAimpoint();
    virtual ~DirectedEnergyPrecisionAimpoint();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const DirectedEnergyPrecisionAimpoint& rhs) const;
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
