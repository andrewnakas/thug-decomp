class Item_0011AA00 {
public:
    int m_pad[5];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int V3(unsigned int crc, void* params, void* script);
};

struct Blend_0011AA00 {
    char pad0[0x3C];
    Item_0011AA00* m_items[4];
    int m_count;
};

extern "C" void func_00119A70(Blend_0011AA00* self, void* params);
extern "C" int func_001E8398(void* s, unsigned int name, unsigned int* out, int);
extern "C" void* func_00119EA8(Blend_0011AA00* self, unsigned int id);
extern "C" void func_00119DC8(Blend_0011AA00* self, void* item);

extern "C" int func_0011AA00(Blend_0011AA00* self, unsigned int crc, void* params, void* script)
{
    switch (crc) {
    case 0x83654874:
        func_00119A70(self, params);
        return 1;
    case 0x986D274E: {
        unsigned int id;
        func_001E8398(params, 0x40C698AF, &id, 1);
        void* item = func_00119EA8(self, id);
        if (item) {
            func_00119DC8(self, item);
        }
        break;
    }
    }
    for (int i = 0; i < self->m_count; i++) {
        int r = self->m_items[i]->V3(crc, params, script);
        if (r != 2) {
            return r;
        }
    }
    return 2;
}
