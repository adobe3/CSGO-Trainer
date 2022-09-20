#include "Menu.h"
#include "../../Utilities/Memory/Memory.h"
#include "../Rendering/Rendering.h"
#include "../../Trainer/Triggerbot/Triggerbot.h"
#include "../../Trainer/ESP/ESP.h"
#include "../../Trainer/Aimbot/Aimbot.h"

void Graphics::Menu::Draw()
{
	if (Graphics::Menu::status)
	{
        ImGui::SetNextWindowSize(ImVec2(400, 275));
		ImGui::Begin(skCrypt("CSGO-Trainer"), NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

        if (ImGui::BeginTabBar(skCrypt("##Menu Bar")))
        {
            if (ImGui::BeginTabItem(skCrypt("Aimbot")))
            {
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(skCrypt("Visuals")))
            {
                ImGui::Checkbox(skCrypt("Box ESP"), &Trainer::ESP::boxStatus);
                ImGui::SameLine();
                ImGui::Combo(skCrypt("##Box Type"), &Trainer::ESP::boxType, "Full\0Cornered\0\0");
                ImGui::ColorEdit3(skCrypt("##Box Color"), Trainer::ESP::boxColor);

                ImGui::Checkbox(skCrypt("Snapline ESP"), &Trainer::ESP::snaplineStatus);
                ImGui::SameLine();
                ImGui::Combo(skCrypt("##Snapline Type"), &Trainer::ESP::snaplineType, "Bottom\0Middle\0Top\0\0");
                ImGui::ColorEdit3(skCrypt("##Snapline Color"), Trainer::ESP::snaplineColor);

                ImGui::Checkbox(skCrypt("Healthbar ESP"), &Trainer::ESP::healthbarStatus);

                ImGui::Checkbox(skCrypt("Distance ESP"), &Trainer::ESP::distanceStatus);
                ImGui::ColorEdit3(skCrypt("##Distance Color"), Trainer::ESP::distanceColor);

                ImGui::Checkbox(skCrypt("Head ESP"), &Trainer::ESP::headStatus);
                ImGui::ColorEdit3(skCrypt("##Head Color"), Trainer::ESP::headColor);
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(skCrypt("Miscellaneous")))
            {
                ImGui::Checkbox(skCrypt("Triggerbot"), &Trainer::Triggerbot::status);
                ImGui::SliderFloat(skCrypt("Delay"), &Trainer::Triggerbot::delay, 0.f, 300.f, "%.3fms");
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(skCrypt("Configuration")))
            {
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(skCrypt("Debug")))
            {
                ImGui::Text(skCrypt("Trainer FPS: %0.f"), ImGui::GetIO().Framerate);
                ImGui::Text(skCrypt("Trainer Uptime: %0.ds"), (clock() - Graphics::Menu::clockStart) / CLOCKS_PER_SEC);

                ImGui::Separator();

                ImGui::Text(skCrypt("Process Identifier: %0.d"), Game::processId);
                ImGui::Text(skCrypt("Process Handle: 0x%x"), Game::handle);
                ImGui::Text(skCrypt("Process Width/Height: %0.f, %0.f"), Graphics::Rendering::gameWidth, Graphics::Rendering::gameHeight);
                ImGui::Text(skCrypt("Process X/Y: %0.f, %0.f"), Graphics::Rendering::gameX, Graphics::Rendering::gameY);

                ImGui::Separator();

                if (ImGui::Button(skCrypt("Unload Trainer")))
                {
                    exit(0);
                }

                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
		ImGui::End();
	}
}