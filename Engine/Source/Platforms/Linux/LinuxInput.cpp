#include <KatalystPCH.h>
#include <GLFW/glfw3.h>

#include "Core/Application.h"
#include "Platforms/Linux/LinuxInput.h"
namespace Katalyst
{
    Input* Input::s_Instance = new LinuxInput();

    bool LinuxInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);

        return state == GLFW_PRESS || state == GLFW_RELEASE;
    }

    bool LinuxInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);

        return state == GLFW_PRESS;
    }

    std::pair<float, float> LinuxInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;

        glfwGetCursorPos(window, &xPos, &yPos);
        return { (float)xPos, (float)yPos };
    }

    float LinuxInput::GetMouseXImpl()
    {
        auto[x, y] = GetMousePositionImpl();
        return x;
    }

    float LinuxInput::GetMouseYImpl()
    {
        auto[x, y] = GetMousePositionImpl();
        return y;
    }
}