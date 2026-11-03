struct Info_002CBE48 {
    int m0[21];
};

struct Item_002CBE48 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    char m1C[0x80];
    Info_002CBE48 m9C;
};

extern "C" void* func_001046B0(int size);
extern "C" Item_002CBE48* func_002CBD30(void* p);
extern "C" char* func_00331A9C(char* d, char* s);

struct Obj_002CBE48 {
    int m0;
    Item_002CBE48* m4[32];
    int m84[32];
    int m104;
    Obj_002CBE48* Copy(Obj_002CBE48* o);
};

Obj_002CBE48* Obj_002CBE48::Copy(Obj_002CBE48* o)
{
    m0 = o->m0;
    for (int i = 0; i < 32; i++) {
        if (o->m4[i]) {
            Item_002CBE48* n = func_002CBD30(func_001046B0(0xF0));
            n->m4 = o->m4[i]->m4;
            n->m8 = o->m4[i]->m8;
            n->mC = 0;
            n->m10 = 0;
            n->m14 = 0;
            n->m18 = 0;
            func_00331A9C(n->m1C, o->m4[i]->m1C);
            n->m9C = o->m4[i]->m9C;
            m4[i] = n;
        } else {
            m4[i] = 0;
        }
        m84[i] = o->m84[i];
    }
    m104 = 0;
    return this;
}
