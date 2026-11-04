struct Obj_00248FF8;

extern "C" void func_00183CB8(Obj_00248FF8* obj, Obj_00248FF8** ref);
extern "C" void func_00183C98(Obj_00248FF8* obj, Obj_00248FF8** ref);

struct Ref_00248FF8 {
    Obj_00248FF8* m_ptr;
    void Set(Obj_00248FF8* obj)
    {
        if (m_ptr) {
            func_00183CB8(m_ptr, &m_ptr);
            m_ptr = 0;
        }
        m_ptr = obj;
        if (obj) {
            func_00183C98(obj, &m_ptr);
        }
    }
};

struct Script_00248FF8 {
    char m_pad[0xBC];
    Ref_00248FF8 m_object;
};

struct Comp_00248FF8 {
    char m_pad[0x44];
    int m44;
};

struct Goal_00248FF8 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
    int m10;
};

extern void* D_0038FC78;
extern void* D_0038C608;
extern void* D_0038DB38;

extern "C" bool func_001E11A8(unsigned int id);
extern "C" void* func_00249FE0(Goal_00248FF8* self);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" Obj_00248FF8* func_0022DD38(void* self);
extern "C" Obj_00248FF8* func_00187B48(void* self, unsigned int id);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" Comp_00248FF8* func_00185578(Obj_00248FF8* self, unsigned int id);
extern "C" void func_002495E8(Goal_00248FF8* self, unsigned int id, int value);
extern "C" int func_001DF818(unsigned int id, int a);
extern "C" bool func_001D0638(void* self, unsigned int id, int a);
extern "C" Script_00248FF8* func_001F0750(unsigned int script, void* params, void* object, int a, int b, int c, int d, int e, int f, int g);
extern "C" void func_001E6AE8(void* self, int flags);

void func_00248FF8(Goal_00248FF8* self, unsigned int id, int quick, unsigned int target, bool flag)
{
    if (self->m4 || !func_001E11A8(id)) {
        return;
    }
    void* params = func_00249FE0(self);
    unsigned int obj_id = target;
    if (!target) {
        func_001E8398(params, 0x02D7E03D, &obj_id, 1);
    }
    Obj_00248FF8* obj;
    if (obj_id == 0x5B8AB877) {
        obj = func_0022DD38(D_0038FC78);
    } else {
        obj = func_00187B48(D_0038C608, obj_id);
    }
    if (!obj) {
        return;
    }
    void* p = func_001E6978(func_001190D0(8));
    func_001E7360(p, 0x0572EA28, id);
    if (!quick) {
        func_001E7200(p, 0xC9B0DEB7, 0);
        int offset = func_00185578(obj, 0x72AD7B23)->m44;
        if (flag) {
            func_002495E8(self, id, offset);
        }
        int screen = func_001DF818(id, 100);
        func_001E7360(p, 0x8A68AB90, screen);
        self->m10 = screen;
        if (func_001D0638(D_0038DB38, id + offset, 0)) {
            func_001E7360(p, 0, 0x93516575);
            self->mC = obj_id;
        }
    }
    Script_00248FF8* script = func_001F0750(0x5376A011, p, 0, 0, -1, 0, 0, 0, 0, 0);
    script->m_object.Set(obj);
    if (p) {
        func_001E6AE8(p, 3);
    }
}
