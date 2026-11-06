struct Mgr_00211030 {
    char pad[0x28];
    void* m28;
};

extern Mgr_00211030* D_0038FC78;
extern char D_00370460[];
extern char D_00370470[];
extern char D_00370480[];
extern char D_00370490[];
extern char D_003704A8[];
extern char D_003704B8[];
extern char D_003704E8[];

extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_0022EEC0(Mgr_00211030* m, void* params);
extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" void* func_0022E040(Mgr_00211030* m);
extern "C" void func_00267C38(void* p, void* params);
extern "C" void func_00267CB8(void* p, void* params);
extern "C" void func_00264998(void* p, void* params);
extern "C" void func_00264AD0(void* p, void* params);
extern "C" void func_00264A38(void* p, void* params);
extern "C" void func_002649B8(void* p, void* params);
extern "C" void* func_00131E48();
extern "C" void* func_00132FD0(void* p, unsigned int name);
extern "C" void func_00134FD8(void* s, unsigned int v);
extern "C" void func_00135048(void* s, int v);
extern "C" void func_001353D8(void* s, int v);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_00132078(unsigned int name, int v);
extern "C" char* func_001E61F0(unsigned int name);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" int func_001E87B8(void* params, const char* name);
extern "C" void func_00269070(void* p, int v, int a, int flag);
extern "C" void func_0026BA18(int v, int a);
extern "C" void func_0026C408(int v, int a);

bool Cmd_00211030(void* params)
{
    Mgr_00211030* m = D_0038FC78;
    void* o = m->m28;
    int v = 0;
    func_001E7DE8(params, 0xE50D6573, &v, 0);
    if (func_0022EEC0(m, params))
        return true;
    unsigned int type = 0;
    func_001E8398(params, 0x12B4E660, &type, 0);
    if (type == 0xE594F0A2) {
        unsigned int sub = 0;
        func_001E8398(params, 0xA1DC81F9, &sub, 0);
    }
    bool ok = true;
    switch (type) {
    case 0xE47F1B79:
        func_0010BFC0(D_00370460);
        func_00267C38(func_0022E040(m), params);
        func_0010BFC8();
        break;
    case 0x061A741E:
    case 0xA0DFAC98:
        func_0010BFC0(D_00370470);
        func_00267CB8(func_0022E040(m), params);
        func_0010BFC8();
        break;
    case 0xEF59C100:
        func_0010BFC0(D_00370480);
        func_00264998(func_0022E040(m), params);
        func_0010BFC8();
        break;
    case 0x19B1E241:
        func_0010BFC0(D_00370490);
        func_00264AD0(func_0022E040(m), params);
        func_0010BFC8();
        break;
    case 0x9E7D469E:
        func_0010BFC0(D_00370490);
        func_00264A38(func_0022E040(m), params);
        func_0010BFC8();
        break;
    case 0xB7B3BD86:
        func_0010BFC0(D_003704A8);
        func_002649B8(func_0022E040(m), params);
        func_0010BFC8();
        break;
    case 0xBF4D3536: {
        unsigned int name = 0;
        if (func_001E8398(params, 0xA1DC81F9, &name, 0)) {
            void* s = func_00132FD0(func_00131E48(), name);
            if (s) {
                func_00134FD8(s, 0xFFFFFFFF);
                func_00135048(s, 1);
                func_001353D8(s, 1);
                if (func_001E8708(params, 0x4E549FE1))
                    func_00132078(name, 1);
            } else {
                func_00103F28(D_003704B8, name, func_001E61F0(name));
            }
        }
        break;
    }
    case 0x30C19600:
    case 0x8E6B02AD:
        func_00269070(o, v, 1, func_001E87B8(params, D_003704E8));
        break;
    case 0x08470F2E:
        func_0026BA18(v, 1);
        break;
    case 0xD64DC7C2:
        func_0026C408(v, 1);
        break;
    default:
        ok = false;
        break;
    }
    return ok;
}
