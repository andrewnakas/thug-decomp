extern int D_00388818;
extern int D_0038881C;
extern int D_0038C258;
extern float D_0038C25C;
extern float D_003940C0;
extern void* D_003940BC;
extern "C" void func_00182578(void* p);
extern "C" void func_00182570();

extern "C" void func_00182580(unsigned int held, unsigned int pressed)
{
    if (!D_00388818 || D_0038881C || !D_0038C258) {
        return;
    }
    float speed = D_0038C25C;
    float s = speed;
    float k = 1.1f;
    if (held & 0x8000) {
        s = speed * k;
    }
    if (held & 0x2000) {
        s = speed / k;
    }
    if (held & 0x1000) {
        D_003940C0 -= speed * 4096.0f;
    }
    if (held & 0x4000) {
        D_003940C0 += speed * 4096.0f;
    }
    if (held & 0x4) {
        D_003940C0 -= speed * 16.0f;
    }
    if (held & 0x1) {
        D_003940C0 += speed * 16.0f;
    }
    if (s < 0.0078125f) {
        s = 0.0078125f;
    }
    if (s > 1024.0f) {
        s = 1024.0f;
    }
    D_0038C25C = s;
    if ((pressed & 0x20) && D_003940BC) {
        func_00182578(D_003940BC);
    }
    if (pressed & 0x80) {
        func_00182570();
    }
}
