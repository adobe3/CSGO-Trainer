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
		ImGui::Begin(skCrypt("##CSGO-Trainer"), NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);

        if (ImGui::BeginTabBar(skCrypt("##Menu Bar")))
        {
            if (ImGui::BeginTabItem(skCrypt("Aimbot")))
            {
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(skCrypt("Visuals")))
            {
                ImGui::Checkbox(skCrypt("Boxes"), &Trainer::ESP::boxStatus);

                ImGui::Checkbox(skCrypt("Snaplines"), &Trainer::ESP::snaplineStatus);
                ImGui::Combo(skCrypt("##Snapline Mode"), &Trainer::ESP::snaplineType, skCrypt("Bottom\0Middle\0\0"));

                ImGui::Checkbox(skCrypt("Healthbars"), &Trainer::ESP::healthbarStatus);

                ImGui::Checkbox(skCrypt("Distance"), &Trainer::ESP::distanceStatus);

                ImGui::Checkbox(skCrypt("Heads"), &Trainer::ESP::headStatus);;
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(skCrypt("Miscellaneous")))
            {
                ImGui::Checkbox(skCrypt("Triggerbot"), &Trainer::Triggerbot::status);
                ImGui::SliderFloat(skCrypt("##Triggerbot Delay"), &Trainer::Triggerbot::delay, 0.f, 300.f, skCrypt("%.3fms"));
                ImGui::Combo(skCrypt("##Triggerbot Hotkey"), &Trainer::Triggerbot::hotkey, skCrypt("Always On\0Left Mouse\0Right Mouse\0Pause/Break Key\0Middle Mouse\0X1 Mouse\0X2 Mouse\0\0"));

                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
		ImGui::End();
	}
}