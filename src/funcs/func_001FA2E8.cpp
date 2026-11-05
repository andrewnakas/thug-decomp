struct Obj_001FA2E8 {
    char pad[0x190];
    char m190[0x2CC - 0x190];
    int m2CC;
    void SetName(char* s);
};
extern "C" int func_00331950(char* a, char* b);
extern "C" char* func_00331A9C(char* d, char* s);

void Obj_001FA2E8::SetName(char* s)
{
    if (func_00331950(s, m190)) {
        func_00331A9C(m190, s);
        m2CC = 1;
    }
}
