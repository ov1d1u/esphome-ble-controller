#pragma once

#include "esphome/core/defines.h"
#ifdef USE_NUMBER

#include <string>

#include "esphome/components/number/number.h"

#include "ble_component_handler.h"

using std::string;

namespace esphome {
namespace esp32_ble_controller {

using number::Number;
/**
* Special component handler for numbers, which allows setting a number value from a BLE client.
*/
class BLENumberHandler : public BLEComponentHandler<Number> {
public:
  BLENumberHandler(Number* component, const BLECharacteristicInfoForHandler& characteristic_info) 
      : BLEComponentHandler(component, characteristic_info) {}
  virtual ~BLENumberHandler() {}

protected:
  virtual bool can_receive_writes() { return true; }
  virtual void on_characteristic_written() override;
};

} // namespace esp32_ble_controller
} // namespace esphome

#endif