extern char D_00366060[];
struct Ent_001F2998 {
    char m0;
    unsigned char m1;
    char pad[14];
};
struct Obj_001F2998 {
    int m0;
    Ent_001F2998 m4[20];
    int m144;
    void Push();
};
extern "C" void func_001F13F8(Obj_001F2998* self, char* msg);
extern "C" void func_001E6360(Ent_001F2998* e);

void Obj_001F2998::Push()
{
    if (m144 || m4[0].m1) {
        if (++m144 >= 20) {
            func_001F13F8(this, D_00366060);
            return;
        }
    }
    func_001E6360(&m4[m144]);
}
