#pragma once

#include "Orientation.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// Section 5.2.4.2. Used when the antenna pattern type field has a value of 1. Specifies           the direction, patter, and polarization of radiation from an antenna.

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO BeamAntennaPattern
{
  /** The rotation that transformst he reference coordinate sytem     into the beam coordinate system. Either world coordinates or entity coordinates may be used as the     reference coordinate system, as specified by teh reference system field of the antenna pattern record. */
  Orientation beamDirection;

  /** Full width of the beam to the -3dB power density points in the x-y plane of the beam coordinnate system.  Elevation beamwidth is represented by a 32 bit floating point number in units of radians. */
  float azimuthBeamwidth;

  /** The full width of the beam to the –3 dB power density points in the x-z plane of the beam coordinate system. Elevation beamwidth shall be represented by a 32-bit floating point number in units of radians. */
  float elevationBeamwidth;

  /** The reference coordinate system wrt which beam direction      is specified. This field should not change over the duration of an exercise. World coordindate systemis      prefered for exercises. The entity coordinate system should be used only when highly directional antennas must be precisely modeled. */
  float referenceSystem;

  /** Padding */
  short padding1;

  /** Padding */
  char padding2;

  /** Magnigute of the z-component in beam coordinates at some arbitrary      single point in the mainbeam      and in the far field of the antenna. */
  float ez;

  /** Magnigute of the x-component in beam coordinates at some arbitrary      single point in the mainbeam      and in the far field of the antenna. */
  float ex;

  /** THe phase angle between Ez and Ex in radians. */
  float phase;

    BeamAntennaPattern();
    virtual ~BeamAntennaPattern();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const BeamAntennaPattern& rhs) const;
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
