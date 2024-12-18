#pragma once

#include "Core/Input.h"
namespace Katalyst {
    class KatalystGLFWInput : public Input
    {
    protected:
        bool IsKeyPressedImpl(int keycode) override;

        bool IsMouseButtonPressedImpl(int button) override;
        std::pair<float, float> GetMousePositionImpl() override;
        float GetMouseXImpl() override;
        float GetMouseYImpl() override;
    };
}
