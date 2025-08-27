#include<stdio.h>
#include<stdint.h>

struct weather_packet {
    float packet_id;
    float temperature_celsius;
    float humidity_percent;
    // uint32_t pressure_pascals;
};

struct weather_packet2 {
    uint8_t  packet_id;
    float temperature_celsius;
    uint16_t humidity_percent;
    uint32_t pressure_pascals;
};

int main(){
    struct weather_packet sensor_data;
    printf("Size of packet_id: %zu bytes\n", sizeof(sensor_data.packet_id));
    printf("Size of temperature_celsius: %zu bytes\n", sizeof(sensor_data.temperature_celsius));
    printf("Size of humidity_percent: %zu bytes\n", sizeof(sensor_data.humidity_percent));
    // printf("Size of pressure_pascals: %zu bytes\n", sizeof(sensor_data.pressure_pascals));
    printf("Total size of weather_packet: %zu bytes\n", sizeof(sensor_data));
  
    printf("\n");    
    printf("\n");
    printf("\n");

    struct weather_packet2 sensor_data2;
    printf("Size of packet_id: %zu bytes\n", sizeof(sensor_data2.packet_id));
    printf("Size of temperature_celsius: %zu bytes\n", sizeof(sensor_data2.temperature_celsius));
    printf("Size of humidity_percent: %zu bytes\n", sizeof(sensor_data2.humidity_percent));
    printf("Size of pressure_pascals: %zu bytes\n", sizeof(sensor_data2.pressure_pascals));
    printf("Total size of weather_packet: %zu bytes\n", sizeof(sensor_data2));
    return 0;
}

