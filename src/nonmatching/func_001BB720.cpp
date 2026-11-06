/* fuzzy: 98.9 */
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_0033ECA8(float f);
extern "C" unsigned int func_0033EBE0(float f);
extern "C" void func_00103F28(const char* file, const char* fmt, int line, ...);
extern char D_00363108[];
extern char D_0036312F[];

struct Timer_001BB720 {
    int m0;
    int m4;
};

extern "C" Timer_001BB720* func_0026F6C0(void* table, unsigned int id);
extern "C" unsigned int func_0026FDA0(Timer_001BB720* t);

struct C_001BB720 {
    int m_pad[9];
    int m24[2];
    int m2C;
    int m30[8];
    int m50;
    int m54[8];
    int m74;
    int m78[8];
    int m98;
    int m9C[290];
    int m524;
    int m528;
    int m52C;
    void Play(unsigned int id, float speed, int loop);
    int Call(unsigned int name, void* params);
};

int C_001BB720::Call(unsigned int name, void* params)
{
    switch (name) {
    case 0xBF7D6C46: {
        unsigned int id = 0;
        if (!func_001E8398(params, 0, &id, 0)) break;
        float speed = 1.0f;
        func_001E7EB0(params, 0x906B67BA, &speed, 0);
        func_00103F28(D_00363108, D_0036312F, 0x83, func_0033ECA8(speed));
        int loop = 0;
        func_001E7DE8(params, 0x1A4E0EF9, &loop, 0);
        Play(id, speed, loop != 0);
        return 1;
    }
    case 0x6E24F5FD:
        m524 = 1;
        break;
    case 0x56C6C0CD:
        m524 = 0;
        break;
    case 0x6DF51774:
        m528 = 1;
        break;
    case 0x31C6454F:
        m528 = 0;
        break;
    case 0x0660746A:
        return m524 || m528;
    case 0x78238598:
        return m74 != 0;
    case 0x1D604A9D:
        return m98 != 0;
    case 0x89AA9B5F:
        return m2C != 0;
    case 0x83028FC5:
        return m50 != 0;
    case 0x2366469C: {
        unsigned int id;
        func_001E8398(params, 0xC5F953C2, &id, 1);
        float t;
        func_001E7EB0(params, 0, &t, 1);
        unsigned int lim;
        if (func_001E8708(params, 0xD029F619) || func_001E8708(params, 0x49E0EE96))
            lim = func_0033EBE0(t * 1000.0f);
        else if (func_001E8708(params, 0x019176C5) || func_001E8708(params, 0x4A07C332))
            lim = func_0033EBE0(t * 16.666668f);
        else
            lim = func_0033EBE0(t);
        Timer_001BB720* e = func_0026F6C0(m24, id);
        if (!e) return 0;
        return (e->m4 && lim < func_0026FDA0(e)) ? 1 : 0;
    }
    case 0x1090A150:
        m52C = 1;
        break;
    case 0x28729460:
        m52C = 0;
        break;
    default:
        return 2;
    }
    return 1;
}
