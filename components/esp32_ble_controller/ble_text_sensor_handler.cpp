#include "ble_text_sensor_handler.h"

#ifdef USE_TEXT_SENSOR

#include "esphome/core/log.h"

namespace esphome {
namespace esp32_ble_controller {

static const char *TAG = "ble_text_sensor_handler";

void BLETextSensorHandler::on_characteristic_written() {
  std::string value = get_characteristic()->getValue();
  // Create a null-terminated string
  std::vector<char> text_value(value.begin(), value.end());
  text_value.push_back('\0');

  // Log as string; correct format specifier
  ESP_LOGD(TAG, "Text characteristic written: %s", text_value.data());

  // Use the data as a string and publish the state
  get_component()->publish_state(text_value.data());
}

} // namespace esp32_ble_controller
} // namespace esphome

#endif