.equ RAMEND, 0x8ff
.equ SREG, 0x3f
.equ SPL, 0x3d
.equ SPH, 0x3e
.equ PORTB, 0x05
.equ DDRB, 0x04
.equ PINB, 0x03

.org 0
   rjmp main

main:
   ldi r16,0 ; reset system status
   out SREG,r16 ; init stack pointer
   ldi r16,lo8(RAMEND)
   out SPL,r16
   ldi r16,hi8(RAMEND)
   out SPH,r16

   ldi r16,0x20 ; set port bits to output mode
   out DDRB,r16

   clr r17
mainloop:
   eor r17,r16 ; invert output bit
   out PORTB,r17 ; write to port
   call wait ; wait some time
   rjmp mainloop ; loop forever

wait:
   push r16
   push r17
   push r18

   ldi r16,0x40 ; loop 0x400000 times
   ldi r17,0x00 ; ~12 million cycles
   ldi r18,0x00 ; ~0.7s at 16Mhz
_w0:
   dec r18
   brne _w0
   dec r17
   brne _w0
   dec r16
   brne _w0

   pop r18
   pop r17
   pop r16
   ret
