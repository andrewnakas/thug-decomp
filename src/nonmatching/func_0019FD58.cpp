/* fuzzy: 99.5 */
extern "C" float fabsf(float);

struct Comp_0019FD58 {
    int m0;
    int m4;
    int m8;
    Comp_0019FD58* m_next;
    int m10;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual int Call(unsigned int name, void* params, void* script);
    Comp_0019FD58* Valid()
    {
        if (~m4) {
            return this;
        }
        return 0;
    }
};

struct Anim_0019FD58 : Comp_0019FD58 {
    int m18[5];
    int m_state;
};

struct Link_0019FD58 {
    int m0;
    int m4;
    int m8;
    Comp_0019FD58* m_next;
    Comp_0019FD58* First() { return m_next->Valid(); }
    int Count()
    {
        int n = 0;
        for (Comp_0019FD58* q = First(); q; q = q->m_next->Valid()) {
            n++;
        }
        return n;
    }
};

struct OwnerBase_0019FD58 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual int Call(unsigned int name, void* params, void* script);
};

struct Owner_0019FD58 : OwnerBase_0019FD58 {
    int mC;
    int m10;
    void* m14;
};

struct Script_0019FD58 {
    char pad0[0x18];
    void* m_params;
};

struct Obj_0019FD58 {
    char pad0[0xC];
    Owner_0019FD58* mC;
    char pad10[0x1C - 0x10];
    Link_0019FD58 m_list;
    char pad2C[0x34 - 0x2C];
    int m34;
    float m38;
    char pad3C[0x48 - 0x3C];
    int m48;
    char pad4C[0x50 - 0x4C];
    float m50;
    int m54;
    float m58;
};

extern "C" Anim_0019FD58* func_001A0718(Obj_0019FD58* p);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E8398(void* params, unsigned int id, void* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" bool func_001E8708(void* params, unsigned int id);
extern "C" void func_001A1AD8(Obj_0019FD58* p, bool on);
extern "C" void func_001A1790(Obj_0019FD58* p, int a, int b);
extern "C" unsigned int func_001A1AE8(Obj_0019FD58* self, void* params, void* script, float f);
extern "C" int func_001A0D78(Obj_0019FD58* p);
extern "C" int func_001A0998(Obj_0019FD58* p, void* params, void* script);
extern "C" float func_001A1A90(Obj_0019FD58* p, void* params, void* script);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" int func_001A0DC0(Obj_0019FD58* p);
extern "C" int func_001A0AD0(Obj_0019FD58* p, unsigned int name);
extern "C" float func_001A0AB0(Obj_0019FD58* p, unsigned int name);
extern "C" void func_001A0E50(Obj_0019FD58* p, float* x, float* y, float* z);
extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* mem);
extern "C" void func_001EE608(void* p);
extern "C" void func_001EE5F8(void* p);
extern "C" void func_0011A188(Comp_0019FD58* c);
extern "C" void func_001EE5D8(Script_0019FD58* script, int a, Obj_0019FD58* p);
extern "C" void func_0019FCF0(Obj_0019FD58* p);

extern "C" int func_0019FD58(Obj_0019FD58* self, unsigned int name, void* params, Script_0019FD58* script)
{
    switch (name) {
    case 0x98A32669: {
        int on;
        func_001E7DE8(params, 0xAF06447B, &on, 1);
        func_001A1AD8(self, on != 0);
        return 1;
    }
    case 0x58C52F64:
        if (func_001E8708(params, 0xD443A2BC)) {
            func_001A1790(self, 0, 1);
        } else {
            func_001A1790(self, 1, 1);
        }
        break;
    case 0x0B1E7291:
    case 0x2CB9AD09: {
        func_001A1AE8(self, params, script, 0.3f);
        Anim_0019FD58* c = func_001A0718(self);
        if (c && c->m_state == 3) {
            self->mC->Call(0xEA6D0EFD, params, script);
        }
        return 1;
    }
    case 0x76CC99D5:
    case 0x2889C6C9:
        return func_001A0D78(self) != 0;
    case 0x1A0F9646:
    case 0xB5FB7EB6:
        return func_001A0998(self, params, script) != 0;
    case 0x5195BCBB: {
        void* s = script->m_params;
        func_001E72B0(s, 0xF0D90109, func_001A1A90(self, params, script));
        return 1;
    }
    case 0x68C86AEC:
        func_001E7EB0(params, 0, &self->m38, 0);
        self->m34 = 1;
        break;
    case 0x80FDBDF2:
        return func_001A0DC0(self) != 0;
    case 0x42FFC3CE: {
        unsigned int anim = 0;
        func_001E8398(params, 0x98549BA4, &anim, 0);
        if (func_001A0AD0(self, anim)) {
            void* s = script->m_params;
            func_001E72B0(s, 0xFE82614D, fabsf(func_001A0AB0(self, anim)));
            return 1;
        }
        break;
    }
    case 0x922E7D14: {
        float a;
        float b;
        float c;
        func_001A0E50(self, &a, &b, &c);
        float t = 0.0f;
        func_001E7EB0(params, 0, &t, 0);
        t *= 1.0f / 60.0f;
        float len = b - a;
        float cur = self->m50 - a;
        if (t == len) {
            break;
        }
        if (cur < t && t < len) {
            return 1;
        }
        if (len < cur && cur < t) {
            return 1;
        }
        if (t < len && len < cur) {
            return 1;
        }
        return 0;
    }
    case 0x74CF5C94: {
        float a;
        float b;
        float c;
        func_001A0E50(self, &a, &b, &c);
        float t = 0.0f;
        func_001E7EB0(params, 0, &t, 0);
        if (func_001E8708(params, 0x4A07C332) || func_001E8708(params, 0x019176C5)) {
            t *= 1.0f / 60.0f;
        } else if (func_001E8708(params, 0x9E497FC6)) {
            t = a + (c - a) * t * 0.01f;
        } else if (!func_001E8708(params, 0x49E0EE96) && !func_001E8708(params, 0xD029F619)) {
            t *= 0.001f;
        }
        if (func_001E8708(params, 0x91A4C826)) {
            if (a <= c) {
                self->m58 = b + t;
            } else {
                self->m58 = b - t;
            }
        } else if (func_001E8708(params, 0xE18CD075)) {
            if (a <= c) {
                self->m58 = c - t;
            } else {
                self->m58 = a + t;
            }
        } else {
            self->m58 = t;
        }
        Owner_0019FD58* o = self->mC;
        if (!o->m14) {
            o->m14 = func_001EE428(func_00121960(0xF4));
        }
        if ((a <= c && b >= self->m58) || (c <= a && b <= self->m58)) {
            func_001EE608(self->mC->m14);
            self->m54 = 0;
            break;
        }
        func_001EE5F8(self->mC->m14);
        self->m54 = 1;
        break;
    }
    case 0x5F495AE0: {
        int n = self->m_list.Count();
        Comp_0019FD58* p = self->m_list.First();
        for (int i = 0; i < n; i++) {
            func_0011A188(p);
            p = p->m_next->Valid();
        }
        return 1;
    }
    case 0xB628A959:
        func_001EE5D8(script, 5, self);
        return 1;
    case 0x9069F357: {
        unsigned int anim;
        func_001E8398(params, 0, &anim, 0);
        return func_001A0AD0(self, anim) != 0;
    }
    case 0x53F06ACC:
    case 0x02565BD1:
    case 0x3E5B6488:
    case 0x5661FB72:
    case 0x599D3707:
    case 0x5EE9D5BD:
    case 0x6AAEB76F:
    case 0x7235DAA7:
    case 0x83654874:
    case 0x987A58AB:
    case 0xA47767F2:
    case 0xD32C2724:
    case 0xC6889E91:
    case 0xBD4EDD44:
    case 0xC85B9AC0:
    case 0xD12B3713:
    case 0xF11DAAAE:
    case 0xD63A1B81:
    case 0xF5E2B871:
    case 0xFA85A1C8: {
        Anim_0019FD58* c = func_001A0718(self);
        if (!c) {
            return 1;
        }
        return c->Call(name, params, script) != 0;
    }
    case 0x986D274E:
        for (Comp_0019FD58* p = self->m_list.m_next->Valid(); p; p = p->m_next->Valid()) {
            p->Call(name, params, script);
        }
        return 1;
    case 0x27A98022:
        func_0019FCF0(self);
        return 1;
    case 0x6ECEB234:
        return (self->m48 >> 29) & 1;
    case 0xEA6D0EFD:
        break;
    default:
        return 2;
    }
    return 1;
}
