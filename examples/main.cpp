
// specific for the example
#include "Connection.h"
#include "Utils.h"
#include "Timer.h"

// the DIS library usage
#include <dis6/EntityStatePdu.h>
#include <dis6/DetonationPdu.h>
#include <dis6/utils/DataStream.h>
#include <dis6/Vector3Double.h>
#include <dis6/BurstDescriptor.h>

#include <dis6/utils/Conversion.h>

#include <iostream>

namespace Example
{
   enum T72_Articulation_Index
   {
      INDEX_TURRET_AZIMUTH = 0,
      INDEX_TURRET_AZIMUTH_RATE = 1,
      INDEX_GUN_ELEVATION = 2,
      INDEX_GUN_2_ELEVATION = 3
   };

   namespace Articulation
   {
      enum Motion
      {
         AZIMUTH = 11,
         AZIMUTH_RATE,
         ELEVATION
      };

      enum Part
      {
         PRIMARY_TURRET = 4096,
         PRIMARY_GUN = 4416,
         SECONDARY_GUN = 6016
      };

      enum Designator
      {
         ARTICULATED = 0,
         ATTACHED = 1
      };
   }

   enum DeadReckoningModel
   {
      STATIC = 1,
      DRM_FPW,
      DRM_RPW,
      DRM_RVW,
      DRM_FVW,
      DRM_FPB,
      DRM_RPB,
      DRM_RVB,
      DRM_FVB,
   };
}


void init_entities(DIS::EntityStatePdu& friendly0,
                   DIS::EntityStatePdu& friendly1,
                   DIS::EntityStatePdu& enemy)
{
   /// basic pdu info

   {
      enemy.protocolVersion = 6;
      enemy.exerciseID = 0;
      //enemy.setPduType(1);
      //enemy.setProtocolFamily(1);

      friendly0.protocolVersion = 6;
      friendly0.exerciseID = 0;
      //friendly0.setPduType(1);
      //friendly0.setProtocolFamily(1);
      //friendly0.setArticulationParameterCount(0);

      friendly1.protocolVersion = 6;
      friendly1.exerciseID = 0;
      //friendly1.setPduType(1);
      //friendly1.setProtocolFamily(1);
      //friendly1.setArticulationParameterCount(0);
   }

   /// entity id data
   {
      // the enemies
      DIS::EntityID enemy_entity_id;
      enemy_entity_id.site = 0;
      enemy_entity_id.application = 1;
      enemy_entity_id.entity = 1;

      enemy.entityID = enemy_entity_id;

      // the friendlies
      DIS::EntityID friendly_entity_id[2];
      friendly_entity_id[0].site = 0;
      friendly_entity_id[0].application = 1;
      friendly_entity_id[0].entity = 2;

      friendly0.entityID = friendly_entity_id[0];

      friendly_entity_id[1].site = 0;
      friendly_entity_id[1].application = 1;
      friendly_entity_id[1].entity = 3;

      friendly1.entityID = friendly_entity_id[1];
   }

   // entity type data
   {
      // a T-72M
      DIS::EntityType t72m;
      t72m.category = 1;
      t72m.country = 222;
      t72m.domain = 1;
      t72m.entityKind = 1;
      t72m.extra = 0;
      t72m.subcategory = 2;

      enemy.entityType = t72m;

      // an AH-1W
      DIS::EntityType ah_1w;
      ah_1w.category = 20;
      ah_1w.country  = 25;
      ah_1w.domain = 2;
      ah_1w.entityKind = 1;
      ah_1w.extra = 0;
      ah_1w.subcategory = 2;

      friendly0.entityType = ah_1w;
      friendly1.entityType = ah_1w;
   }

   // dead reckoning
   {
      DIS::DeadReckoningParameter drp;
      drp.deadReckoningAlgorithm = Example::DRM_FVW;

      friendly0.deadReckoningParameters = drp;
      friendly1.deadReckoningParameters = drp;
      enemy.deadReckoningParameters = drp;
   }

   // articulation
   {
      DIS::ArticulationParameter turret_azimuth;
      turret_azimuth.parameterType = DIS::Convert::MakeArticulationParameterType(Example::Articulation::PRIMARY_TURRET,Example::Articulation::AZIMUTH);
      turret_azimuth.partAttachedTo = 0;            // 0 = connected directly to the vehicle
      turret_azimuth.parameterTypeDesignator = Example::Articulation::ARTICULATED;

      DIS::ArticulationParameter turret_azimuth_rate;
      turret_azimuth_rate.parameterType = DIS::Convert::MakeArticulationParameterType(Example::Articulation::PRIMARY_TURRET,Example::Articulation::AZIMUTH_RATE);
      turret_azimuth_rate.partAttachedTo = 0;       // 0 = connected directly to the vehicle
      turret_azimuth_rate.parameterTypeDesignator = Example::Articulation::ARTICULATED;

      DIS::ArticulationParameter turret_gun_elevation;
      turret_gun_elevation.parameterType = DIS::Convert::MakeArticulationParameterType(Example::Articulation::PRIMARY_GUN,Example::Articulation::ELEVATION);
      turret_gun_elevation.partAttachedTo = 1;            // 1 = connected to the turret
      turret_gun_elevation.parameterTypeDesignator = Example::Articulation::ARTICULATED;

      DIS::ArticulationParameter gun2_elevation;
      gun2_elevation.parameterType = DIS::Convert::MakeArticulationParameterType(Example::Articulation::SECONDARY_GUN,Example::Articulation::ELEVATION);
      gun2_elevation.partAttachedTo = 1;            // 1 = connected to the turret
      gun2_elevation.parameterTypeDesignator = Example::Articulation::ARTICULATED;

      std::vector<DIS::ArticulationParameter>& params = enemy.articulationParameters;
      params.clear();
      params.resize(4);  // make default number of parameters
      params[Example::INDEX_TURRET_AZIMUTH] = turret_azimuth;
      params[Example::INDEX_TURRET_AZIMUTH_RATE] = turret_azimuth_rate;
      params[Example::INDEX_GUN_ELEVATION] = turret_gun_elevation;
      params[Example::INDEX_GUN_2_ELEVATION] = gun2_elevation;
   }

   friendly0.pduLength = friendly0.getMarshalledSize();
   friendly1.pduLength = friendly1.getMarshalledSize();
   enemy.pduLength = enemy.getMarshalledSize();
}


void init_effects(DIS::DetonationPdu &detonation, const DIS::EntityID& firing, const DIS::EntityID& target)
{
   /// basic pdu info
   {
      detonation.protocolVersion = 1;  // not sure what is 1
      detonation.exerciseID = 1;
   }

   /// entity id data
   {
      DIS::EntityID detonation_entity_id;
      detonation_entity_id.site = 0;
      detonation_entity_id.application = 1;
      detonation_entity_id.entity = 4;

      detonation.munitionID = detonation_entity_id;
   }

   /// event id data
   {
      //Event ID.
      //   This field shall contain the same data as in the Event ID field of the Fire PDU that communicated
      //   the launch of the munition. If the detonation is not preceded by a corresponding fire event,
      //   then the Event Number field of the Event Identifier record shall be zero (e.g., land mines detonation).
      //   This field shall be represented by an Event Identifier record (see 5.2.18).

      // 0200 Point Detonation (PD)
      DIS::EventID detonation_event_id;
      detonation_event_id.site = 0;
      detonation_event_id.application = 1;
      detonation_event_id.eventNumber = 0;
      detonation.eventID = detonation_event_id;   
   }

   // warfare data
   {
      detonation.firingEntityID = firing;
      detonation.targetEntityID = target;
   }

   /// detonation specific data
   {  ///\todo update this position in the main loop

      // dead reckoning info
      DIS::Vector3Float detonation_velocity;
      detonation_velocity.x = 0.f;
      detonation_velocity.y = 0.f;
      detonation_velocity.z = 0.f;

      DIS::Vector3Double worldPosition;
      worldPosition.x =50.0;
      worldPosition.y =50.0;
      worldPosition.z = 50.0;

      detonation.locationInWorldCoordinates = worldPosition;

      DIS::BurstDescriptor burstDescriptor;
      //burstDescriptor.setMunition( 0 );      ///\todo set this with the 64 bit type.
      burstDescriptor.warhead = 1000;    // 1000 High Explosive (HE)
      burstDescriptor.fuse = 200;        // 0200 Point Detonation (PD)
      burstDescriptor.quantity = 1;
      burstDescriptor.rate = 1;

      detonation.detonationResult = 5; // 5 Detonation
   }

   detonation.pduLength =  detonation.getMarshalledSize();
}

void UpdateHelo(DIS::EntityStatePdu& helo, Example::HeloFlightDynamics& dynamics, double dt, unsigned int frame_stamp)
{
   dynamics( dt );
   helo.entityLocation = dynamics.position;
   helo.entityOrientation = dynamics.orientation;
   helo.entityLinearVelocity = dynamics.velocity;
   helo.timestamp = frame_stamp;
}

void UpdateTank(DIS::EntityStatePdu& tank, Example::TankDynamics& dynamics, double dt, unsigned int frame_stamp)
{
   dynamics.Update( dt );

   // articulation
   std::vector<DIS::ArticulationParameter> &params = tank.articulationParameters;

   DIS::ArticulationParameter& turret_azimuth = params[Example::INDEX_TURRET_AZIMUTH];
   turret_azimuth.parameterValue = dynamics._angle_primary_turret;
   turret_azimuth.changeIndicator = frame_stamp;  // constantly changing

   DIS::ArticulationParameter& turret_azimuth_rate = params[Example::INDEX_TURRET_AZIMUTH_RATE];
   turret_azimuth_rate.changeIndicator = 0; // no change
   turret_azimuth_rate.parameterValue = dynamics._velocity_turret;

   DIS::ArticulationParameter& gun_elevation = params[Example::INDEX_GUN_ELEVATION];
   gun_elevation.changeIndicator = 0;  // no change
   gun_elevation.parameterValue = dynamics._angle_primary_gun;

   DIS::ArticulationParameter& gun2_elevation = params[Example::INDEX_GUN_2_ELEVATION];
   gun2_elevation.changeIndicator = frame_stamp;  // no change
   gun2_elevation.parameterValue = dynamics._angle_secondary_gun;
}

int main(int argc, char* argv[])
{
   unsigned int port(62040);
   std::string ip("127.0.0.1");
   if( argc > 2 )
   {
      port = Example::ToType<unsigned int>( argv[1] );
      ip = argv[2];
   }

   /// the basic pieces for sending data
   Example::Connection multicast;
   multicast.Connect( port , ip , false);
   DIS::DataStream buffer( DIS::BIG );

   DIS::EntityStatePdu enemy;
   DIS::EntityStatePdu friendly[2];
   init_entities( friendly[0], friendly[1], enemy );

   DIS::DetonationPdu tank_round;
   init_effects( tank_round, friendly[0].entityID, enemy.entityID);

   // -- initialize the flight controllers -- //
   // the holding location of the friendly aircraft
   Example::Point3d IP;
   IP.x = 50.f;
   IP.y = 50.f; // altitude?
   IP.z = 50.f;
   Example::HeloFlightDynamics helo_flight_dynamics_0(Example::DegreesToRadians(20.f),20., IP, 0.);
   IP.x = 75.f;
   IP.y = 75.f; // altitude?
   IP.z = 75.f;
   Example::HeloFlightDynamics helo_flight_dynamics_1(Example::DegreesToRadians(40.f),40., IP, 0.);

   Example::TankDynamics tank_dynamics( Example::DegreesToRadians(10.f), Example::DegreesToRadians(20.f) );
   // Initialize the timer
   Example::Timer timer;
   timer.Update();

   // define the content to be sent of the network
   double sim_time = 0;
   double dt = 0;
   unsigned int frame_stamp=0;

   Example::TimedAlert isDetonationReady(10.0);   // alert us at 10.0 second intervals
   Example::TimedAlert isTimeToPrintStatistics(5.0);   // alert us at 10.0 second intervals

   double last_time = timer.GetSeconds();

   // the simulation loop
   ///\todo find an exit condition so we don't need to explicitly kill the app
   while( true )
   {
      timer.Update();
      double current_time = timer.GetSeconds();
      dt = current_time - last_time;
      sim_time += dt;
      last_time = current_time;

      // use the dynamics to update the entities' state.
      UpdateHelo( friendly[0], helo_flight_dynamics_0, dt, frame_stamp );
      UpdateHelo( friendly[1], helo_flight_dynamics_1, dt, frame_stamp );
      UpdateTank( enemy, tank_dynamics, dt, frame_stamp );

      // serialize for network send
      friendly[0].marshal( buffer );
      friendly[1].marshal( buffer );
      enemy.marshal( buffer );

      // Are we ready for le boom boom?
      if( isDetonationReady(dt) )
      {
         tank_round.marshal( buffer );
         // some feedback
         std::cout << "detonation!" << std::endl;
      }

      // some feedback
      if( isTimeToPrintStatistics(dt) )
      {
         std::cout << "frame:" << frame_stamp
            << "\t dt:" << dt
            //<< " | x:" << temp_position.getX()
            //<< " | y:" << temp_position.getY()
            << std::endl;
      }

      // send it over the line
      multicast.Send( &buffer[0] , buffer.size() );

      // clear for next frame
      buffer.clear();

      // increase for next frame
      frame_stamp++;

      Example::sleep( 10000 );
   }

   multicast.Disconnect();
   return 0;
}
