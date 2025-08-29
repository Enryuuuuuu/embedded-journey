Struct

struct is a data type that allow you to make a group that consist of various type and size of data. for example

struct weather_packet2 {
uint8_t packet_id; // 1 byte
float temperature_celsius; // 4 bytes
uint16_t humidity_percent; // 2 bytes
uint32_t pressure_pascals; // 4 bytes
};

that stuct is consist of a several data size and type like uint8_t,float, uint16_t, and uint32_t. to use struct first we should make the format for out struct. we should define what our struct consist of. next we should make variable using our struct as the data type:

struct weather_packet2 sensor2;

in that code we are making a variable named sensor2 that have data type weather_packet2.

to access the content of the struct we use dot operator (.):

sensor2.packet_id

=============================================================================================================

## Pointer function

same as variable, function has an address too.

for initialize Pointer function use format:
return_type (\*pointer_name)(type_arg1, tipe_arg2, ...);

example:
void (\*on_press_action)(void);
---------------I---------------
---------------V---------------
for function:
void stop_music(){
printf("music stoped...\n");
}

to fill the pointer function use:
pointer_name = function_name; //without a ()

to call the function use:
pointer_name(); //whit a ()

=============================================================================================================
uses of pointer function

bellow is code if we doesnt use a pointer variabel, it will difficult if we want to add another function. if we want to add another function we shoulde write it down in every event function.

// THIS IS THE BAD WAY
void handle_button_press() {
switch (current_state) {
case HEATING: run_heater(); break;
case COOLING: run_cooler(); break;
case FAN_ONLY: run_fan(); break;
case IDLE: turn_off(); break;
}
}

void handle_timer_event() {
// The exact same logic is repeated here!
switch (current_state) {
case HEATING: run_heater(); break;
case COOLING: run_cooler(); break;
case FAN_ONLY: run_fan(); break;
case IDLE: turn_off(); break;
}
}

void handle_wifi_command() {
// And it's repeated here again!
switch (current_state) {
case HEATING: run_heater(); break;
case COOLING: run_cooler(); break;
case FAN_ONLY: run_fan(); break;
case IDLE: turn_off(); break;
}
}

and this is if we use pointer function. if we want to add another function we just need to write it down in centrilize action function

// Pointer that holds the correct action for the current state.
void (\*current_action)(void);

// The logic is now CENTRALIZED in one place.
void set_action_for_state(SystemState state) {
switch (state) {
case HEATING: current_action = &run_heater; break;
case COOLING: current_action = &run_cooler; break;
case FAN_ONLY: current_action = &run_fan; break;
case IDLE: current_action = &turn_off; break;
}
}

// Now, the event handlers are incredibly simple and clean.
void handle_button_press() {
current_action();
}

void handle_timer_event() {
current_action();
}

void handle_wifi_command() {
current_action();
}
