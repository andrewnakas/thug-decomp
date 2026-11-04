typedef int qword __attribute__((mode(TI)));
union Vec_00219FD0 {
    qword q;
    struct { float x, y, z, w; } f;
};

struct Obj_00219FD0 {
    char pad0[0x50];
    Vec_00219FD0 m50;
};

struct Mgr_00219FD0 {
    char pad0[0x28];
    void* m28;
};

extern char D_00371390[];
extern char D_003713A0[];
extern char D_003713C8[];
extern void* D_0038C608;
extern Mgr_00219FD0* D_0038FC78;

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_00219FD0* out, int required);
extern "C" int func_00229668(unsigned int name, int a);
extern "C" void* func_00229DF0(int idx);
extern "C" void func_00103F28(char* msg);
extern "C" void func_001E7410(void* s, unsigned int name, float x, float y, float z);
extern "C" Obj_00219FD0* func_00187B48(void* m, unsigned int name);
extern "C" void* func_00141250(unsigned int name);
extern "C" void func_001404A0(void* p);
extern "C" void func_002691A8(void* p, int idx, Vec_00219FD0* pos);

bool Cmd_00219FD0(void* params, void* script)
{
    Vec_00219FD0 pos;
    Vec_00219FD0 rot;
    unsigned int name;
    unsigned int type;
    if (!func_001E8398(params, 0xA1DC81F9, &name, 0)) {
        func_00103F28(D_00371390);
        return false;
    }
    int idx = func_00229668(name, 0);
    if (idx == -1) return false;
    void* node = func_00229DF0(idx);
    if (!func_001E7FA8(params, 0xB9D31B0A, &pos, 0) && !func_001E7FA8(params, 0x7F261953, &pos, 0)) {
        func_00103F28(D_003713A0);
        return false;
    }
    Vec_00219FD0* r = &rot;
    if (!func_001E7FA8(node, 0xB9D31B0A, r, 0) && !func_001E7FA8(node, 0x7F261953, r, 0)) {
        func_00103F28(D_003713C8);
        return false;
    }
    func_001E7410(node, 0x7F261953, pos.f.x, pos.f.y, pos.f.z);
    Obj_00219FD0* obj = func_00187B48(D_0038C608, name);
    if (obj) obj->m50 = pos;
    type = 0;
    func_001E8398(node, 0x12B4E660, &type, 0);
    switch (type) {
    case 0xA0DFAC98:
    case 0xE47F1B79:
    case 0xEF59C100:
        return true;
    case 0x19B1E241: {
        void* v = func_00141250(name);
        if (v) func_001404A0(v);
        return true;
    }
    case 0x8E6B02AD:
    case 0x30C19600:
        func_002691A8(D_0038FC78->m28, idx, &pos);
        break;
    case 0x08470F2E:
    case 0x061A741E:
    case 0xBF4D3536:
    case 0xB7B3BD86:
        break;
    default:
        return false;
    }
    return true;
}
