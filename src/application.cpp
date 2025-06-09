#include "application.h"
#include "imgui.h"
#include <iostream>


bool Menu::setMenu() {
    bool endProgram = false;

    if (ImGui::BeginMainMenuBar()) {

        // FIL
        if (ImGui::BeginMenu("Arkiv")) {
            if (ImGui::MenuItem("New budget...")) {
                // Stub for later, menu
            }
            if (ImGui::MenuItem("Open...", "Ctrl+O")) {
                // Stub for later, menu
            }
            if (ImGui::MenuItem("Save", "Ctrl+S")) {
                // Stub for later, menu
            }
            if (ImGui::MenuItem("Save as...")) {
                // Stub for later, menu
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Quit")) {
                endProgram = true;
            }
            ImGui::EndMenu();
        }

        // REDIGERA
        if (ImGui::BeginMenu("Edit")) {
            if (ImGui::MenuItem("Add income...")) {
                // Stub for later, menu
            }
            if (ImGui::MenuItem("Add expence...")) {
                // Stub for later, menu
            }
            if (ImGui::MenuItem("Clear budget")) {
                // Stub for later, menu
            }
            ImGui::EndMenu();
        }

        // VISA
        if (ImGui::BeginMenu("View")) {
            if (ImGui::MenuItem("Compilation")) {
                // Stub for later, menu
            }
            if (ImGui::MenuItem("Diagram")) {
                // Stub for later, menu
            }
            if (ImGui::MenuItem("Detail by month")) {
                // Stub for later, menu
            }
            ImGui::EndMenu();
        }

        // HJÄLP
        if (ImGui::BeginMenu("Help")) {
            if (ImGui::MenuItem("Manual")) {
                // Stub for later, menu
            }
            if (ImGui::MenuItem("About")) {
                // Stub for later, menu
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    return endProgram;
}



void Application::Render(){

    ImGui::Begin("Testfönster");
    ImGui::Text("Fungerar det?");
    ImGui::InputInt("Input text", &salary);
    salaryOk = ImGui::Button("OK");
        if ((salaryOk == true) && (salary > 1)){
            taxCalculation(salary);
            calculateSavingsAmount(salary);
        }
    ImGui::End();
}


float Application::taxCalculation(float salary){
    std::cout << salary;
    return 0;
}

float Application::calculateSavingsAmount(float salary){
    std::cout << salary * savingsPercentage;
    return 0;
}