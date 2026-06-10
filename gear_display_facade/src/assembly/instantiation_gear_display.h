#if defined(INSTANTIATION_DEFINE) || !defined(INSTANTIATION_GEAR_DISPLAY_H)
#define INSTANTIATION_GEAR_DISPLAY_H

#if defined(INSTANTIATION_DEFINE)

// #include "instantiation.h"
#include "manager.h"
#include "module_interface.h"
#include "signal.h"
#include "gear_display_facade.h"

#else

// forward declaration
namespace framework {
class Manager;
}

namespace gear_display_facade {
class GearDisplayFacade;
}

#endif

INSTANTIATION(
    framework::Manager,
    app_manager
)
// normal: extern framework::Manager app_manager;
// definition: framework::Manager app_manager{};

INSTANTIATION(
    gear_display_facade::GearDisplayFacade,
    gear_display_facade_module,
    ac_gear_position_signal,
    ac_is_eco_mode_signal,
    app_manager
)
// normal: extern gear_display_facade::GearDisplayFacade gear_display_facade_module;
// define: gear_display_facade::GearDisplayFacade gear_display_facade_module{
//          ac_gear_position_signal,
//          ac_is_eco_mode_signal,
//          app_manager
//         };

#endif
