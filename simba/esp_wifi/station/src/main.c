
#include "simba.h"

#define WIFI_SSID "WIFI_SSID"
#define WIFI_PASS "WIFI_PASS"

int main()
{
    /* Start the system. */
    sys_start();

    /* Set operation mode to Station. */
    esp_wifi_set_op_mode(esp_wifi_op_mode_station_t);

    /* Configure the WiFi module as a Station.*/
    if (esp_wifi_station_init(WIFI_SSID, WIFI_PASS, NULL, NULL)) {
        std_printf(FSTR("Failed to configure the wifi interface.\r\n"));
    }

    /* Connect to the WiFi network.*/
    if (esp_wifi_station_connect()) {
        std_printf(FSTR("Failed to connect the wifi interface.\r\n"));
    }

    int status = -1;
    while (1) {

        /* Get the wifi connect status. */
        int new_status = esp_wifi_station_get_status();
        if (new_status != status) {

            /* Print information about the WiFi. */
            std_printf(FSTR("----------------------------------------\r\n"));
            esp_wifi_print(sys_get_stdout());

            status = new_status;
        }

        /* Test each 1 second. */
        thrd_sleep(1);
    }

    return 0;
}
