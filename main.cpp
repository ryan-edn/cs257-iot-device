#include <iostream>
#include <string>
#include <vector>

class SmartCoffeeMaker {
private:
    int waterLevel;      // mL (0-1000)
    int coffeeLevel;     // grams (0-500)
    int temperature;     // Celsius
    bool isBrewing;
    std::string brewStrength; // "mild", "medium", "strong"
    int cupsRequested;

public:
    SmartCoffeeMaker() : waterLevel(500), coffeeLevel(250), 
                        temperature(20), isBrewing(false), 
                        brewStrength("medium"), cupsRequested(1) {}
    
    void fillWater(int amount) {
        waterLevel += amount;
        std::cout << "Water level: " << waterLevel << " mL" << std::endl;
    }
    
    void addCoffee(int grams) {
        coffeeLevel += grams;
        std::cout << "Coffee level: " << coffeeLevel << " grams" << std::endl;
    }
    
    void setStrength(const std::string& strength) {
        brewStrength = strength;
        std::cout << "Brew strength set to " << brewStrength << std::endl;
    }
    
    bool brew(int cups) {
        cupsRequested = cups;
        int waterNeeded = cups * 240;  // 240mL per cup
        int coffeeNeeded = cups * 15;  // 15g per cup
        
        if (waterLevel < waterNeeded) {
            std::cout << "Not enough water! Need " << waterNeeded << " mL" << std::endl;
            return false;
        }
        
        if (coffeeLevel < coffeeNeeded) {
            std::cout << "Not enough coffee! Need " << coffeeNeeded << " grams" << std::endl;
            return false;
        }
        
        isBrewing = true;
        std::cout << "Brewing " << cups << " cups..." << std::endl;
        
        // Heat water
        temperature = 95;
        
        // Use resources
        waterLevel -= waterNeeded;
        coffeeLevel -= coffeeNeeded;
        
        isBrewing = false;
        std::cout << "Coffee ready!" << std::endl;
        return true;
    }
    
    void clean() {
        std::cout << "Running cleaning cycle..." << std::endl;
        temperature = 20;
        waterLevel = 0;
    }
    
    void displayStatus() {
        std::cout << "Coffee Maker Status:" << std::endl;
        std::cout << "  Water: " << waterLevel << " mL" << std::endl;
        std::cout << "  Coffee: " << coffeeLevel << " grams" << std::endl;
        std::cout << "  Temperature: " << temperature << "°C" << std::endl;
        std::cout << "  Strength: " << brewStrength << std::endl;
        std::cout << "  Brewing: " << (isBrewing ? "YES" : "NO") << std::endl;
    }
};

int main() {
    SmartCoffeeMaker myCoffee;
    
    myCoffee.displayStatus();
    myCoffee.setStrength("strong");
    myCoffee.brew(2);
    
    myCoffee.displayStatus();
    
    // Try to overfill
    myCoffee.fillWater(600);  // Tank capacity is 1000mL
    myCoffee.displayStatus();
    
    return 0;
}
