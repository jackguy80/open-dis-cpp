#pragma once

#include "MinefieldIdentifier.h"
#include "EntityType.h"
#include "Vector3Double.h"
#include "EulerAngles.h"
#include "Vector2Float.h"
#include "EntityType.h"
#include "MinefieldFamilyPdu.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// information about the complete minefield. The minefield presence, perimiter, etc. Section 7.9.2 COMPLETE

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO MinefieldStatePdu : public MinefieldFamilyPdu
{
  /** Minefield ID */
  MinefieldIdentifier minefieldID;

  /** Minefield sequence */
  unsigned short minefieldSequence;

  /** force ID */
  unsigned char forceID;

  /** Number of permieter points */
  unsigned char numberOfPerimeterPoints;

  /** type of minefield */
  EntityType minefieldType;

  /** how many mine types */
  unsigned short numberOfMineTypes;

  /** location of center of minefield in world coords */
  Vector3Double minefieldLocation;

  /** orientation of minefield */
  EulerAngles minefieldOrientation;

  /** appearance bitflags */
  unsigned short appearance;

  /** protocolMode. First two bits are the protocol mode, 14 bits reserved. */
  unsigned short protocolMode;

  /** perimeter points for the minefield */
  Vector2Float perimeterPoints;

  /** Type of mines */
  EntityType mineType;

    MinefieldStatePdu();
    virtual ~MinefieldStatePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const MinefieldStatePdu& rhs) const;
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
