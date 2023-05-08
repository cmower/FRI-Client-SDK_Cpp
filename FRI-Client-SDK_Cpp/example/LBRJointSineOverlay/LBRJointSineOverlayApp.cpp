/**

The following license terms and conditions apply, unless a redistribution
agreement or other license is obtained by KUKA Roboter GmbH, Augsburg, Germany.

SCOPE

The software �KUKA Sunrise.Connectivity FRI Client SDK� is targeted to work in
conjunction with the �KUKA Sunrise.Connectivity FastRobotInterface� toolkit.
In the following, the term �software� refers to all material directly
belonging to the provided SDK �Software development kit�, particularly source
code, libraries, binaries, manuals and technical documentation.

COPYRIGHT

All Rights Reserved
Copyright (C)  2014-2021 
KUKA Roboter GmbH
Augsburg, Germany

LICENSE 

Redistribution and use of the software in source and binary forms, with or
without modification, are permitted provided that the following conditions are
met:
a) The software is used in conjunction with KUKA products only. 
b) Redistributions of source code must retain the above copyright notice, this
list of conditions and the disclaimer.
c) Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the disclaimer in the documentation and/or other
materials provided with the distribution. Altered source code of the
redistribution must be made available upon request with the distribution.
d) Modification and contributions to the original software provided by KUKA
must be clearly marked and the authorship must be stated.
e) Neither the name of KUKA nor the trademarks owned by KUKA may be used to
endorse or promote products derived from this software without specific prior
written permission.

DISCLAIMER OF WARRANTY

The Software is provided "AS IS" and "WITH ALL FAULTS," without warranty of
any kind, including without limitation the warranties of merchantability,
fitness for a particular purpose and non-infringement. 
KUKA makes no warranty that the Software is free of defects or is suitable for
any particular purpose. In no event shall KUKA be responsible for loss or
damages arising from the installation or use of the Software, including but
not limited to any indirect, punitive, special, incidental or consequential
damages of any character including, without limitation, damages for loss of
goodwill, work stoppage, computer failure or malfunction, or any and all other
commercial damages or losses. 
The entire risk to the quality and performance of the Software is not borne by
KUKA. Should the Software prove defective, KUKA is not liable for the entire
cost of any service and repair.



\file
\version {1.15}
*/
#include <cstdlib>
#include <cstdio>
#include <cstring> // strstr
#include "LBRJointSineOverlayClient.h"
#include "friUdpConnection.h"
#include "friClientApplication.h"

using namespace KUKA::FRI;


#define DEFAULT_PORTID 30200
#define DEFAULT_JOINTMASK 0x8
#define DEFAULT_FREQUENCY 0.25
#define DEFAULT_AMPLITUDE 0.04
#define DEFAULT_FILTER_COEFFICIENT 0.99



int main (int argc, char** argv)
{
   // parse command line arguments
   if (argc > 1)
   {
	   if ( strstr (argv[1],"help") != NULL)
	   {
	      printf(
	            "\nKUKA LBR joint sine overlay test application\n\n"
	            "\tCommand line arguments:\n"
	            "\t1) remote hostname (optional)\n"
	            "\t2) port ID (optional)\n"
	            "\t3) bitmask encoding of joints to be overlayed (optional)\n"
	            "\t4) sine frequency in Hertz (optional)\n"
	            "\t5) sine amplitude in radians (optional)\n"
	            "\t6) filter coefficient from 0 (off) to 1 (optional)\n"            
	      );
	      return 1;
	   }
   }
   char* hostname = (argc >= 2) ? argv[1] : NULL;
   int port = (argc >= 3) ? atoi(argv[2]) : DEFAULT_PORTID;
   unsigned int jointMask = (argc >= 4) ? (unsigned int)atoi(argv[3]) : DEFAULT_JOINTMASK;
   double frequency = (argc >= 5) ? atof(argv[4]) : DEFAULT_FREQUENCY;
   double amplitude = (argc >= 6) ? atof(argv[5]) : DEFAULT_AMPLITUDE;
   double filterCoeff = (argc >= 7) ? atof(argv[6]) : DEFAULT_FILTER_COEFFICIENT;

   /***************************************************************************/
   /*                                                                         */
   /*   Place user Client Code here                                           */
   /*                                                                         */
   /**************************************************************************/
   
   // create new sine overlay client
   LBRJointSineOverlayClient trafoClient(jointMask, frequency, amplitude, filterCoeff);

   /***************************************************************************/
   /*                                                                         */
   /*   Standard application structure                                        */
   /*   Configuration                                                         */
   /*                                                                         */
   /***************************************************************************/

   // create new udp connection
   UdpConnection connection;


   // pass connection and client to a new FRI client application
   ClientApplication app(connection, trafoClient);
   
   // connect client application to KUKA Sunrise controller
   app.connect(port, hostname);

   /***************************************************************************/
   /*                                                                         */
   /*   Standard application structure                                        */
   /*   Execution mainloop                                                    */
   /*                                                                         */
   /***************************************************************************/

   // repeatedly call the step routine to receive and process FRI packets
   bool success = true;
   while (success)
   {
      success = app.step();
      
      // check if we are in IDLE because the FRI session was closed
      if (trafoClient.robotState().getSessionState() == IDLE)
      {
         // In this demo application we simply quit.
         // Waiting for a new FRI session would be another possibility.
         break;
      }
   }

   /***************************************************************************/
   /*                                                                         */
   /*   Standard application structure                                        */
   /*   Dispose                                                               */
   /*                                                                         */
   /***************************************************************************/

   // disconnect from controller
   app.disconnect();
   
   return 1;
}
