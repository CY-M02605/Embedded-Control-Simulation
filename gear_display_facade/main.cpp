/**
 * @file main.cpp
 * @brief test for gear_display_facade
 * @date 08.06.2026
 */

#include "manager.h"
#include "module_interface.h"
#include "signal.h"

#include "gear_types.h"
#include "gear_display_facade.h"

#include <iostream>

const char* GearPositionToStr(GearPosition RawGearSignal) {
    switch (RawGearSignal) {
        case GearPosition::NEUTRAL: return "NEUTRAL";
        case GearPosition::FORWARD_1: return "FORWARD_1";
        case GearPosition::FORWARD_2: return "FORWARD_2";
        case GearPosition::FORWARD_3: return "FORWARD_3";
        case GearPosition::REVERSE_1: return "REVERSE_1";
        case GearPosition::REVERSE_2: return "REVERSE_2";
        default:                      return "UNKNOWN";
    }
}

const char* DriveModeToStr(DriveMode RawModeSignal) {
    switch (RawModeSignal) {
        case DriveMode::ECO: return "ECO";
        case DriveMode::POWER: return "POWER";
        default:               return "UNKNOWN";
    }
}

const char* ValidityToStr(signals::ValidationStatus& RawValiditySignal) {
    return RawValiditySignal == signals::ValidationStatus::VALID? "VALID" : "INVALID"; 
}

void CheckGearPosition(
    const char* test_name, const gear_display_facade::GearPositionSignal& actual,
    GearPosition expected_value, signals::ValidationStatus expected_validity
) {
    bool pass = (actual.GetValue() == expected_value && 
                 actual.GetValidity() == expected_validity) ? true : false;

    // std::cout << "Test_name: " << test_name << " | " 
    //           << "PASS or FAIL ? " << pass << " | "
    //           << 
}

void CheckDriveMode() {

}

int main() {

    framework::Manager manager;
    gear_display_facade::AcGearPositionSignal ac_gear_position_signal(
        0, signals::ValidationStatus::VALID
    );

    gear_display_facade::AcIsEcoModeSignal ac_is_eco_mode_signal(
        false, signals::ValidationStatus::VALID
    );

    gear_display_facade::GearDisplayFacade facade(ac_gear_position_signal,ac_is_eco_mode_signal,manager);

    // manager.UpdateAll();

    struct GearInputs { 
        int raw_gear; signals::ValidationStatus gear_validity; 
        GearPosition expected_value; signals::ValidationStatus expected_validity;
    };

    GearInputs GearInputArray[] = {
        {0, signals::ValidationStatus::VALID, GearPosition::NEUTRAL, signals::ValidationStatus::VALID},
        {1, signals::ValidationStatus::VALID, GearPosition::FORWARD_1, signals::ValidationStatus::VALID},
        {2, signals::ValidationStatus::VALID, GearPosition::FORWARD_2, signals::ValidationStatus::VALID},
        {3, signals::ValidationStatus::VALID, GearPosition::FORWARD_3, signals::ValidationStatus::VALID},
        {-1, signals::ValidationStatus::VALID, GearPosition::REVERSE_1, signals::ValidationStatus::VALID},
        {-2, signals::ValidationStatus::VALID, GearPosition::REVERSE_2, signals::ValidationStatus::VALID},
        {99, signals::ValidationStatus::VALID, GearPosition::NEUTRAL, signals::ValidationStatus::VALID},

        {0, signals::ValidationStatus::INVALID, GearPosition::NEUTRAL, signals::ValidationStatus::INVALID},
        {1, signals::ValidationStatus::INVALID, GearPosition::NEUTRAL, signals::ValidationStatus::INVALID},
        {2, signals::ValidationStatus::INVALID, GearPosition::NEUTRAL, signals::ValidationStatus::INVALID},
        {3, signals::ValidationStatus::INVALID, GearPosition::NEUTRAL, signals::ValidationStatus::INVALID},
        {-1, signals::ValidationStatus::INVALID, GearPosition::NEUTRAL, signals::ValidationStatus::INVALID},
        {-2, signals::ValidationStatus::INVALID, GearPosition::NEUTRAL, signals::ValidationStatus::INVALID},
        {99, signals::ValidationStatus::INVALID, GearPosition::NEUTRAL, signals::ValidationStatus::INVALID},
    };

    struct ModeInputs {
        bool raw_mode; signals::ValidationStatus mode_validity;
        DriveMode expected_value; signals::ValidationStatus expected_validity;
    };

    ModeInputs ModeInputArray[] = {
        {true, signals::ValidationStatus::VALID, DriveMode::ECO, signals::ValidationStatus::VALID},
        {false, signals::ValidationStatus::VALID, DriveMode::POWER, signals::ValidationStatus::VALID},
        // {"xxx", signals::ValidationStatus::VALID, DriveMode::POWER, signals::ValidationStatus::VALID},
        {true, signals::ValidationStatus::VALID, DriveMode::ECO, signals::ValidationStatus::VALID},
        {false, signals::ValidationStatus::VALID, DriveMode::POWER, signals::ValidationStatus::VALID},
        // {"xxx", signals::ValidationStatus::INVALID, DriveMode::POWER, signals::ValidationStatus::INVALID},
    };

    return 0;
}