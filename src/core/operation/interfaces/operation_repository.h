#pragma once
#include <core/operation/data_transfer_object/data_received_remote_device.h>
#include <core/operation/data_transfer_object/data_transmitted_remote_device.h>

class IOperationRepository
{
public:
    virtual void send(DataTransmittedRemoteDevice data) = 0;
    virtual DataReceivedRemoteDevice listen() = 0;
    virtual ~IOperationRepository() = default;
};