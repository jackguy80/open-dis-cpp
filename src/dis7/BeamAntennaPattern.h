#pragma once

#include "EulerAngles.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// Used when the antenna pattern type field has a value of 1. Specifies the direction, pattern, and polarization of radiation from an antenna. Section 6.2.9.2

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO BeamAntennaPattern
{
  /** The rotation that transforms the reference coordinate sytem into the beam coordinate system. Either world coordinates or entity coordinates may be used as the reference coordinate system, as specified by the reference system field of the antenna pattern record. */
  EulerAngles beamDirection;

  /** Full width of the beam to the -3dB power density points in the x-y plane of the beam coordinnate system.  Elevation beamwidth is represented by a 32 bit floating point number in units of radians. */
  float azimuthBeamwidth;

  /** This field shall specify the full width of the beam to the –3 dB power density points in the x-z plane of the beam coordinate system. Elevation beamwidth shall be represented by a 32-bit floating point number in units of radians. */
  float elevationBeamwidth;

  /** The reference coordinate system wrt which beam direction  is specified. This field should not change over the duration of an exercise. World coordindate systemis prefered for exercises. The entity coordinate system should be used only when highly directional antennas must be precisely modeled. */
  unsigned char referenceSystem;

  /** Padding */
  unsigned char padding1;

  /** Padding */
  unsigned short padding2;

  /** This field shall specify the magnitude of the Z-component (in beam coordinates) of the Electrical field at some arbitrary single point in the main beam and in the far field of the antenna.  */
  float ez;

  /** This field shall specify the magnitude of the X-component (in beam coordinates) of the Electri- cal field at some arbitrary single point in the main beam and in the far field of the antenna. */
  float ex;

  /** This field shall specify the phase angle between EZ and EX in radians. If fully omni-direc- tional antenna is modeled using beam pattern type one, the omni-directional antenna shall be repre- sented by beam direction Euler angles psi, theta, and phi of zero, an azimuth beamwidth of 2PI, and an elevation beamwidth of PI */
  float phase;

  /** padding */
  unsigned int padding3;

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
