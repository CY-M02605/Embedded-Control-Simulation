/**
 * @file module_interface.h
 * @brief ModuleInterface for gear_display_facade in framework
 * @date 05.06.2026 
 */

#ifndef MODULE_INTERFACE_H
#define MODULE_INTERFACE_H

namespace framework {
class ModuleInterface {
    public:
        virtual ~ModuleInterface() {}

        virtual void Update() = 0;

        virtual void Init() {}
};
}

#endif
