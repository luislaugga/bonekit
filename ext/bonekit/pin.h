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
  int _mode;
  int _value;
};

typedef struct pin_s pin_t;

pin_t * pin_create(unsigned);
void pin_destroy(pin_t *);
int pin_mode(pin_t *);
void pin_set_mode(pin_t *, int);
int pin_value(pin_t *);
void pin_set_value(pin_t *, int);

#ifdef __cplusplus
}
#endif

#endif