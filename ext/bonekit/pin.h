/*
*/

#ifndef BONEKIT_PIN_H__
#define BONEKIT_PIN_H__

#ifdef __cplusplus
extern "C" {
#endif

struct pin_s
{
  unsigned _gpio;
  uint8_t _mode;
  int _value;
};

typedef struct pin_s pin_t;

pin_t * pin_create(unsigned);
void pin_destroy(pin_t *);
uint8_t pin_mode(pin_t *);
void pin_set_mode(pin_t *, uint8_t);
int pin_value(pin_t *);
void pin_set_value(pin_t *, int);

#ifdef __cplusplus
}
#endif

#endif