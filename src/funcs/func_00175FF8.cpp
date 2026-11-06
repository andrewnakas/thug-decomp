struct Pt_00175FF8 {
    unsigned short x, y;
};

extern unsigned char* D_00394274;
extern unsigned char* D_00394288;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern unsigned int D_00394000;
extern int D_00394018;
extern int D_0039401C;
extern unsigned short* D_00394028;
extern int D_0038BF80;
extern Pt_00175FF8 D_00393F70;
extern Pt_00175FF8 D_00393F74;
extern char D_00361010[];
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_00334148(int code) __attribute__((noreturn));

static inline unsigned int Unpack_00175FF8(unsigned short addr, unsigned int cmd)
{
    return (addr & 0x3FF) | cmd;
}

void Emit_00175FF8(float* v)
{
    if (D_0039401C == 0) {
        unsigned int* p = (unsigned int*)D_00394274;
        D_00394284 = 0x10;
        D_0039428C = 2;
        D_00394288 = (unsigned char*)p;
        *p = Unpack_00175FF8(D_00394000 + D_00394280, 0x65008000);
        D_00394274 = (unsigned char*)(p + 1);
        D_00394028 = (unsigned short*)(p + 1);
        if (D_0038BF80) {
            *D_00394028++ = D_00393F70.x;
            *D_00394028++ = D_00393F70.y;
            *D_00394028++ = D_00393F74.x;
            *D_00394028++ = D_00393F74.y;
        }
        D_00394274 = (unsigned char*)D_00394028 + D_00394018 * 4;
        unsigned char* end = (unsigned char*)(((int)D_00394274 + 3) & ~3);
        D_00394290 = ((D_00394274 - D_00394288) - 4) * 8 / (D_0039428C * D_00394284);
        while (D_00394274 < end)
            *D_00394274++ = 0;
        if (D_00394290 == 0) {
            D_00394274 -= 4;
        } else if (D_00394290 < 0x100) {
            D_00394288[2] = D_00394290;
        } else if (D_00394290 == 0x100) {
            D_00394288[2] = 0;
        } else {
            func_00103F28(D_00361010);
            func_00334148(1);
        }
    }
    *D_00394028++ = (int)(v[0] * 4096.0f);
    *D_00394028++ = (int)(v[1] * 4096.0f);
    D_00393F70.x = D_00393F74.x;
    D_00393F74.x = D_00394028[-2];
    D_00393F70.y = D_00393F74.y;
    D_00393F74.y = D_00394028[-1];
    D_00394000++;
}
