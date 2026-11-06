extern char D_00361AA0[];

struct Obj_00256C08;

struct Node_00256C08 {
    int m0;
    Obj_00256C08* data;
    int m8;
    Node_00256C08* next;
    Obj_00256C08* GetData() { return data; }
    Node_00256C08* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct It_00256C08 {
    int m0;
    Node_00256C08* cur;
    void* vt;
    It_00256C08() { vt = D_00361AA0; cur = 0; }
    ~It_00256C08() { vt = D_00361AA0; }
    Obj_00256C08* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Obj_00256C08* Advance(Node_00256C08* c) {
        Node_00256C08* n = c->next;
        cur = (int)n->data != -1 ? n : 0;
        if (!cur) return 0;
        return cur->GetData();
    }
    Obj_00256C08* First(Node_00256C08* h) {
        cur = h;
        return Next();
    }
};

class Mgr_00256C08 {
public:
    char pad0[0x2C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual Node_00256C08* V6();
};

struct Obj_00256C08 {
    char pad0[0x10];
    Mgr_00256C08* m10;
    char pad14[0x18 - 0x14];
    int m18;
    char pad1C[0x50 - 0x1C];
    char m50[0x10];
    int Fn(void* params);
};

extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" Obj_00256C08* func_002582E0(Obj_00256C08* self, int a);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_001A6CA0(void* o, void* params, void* pos);

int Obj_00256C08::Fn(void* params)
{
    unsigned int name;
    int ok = func_001E8398(params, 0x7321A8D6, &name, 0);
    if (ok) {
        int t;
        switch (name) {
        case 0x5B8AB877:
            t = 1;
            break;
        case 0x88C21962:
            t = 3;
            break;
        case 0x061A741E:
            t = 2;
            break;
        case 0x3B5737A6:
            t = 4;
            break;
        default:
            return 0;
        }
        Obj_00256C08* e = func_002582E0(this, t);
        if (!e)
            return 0;
        return func_001A6CA0(func_00185578(this, 0x0A015E17), params, e->m50);
    }
    unsigned int id;
    if (func_001E8398(params, 0xA1DC81F9, &id, 0)) {
        It_00256C08 it;
        Obj_00256C08* d = it.First(m10->V6());
        Obj_00256C08* s;
        if (d) {
            It_00256C08* p = &it;
            do {
                s = d;
                Obj_00256C08* n = p->Advance(it.cur);
                d = n;
                if (s != this && s->m18 == id)
                    goto found;
            } while (d);
        }
        return 0;
    found:
        return func_001A6CA0(func_00185578(this, 0x0A015E17), params, s->m50);
    }
    return 0;
}
