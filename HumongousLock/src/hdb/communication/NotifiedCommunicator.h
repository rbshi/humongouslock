/*
 * NotifiedCommunicator.h
 *
 *  Created on: Apr 28, 2018
 *      Author: claudeb
 */

#ifndef SRC_HDB_COMMUNICATION_NOTIFIEDCOMMUNICATOR_H_
#define SRC_HDB_COMMUNICATION_NOTIFIEDCOMMUNICATOR_H_

#ifdef USE_FOMPI

#include <mpi.h>
#include <fompi.h>

#include <hdb/configuration/SystemConfig.h>
#include <hdb/messages/Message.h>

namespace hdb {
namespace communication {

class NotifiedCommunicator {

public:

    NotifiedCommunicator(hdb::configuration::SystemConfig *config);
    virtual ~NotifiedCommunicator();

protected:

    uint32_t windowSizeInSlots;
    void *buffer;
    foMPI_Win window;

protected:

    foMPI_Request request;
    MPI_Status status;

public:
    const uint32_t comdelay;
    bool sendMessage(hdb::messages::Message *message, uint32_t targetGlobalRank);
    hdb::messages::Message * getMessage();
    hdb::messages::Message * getMessageBlocking();

protected:

    uint32_t globalRank;
    uint32_t internalRank;
    uint32_t localMachineId;
    uint32_t numberOfProcessesPerMachine;
    bool isLockServerEndPoint;


};

} /* namespace communication */
} /* namespace hdb */

#endif

#endif /* SRC_HDB_COMMUNICATION_NOTIFIEDCOMMUNICATOR_H_ */
