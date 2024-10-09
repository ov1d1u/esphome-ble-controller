#include "ble_number_handler.h"

#ifdef USE_NUMBER

#include "esphome/core/log.h"

namespace esphome {
namespace esp32_ble_controller {

static const char *TAG = "ble_number_handler";

void BLENumberHandler::on_characteristic_written() {
  std::string value = get_characteristic()->getValue();
  if (value.length() == 4) {
    // Value is a 32-bit IEEE 754 float
    // https://en.wikipedia.org/wiki/Single-precision_floating-point_format
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(value.data());
    float number_value;
    memcpy(&number_value, bytes, sizeof(float));

    ESP_LOGD(TAG, "Number characteristic written: %f", number_value);
    get_component()->publish_state(number_value);
  } else {
    ESP_LOGE(TAG, "Received characteristic with invalid size. Expected 4 bytes for a float.");
  }
}

} // namespace esp32_ble_controller
} // namespace esphome

#endif