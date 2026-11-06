struct Sub_001B41E8 {
    char pad[0x30];
    float m30;
};
extern "C" Sub_001B41E8* func_00185578(void* p, unsigned int id);
struct Obj_001B41E8 {
    int m0, m4, m8;
    void* mC;
    void Scale(float f);
};

void Obj_001B41E8::Scale(float f)
{
    Sub_001B41E8* s = func_00185578(mC, 0x0A015E17);
    s->m30 *= f;
}
