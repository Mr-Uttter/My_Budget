#pragma once

class Application{
    private:
        bool salaryOk = false;
        int salary = 0;
        int savingsPercentage = 10;
        float tax = 0.0f;
        float savings = 0.0f;
        
        float taxCalculation(float salary);
        float calculateSavingsAmount(float salary);

    public:
        void Render(); // Draw the GUI
};

class Menu{
    private:
        
    public:
        bool setMenu(); // Set menu
};