#pragma once

#include "Message.h"
#include <Buffer.hpp>
#include <Structs/Mods.h>
#include <Structs/Scripts.h>
#include <Structs/FullObjects.h>

struct AssignCharacterResponse final : ServerMessage
{
    AssignCharacterResponse()
        : ServerMessage(kAssignCharacterResponse)
    {
    }

    void SerializeRaw(TiltedPhoques::Buffer::Writer& aWriter) const noexcept override;
    void DeserializeRaw(TiltedPhoques::Buffer::Reader& aReader) noexcept override;

    bool operator==(const AssignCharacterResponse& achRhs) const noexcept
    {
        return GetOpcode() == achRhs.GetOpcode() &&
            Owner == achRhs.Owner &&
            Cookie == achRhs.Cookie &&
            ServerId == achRhs.ServerId;
    }

    bool Owner{ false };
    uint32_t Cookie{};
    uint32_t ServerId{};
};
