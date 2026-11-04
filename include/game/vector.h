#ifndef GAME_VECTOR_H
#define GAME_VECTOR_H
#ifndef M2CTX /* C++ only; m2c parses these headers as C */

/* 128-bit integer: gives 16-byte alignment and lq/sq copies. */
typedef int qword __attribute__((mode(TI)));

/* 4-float vector, 16-byte aligned (copied with lq/sq). */
struct Vector {
    union {
        struct { float x, y, z, w; };
        qword q;
    };

    void DegToRad();      /* x,y,z *= pi/180 */
    void FeetToInches();  /* x,y,z *= 12 */
    void Swizzle();       /* (x,y,z) -> (-x,-z,y) */
};

#endif /* M2CTX */
#endif
