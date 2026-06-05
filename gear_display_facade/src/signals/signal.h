/**
 * @file signal.h
 * @brief Signal for gear_display_facade in signals
 * @date 05.06.2026
 */

#ifndef SIGNAL_H
#define SIGNAL_H

namespace signals {

// strongly-typed enumeration
enum class ValidationStatus {
    VALID, INVALID
};

// in general, OFF at first for 0
enum class OnOffStatus {
    OFF, ON
};

// T is a template parametre for signal value type
template <typename T>
class Signal {
    public:

        Signal():
            // T() creates a default value for current signal value type
            // for example, Signal<int> -> T() means int(), value = 0; Signal<boo> -> T() means bool(),  value = false
            value_(T()),
            validity_(ValidationStatus::VALID){}
            
        Signal(
            T value,
            ValidationStatus validity
        ):value_(value),
        validity_(validity){
        }

        void SetValue(T value) {
            value_ = value;
        }
        
        T GetValue() const {
            return value_;
        }

        void SetValidity(ValidationStatus validity) {
            validity_ = validity;
        }

        ValidationStatus GetValidity() const {
            return validity_;
        }

        bool IsValid() const {
            return validity_ == ValidationStatus::VALID;
        }

        void Set(T value, ValidationStatus validity) {
            value_ = value;
            validity_ = validity;
        }

    private:
        T value_;
        ValidationStatus validity_;
        
};
}


#endif
